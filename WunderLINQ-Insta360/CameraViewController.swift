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

class CameraViewController: UIViewController {

    @IBOutlet weak var recordButton: UIButton!
    @IBOutlet weak var modeImageView: UIImageView!
    
    var bluetoothManager = INSBluetoothManager()
    var bluetoothDevice: INSBluetoothDevice?
    let longShutterSpeed: [Int64] = [0, 30, 15, 60, 20];
    var longShutterSpeedIndex = 0;
    
    var wifiSSID = ""
    var wifiPASS = ""
    
    /// A struct representing the camera's status
    struct CameraStatus {
        var busy: Bool
        var mode: Int
    }
    var cameraStatus: CameraStatus?

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
        
        self.navigationItem.title = bluetoothDevice?.name ?? "?"
        
        var highlightColor = UIColor(named: "accent")
        if let colorData = UserDefaults.standard.data(forKey: "highlight_color_preference"){
            highlightColor = NSKeyedUnarchiver.unarchiveObject(with: colorData) as? UIColor
        }
        recordButton.backgroundColor = highlightColor
        recordButton.addTarget(self, action: #selector(toggleShutter), for: .touchUpInside)
        recordButton.isHidden = true
        
        cameraStatus = CameraStatus(busy: false, mode: 0)
        
        // Keep screen unlocked
        UIApplication.shared.isIdleTimerDisabled = true

    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        updateDisplay()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
    }
    
    override var keyCommands: [UIKeyCommand]? {
        let commands = [
            UIKeyCommand(input: "\u{d}", modifierFlags:[], action: #selector(enterKey)),
            UIKeyCommand(input: UIKeyCommand.inputUpArrow, modifierFlags:[], action: #selector(upKey)),
            UIKeyCommand(input: "+", modifierFlags:[], action: #selector(upKey)),
            UIKeyCommand(input: UIKeyCommand.inputDownArrow, modifierFlags:[], action: #selector(downKey)),
            UIKeyCommand(input: "-", modifierFlags:[], action: #selector(downKey)),
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
            let destinationVC = segue.destination as! PreviewViewController
            destinationVC.wifiSSID = self.wifiSSID
            destinationVC.wifiPASS = self.wifiPASS
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
                //Video
                self.modeImageView.image = UIImage(systemName:"video")
                if (cameraStatus!.busy) {
                    self.recordButton.setTitle(NSLocalizedString("task_title_stop_record", comment: ""), for: .normal)
                } else {
                    self.recordButton.setTitle(NSLocalizedString("task_title_start_record", comment: ""), for: .normal)
                }
                self.recordButton.isHidden = false
            case 1:
                //Photo
                self.modeImageView.image = UIImage(systemName:"camera")
                self.recordButton.setTitle(NSLocalizedString("task_title_photo", comment: ""), for: .normal)
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
            guard let peripheral = self.bluetoothDevice else { return }
            let commandManager = self.bluetoothManager.command(by: peripheral)
            commandManager.stopCapture(with: nil, completion: { (err, video) in
                NSLog("\(String(describing: err)), \(String(describing: video?.uri))")
                self.updateDisplay()
            })
            cameraStatus!.busy = false
        } else {
            //Start Capture
            switch (cameraStatus?.mode){
            case 0: //Video
                guard let peripheral = self.bluetoothDevice else { return }
                let commandManager = self.bluetoothManager.command(by: peripheral)
                commandManager.startCapture(with: nil, completion: { (err) in
                    if (err == nil) {
                        self.cameraStatus?.busy = true
                    } else {
                        self.cameraStatus?.busy = false
                        NSLog(String(describing: err))
                    }
                    self.updateDisplay()
                })
                break;
            case 1: //Photo
                guard let peripheral = self.bluetoothDevice else { return }
                let commandManager = self.bluetoothManager.command(by: peripheral)
                let options = INSTakePictureOptions.init()
                let exposureOptions = INSCameraExposureOptions()
                exposureOptions.program = 3
                exposureOptions.iso = 100
                exposureOptions.shutterSpeed = CMTime(value: longShutterSpeed[longShutterSpeedIndex],
                                                      timescale: 1)
                options.currenExposureOptions = exposureOptions
                commandManager.takePicture(with: options, completion: { (err, photo) in
                    guard let photo = photo else {
                        NSLog("Photo: \(String(describing: err))")
                        self.cameraStatus?.busy = false
                        self.updateDisplay()
                        return
                    }
                })
                
                break;
            default:
                print("Unexpected Mode")
                break;
            }
        }
    }
    private func getWifi(){
        NSLog("getWifi()")
        guard let peripheral = self.bluetoothDevice else { return }
        let commandManager = self.bluetoothManager.command(by: peripheral)
        let optionTypes = [
            NSNumber(value: INSCameraOptionsType.serialNumber.rawValue),
            NSNumber(value: INSCameraOptionsType.wifiInfo.rawValue),
            NSNumber(value: INSCameraOptionsType.wifiChannelList.rawValue),
            NSNumber(value: INSCameraOptionsType.cameraType.rawValue)
        ]
        
        commandManager.getOptionsWithTypes(optionTypes, completion: { (err, options, successTypes) in
            if let err = err {
                NSLog("\((err as NSError).code)", err.localizedDescription)
            } else {
                NSLog(options!.wifiInfo?.ssid ?? "", options!.wifiInfo?.password ?? "")
                self.wifiSSID = options!.wifiInfo?.ssid ?? ""
                self.wifiPASS = options!.wifiInfo?.password ?? ""
                //Open Preview
                let destinationVC = PreviewViewController()
                destinationVC.wifiSSID = self.wifiSSID
                destinationVC.wifiPASS = self.wifiPASS
                self.performSegue(withIdentifier: "cameraViewToPreviewView", sender: self)
            }
        })
    }
    
    @objc func enterKey() {
        SoundManager().playSoundEffect("enter")
        toggleShutter()
    }
    
    @objc func upKey() {
        SoundManager().playSoundEffect("directional")
        if(!cameraStatus!.busy) {
            if (cameraStatus!.mode == 1) {
                cameraStatus!.mode = 0
            } else {
                cameraStatus!.mode = cameraStatus!.mode + 1
            }
        }
        updateDisplay()
    }
    
    @objc func downKey() {
        SoundManager().playSoundEffect("directional")
        if(!cameraStatus!.busy) {
            if (cameraStatus!.mode == 0) {
                cameraStatus!.mode = 1
            } else {
                cameraStatus!.mode = cameraStatus!.mode - 1
            }
        }
        updateDisplay()
    }
    
    @objc func leftKey() {
        SoundManager().playSoundEffect("directional")
        if bluetoothDevice != nil {
            NSLog("Camera is connected over BLE, shutting down...")
            bluetoothManager.disconnectDevice(bluetoothDevice!)
        }
        navigationController?.popToRootViewController(animated: true)
    }
    
    @objc func rightKey() {
        if UserDefaults.standard.bool(forKey: "prefEnablePreview") {
            SoundManager().playSoundEffect("directional")
            getWifi()
        }
    }
    
    @objc func escapeKey() {
        SoundManager().playSoundEffect("enter")
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
        NSLog("getCaptureStatus()")
        guard let peripheral = self.bluetoothDevice else { return }
        let commandManager = self.bluetoothManager.command(by: peripheral)
        commandManager.getCurrentCaptureStatus(completion: { (err, status) in
            let title: String
            let message: String
            if let err = err {
                title = "failed"
                message = String.init(describing: err)
            } else {
                title = "success"
                message = "\(String(describing: status))"
            }
            NSLog("Status: \(message)")
        })
    }
}
