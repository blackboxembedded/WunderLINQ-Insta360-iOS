//
//  INSPhotographyOptions.h
//  INSCameraSDK
//
//  Created by zeng bin on 6/1/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <CoreMedia/CoreMedia.h>
#endif
#import "INSCameraMediaBasic.h"
#import "INSCameraPhotographyBasic.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSPhotoDataFormat) {
    INSPhotoDataFormatNormal = 0,
    INSPhotoDataFormatRaw = 1,
};

typedef NS_ENUM(NSUInteger, INSPhotoMode) {
    INSPhotoModeNormal = 0,
    INSPhotoModeAeb = 1,
    INSPhotoModeBurst = 3,
    INSPhotoModeAebNight = 4,
};

typedef NS_ENUM(NSUInteger, INSCameraGammaMode) {
    INSCameraGammaModeLinear = 0,
    INSCameraGammaModeLog = 1,
    INSCameraGammaModeVivid = 2,
    INSCameraGammaModeFlat = 3,
    INSCameraGammaModeUrban1 = 4,
    INSCameraGammaModeUrban2 = 5,
    INSCameraGammaModeOceanblue1 = 6,
    INSCameraGammaModeOceanblue2 = 7,
    INSCameraGammaModeSnow1 = 8,
    INSCameraGammaModeSnow2 = 9,
    INSCameraGammaModeBiking1 = 10,
    INSCameraGammaModeBiking2 = 11,
    INSCameraGammaModeNightlight1 = 12,
    INSCameraGammaModeNightlight2 = 13,
};

extern const NSTimeInterval INSLongExposureMinShutterSpeed;

extern const NSInteger INSExposureBiasAuto;

typedef NS_ENUM(uint16_t, INSPhotographyOptionsType) {
    INSPhotographyOptionsTypePhotographyOptionUnknown = 0,
    
    /// VIN Channel, readwrite. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeChannel = 1,
    
    /// 亮度, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeBrightness = 2,
    
    /// 对比度, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeContrast = 3,
    
    /// 饱和度, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeSaturation  = 4,
    
    /// 色调, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeHUE = 5,
    
    /// 锐度, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeSharpness = 6,
    
    /// 曝光补偿, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeExposureBias = 7,
    
    /// 测光， readwrite. @available ONE, NANO, ONE X
    INSPhotographyOptionsTypeAEMeterMode = 11,
    
    /// 手动测光权值, readwrite. @available ONE, Nano, ONE X
    INSPhotographyOptionsTypeAEManualMeterWeights = 12,
    
    /// 白平衡, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeWhiteBalance = 13,
    
    /// 防闪烁电流频率值, readwrite. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeFlicker = 14,
    
    /// 测光数据, readonly. @available ONE, Nano, Nano S, ONE X
    INSPhotographyOptionsTypeEVIndex = 15,
    
    /// 自动曝光模式下拍摄视频使用的参数, readonly. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeAutoModeVideoParam = 16,
    
    /// 自动曝光模式下拍照使用的参数, readonly. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeAutoModeStillParam = 17,
    
    /// 视频的Gamma correction 模式, readwrite. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeVideoGamma = 18,
    
    /// 图像的拍照参数, readwrite. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeStillExposureOptions = 20,
    
    /// 视频的拍照参数, readwrite. @available ONE, Nano S, ONE X
    INSPhotographyOptionsTypeVideoExposureOptions = 21,
    
    /// 3D降噪开关, readwrite. @available ONE(v1.16.9.1)
    INSPhotographyOptionsTypeMCTF = 22,
    
    /// 运动模式开关, readwrite. @available ONE(v1.16.9.1)
    INSPhotographyOptionsTypeSportMode = 23,
    
    /// 录像自动曝光ISO上限, readwrite. @available ONE X
    INSPhotographyOptionsTypeISOTopLimit = 24,
    
    /// 存储RAW文件开关/类型, readwrite. @available ONE X
    INSPhotographyOptionsTypeRawCaptureType = 25,
    
    /// 子模式拍摄倒计时, readwrite. @available ONE X
    INSPhotographyOptionsTypePhotographySelfTimer = 26,
    
    /// 当前拍摄HDR的的张数, readwrite. @available ONE X(v1.18.7.1_build1)
    INSPhotographyOptionsTypeAEBCaptureNumber = 27,
    
    /// 运动模式level, readwrite. @available ONE X(v1.18.8.1_build1)
    INSPhotographyOptionsTypeSportLevel = 28,
    
    /// 单次录像时长, readwrite. @available Go
    INSPhotographyOptionsTypeRecordDuration = 29,
    
    /// 照片比例, readwrite. @available ONE R
    INSPhotographyOptionsTypePhotoSizeID = 30,
    
    /// 特定模式录像分辨率, readwrite. @available ONE R
    INSPhotographyOptionsTypeVideoResolution = 31,
    
    /// 特定模式录像码率, readwrite. @available ONE R
    INSPhotographyOptionsTypeVideoBitrate = 32,
    
    /// 视野模式, readwrite. @available ONE R
    INSPhotographyOptionsTypeFovType = 33,
    
    /// 机内防抖开关, readwrite. @available ONE R
    INSPhotographyOptionsTypeInternalFlowstate = 34,
    
    /// 图像参数字段色彩模式, readwrite. @available ONE R
    INSPhotographyOptionsTypeColorMode = 35,
    
    /// 每个分辨率对应的录像限时, readwrite. @available GO2
    INSPhotographyOptionsTypeResolutionRecordLimited = 36,
    
    /// Timeshift视频加速倍数(移动延时). 1x、6x. @available ONE R (v1.2.47)
    INSPhotographyOptionsTypeAccelerateFequency = 37,
    
    /// 预览流变焦数值. @available ONE RS
    INSPhotographyOptionsTypeFocalLengthValue = 38,
    
    /// 白平衡(数值), readwrite. @available ONE RS
    INSPhotographyOptionsTypeWhiteBalanceValue = 39,
    
    /// 照片分辨率, readwrite. @available ONE RS
    INSPhotographyOptionsTypePhotoSize = 40,
    
    /// 剩余录像时长
    INSPhotographyOptionsTypeRemainingTime = 41,
    
    /// 暗光增稳开关
    INSPhotographyOptionsTypeDarkEnable = 42,
    
    /// Flow等级
    INSPhotographyOptionsTypeFlowstateLevel = 43,
    
    /// Burst连拍张数
    INSPhotographyOptionsTypeBurstCaptureNum = 44,
    
    /// Burst预拍张数
    INSPhotographyOptionsTypeCacheCaptureNum = 45,
    
    /// 人脸检测开关
    INSPhotographyOptionsTypeMeteringEnable = 46,
    
    /// Burst连拍时间，单位：秒
    INSPhotographyOptionsTypeBurstCaptureTime = 51,
    
    /// Burst预拍开关
    INSPhotographyOptionsTypeCacheCaptureEnable = 52,
    
    /// Zoom缩放倍数
    INSPhotographyOptionsTypeZoomScale = 53,
    
    /// 最大录制时长
    INSPhotographyOptionsTypeMaxRecTime = 54,
    
    /// CV5防抖等级
    INSPhotographyOptionsTypeFlowstateLevelByCv5 = 55,
    
    /// 星空合成模式
    INSPhotographyOptionsTypeStarlapseExportType = 56,
    
    /// timeshift 常速开关
    INSPhotographyOptionsTypeTimeshiftNormalSpeed = 57,
    
    /// 成片机内防抖开关
    INSPhotographyOptionsTypeVideoFlowstateBaseType = 58,

    /// 双击zoom
    INSPhotographyOptionsTypeDoubleZoom = 59,
    
    /// 全景曝光模式
    INSPhotographyOptionsTypePanoExposureMode = 61,
    
    /// 跟拍模式
    INSPhotographyOptionsTypeVideoSelfieMode = 62,
    
    /// HDR开关状态
    INSPhotographyOptionsTypeHdrSwitchStatus = 63,
    
    /// 自适应码率设置
    INSPhotographyOptionsTypeLiveRtmpEnableAutoBitrate = 64,

    /// 用户自定义视频码率
    INSPhotographyOptionsTypeLiveRtmpPreferVideoBitrate = 65,

    /// 用户自定义音频码率
    INSPhotographyOptionsTypeLiveRtmpPreferAudioBitrate = 66,

    /// 视频编码格式
    INSPhotographyOptionsTypeLiveRtmpVideoEncoder = 67,

    /// 音频编码格式
    INSPhotographyOptionsTypeLiveRtmpAudioEncoder = 68,

    /// 直播平台
    INSPhotographyOptionsTypeLiveRtmpPlantform = 69,
};

@interface INSCameraExposureParameter : NSObject

@property (nonatomic) NSUInteger iso;

#if TARGET_OS_IOS
@property (nonatomic) CMTime shutterSpeed;
#endif

@end

typedef NS_ENUM(uint16_t, INSCameraWhiteBalance) {
    INSCameraWhiteBalanceAutomatic = 0,
    
    /// Inscandescent
    INSCameraWhiteBalanceColorTemp2700K,
    
    /// Sunny.   ONE X Fluorescent
    INSCameraWhiteBalanceColorTemp4000K,
    
    /// Cloudy.  ONE X Sunny
    INSCameraWhiteBalanceColorTemp5000K,
    
    /// Fluorescent. ONE X Cloudy
    INSCameraWhiteBalanceColorTemp6500K,
    
    /// Outdoor.
    INSCameraWhiteBalanceColorTemp7500K = 5,
};

typedef NS_ENUM(uint16_t, INSCameraFlicker) {
    INSCameraFlickerAuto = 0,
    INSCameraFlickerF60Hz,
    INSCameraFlickerF50Hz,
};

typedef NS_ENUM(uint16_t, INSCameraAEMeterMode) {
    INSCameraAEMeterModeNormal = 0,
    INSCameraAEMeterModeManual,
};

typedef NS_ENUM(uint16_t, INSCameraCalibrationVignetteType) {
    INSCameraCalibrationVignetteTypeRelative = 0,
    INSCameraCalibrationVignetteTypeGradient1,
    INSCameraCalibrationVignetteTypeGradient2,
};

typedef NS_ENUM(NSUInteger, INSCameraExposureProgram) {
    INSCameraExposureProgramAuto = 0,
    INSCameraExposureProgramISOPriority = 1,
    INSCameraExposureProgramShutterPriority = 2,
    INSCameraExposureProgramManual = 3,
    INSCameraExposureProgramAdaptive = 4,
    INSCameraExposureProgramFullAuto = 5,
};

typedef NS_ENUM(NSUInteger, INSCameraRawCaptureType) {
    INSCameraRawCaptureTypeOFF,
    INSCameraRawCaptureTypeDNG,
    INSCameraRawCaptureTypeRAW, //not support yet
    INSCameraRawCaptureTypePureshot,
    INSCameraRawCaptureTypePureshotRaw,
    INSCameraRawCaptureTypeINSP,
    INSCameraRawCaptureTypeINSPRAW,
};

typedef NS_ENUM(NSUInteger, INSCameraSportLevel) {
    INSCameraSportLevelAuto = 0,
    INSCameraSportLevelFast,
    INSCameraSportLevelFaster,
};

DEPRECATED_MSG_ATTRIBUTE("use 'INSCameraGammaMode' instead")
typedef NS_ENUM(NSUInteger, INSCameraColorMode) {
    INSCameraColorModeNormal = 0,
    INSCameraColorModeLOG,
    INSCameraColorModeVivid,
    INSCameraColorModeHDR,
};

typedef NS_ENUM(NSUInteger, INSFlowStateLevel) {
    INSFlowStateLevelClose = 0,
    INSFlowStateLevelLow,
    INSFlowStateLevelStandard,
    INSFlowStateLevelHigh,
};

typedef NS_ENUM(NSUInteger, INSFlowStateLevelByCv5) {
    INSFlowStateLevelCV5Close = 0,
    INSFlowStateLevelCv5Slight,
    INSFlowStateLevelCv5General,
    INSFlowStateLevelCv5Strong,
};

typedef NS_ENUM(NSUInteger, INSStarlapseExportType) {
    INSStarlapseExportTypeStarlapseVideo = 0,
    INSStarlapseExportTypeStarTrailsVideo,
    INSStarlapseExportTypeStarTrailsPhoto,
};

typedef NS_ENUM(NSUInteger, INSPanoExposureModeType) {
    /** 关闭 */
    INSPanoExposureModeTypeOff = 0,
    /** 轻度曝光 */
    INSPanoExposureModeTypeLight,
    /** 独立曝光 */
    INSPanoExposureModeTypeLsolated,
};

typedef NS_ENUM(NSUInteger, INSVideoSelfieMode) {
    /** 关闭 */
    INSVideoSelfieModeNone = 0,
    /** 跟拍模式（视角向后） */
    INSVideoSelfieModeMe,
    /** 手电模式（视角向前） */
    INSVideoSelfieModeTorch,
};

typedef NS_ENUM(NSUInteger, INSPhotographyOptionsBoolTypeSecure) {
    INSPhotographyOptionsBoolTypeSecureUnknown = 0,
    INSPhotographyOptionsBoolTypeSecureDisable = 1,
    INSPhotographyOptionsBoolTypeSecureEnable = 2,
};

typedef NS_ENUM(NSUInteger, INSPhotographyOptionsVideoEncoderType) {
    INSPhotographyOptionsVideoEncoderTypeDefault = 0,
    INSPhotographyOptionsVideoEncoderTypeH264 = 1,
    INSPhotographyOptionsVideoEncoderTypeH265 = 2,
};

typedef NS_ENUM(NSUInteger, INSPhotographyOptionsAudioEncoderType) {
    INSPhotographyOptionsAudioEncoderTypeDefault = 0,
    INSPhotographyOptionsAudioEncoderTypeAcc = 1,
};

typedef NS_ENUM(NSUInteger, INSPhotographyOptionsPlantformType) {
    INSPhotographyOptionsPlantformTypeDefault = 0,
    INSPhotographyOptionsPlantformTypeFacebook = 1,
    INSPhotographyOptionsPlantformTypeWechat = 2,
    INSPhotographyOptionsPlantformTypeWeibo = 3,
    INSPhotographyOptionsPlantformTypeGoogleStreetView = 4,
    INSPhotographyOptionsPlantformTypeQzone = 5,
    INSPhotographyOptionsPlantformTypeYoutube = 6,
    INSPhotographyOptionsPlantformTypeKakaotalk = 7,
    INSPhotographyOptionsPlantformTypeTwitter = 8,
    INSPhotographyOptionsPlantformTypeQq = 9,
    INSPhotographyOptionsPlantformTypeVeer = 10,
    INSPhotographyOptionsPlantformTypeKuaishou = 11,
    INSPhotographyOptionsPlantformTypeDouyin = 12,
    INSPhotographyOptionsPlantformTypeBilibili = 13,
    INSPhotographyOptionsPlantformTypeDouyu = 14,
    INSPhotographyOptionsPlantformTypeHuya = 15,
    INSPhotographyOptionsPlantformTypeNone = 16,
};

@interface INSCameraExposureOptions : NSObject

@property (nonatomic) INSCameraExposureProgram program;

@property (nonatomic) NSUInteger iso;

#if TARGET_OS_IOS
@property (nonatomic) CMTime shutterSpeed;
#endif

@end

@interface INSCameraExposureStatus : NSObject

@property (nonatomic) INSCameraFunctionMode mode;

/*!
 * the exposure mode and parameters for taking picture. default is INSCameraExposureProgramAuto
 */
@property (nullable, nonatomic) INSCameraExposureOptions *stillExposure;

/*!
 * the exposure program and parameters for the video capture or live stream. default is INSCameraExposureProgramAuto
 * Only INSCameraExposureProgramAuto and INSCameraExposureProgramManual are supported.
 * when program is INSCameraExposureProgramManual, the shutter speed should not be larger than 1.0/framerate
 */
@property (nullable, nonatomic) INSCameraExposureOptions *videoExposure;

- (instancetype)initWithStillExposure:(INSCameraExposureOptions *)stillExposure
                        videoExposure:(INSCameraExposureOptions *)videoExposure;

@end

@interface INSCameraCalibrationWhiteBalanceGain : NSObject

@property (nonatomic)  uint32_t calibration_save;

/// sensor0 red gain
@property (nonatomic) int32_t gain_r0;

/// sensor0 blue gain
@property (nonatomic) int32_t gain_b0;

/// sensor1 red gain
@property (nonatomic) int32_t gain_r1;

/// sensor1 blue gain
@property (nonatomic) int32_t gain_b1;

@end

@interface INSCameraCalibrationVignetteLuma : NSObject

@property (nonatomic) uint32_t calibration_save;
@property (nonatomic) INSCameraCalibrationVignetteType type;

// sensor0 luma
@property (nonatomic) int32_t luma0;

// sensor1 luma
@property (nonatomic) int32_t luma1;

@end

@interface INSCameraCalibrationVignetteGain : NSObject

@property (nonatomic) uint32_t calibration_save;
@property (nonatomic) INSCameraCalibrationVignetteType type;

// sensor0 red
@property (nonatomic) int32_t r0;

// sensor0 green
@property (nonatomic) int32_t g0;

// sensor0 blue
@property (nonatomic) int32_t b0;

// sensor1 red
@property (nonatomic) int32_t r1;

// sensor1 green
@property (nonatomic) int32_t g1;

// sensor1 blue
@property (nonatomic) int32_t b1;

@end

typedef struct INSAEMeterManualWeights {
    uint8_t weights[96];
} INSAEMeterManualWeights;

@interface INSRecordLimit : NSObject

@property (nonatomic) INSVideoResolution resolution;

@property (nonatomic) uint32_t timeLimit;

@end

@interface INSPhotographyOptions : NSObject

/// -256 ~ 256, default 0
@property (nonatomic) uint32_t channel;

/// -256 ~ 256, default 0
@property (nonatomic) int32_t brightness;

/// 0 ~ 256, default 64
@property (nonatomic) uint32_t contrast;

/// 0 ~ 256, default 64
@property (nonatomic) uint32_t saturation;

/// -15 ~ 15, default 0
@property (nonatomic) int32_t hue;

/// 0 ~ 6, default 3
@property (nonatomic) uint32_t sharpness;

/*!
 *  -8.0EV ~ +8.0EV.
 *  By setting INSExposureBiasAuto, the camera can automatically set exposure parameters according to the situation.
 */
@property (nonatomic) float exposureBias;

/// default is INSCameraWhiteBalanceAutomatic
@property (nonatomic) INSCameraWhiteBalance whiteBalance;

/// default is INSCameraFlickerAuto
@property (nonatomic) INSCameraFlicker flicker;

@property (nonatomic) uint32_t evIndex;

/// default is INSCameraAEMeterModeNormal
@property (nonatomic) INSCameraAEMeterMode aeMeterMode;

/// value 0 ~ 5, col 12, row 8, size = col * row
@property (nonatomic, assign) INSAEMeterManualWeights aeMeterManualWeights;

@property (nonatomic) BOOL enableCalibrationWhiteBalance;

@property (nonatomic) BOOL enableCalibrationVignette;

@property (nullable, nonatomic) INSCameraCalibrationWhiteBalanceGain *calibrationWhiteBalanceGain;

@property (nullable, nonatomic) INSCameraCalibrationVignetteLuma *calibrationVignetteLuma;

@property (nullable, nonatomic) INSCameraCalibrationVignetteGain *calibrationVignetteGain;

/// the current still parameters that the camera is using if it is in auto program
@property (nullable, nonatomic) INSCameraExposureParameter *autoModeVideoParam;

/// the current video parameters that the camera is using if it is in auto program
@property (nullable, nonatomic) INSCameraExposureParameter *autoModeStillParam;

/// log or linear
@property (nonatomic) INSCameraGammaMode videoGamma;

/*!
 * the exposure mode and parameters for taking picture. default is INSCameraExposureProgramAuto
 */
@property (nullable, nonatomic) INSCameraExposureOptions *stillExposure;

/*!
 * the exposure program and parameters for the video capture or live stream. default is INSCameraExposureProgramAuto
 * Only INSCameraExposureProgramAuto and INSCameraExposureProgramManual are supported.
 * when program is INSCameraExposureProgramManual, the shutter speed should not be larger than 1.0/framerate
 */
@property (nullable, nonatomic) INSCameraExposureOptions *videoExposure;

@property (nonatomic) BOOL enableMCTF;

@property (nonatomic) BOOL enableSportMode;

@property (nonatomic) uint32_t videoISOTopLimit;

@property (nonatomic) INSCameraRawCaptureType rawCaptureType;

@property (nonatomic) uint32_t photographySelfTimer;

@property (nonatomic) uint32_t aebCaptureNumber;

@property (nonatomic) INSCameraSportLevel sportLevel;

@property (nonatomic) uint32_t recordDuration;

/**
 * Photo scale
 * ONE R:    283(FishEye/WideAngle) - {0:3x2, 1:16x9}, 577(FishEye/WideAngle) - {0:4x3, 1:16x9}, 586(FishEye/WideAngle) - {0:4x3, 1:16x9}
 * ONE X2:   (FishEye/WideAngle) - {0:16x9, 1:1x1, 2:9x16}
 * GO2:      {0:16x9, 1:1x1, 2:9x16, 3:2.7x1}
 */
@property (nonatomic) uint32_t photoSizeId;

@property (nonatomic) INSVideoResolution videoResolution;

@property (nonatomic) uint32_t videoBitrate;

@property (nonatomic) INSCameraFovType fovType;

/*
 *  @discussion The switch of internal flowstate.
 *  @available ONE R
 */
@property (nonatomic) BOOL enableInternalFlowstate;

@property (nonatomic) NSArray<INSRecordLimit *> *recordLimits;

/// Timeshift视频加速倍数(移动延时). 1x、6x. @available ONE R (v1.2.47)
@property (nonatomic) uint32_t accelerateFequency;

/// 预览流缩放数值. (0 ~ 10)
@property (nonatomic) float focalLengthValue;

@property (nonatomic) uint32_t whiteBalanceValue;

@property (nonatomic) INSPhotoSize photoSize;
// 剩余录像时长(单位s)/拍照张数
@property (nonatomic) uint32_t remainingTime;
//暗光增稳开关
@property (nonatomic) BOOL darkEnable;
// 测光模式开关
@property (nonatomic) BOOL meteringEnable;
// 防抖等级
@property (nonatomic) INSFlowStateLevel flowStateLevel;
/// Burst连拍张数
@property(nonatomic) uint32_t burstCaptureNum;

/// Burst预拍张数
@property(nonatomic) uint32_t cacheCaptureNum;

/// Burst连拍时间，单位：秒
@property(nonatomic) uint32_t burstCaptureTime;

/// Burst预拍开关
@property(nonatomic) BOOL cacheCaptureEnable;

/// Zoom缩放倍数
@property(nonatomic) double zoomScale;

/** 最大录制时长 */
@property(nonatomic) uint32_t maxRecTime;

/** CV5防抖等级 */
@property(nonatomic) INSFlowStateLevelByCv5 flowStateLevelByCv5;

/** 星空导出模式 */
@property(nonatomic)INSStarlapseExportType starlapseExportType;

/** 成片机内防抖开关 */
@property(nonatomic) BOOL videoFlowstateBaseEnable;

/** timeshift 常速开关 */
@property(nonatomic) BOOL timeshiftNormalSpeed;

/** 双击zoom */
@property(nonatomic) BOOL doubleZoomEnable;

/** 全景曝光模式 */
@property(nonatomic) INSPanoExposureModeType panoExposureMode;

/** 跟拍模式 */
@property(nonatomic) INSVideoSelfieMode selfieMode;
/** HDR开关状态 */
@property(nonatomic) BOOL hdrSwitchStatus;

@property(nonatomic) INSPhotographyOptionsBoolTypeSecure liveRtmpAutoBitrate;

@property(nonatomic) uint32_t livePreferVideoBitrate;

@property(nonatomic) uint32_t livePreferAudioBitrate;

@property(nonatomic) INSPhotographyOptionsVideoEncoderType liveVideoEncoder;

@property(nonatomic) INSPhotographyOptionsAudioEncoderType liveAudioEncoder;

@property(nonatomic) INSPhotographyOptionsPlantformType livePlantform;

@end

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface INSPhotographyOptions (Deprecated)

// Deprecated, use 'videoGamma' instead
@property (nonatomic) INSCameraColorMode colorMode DEPRECATED_MSG_ATTRIBUTE("use 'videoGamma' instead");

@end
#pragma clang diagnostic pop

NS_ASSUME_NONNULL_END
