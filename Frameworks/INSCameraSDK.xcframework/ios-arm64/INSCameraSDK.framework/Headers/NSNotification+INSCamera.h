//
//  NSNotification+INSCamera.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/8/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 *  battery status update
 *  userInfo - {"battery_status": INSCameraBatteryStatus}
 */
extern NSString *const INSCameraBatteryStatusNotification;
/*!
 * box battery status update
 *  userInfo - {"battery_status": INSCameraBatteryStatus}
 */
extern NSString *const INSCameraChargeBoxBatteryStatusNotification;

/*!
 *  battery low
 *  userInfo - {"battery_status": INSCameraBatteryStatus}
 */
extern NSString *const INSCameraBatteryLowNotification;

/*!
 *  storage status update
 *  userInfo - {"card_state": INSCameraCardState, "card_location": INSStorageCardLocation}
 */
extern NSString *const INSCameraStorageStatusNotification;

/*!
 *  storage full
 */
extern NSString *const INSCameraStorageFullNotification;

/*!
 *  camera will shutdown.
 *  userInfo - {"error_code": code, "message": message string}
 */
extern NSString *const INSCameraWillShutDownNotification;

/*!
 *  firmware upgrade complete
 */
extern NSString *const INSCameraFWUpgradeDoneNotification;

/*!
 *  capture stopped
 *  userInfo - {"error_code": code, "video": INSCameraVideoInfo}
 */
extern NSString *const INSCameraCaptureStoppedNotification;

/*!
 *  capture auto split
 *  userInfo - {"video": INSCameraVideoInfo}
 */
extern NSString *const INSCameraCaptureSplitNotification;

/*!
 *  take picture state update
 *  userInfo - {"state": INSCameraTakePictureState}
 */
extern NSString *const INSCameraTakePictureStateUpdateNotification;

/*!
 *  for bluetooth, sent when the camera is connected through usb
 */
extern NSString *const INSCameraUSBConnectedNotification;

/*!
 *  for bluetooth, sent when the camera has discovered peripherals
 *  userInfo - {"peripherals": [INSCameraBTPeripheral]}
 */
extern NSString *const INSCameraDiscoverBTPeripheralsNotification;

/*!
 *  for bluetooth, sent when the camera has connected to a peripheral
 *  userInfo - {"peripheral": INSCameraBTPeripheral}
 */
extern NSString *const INSCameraConnectedToBTPeripheralNotification;

/*!
 *  for bluetooth, sent when the camera has disconnected with a peripheral
 *  userInfo - {"peripheral": INSCameraBTPeripheral}
 */
extern NSString *const INSCameraDisconnectedBTPeripheralNotification;

/*!
 *  for one x, sent when in preview and the camera capture status change, such as HDR and Bullet shooting
 *  for evo, sent when the camera capture status change or evoStatusMode change
 *  userInfo - {"status": INSCameraCaptureStatus}
 */
extern NSString *const INSCameraCurrentCaptureStatusNotification;

/*!
 *  for evo, sent when in preview and the camera capture mode change, synchronize the UI of camera and app
 */
extern NSString *const INSCameraSyncCaptureModeUpdateNotification;

/*!
 *  for evo, sent when the camera capture mode button triggered
 */
extern NSString *const INSCameraSyncCaptureButtonTriggerNotification;

/*!
 *  for one x, sent when the camera has gotten the bluetooth peripheral version
 */
extern NSString *const INSCameraBtRemoteVerUpdatedNotification;

/*!
 *  for one x bluetooth, sent before fetch wifi ssid via bluetooth
 *  userInfo - {"result": INSPhoneAuthorizationResult}
 */
extern NSString *const INSCameraAuthorizationResultNotification;

/*!
 *  for one x , sent when timelapse status update
 *  userInfo - {"timelapse_status": INSCameraTimelapseStatus}
 */
extern NSString *const INSCameraTimelapseStatusUpdateNotification;

/*!
 *  for go , sent when camera temperature reaching the limit value
 */
extern NSString *const INSCameraTemperatureStatusNotification;

/*!
 *  for go2 , sent when wifi status changed
 */
extern NSString *const INSCameraWifiStatusUpdateNotification;

/*!
 *  for go2 , sent when camera was rotated in the live broadcast
 *  userInfo = @{@"cameraPosture": @(msg.cameraPosture)};
 */
extern NSString *const INSCameraRotatedNotification;

/*!
 *  for one r , sent when exposure configs changed
 *  userInfo - {"exposure_status": INSCameraExposureStatus}
 */
extern NSString *const INSCameraExposureUpdateNotification;

/*!
 *  for one rs, sent when RTOS state changed or RTOS status check request is triggered
 *  userInfo - {"state": INSCameraRTOSState}
 */
extern NSString *const INSCameraRTOSStateNotification;
/*!
 *  for go3 Charge Box Connect Status change
 *  userInfo - {"chargeBoxStatus": INSChargeBoxStatus}
 */
extern NSString *const NSCameraCameraChargeBoxConnectStatusNotification;

/*!
 *  for FMG, send options update
 *  userInfo - {"options": INSFMGOptions, "type": INSFMGOptionsType}
 */
extern NSString *const INSCameraFMGStateChangeNotification;

/*!
 *  for go3 Firmware Upgrade Status To App
 *  userInfo - {"firmwareUpgradeStatusToapp": INSUpgradeStateOptions}
 */
extern NSString *const INSCameraFirmwareUpgradeStatusToappNotification;

/*!
 *  for Ace Update Live Stream Params
 *  userInfo - @{@"updateLiveStreamParams": INSLiveStreamParamsUpdate}
 */
extern NSString *const INSCameraUpdateLiveStreamParamsNotification;
/*!

 *  for go3
 *  userInfo = @{@"detectFaceStatus": INSDetectFace};
 */
extern NSString *const INSCameraDetectedFaceNotification;

/*!
 *  for go3
 *  userInfo = @{@"trackStatus": INSFileTrackState};
 */
extern NSString *const INSCameraDataExportStatusNotification;

/*!
 *  for go3
 *  userInfo = @{@"darkEisStatus": INSNoticDarkEisStatus};
 */
extern NSString *const INSCameraDarkEisStatusNotification;

/*!
 *  for x4 , sent when wifi mode changed
 */
extern NSString *const INSCameraWifiModeChangeNotification;

/*!
 *  for ace
 *  userInfo - {"status": INSCameraCaptureStatus}
 */
extern NSString *const INSCameraSupportTakePhotoOnRecStatusNotification;

/*!
 *  for x4 , sent when wifi scan list changed
 *  userInfo = @{@"scanWifiList": scanWifiList};
 */
extern NSString *const INSCameraWifiScanListChangedNotification;

/*!
 *  for x4 , sent when wifi status
 *  userInfo = @{@"wifiConnectionResult": wifiConnectionResult};
 */
extern NSString *const INSCameraCameraWifiStatusNotification;

/*!
 *  for x4 , sent when download file changed
 */
extern NSString *const INSCameraNeedDownloadFileNotification;

typedef NS_ENUM(NSUInteger, INSCaptureStoppedError) {
    INSCaptureStoppedErrorOverTimeLimit,
    INSCaptureStoppedErrorStorageFull,
    INSCaptureStoppedErrorOther,
    INSCaptureStoppedErrorOverFileNumberLimit,
    INSCaptureStoppedErrorLowCardSpeed,
    INSCaptureStoppedErrorMuxerStreamError,
    INSCaptureStoppedErrorDropFrames,
    INSCaptureStoppedErrorLowBattery,
};

typedef NS_ENUM(NSUInteger,  INSCameraTakePictureState) {
    INSCameraTakePictureStatePrepare,
    INSCameraTakePictureStateShutter,
    INSCameraTakePictureStateCompress,
    INSCameraTakePictureStateWriteToFile,
};

typedef NS_ENUM(NSUInteger, INSPhoneAuthorizationResult) {
    INSPhoneAuthorizationResultUnknown,
    INSPhoneAuthorizationResultSuccess,
    INSPhoneAuthorizationResultReject,
    INSPhoneAuthorizationResultTimeout,
    INSPhoneAuthorizationResultSystemBusy,
};

typedef NS_ENUM(NSUInteger, INSCameraShutdownErrorCode) {
    INSCameraShutdownErrorCodeBatteryRunout = 0,
    INSCameraShutdownErrorCodeTemperatureOverLimit,
};

typedef NS_ENUM(NSUInteger, INSCameraRTOSState) {
    INSCameraRTOSStateUnknown = 0,
    INSCameraRTOSStateNormal,
    INSCameraRTOSStateError,
};

@class INSUSBDevice;

@interface NSNotification (INSCamera)

+ (nullable instancetype)ins_notificationWithCode:(NSUInteger)code
                                      contentType:(NSInteger)contentType
                                             data:(NSData *)data;


+ (nullable instancetype)ins_notificationWithCode:(NSUInteger)code
                                      contentType:(NSInteger)contentType
                                             data:(NSData *)data
                                    extraUserInfo:(nullable NSDictionary *)extraUserInfo;

+ (nullable instancetype)ins_notificationWithCMD:(uint8_t)cmd data:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
