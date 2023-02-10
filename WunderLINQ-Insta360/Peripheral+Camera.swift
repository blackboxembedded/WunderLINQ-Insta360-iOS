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
    
    /// Reads camera's wifi info
    func requestCameraWifi(_ completion: ((Result<CommandResponse, Error>) -> Void)?) {
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0A, 0x02, 0x24, 0x30])

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
            NSLog("Status Raw: \(messageHexString)")

            finishWithResult(.success(CommandResponse(command:data, response:data)))
            return
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
    /// Reads camera's status
    func requestCameraStatus(_ completion: ((Result<CommandResponse, Error>) -> Void)?) {
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([0x1C, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x02, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00,0x0A, 0x0A, 0x0B, 0x0F, 0x13, 0x16, 0x1E, 0x24, 0x25, 0x2b, 0x30, 0x43])

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
            NSLog("Status Raw: \(messageHexString)")

            finishWithResult(.success(CommandResponse(command:data, response:data)))
            return
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
    /// ? Command 2
    func command2(_ completion: ((Result<CommandResponse, Error>) -> Void)?) {
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([0x36,0x00,0x00,0x00,0x04,0x00,0x00,0x27,0x00,0x02,0x02,0x00,0x00,0x80,0x00,0x00,0x0A,0x24,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x2D,0x34,0x62,0x33,0x61,0x2D,0x33,0x64,0x37,0x31,0x2D,0x66,0x66,0x66,0x66,0x2D,0x66,0x66,0x66,0x66,0x65,0x66,0x30,0x35,0x61,0x63,0x34,0x61])

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
            NSLog("Status Raw: \(messageHexString)")

            finishWithResult(.success(CommandResponse(command:data, response:data)))
            return
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
    /// ? Command 3
    func command3(_ completion: ((Result<CommandResponse, Error>) -> Void)?) {
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = Data([0xFF,0x0C,0x01,0x01,0x00,0x00,0xCC])

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
            NSLog("Status Raw: \(messageHexString)")

            finishWithResult(.success(CommandResponse(command:data, response:data)))
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
