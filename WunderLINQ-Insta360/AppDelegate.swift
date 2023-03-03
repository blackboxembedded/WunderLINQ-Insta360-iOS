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

import UIKit

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        // Create and write to log file
        if UserDefaults.standard.bool(forKey: "debug_logging_preference") {
            let paths = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)
            let documentsDirectory = paths[0]
            let fileName = "wunderlinq-insta360.log"
            let logFilePath = (documentsDirectory as NSString).appendingPathComponent(fileName)
            
            let fileManager = FileManager.default
            
            do {
                let attributes = try fileManager.attributesOfItem(atPath: logFilePath)
                let fileSize = attributes[FileAttributeKey.size] as! UInt64
                
                if fileSize > 20 * 1024 * 1024 {
                    try fileManager.removeItem(atPath: logFilePath)
                    NSLog("AppDelegate: File deleted successfully")
                } else {
                    NSLog("AppDelegate: File is not over 20MB")
                }
            } catch {
                NSLog("AppDelegate: Error: \(error)")
            }
            freopen(logFilePath.cString(using: String.Encoding.ascii)!, "a+", stderr)
        }
        
        // Keep screen unlocked
        application.isIdleTimerDisabled = true
        
        INSCameraManager.shared().setup()
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

