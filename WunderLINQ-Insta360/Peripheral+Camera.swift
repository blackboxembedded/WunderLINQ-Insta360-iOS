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
import CoreBluetooth

/// A struct representing the camera's Wi-Fi settings
struct WiFiSettings {
    var SSID: String
    let password: String
}

/// A struct representing the camera's status
struct CameraStatus {
    var busy: Bool
    var mode: UInt8
}

struct CommandResponse {
    var command: Data
    var response: Data
}

extension Peripheral {
    
    /// Send Command to camera
    /// - Parameter completion: The completion handler with an optional error that is invoked once the request completes.
    ///
    func setCommand(command: Data, completion: ((Result<CommandResponse, Error>) -> Void)?) {
        var messageHexString = ""
        for i in 0 ..< command.count {
            messageHexString += String(format: "%02X", command[i])
        }
        NSLog("Command: \(messageHexString)")
        
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([UInt8(command.count)] + command)

        let finishWithResult: (Result<CommandResponse, Error>) -> Void = { result in
            // make sure to dispatch the result on the main thread
            DispatchQueue.main.async {
                completion?(result)
            }
        }
        
        registerObserver(serviceUUID: serviceUUID, characteristicUUID: commandResponseUUID) { data in

            var messageHexString = ""
            for i in 0 ..< data.count {
                messageHexString += String(format: "%02X", data[i])
            }
            NSLog("Response: \(messageHexString)")
            
            // The response to a command is expected to be 3 bytes
            if data.count != 3 {
                finishWithResult(.failure(CameraError.invalidResponse))
                return
            }

            // The third byte represents the camera response. If the byte is 0x00 then the request was successful
            if (data[2] != 0x00) {
                finishWithResult(.failure(CameraError.responseError))
                return
            }
            
            finishWithResult(.success(CommandResponse(command:command, response:data)))
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
    /// Reads camera's status
    func requestCameraStatus(_ completion: ((Result<CameraStatus, Error>) -> Void)?) {
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([0x07, 0x13, 0x08, 0x11, 0x2B, 0x2C, 0x37, 0x60])

        let finishWithResult: (Result<CameraStatus, Error>) -> Void = { result in
            // make sure to dispatch the result on the main thread
            DispatchQueue.main.async {
                completion?(result)
            }
        }

        registerObserver(serviceUUID: serviceUUID, characteristicUUID: commandResponseUUID) { data in

            var messageHexString = ""
            for i in 0 ..< data.count {
                messageHexString += String(format: "%02X", data[i])
            }
            NSLog("Status Raw: \(messageHexString)")
            
            // The response to the command is expected to be 12 bytes
            if data.count < 18 {
                finishWithResult(.failure(CameraError.invalidResponse))
                return
            }
            var cmode: UInt8 = 0x00
            if (data[12] == 0x60){
                cmode = data[17]
            } else if(data[12] == 0x2C){
                switch (data[11]){
                case 0x00:
                    //Video
                    cmode = 0xE8
                    if(data[14] == 0x01){
                        cmode = 0xEA
                    }
                case 0x01:
                    //Photo
                    cmode = 0xE8
                case 0x02:
                    //Timelapse
                    cmode = 0xEA
                default:
                    cmode = 0x00
                }
            }
            finishWithResult(.success(CameraStatus(busy: (data[5] == 0x01), mode: cmode)))
            return
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
}
