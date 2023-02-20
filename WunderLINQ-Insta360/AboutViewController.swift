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
import MessageUI
import MobileCoreServices

class AboutViewController: UIViewController, MFMailComposeViewControllerDelegate {
    
    @IBOutlet weak var logoImageView: UIImageView!
    @IBOutlet weak var versionLabel: UILabel!
    
    @IBAction func corpNameBtnPressed(_ sender: Any) {
        guard let url = URL(string: "https://www.blackboxembedded.com") else {
            return //be safe
        }
        
        if #available(iOS 10.0, *) {
            UIApplication.shared.open(url, options: convertToUIApplicationOpenExternalURLOptionsKeyDictionary([:]), completionHandler: nil)
        } else {
            UIApplication.shared.openURL(url)
        }
    }
    
    @IBAction func documentationBtnPressed(_ sender: Any) {
        guard let url = URL(string: "https://blackboxembedded.github.io/WunderLINQ-Documentation/en/index-insta360-ios.html") else {
            return //be safe
        }
        
        if #available(iOS 10.0, *) {
            UIApplication.shared.open(url, options: convertToUIApplicationOpenExternalURLOptionsKeyDictionary([:]), completionHandler: nil)
        } else {
            UIApplication.shared.openURL(url)
        }
    }
    
    @IBAction func sendLogsBtnPressed(_ sender: Any) {
        if MFMailComposeViewController.canSendMail() {
            var dateFormatter: DateFormatter {
                let formatter = DateFormatter()
                formatter.dateFormat = "yyyyMMdd-HH:mm"
                formatter.locale = Locale.current
                formatter.timeZone = TimeZone.current
                return formatter
            }
            let today = dateFormatter.string(from: Date())

            let mailComposer = MFMailComposeViewController()
            mailComposer.setSubject("WunderLINQ Insta360 iOS Logs \(today)")
            mailComposer.setMessageBody("App Version: \(getAppInfo())\niOS Version: \(getOSInfo())\nDevice: \(UIDevice.current.modelName)\n\(NSLocalizedString("sendlogs_body", comment: ""))", isHTML: false)
            mailComposer.setToRecipients(["support@blackboxembedded.com"])
            // Get the documents folder url
            let documentDirectory = try! FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
            // Destination url for the log file to be saved
            let logURL = documentDirectory.appendingPathComponent("wunderlinq-insta360.log")
            do {
                let logAttachmentData = try Data(contentsOf: logURL)
                mailComposer.addAttachmentData(logAttachmentData, mimeType: "text/log", fileName: "wunderlinq-insta360.log")
            } catch let error {
                print("We have encountered error \(error.localizedDescription)")
            }
            mailComposer.mailComposeDelegate = self
            self.present(mailComposer, animated: true, completion: nil)
            
        } else {
            print("Email is not configured in settings app or we are not able to send an email")
        }
    }
    
    @objc func leftScreen() {
        navigationController?.popViewController(animated: true)
        dismiss(animated: true, completion: nil)
    }
    
    @objc func logoTap() {
        let url = URL(string: "http://www.wunderlinq.com")!

        if #available(iOS 10.0, *) {
            UIApplication.shared.open(url, options: convertToUIApplicationOpenExternalURLOptionsKeyDictionary([:]), completionHandler: nil)
        } else {
            UIApplication.shared.openURL(url)
        }
    }
    
    @objc func handleGesture(gesture: UISwipeGestureRecognizer) -> Void {
        if gesture.direction == UISwipeGestureRecognizer.Direction.right {
            navigationController?.popViewController(animated: true)
            dismiss(animated: true, completion: nil)
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        if let version = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String {
            let versionLabelString = NSLocalizedString("version_label", comment: "")
            self.versionLabel.text = "\(versionLabelString) \(version)"
        }
        
        logoImageView.isUserInteractionEnabled = true
        let singleTap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(logoTap))
        singleTap.numberOfTapsRequired = 1;
        logoImageView.addGestureRecognizer(singleTap)
        
        self.view.addSubview(logoImageView)
        
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
    }
    
    func mailComposeController(_ controller: MFMailComposeViewController, didFinishWith result: MFMailComposeResult, error: Error?) {
        switch result {
        case .cancelled:
            print("User cancelled")
            break
        case .saved:
            print("Mail is saved by user")
            break
        case .sent:
            print("Mail is sent successfully")
            break
        case .failed:
            print("Sending mail is failed")
            break
        default:
            break
        }
        controller.dismiss(animated: true)
    }
    
    func getOSInfo() -> String {
        let os = ProcessInfo.processInfo.operatingSystemVersion
        return String(os.majorVersion) + "." + String(os.minorVersion) + "." + String(os.patchVersion)
    }
    
    func getAppInfo() -> String {
        let dictionary = Bundle.main.infoDictionary!
        let version = dictionary["CFBundleShortVersionString"] as! String
        let build = dictionary["CFBundleVersion"] as! String
        return version + "(" + build + ")"
    }
}

extension UIDevice {
    var modelName: String {
        var systemInfo = utsname()
        uname(&systemInfo)
        let machineMirror = Mirror(reflecting: systemInfo.machine)
        let identifier = machineMirror.children.reduce("") { identifier, element in
            guard let value = element.value as? Int8, value != 0 else { return identifier }
            return identifier + String(UnicodeScalar(UInt8(value)))
        }
        return identifier
    }
}

// Helper function inserted by Swift 4.2 migrator.
fileprivate func convertToUIApplicationOpenExternalURLOptionsKeyDictionary(_ input: [String: Any]) -> [UIApplication.OpenExternalURLOptionsKey: Any] {
	return Dictionary(uniqueKeysWithValues: input.map { key, value in (UIApplication.OpenExternalURLOptionsKey(rawValue: key), value)})
}
