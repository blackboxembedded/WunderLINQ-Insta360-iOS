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

class CameraTableViewCell: UITableViewCell {

    @IBOutlet weak var uiView: UIView!
    @IBOutlet weak var chevronImage: UIImageView!
    @IBOutlet weak var nameLabel: UILabel!
    
    public var icon: UIImageView!
    public var label: String!
    
    func displayContent(label: String) {
        chevronImage.tintColor = UIColor(named: "imageTint")
        nameLabel.text = label
    }
    
    func highlightEffect(){
        var highlightColor: UIColor?
        if let colorData = UserDefaults.standard.data(forKey: "highlight_color_preference"){
            highlightColor = NSKeyedUnarchiver.unarchiveObject(with: colorData) as? UIColor
        } else {
            highlightColor = UIColor(named: "accent")
        }
        
        uiView.backgroundColor = highlightColor
        chevronImage.tintColor = UIColor.white
        nameLabel.textColor = UIColor.white
    }
    
    func removeHighlight(){
        uiView.backgroundColor = UIColor.clear
        chevronImage.tintColor = UIColor(named: "imageTint")
        nameLabel.textColor = UIColor(named: "imageTint")
    }
}
