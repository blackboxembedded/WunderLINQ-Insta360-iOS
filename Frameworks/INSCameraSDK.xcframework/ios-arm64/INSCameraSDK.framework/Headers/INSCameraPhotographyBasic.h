//
//  INSCameraPhotographyBasic.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef INSCameraPhotographyBasic_H
#define INSCameraPhotographyBasic_H

typedef NS_ENUM(NSUInteger, INSCameraFovType) {
    INSCameraFovTypeWide = 0,
    INSCameraFovTypeLinear,
    INSCameraFovTypeUltraWide,
    INSCameraFovTypeNarrow,
    INSCameraFovTypePOV,
    INSCameraFovTypeLinearPlus,
    INSCameraFovTypeLinearHorizon,
    INSCameraFovTypeFPV,
    INSCameraFovTypeSuper,
    INSCameraFovTypeTinyplanet,
    INSCameraFovTypeInfinityWide,
    INSCameraFovTypeLinear360Horizon,
    INSCameraFovTypeLinear22Horizon,
    INSCameraFovTypeDewarp,
    INSCameraFovTypeMega
};

typedef NS_ENUM(NSUInteger, INSSensorDevice) {
    INSSensorDeviceUnknown,
    INSSensorDeviceFront,
    INSSensorDeviceRear,
    INSSensorDeviceAll,
};

typedef NS_ENUM(NSUInteger, INSCameraFunctionMode) {
    /// 普通拍照和录像 [ Deprecated ]
    INSCameraFunctionModeNormal = 0,
    
    /// 预览流
    INSCameraFunctionModeLiveStream = 1,
    
    /// Timelapse for moving scenes
    INSCameraFunctionModeTimelapse = 2,
    
    /// interval shooting
    INSCameraFunctionModeIntervalShooting = 3,
    
    /// 高帧率模式
    INSCameraFunctionModeHighFrameRate = 4,
    
    /// burst. @available ONE X
    INSCameraFunctionModeBurst = 5,
    
    /// normal image. @available ONE X
    INSCameraFunctionModeNormalImage = 6,
    
    /// normal video. @available ONE X
    INSCameraFunctionModeNormalVideo = 7,
    
    /// HDR image. @available ONE X
    INSCameraFunctionModeHdrImage = 8,
    
    /// HDR video. @available ONE X
    INSCameraFunctionModeHdrVideo = 9,
    
    /// Interval video. @available GO
    INSCameraFunctionModeIntervalVideo = 10,
    
    /// Timelapse for non-moving scenes. @available GO
    INSCameraFunctionModeStaticTimelapse = 11,
    
    /// TimeShift video. @available ONE R
    INSCameraFunctionModeTimeShift = 12,
    
    /// Nightscape image. @available ONE R
    INSCameraFunctionModeNightscape = 13,
    
    /// Insta pano image. @available ONE X2
    INSCameraFunctionModeInstaPanoImage = 14,
    
    /// Insta pano HDR image. @available ONE X2
    INSCameraFunctionModeInstaPanoHdrImage = 15,
    
    /// Super video (video without flowstate). @available GO2
    INSCameraFunctionModeSuperVideo = 16,
    
    /// Loop recording. @available ONE R
    INSCameraFunctionModeLoopRecording = 17,
    
    /// Starlapse. @available GO2
    INSCameraFunctionModeStarlapse = 18,
    
    /// FPV. @available ONE RS
    INSCameraFunctionModeFPV = 19,
    
    /// Movie recording. @available ONE RS
    INSCameraFunctionModeMovieRecording = 20,
    
    /// Slow motion. @available ONE RS
    INSCameraFunctionModeSlowMotion = 21,
    
    /// selfie. @available X3
    INSCameraFunctionModeSelfie = 22,
    
    /// GO3 QC @available Go3
    INSCameraFunctionModeQcSinglePress = 23,

    /// GO3 QC @available Go3
    INSCameraFunctionModeQcDoublePress = 24,

    /// GO3 single press @available Go3
    INSCameraFunctionModeCameraSinglePress = 25,

    /// GO3 DoublePress @available Go3
    INSCameraFunctionModeCameraDoublePress = 26,
    
    /// PureVideo @available Ace
    INSCameraFunctionModePureVideo = 27,
    
    ///IAC/DLC4 机内直播(非APP直播)
    INSCameraFunctionModeCameraLiveview = 54,
};

#endif /* INSCameraPhotographyBasic_H */
