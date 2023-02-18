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
    var mode: Int
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
        let serviceUUID = CBUUID(string: "BE80")
        let commandUUID = CBUUID(string: "0000BE81-0000-1000-8000-00805F9B34FB")
        let commandResponseUUID = CBUUID(string: "0000BE82-0000-1000-8000-00805F9B34FB")
        let data = command

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
            NSLog("Response Raw: \(messageHexString)")
            finishWithResult(.success(CommandResponse(command:command, response:data)))
        } completion: { [weak self] error in
            // Check that we successfully enable the notification for the response before writing to the characteristic
            if error != nil { finishWithResult(.failure(error!)); return }
            self?.write(data: data, serviceUUID: serviceUUID, characteristicUUID: commandUUID) { error in
                if error != nil { finishWithResult(.failure(error!)) }
            }
        }
    }
    
}
