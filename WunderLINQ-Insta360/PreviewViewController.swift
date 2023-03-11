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
import INSCameraSDK

class PreviewViewController: UIViewController, INSCameraPreviewPlayerDelegate {
    @IBOutlet weak var previewView: UIView!
    
    var peripheral: Peripheral?
    
    var child = SpinnerViewController()
    
    private var mediaSession = INSCameraMediaSession()
    private var previewPlayer: INSCameraPreviewPlayer?
    private var storageState: INSCameraStorageStatus?
    private var videoEncode: INSVideoEncode = .H264

    
    override func viewDidLoad() {
        super.viewDidLoad()

        let swipeRight = UISwipeGestureRecognizer(target: self, action: #selector(handleGesture))
        swipeRight.direction = .right
        self.view.addGestureRecognizer(swipeRight)
        
        self.child = SpinnerViewController()
        addChild(child)
        child.view.frame = view.frame
        
        INSCameraManager.socket().addObserver(self, forKeyPath: "cameraState", options: .new, context: nil)
        setupRenderView()
        
        // Keep screen unlocked
        UIApplication.shared.isIdleTimerDisabled = true
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let currentCamera = INSCameraManager.shared().currentCamera {
            fetchOptions {
                self.updateConfiguration()
                self.runMediaSession()
            }
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
    }
    
    override var keyCommands: [UIKeyCommand]? {
        let commands = [
            UIKeyCommand(input: UIKeyCommand.inputLeftArrow, modifierFlags:[], action: #selector(leftKey)),
            UIKeyCommand(input: UIKeyCommand.inputEscape, modifierFlags:[], action: #selector(escapeKey))
        ]
        if #available(iOS 15, *) {
            commands.forEach { $0.wantsPriorityOverSystemBehavior = true }
        }
        return commands
    }
    
    @objc func leftKey() {
        self.dismiss(animated: true, completion: nil)
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
    
    @objc func handleGesture(gesture: UISwipeGestureRecognizer) -> Void {
        if gesture.direction == UISwipeGestureRecognizer.Direction.right {
            leftKey()
        }
    }
    
    deinit {
        mediaSession.stopRunning(completion: { error in
                print("stop media session with err: \(error?.localizedDescription ?? "")")
            })
        //INSCameraManager.socket().removeObserver(self, forKeyPath: "cameraState")
        }

    func updateConfiguration() {
        mediaSession.expectedVideoResolution = INSVideoResolution.init(width: 1920, height: 960, fps: 30)
        mediaSession.expectedVideoResolutionSecondary = INSVideoResolution.init(width: 960, height: 480, fps: 30)
        mediaSession.previewStreamType = .secondary
        mediaSession.expectedAudioSampleRate = .rate48000Hz
        mediaSession.videoStreamEncode = .H264
        mediaSession.gyroPlayMode = .default
    }
    
    func setupRenderView() {
        let height = view.bounds.height
        let frame = CGRect(x: 0, y: view.bounds.height - height, width: view.bounds.width, height: height)
        previewPlayer = INSCameraPreviewPlayer(frame: frame, renderType: .sphericalPanoRender)
        previewPlayer?.play(withGyroTimestampAdjust: 30)
        previewPlayer?.delegate = self
        if let renderView = previewPlayer?.renderView {
            view.addSubview(renderView)
        }
        mediaSession.plug(previewPlayer!)
            
        if let offset = INSCameraManager.shared().currentCamera!.settings?.mediaOffset {
            let rawValue = INSLensOffset(offset: offset).lensType
            if rawValue == INSLensType.oneR577Wide.rawValue || rawValue == INSLensType.oneR283Wide.rawValue {
                    previewPlayer?.renderView.enablePanGesture = false
                    previewPlayer?.renderView.enablePinchGesture = false
                    previewPlayer?.renderView.render.camera!.xFov = 37
                    previewPlayer?.renderView.render.camera!.distance = 700
                }
            }
        }
        
        func fetchOptions(completion: (() -> Void)?) {
            weak var weakSelf = self
            let optionTypes: [NSNumber] = [NSNumber(value: INSCameraOptionsType.storageState.rawValue), NSNumber(value: INSCameraOptionsType.videoEncode.rawValue)]
            INSCameraManager.shared().commandManager.getOptionsWithTypes(optionTypes) { (error, options, successTypes) in
                guard let options = options else {
                    completion?()
                    return
                }
                weakSelf?.storageState = options.storageStatus
                weakSelf?.videoEncode = options.videoEncode
                completion?()
            }
        }

        
        func runMediaSession() {
            guard INSCameraManager.shared().cameraState == .connected else {
                return
            }
            if mediaSession.running {
                view.isUserInteractionEnabled = false
                mediaSession.commitChanges { [weak self] error in
                    print("commitChanges media session with error: \(error?.localizedDescription ?? "nil")")
                    self?.view.isUserInteractionEnabled = true
                }
            } else {
                view.isUserInteractionEnabled = false
                mediaSession.startRunning { [weak self] error in
                    print("start running media session with error: \(error?.localizedDescription ?? "nil")")
                    self?.view.isUserInteractionEnabled = true
                }
            }
        }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        if keyPath == "cameraState" {
            if let state = change?[.newKey] as? INSCameraState {
                switch state {
                case .found:
                    break
                case .connected:
                    runMediaSession()
                default:
                    mediaSession.stopRunning(completion: nil)
                }
            }
        }
    }

    func offset(toPlay player: INSCameraPreviewPlayer) -> String? {
        guard let mediaOffset = INSCameraManager.shared().currentCamera?.settings?.mediaOffset else { return nil }
        
        if (INSCameraManager.shared().currentCamera?.name == kInsta360CameraNameOneX
            || INSCameraManager.shared().currentCamera?.name == kInsta360CameraNameOneR
            || INSCameraManager.shared().currentCamera?.name == kInsta360CameraNameOneX2)
            && INSLensOffset.isValidOffset(mediaOffset) {
            return INSOffsetCalculator.convertOffset(mediaOffset, to: INSOffsetConvertType.oneX3040_2_2880)
        }
        
        return mediaOffset
    }
}
