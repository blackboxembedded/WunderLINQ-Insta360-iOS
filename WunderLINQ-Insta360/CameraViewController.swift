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
    var wifiResponse: Data?
    var responsePosition: Int = 0
    
    var timer = Timer()
    
    let getCameraWiFi = Data([0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0A, 0x02, 0x24, 0x30])
    let getCameraStatus = Data([0x1C, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x02, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00,0x0A, 0x0A, 0x0B, 0x0F, 0x13, 0x16, 0x1E, 0x24, 0x25, 0x2b, 0x30, 0x43])
    let command2 = Data([0x36,0x00,0x00,0x00,0x04,0x00,0x00,0x27,0x00,0x02,0x02,0x00,0x00,0x80,0x00,0x00,0x0A,0x24,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x2D,0x34,0x62,0x33,0x61,0x2D,0x33,0x64,0x37,0x31,0x2D,0x66,0x66,0x66,0x66,0x2D,0x66,0x66,0x66,0x66,0x65,0x66,0x30,0x35,0x61,0x63,0x34,0x61])
    let command3 = Data([0xFF,0x0C,0x01,0x01,0x00,0x00,0xCC])
   
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
        sendCameraCommand(command: getCameraWiFi)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if let peripheral = peripheral {
            NSLog("Disconnecting to \(peripheral.name)..")
            peripheral.disconnect()
        }
        
        if INSCameraManager.socket().cameraState == .connected {
            print("Camera is already connected")
            INSCameraManager.shared().shutdown()
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
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_hdr", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_hdr", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            case 2:
                //Interval/Bullet  Time
                self.modeImageView.image = UIImage(named:"interval")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_bullettime", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_bullettime", comment: ""), for: .normal)
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
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_record", comment: ""), for: .normal)
                    self.recordButton.isHidden = false
                }
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
            switch (cameraStatus?.mode){
            case 0:
                let options = INSCaptureOptions()
                options.mode = INSCaptureMode.normal
                INSCameraManager.shared().commandManager.startCapture(with: options) { error in
                    if let error = error {
                        print("start capture error: \(error)")
                    }
                }
                break;
            case 1:
                let options = INSCaptureOptions()
                options.mode = INSCaptureMode.HDR
                INSCameraManager.shared().commandManager.startCapture(with: options) { error in
                    if let error = error {
                        print("start capture error: \(error)")
                    }
                }
                break;
            case 2:
                let options = INSCaptureOptions()
                options.mode = INSCaptureMode.bulletTime
                INSCameraManager.shared().commandManager.startCapture(with: options) { error in
                    if let error = error {
                        print("start capture error: \(error)")
                    }
                }
                break;
            case 3:
                let options = INSTimelapseOptions()
                //options.duration = /* total record duration that you expect */
                options.lapseTime = 500/* the time interval for capturing each picture */
                let tloptions = INSStartCaptureTimelapseOptions()
                tloptions.mode = INSTimelapseMode.video
                tloptions.timelapseOptions = options
                INSCameraManager.shared().commandManager.startCaptureTimelapse(with: tloptions) { error in
                    if let error = error {
                        print("start timelapse capture error: \(error)")
                    }
                }
                
                break;
            default:
                print("Unexpected Mode")
                break;
            }
            
            cameraStatus!.busy = true
        }
        getCaptureStatus()
    }
    
    func sendCameraCommand(command: Data){
        self.lastCommand = command
        self.peripheral?.setCommand(command: command) { [self] result in
            switch result {
            case .success(let response):
                //Check command/response and do something
                let commandResponse:Data = response.response
                if self.wifiResponse == nil {
                    if commandResponse[0] > 0x20 {
                        self.wifiResponse = Data()
                        self.wifiResponse?.append(contentsOf: commandResponse)
                        self.responsePosition += commandResponse.count
                    }
                } else {
                    if self.responsePosition != self.wifiResponse?.count {
                        self.wifiResponse?.append(contentsOf: commandResponse)
                        self.responsePosition += commandResponse.count
                        if self.responsePosition == self.wifiResponse?.count {
                            self.sendCameraCommand(command: self.command2)
                        }
                    } else {
                        if commandResponse[0] == 0x12 {
                            self.joinWiFi(with: self.peripheral!.name + ".OSC", password: "88888888")
                        } else if commandResponse[0] == 0x07 {
                            //Do Nothing
                        }
                    }
                }
                //self.updateDisplay()
            case .failure(let error):
                NSLog("\(error)")
            }
        }
    }
    
    private func joinWiFi(with SSID: String, password: String) {
        NSLog("Joining WiFi \(SSID)...")
        let configuration = NEHotspotConfiguration(ssid: SSID, passphrase: password, isWEP: false)
        
        NEHotspotConfigurationManager.shared.apply(configuration) { error in
            guard let error = error else {
                NSLog("Joining WiFi succeeded");
                DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 3) {
                    if INSCameraManager.socket().cameraState == .connected {
                        print("Camera is already connected")
                    } else {
                        INSCameraManager.socket().setup()
                    }
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
        if UserDefaults.standard.bool(forKey: "prefEnablePreview") {
            //Open Preview
            let destinationVC = PreviewViewController()
            destinationVC.peripheral = self.peripheral
            self.performSegue(withIdentifier: "cameraViewToPreviewView", sender: self)
        }
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
                if (status.state == INSCameraCaptureState.notCapture){
                    self.cameraStatus?.busy = false
                } else if (status.state == INSCameraCaptureState.normalCapture){
                    //print("normalCapture")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 0
                } else if (status.state == INSCameraCaptureState.hdrVideoCapture){
                    //print("hdrVideoCapture")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 1
                } else if (status.state == INSCameraCaptureState.intervalShootingCapture){
                    //print("intervalShootingCapture")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 2
                } else if (status.state == INSCameraCaptureState.timelapseCapture){
                    //print("timelapseCapture")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 3
                } else if (status.state == INSCameraCaptureState.bulletTimeCapture){
                    //print("bulletTimeCapture")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 2
                } else if (status.state.rawValue == 13){
                    //print("timeShift")
                    self.cameraStatus?.busy = true
                    self.cameraStatus?.mode = 3
                }
                self.updateDisplay()
            }
        }
    }
    
    func startSendingHeartbeats() {
        print("Heartbeat Start")
        timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(self.heartbeat), userInfo: nil, repeats: true)
    }

    func stopSendingHeartbeats() {
        print("Heartbeat Canceled")
        timer.invalidate()
    }
    
    @objc func heartbeat() {
        INSCameraManager.socket().commandManager.sendHeartbeats(with: nil)
        getCaptureStatus()
    }

}
