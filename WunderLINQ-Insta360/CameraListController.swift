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
import CoreBluetooth
import InAppSettingsKit

class CameraListController: UITableViewController {
    
    @IBOutlet weak var cameraListTableView: UITableView!
    
    var scanner = CentralManager()
    private var peripheral: Peripheral?
    
    private let notificationCenter = NotificationCenter.default
    
    var itemRow = 0

    override func viewDidLoad() {
        super.viewDidLoad()
            
        self.navigationItem.title = NSLocalizedString("cameralist_title", comment: "")
        let menuBtn = UIButton()
        menuBtn.setImage(UIImage(named: "Menu")?.withRenderingMode(.alwaysTemplate), for: .normal)
        if #available(iOS 13.0, *) {
            menuBtn.tintColor = UIColor(named: "imageTint")
        }
        menuBtn.addTarget(self, action: #selector(menuButton), for: .touchUpInside)
        let menuButton = UIBarButtonItem(customView: menuBtn)
        let menuButtonWidth = menuButton.customView?.widthAnchor.constraint(equalToConstant: 30)
        menuButtonWidth?.isActive = true
        let menuButtonHeight = menuButton.customView?.heightAnchor.constraint(equalToConstant: 30)
        menuButtonHeight?.isActive = true
        self.navigationItem.rightBarButtonItems = [menuButton]
        
        if let peripheral = peripheral {
            NSLog("Disconnecting to \(peripheral.name)..")
            peripheral.disconnect()
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        NSLog("Scanning for Insta360 cameras..")
        scanner.start(withServices: [CBUUID(string: "BE80")])
        notificationCenter.addObserver(self, selector:#selector(updateDisplay), name: NSNotification.Name("CameraFound"), object: nil)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        notificationCenter.removeObserver(self)
        scanner.stop()
    }

    // MARK: - Table view data source
    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return scanner.peripherals.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "CameraListViewCell", for: indexPath) as! CameraTableViewCell
        // Configure the cell
        if (indexPath.row < scanner.peripherals.count ){
            let labelText = scanner.peripherals[indexPath.row].name
            cell.displayContent(label: labelText)
            if (itemRow == indexPath.row){
                cell.highlightEffect()
            } else {
                cell.removeHighlight()
            }
        }
        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        itemRow = indexPath.row
        enterKey()
    }
    
    @objc func updateDisplay(){
        if self.viewIfLoaded?.window != nil {
            cameraListTableView.reloadData()
        }
    }
    
    override var keyCommands: [UIKeyCommand]? {
        let commands = [
            UIKeyCommand(input: "\u{d}", modifierFlags:[], action: #selector(enterKey)),
            UIKeyCommand(input: UIKeyCommand.inputUpArrow, modifierFlags:[], action: #selector(upKey)),
            UIKeyCommand(input: UIKeyCommand.inputDownArrow, modifierFlags:[], action: #selector(downKey)),
            UIKeyCommand(input: UIKeyCommand.inputEscape, modifierFlags:[], action: #selector(escapeKey))
        ]
        if #available(iOS 15, *) {
            commands.forEach { $0.wantsPriorityOverSystemBehavior = true }
        }
        return commands
    }
    
    @objc func menuButton() {
        let appSettingsViewController = IASKAppSettingsViewController()
        self.navigationController!.pushViewController(appSettingsViewController, animated: true)
    }
    
    @objc func enterKey() {
        let child = SpinnerViewController()
        //Add the spinner view controller
        addChild(child)
        child.view.frame = view.frame
        view.addSubview(child.view)
        child.didMove(toParent: self)
        
        let selected: Peripheral = scanner.peripherals[itemRow]
        selected.connect { error in
            //Remove the spinner view controller
            child.willMove(toParent: nil)
            child.view.removeFromSuperview()
            child.removeFromParent()
            if error != nil {
                NSLog("Error connecting to \(selected.name)")
                return
            }
            NSLog("Connected to \(selected.name)!")
            self.peripheral = selected
            let destinationVC = CameraViewController()
            destinationVC.peripheral = selected
            self.performSegue(withIdentifier: "cameraListToCameraView", sender: self)
        }
    }
    
    @objc func upKey() {
        var nextRow = 0
        if (itemRow == 0){
            nextRow = scanner.peripherals.count - 1
        } else if (itemRow < scanner.peripherals.count){
            nextRow = itemRow - 1
        }
        
        self.cameraListTableView.scrollToRow(at: IndexPath(row: nextRow, section: 0), at: .middle, animated: true)
        self.view.layoutIfNeeded()
        cameraListTableView.reloadData()
        itemRow = nextRow
    }
    
    @objc func downKey() {
        
        var nextRow = 0
        if (itemRow == (scanner.peripherals.count - 1)){
            nextRow = 0
        } else if (itemRow < scanner.peripherals.count ){
            nextRow = itemRow + 1
        }
        
        self.cameraListTableView.scrollToRow(at: IndexPath(row: nextRow, section: 0), at: .middle, animated: true)
        self.view.layoutIfNeeded()
        cameraListTableView.reloadData()
        itemRow = nextRow
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

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if (segue.identifier == "cameraListToCameraView") {
            let vc = segue.destination as! CameraViewController
            vc.peripheral = self.peripheral
        }
    }

}

