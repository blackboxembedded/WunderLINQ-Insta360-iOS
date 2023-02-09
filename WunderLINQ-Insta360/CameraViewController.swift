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
    
    var peripheral: Peripheral?
    var cameraStatus: CameraStatus?
    var wifiSettings: WiFiSettings?
    
    var lastCommand: Data?
   
    @IBAction func didTapImageView(_ sender: UITapGestureRecognizer) {
        enableWifi()
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
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        getCameraStatus()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if let peripheral = peripheral {
            NSLog("Disconnecting to \(peripheral.name)..")
            peripheral.disconnect()
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
            vc.wifiSettings = self.wifiSettings
            vc.cameraStatus = self.cameraStatus
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
        switch cameraStatus!.mode {
        case 0xE8:
            //Video
            self.modeImageView.image = UIImage(systemName:"video")
            if (cameraStatus!.busy) {
                self.recordButton.setTitle(NSLocalizedString("task_title_stop_record", comment: ""), for: .normal)
            } else {
                self.recordButton.setTitle(NSLocalizedString("task_title_start_record", comment: ""), for: .normal)
            }
            self.recordButton.isHidden = false
        case 0xE9:
            //Photo
            self.modeImageView.image = UIImage(systemName:"camera")
            self.recordButton.setTitle(NSLocalizedString("task_title_photo", comment: ""), for: .normal)
            self.recordButton.isHidden = false
        case 0xEA:
            //Timelapse
            self.modeImageView.image = UIImage(systemName:"timelapse")
            if (cameraStatus!.busy) {
                self.recordButton.setTitle(NSLocalizedString("task_title_start_timelapse", comment: ""), for: .normal)
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
    
    @objc func toggleShutter() {
        NSLog("toggleShutter()")
        if (cameraStatus!.busy){
            sendCameraCommand(command: Data([0x01, 0x01, 0x00]))
        } else {
            sendCameraCommand(command: Data([0x01, 0x01, 0x01]))
        }
    }
    
    func enableWifi() {
        NSLog("enableWifi()")
        sendCameraCommand(command: Data([0x17, 0x01, 0x01]))
    }
    
    func sendCameraCommand(command: Data){
        self.lastCommand = command
        self.peripheral?.setCommand(command: command) { result in
            switch result {
            case .success(let response):
                NSLog("Command Response: \(response)")
                //Check command/response and do something
                let commandResponse: CommandResponse = response
                var messageHexString = ""
                for i in 0 ..< commandResponse.command.count {
                    messageHexString += String(format: "%02X", commandResponse.command[i])
                }
                NSLog("Command: \(messageHexString)")
                if ((self.lastCommand![0] == 0x01) && (commandResponse.response[1] == 0x01)){
                    //Shutter Command
                    if (self.lastCommand![2] == 0x01){
                        self.cameraStatus!.busy = true
                    } else {
                        self.cameraStatus!.busy = false
                    }
                } else if (commandResponse.response[1] == 0x17){
                    if (commandResponse.response[2] == 0x00){
                        //Enable WiFi Command
                        self.requestWiFiSettngs()
                    }
                }
                //self.getCameraStatus()
                self.updateDisplay()
            case .failure(let error):
                NSLog("\(error)")
                self.getCameraStatus()
            }
        }
    }
    
    func getCameraStatus() {
        peripheral?.requestCameraStatus() { result in
            switch result {
            case .success(let status):
                print("Camera Status: \(status)")
                self.cameraStatus = status
                self.updateDisplay()
            case .failure(let error):
                print("\(error)")
                self.getCameraStatus()
            }
        }
    }
    
    func requestWiFiSettngs() {
        NSLog("requestWiFiSettngs()")
        self.peripheral?.requestWiFiSettings { result in
            switch result {
            case .success(let settings):
                NSLog("WiFi settings: \(settings)")
                self.wifiSettings = settings
                let destinationVC = PreviewViewController()
                destinationVC.peripheral = self.peripheral
                destinationVC.wifiSettings = self.wifiSettings
                destinationVC.cameraStatus = self.cameraStatus
                self.performSegue(withIdentifier: "cameraViewToPreviewView", sender: self)
            case .failure(let error):
                NSLog("\(error)")
            }
        }
    }
    
    @objc func enterKey() {
        toggleShutter()
    }
    
    @objc func upKey() {
        if (cameraStatus?.mode == 0x00) {
            getCameraStatus()
        } else if (cameraStatus?.mode == 0xEA) {
            cameraStatus?.mode = 0xE8
        } else {
            let mode = cameraStatus?.mode
            cameraStatus?.mode = mode! + 1
        }
        var cmode:UInt8 = 0x00
        switch (cameraStatus?.mode){
        case 0xE8:
            cmode = 0x00
        case 0xE9:
            cmode = 0x01
        case 0xEA:
            cmode = 0x02
        default:
            print("Unknown mode")
        }
        if((0xE8...0xEA).contains(cameraStatus!.mode)){
            sendCameraCommand(command: Data([0x02,0x01,cmode]))
        }
    }
    
    @objc func downKey() {
        if (cameraStatus?.mode == 0x00) {
            getCameraStatus()
        } else if (cameraStatus?.mode == 0xE8) {
            cameraStatus?.mode = 0xEA
        } else {
            let mode = cameraStatus?.mode
            cameraStatus?.mode = mode! - 1
        }
        var cmode:UInt8 = 0x00
        switch (cameraStatus?.mode){
        case 0xE8:
            cmode = 0x00
        case 0xE9:
            cmode = 0x01
        case 0xEA:
            cmode = 0x02
        default:
            print("Unknown mode")
        }
        if((0xE8...0xEA).contains(cameraStatus!.mode)){
            sendCameraCommand(command: Data([0x02,0x01,cmode]))
        }
    }
    
    @objc func leftKey() {
        navigationController?.popToRootViewController(animated: true)
    }
    
    @objc func rightKey() {
        enableWifi()
        
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

}
