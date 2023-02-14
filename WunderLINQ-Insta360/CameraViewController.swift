/*
WunderLINQ Client Application
Copyright (C) 2020  Keith Conger, Black Box Embedded, LLC
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

import Foundation
import UIKit
import NetworkExtension

class CameraViewController: UIViewController {

    @IBOutlet weak var recordButton: UIButton!
    @IBOutlet weak var modeImageView: UIImageView!
    
    var peripheral: Peripheral?
    var cameraStatus: CameraStatus?
    
    var lastCommand: Data?
    
    var timer = Timer()
   
    @IBAction func didTapImageView(_ sender: UITapGestureRecognizer) {
        //Open Preview
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let swipeUp = UISwipeGestureRecognizer(target: self, action: #selector(handleGesture))
        swipeUp.direction = .up
        self.view.addGestureRecognizer(swipeUp)
        
        let swipeDown = UISwipeGestureRecognizer(target: self, action: #selector(handleGesture))
        swipeDown.direction = .down
        self.view.addGestureRecognizer(swipeDown)
        
        let swipeLeft = UISwipeGestureRecognizer(target: self, action: #selector(handleGesture))
        swipeLeft.direction = .left
        self.view.addGestureRecognizer(swipeLeft)
        
        let swipeRight = UISwipeGestureRecognizer(target: self, action: #selector(handleGesture))
        swipeRight.direction = .right
        self.view.addGestureRecognizer(swipeRight)
        
        self.navigationItem.title = peripheral?.name ?? "?"
        
        var highlightColor = UIColor(named: "accent")
        if let colorData = UserDefaults.standard.data(forKey: "highlight_color_preference"){
            highlightColor = NSKeyedUnarchiver.unarchiveObject(with: colorData) as? UIColor
        }
        recordButton.backgroundColor = highlightColor
        recordButton.addTarget(self, action: #selector(toggleShutter), for: .touchUpInside)
        recordButton.isHidden = true
        
        cameraStatus = CameraStatus(busy: false, mode: 0)
        
        INSCameraManager.socket().addObserver(self, forKeyPath: "cameraState", options: .new, context: nil)

    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        //getCameraWifi()
        joinWiFi(with: self.peripheral!.name + ".OSC", password: "88888888")
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if let peripheral = peripheral {
            NSLog("Disconnecting to \(peripheral.name)..")
            peripheral.disconnect()
        }
        
        if INSCameraManager.socket().cameraState == .connected {
            print("Camera is already connected")
            //INSCameraManager.shared().shutdown()
        }
    }
    
    override var keyCommands: [UIKeyCommand]? {
        let commands = [
            UIKeyCommand(input: "\u{d}", modifierFlags:[], action: #selector(enterKey)),
            UIKeyCommand(input: UIKeyCommand.inputUpArrow, modifierFlags:[], action: #selector(upKey)),
            UIKeyCommand(input: UIKeyCommand.inputDownArrow, modifierFlags:[], action: #selector(downKey)),
            UIKeyCommand(input: UIKeyCommand.inputLeftArrow, modifierFlags:[], action: #selector(leftKey)),
            UIKeyCommand(input: UIKeyCommand.inputRightArrow, modifierFlags:[], action: #selector(rightKey)),
            UIKeyCommand(input: UIKeyCommand.inputEscape, modifierFlags:[], action: #selector(escapeKey))
        ]
        if #available(iOS 15, *) {
            commands.forEach { $0.wantsPriorityOverSystemBehavior = true }
        }
        return commands
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if (segue.identifier == "cameraViewToPreviewView") {
            let vc = segue.destination as! PreviewViewController
            vc.peripheral = self.peripheral
        }
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        guard let object = object as? INSCameraManager else {
            super.observeValue(forKeyPath: keyPath, of: object, change: change, context: context)
            return
        }
        guard let stateValue = change?[.newKey] as? UInt, let state = INSCameraState(rawValue: stateValue) else {
            print("Invalid state value: \(change?[.newKey] ?? "nil")")
            return
        }
        switch state {
        case .found:
            print("Camera Found")
        case .connected:
            print("Camera Connected")
            updateDisplay()
            startSendingHeartbeats()
        case .connectFailed:
            print("Camera Connect Failed")
            stopSendingHeartbeats()
        default:
            print("Camera Not connected")
            stopSendingHeartbeats()
        }
    }
    
    @objc func handleGesture(gesture: UISwipeGestureRecognizer) -> Void {
        if gesture.direction == UISwipeGestureRecognizer.Direction.right {
            leftKey()
        }
        else if gesture.direction == UISwipeGestureRecognizer.Direction.left {
            rightKey()
        }
        else if gesture.direction == UISwipeGestureRecognizer.Direction.up {
            upKey()
        }
        else if gesture.direction == UISwipeGestureRecognizer.Direction.down {
            downKey()
        }
    }
    
    func updateDisplay() {
        print("updateDisplay()")
        if (cameraStatus != nil){
            switch cameraStatus!.mode {
            case 0:
                //Normal
                self.modeImageView.image = UIImage(systemName:"video")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_record", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_record", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            case 1:
                //HDR
                self.modeImageView.image = UIImage(named: "hdr")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_record", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_record", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            case 2:
                //Interval
                self.modeImageView.image = UIImage(named:"interval")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_interval", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_interval", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            case 3:
                //Timelapse
                self.modeImageView.image = UIImage(systemName:"timelapse")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_timelapse", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_timelapse", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            default:
                //Unknown
                self.modeImageView.image = nil
                self.recordButton.isHidden = false
            }
        }
    }
    
    @objc func toggleShutter() {
        NSLog("toggleShutter()")
        if (cameraStatus!.busy){
            //Stop Capture
            let options = INSCaptureOptions()
            INSCameraManager.shared().commandManager.stopCapture(with: options) { error, videoInfo in
                if let error = error {
                    print("stop capture error: \(error)")
                } else if let videoInfo = videoInfo {
                    print("video url: \(videoInfo.uri)")
                }
            }
            cameraStatus!.busy = false
        } else {
            //Start Capture
            let options = INSCaptureOptions()
            switch (cameraStatus?.mode){
            case 0:
                options.mode = INSCaptureMode.normal
                break;
            case 1:
                options.mode = INSCaptureMode.HDR
                break;
            case 2:
                options.mode = INSCaptureMode.bulletTime
                break;
            case 3:
                options.mode = INSCaptureMode.timeShift
                break;
            default:
                options.mode = INSCaptureMode.normal
                break;
            }
            INSCameraManager.shared().commandManager.startCapture(with: options) { error in
                if let error = error {
                    print("start capture error: \(error)")
                }
            }
            cameraStatus!.busy = true
        }
        getCaptureStatus()
    }
    
    func getCameraWifi() {
        print("getCameraWifi()")
        peripheral?.requestCameraWifi() { result in
            switch result {
            case .success(let status):
                print("requestCameraWif Status: \(status)")
                self.sendCommand2()
                self.updateDisplay()
            case .failure(let error):
                print("\(error)")
                //self.getCameraStatus()
            }
        }
    }
    
    func sendCommand2() {
        print("sendCommand2()")
        peripheral?.command2() { result in
            switch result {
            case .success(let status):
                print("Command2 Status: \(status)")
                self.sendCommand3()
                self.updateDisplay()
            case .failure(let error):
                print("\(error)")
                //self.getCameraStatus()
            }
        }
    }
    
    func sendCommand3() {
        print("sendCommand3()")
        peripheral?.command3() { result in
            switch result {
            case .success(let status):
                print("Command3 Status: \(status)")
                self.updateDisplay()
                self.joinWiFi(with: self.peripheral!.name + ".OSC", password: "88888888")
            case .failure(let error):
                print("\(error)")
                //self.getCameraStatus()
            }
        }
    }
    
    private func joinWiFi(with SSID: String, password: String) {
        NSLog("Joining WiFi \(SSID)...")
        let configuration = NEHotspotConfiguration(ssid: SSID, passphrase: password, isWEP: false)
        
        NEHotspotConfigurationManager.shared.apply(configuration) { error in
            guard let error = error else {
                NSLog("Joining WiFi succeeded");
                if INSCameraManager.socket().cameraState == .connected {
                    print("Camera is already connected")
                } else {
                    INSCameraManager.socket().setup()
                }
                return
            }
            NSLog("Joining WiFi failed: \(error)")
            if error.localizedDescription == "already associated." {
                print("Already Associated")
                if INSCameraManager.socket().cameraState == .connected {
                    print("Camera is already connected")
                } else {
                    INSCameraManager.socket().setup()
                }
            }
        }
    }
    
    
    @objc func enterKey() {
        toggleShutter()
    }
    
    @objc func upKey() {
        if(!cameraStatus!.busy) {
            if (cameraStatus!.mode == 3) {
                cameraStatus!.mode = 0
            } else {
                cameraStatus!.mode = cameraStatus!.mode + 1
            }
        }
        updateDisplay()
    }
    
    @objc func downKey() {
        if(!cameraStatus!.busy) {
            if (cameraStatus!.mode == 0) {
                cameraStatus!.mode = 3
            } else {
                cameraStatus!.mode = cameraStatus!.mode - 1
            }
        }
        updateDisplay()
    }
    
    @objc func leftKey() {
        navigationController?.popToRootViewController(animated: true)
    }
    
    @objc func rightKey() {
        //Open Preview
        let destinationVC = PreviewViewController()
        destinationVC.peripheral = self.peripheral
        self.performSegue(withIdentifier: "cameraViewToPreviewView", sender: self)
    }
    
    @objc func escapeKey() {
        guard let url = URL(string: "wunderlinq://") else {
            return
        }
        if #available(iOS 10.0, *) {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        } else {
            UIApplication.shared.openURL(url)
        }
    }
    
    func getCaptureStatus() {
        INSCameraManager.socket().commandManager.getCurrentCaptureStatus { error, status in
            if let error = error {
                print("Error getting current capture status: \(error)")
            } else if let status = status {
                print("Current capture status: \(status.state)")
                if (status.state == INSCameraCaptureState.notCapture){
                    self.cameraStatus?.busy = false
                } else if (status.state == INSCameraCaptureState.normalCapture){
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 0
                } else if (status.state == INSCameraCaptureState.hdrVideoCapture){
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 1
                } else if (status.state == INSCameraCaptureState.intervalVideoCapture){
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 2
                } else if (status.state == INSCameraCaptureState.timelapseCapture){
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 3
                } else if (status.state == INSCameraCaptureState.bulletTimeCapture){
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 3
                }
                self.updateDisplay()
            }
        }
    }
    
    func startSendingHeartbeats() {
        print("heartbeat start")
        timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(self.heartbeat), userInfo: nil, repeats: true)
    }

    func stopSendingHeartbeats() {
        print("heartbeat canceled")
        timer.invalidate()
    }
    
    @objc func heartbeat() {
        INSCameraManager.socket().commandManager.sendHeartbeats(with: nil)
        getCaptureStatus()
    }

}
