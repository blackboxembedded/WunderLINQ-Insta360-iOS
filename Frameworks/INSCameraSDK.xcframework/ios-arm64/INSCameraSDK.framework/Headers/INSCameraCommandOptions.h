//
//  INSCameraCommandOptions.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/15/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSSubmodeOptions.h"
#import "INSCameraMediaBasic.h"
#import "INSPhotographyOptions.h"
#import "INSMultiPhotographyOptions.h"

NS_ASSUME_NONNULL_BEGIN

@class INSCameraMediaConfiguration;

@interface INSLiveStreamOptions : NSObject <NSCopying>

@property (nonatomic) BOOL enableAudio;

@property (nonatomic) BOOL enableVideo;

/// @available ONE, ONE X
@property (nonatomic) BOOL enableGyro;

@property (nonatomic) INSAudioFormat audioFormat;

@property (nonatomic) INSAudioSampleRate audioSampleRate;

@property (nonatomic) INSVideoResolution videoResolution;

@property (nonatomic, readonly) uint32_t preferredVideoBitRate;

/// @available ONE X
@property (nonatomic) INSVideoResolution videoResolution1;

@property (nonatomic, readonly) uint32_t preferredVideoBitRate1;

/// @available ONE X
@property (nonatomic) INSPreviewStreamType previewStreamType;

- (instancetype)initWithMediaSessionConfiguration:(INSCameraMediaConfiguration *)configuration;

@end

@class INSMediaGps;
@class INSMediaGyro;
@class INSMediaOrientation;
@class INSExtraInfo;

@protocol INSHDRTaskDelegate;

@interface INSTakePictureOptions : NSObject

/// @available ONE, Nano, Nano S, ONE X
@property (nonatomic, nullable) INSExtraInfo *extraInfo;

/// @available Nano, ONE X. As for One X fireware version v1.18.7.1_build1 and above, every photo's ev value depends on the array's count but not the array's element.
@property (nonatomic, nullable) NSArray *AEBEVBias;

/// When camera is connecting via USB, it is okay to process the hdr images once taken.
/// But if via BLE, this property should be set to YES.
@property (nonatomic) BOOL delayHDRProcess;

/// hdr and purshot is automatically synthesized inside the camera, x4 requires true
@property (nonatomic) BOOL inerProccess;

/// Default is NO, indicates processing the hdr images automatically using `OpenCV`. When you set this to YES, three image uri would be given and you should generate HDR yourself. @available ONE X
@property (nonatomic) BOOL generateManually;

/// @available ONE X
@property (nonatomic, weak) id<INSHDRTaskDelegate> hdrDelegate;

/// @available ONE R.
/// Photo capture mode, used to take specific types of photos. Default is photo INSPhotoModeNormal.
@property (nonatomic) INSPhotoMode mode;

/// Shot countdown. @available X3
@property (nonatomic) uint32_t countDown;

/// Indicates whether the corresponding raw file is generated when taking photos. Default is NO.
@property (nonatomic) BOOL isRawEnabled;

/// Current exposure options, used to calculate timeout.
@property (nonatomic, nullable) INSCameraExposureOptions *currenExposureOptions;

- (nonnull instancetype)initWithExtraInfo:(nullable INSExtraInfo *)extraInfo;

@end


typedef NS_ENUM(NSUInteger, INSCameraCaptureState) {
    /// @available ONE, ONE X
    INSCameraCaptureStateNotCapture = 0,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateNormalCapture = 1,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateTimelapseCapture = 2,
    
    /// @available ONE, ONE X
    INSCameraCaptureStateIntervalShootingCapture = 3,
    
    /// @available ONE X
    INSCameraCaptureStateSingleShooting = 4,
    
    /// @available ONE X
    INSCameraCaptureStateHDRShooting = 5,
    
    /// @available ONE X
    INSCameraCaptureStateSelfTimerShooting = 6,
    
    /// @available ONE X
    INSCameraCaptureStateBulletTimeCapture = 7,
    
    /// @available ONE X
    INSCameraCaptureStateSettingNewValue = 8,
    
    /// @available ONE X
    INSCameraCaptureStateHDRVideoCapture = 9,
    
    /// @available ONE X
    INSCameraCaptureStateBurstShooting = 10,
    
    /// @available GO
    INSCameraCaptureStateStaticTimelapseShooting = 11,
    
    /// @available GO
    INSCameraCaptureStateIntervalVideoCapture = 12,
    
    /// @available ONE R
    INSCameraCaptureStateTimeShiftCapture = 13,
    
    /// @available ONE R
    INSCameraCaptureStateNightscapeShooting = 14,
    
    /// @available ONE X2
    INSCameraCaptureStateNormalInstaPano = 15,
    
    /// @available ONE X2
    INSCameraCaptureStateHDRInstaPano = 16,
    
    /// @available GO2
    INSCameraCaptureStateSuperVideo = 17,
    
    /// @available ONE R
    INSCameraCaptureStateLoopRecording = 18,
    
    /// @available GO2
    INSCameraCaptureStateStarlapse = 19,
    
    /// @available ONE RS
    INSCameraCaptureStateFPV = 20,
    
    /// @available ONE RS
    INSCameraCaptureStateMovieRecording = 21,
    
    /// @available ONE RS
    INSCameraCaptureStateSlowMotion = 22,
    
    /// @available ONE X3
    INSCameraCaptureStateSelfie = 23,
    
    /// @available ACE
    INSCameraCaptureStatePure = 24,
    
    /// @available ACE
    INSCameraCaptureStatePreRecord = 25,
    
    /// @available ACE
    INSCameraCaptureStateTimeRecording = 26,
    
    /// @available ACE
    INSCameraCaptureStateTimeIntervalShooting = 27,
    
    /// @available ACE
    INSCameraCaptureStatePreRecordStop = 28,
};

typedef NS_ENUM(NSUInteger, INSCameraSyncCaptureMode) {
    /// @available EVO
    INSCameraSyncCaptureModeUnknow,
    
    /// @available EVO
    INSCameraSyncCaptureModeNormalImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeNormalVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeHDRImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeHDRVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeIntervalImage,
    
    /// @available EVO
    INSCameraSyncCaptureModeIntervalVideo,
    
    /// @available EVO
    INSCameraSyncCaptureModeBurstPhoto,
    
    /// @available EVO
    INSCameraSyncCaptureModeBulletiTime,
    
    /// @available ONE R
    INSCameraSyncCaptureModeTimeShift,
    
    /// @available ONE R
    INSCameraSyncCaptureModeNightscape,
};

/** 录像子状态 */
typedef NS_ENUM(NSUInteger, INSCameraCaptureSubmodStatus) {
    INSCameraCaptureSubmodStatusNull = 0,
    INSCameraCaptureSubmodStatusPause = 1,
    INSCameraCaptureSubmodStatusRecordSave = 2,
    INSCameraCaptureSubmodStatusPhotoSave = 3,
    INSCameraCaptureSubmodStatusStartlapseSynthesis = 4,
};

@interface INSCameraCaptureStatus : NSObject

@property (nonatomic) INSCameraCaptureState state;

/// 以s 为单位
@property (nonatomic) NSUInteger captureTime;

/// @available Go
@property (nonatomic) NSUInteger captureNum;

/// @available ONE X2
@property (nonatomic, nullable) NSString *keyTimePointDetail;

/// 录像子状态
@property (nonatomic) INSCameraCaptureSubmodStatus captureSubmode;

@end

@interface INSCameraTimelapseStatus : NSObject

@property (nonatomic) NSUInteger intervalCount;

@end

typedef NS_ENUM(NSUInteger, INSCameraWifiMode) {
    /// AP模式，iOS只能用该模式
    INSCameraWifiModeAP = 0,
    /// STA模式，固件不支持，不使用
    INSCameraWifiModeSTA = 1,
    /// 又称Direct模式，iOS不支持，Android支持；如遇到不支持的模式，可以通过setOption切换模式
    INSCameraWifiModeP2P = 2,
};

typedef NS_ENUM(NSUInteger, INSCameraWifiState) {
    INSCameraWifiStateUnknow = 0,
    INSCameraWifiStateAuto,
    INSCameraWifiStateOn,
    INSCameraWifiStateOff,
};

@interface INSCameraWifiInfo : NSObject

@property (nonatomic) NSString *ssid;

@property (nonatomic) NSString *password;

@property (nonatomic) NSUInteger channel;

@property (nonatomic) INSCameraWifiMode mode;

@property (nonatomic) INSCameraWifiState wifiState;

- (nonnull instancetype)initWithSSID:(NSString *)ssid password:(NSString *)password channel:(NSUInteger)channel mode:(INSCameraWifiMode)mode state:(INSCameraWifiState)wifiState;

@end

@interface INSCameraWifiChannelList : NSObject

@property (nonatomic) NSString *countryCode;

- (instancetype)initWithCountryCode:(NSString *)countryCode;

@end

typedef NS_ENUM(NSUInteger, INSPhoneAuthorizationState) {
    INSPhoneAuthorizationStateAuthorized,
    INSPhoneAuthorizationStateUnauthorized,
    INSPhoneAuthorizationStateSystemBusy,
};

@interface INSPhoneAuthorizationStatus : NSObject

@property (nonatomic) INSPhoneAuthorizationState state;

@end

typedef NS_ENUM(NSUInteger, INSCameraSensorType) {
    INSCameraSensorTypePano577,
    INSCameraSensorTypeWideAngle577,
    INSCameraSensorTypeWideAngle283,
};

@interface INSCameraSensor : NSObject

@property (nonatomic) NSArray <NSString *> *serials;

@property (nonatomic) NSArray <NSString *> *idArrays;

@property (nonatomic) INSCameraSensorType type;

@end

typedef NS_ENUM(uint16_t, INSCaptureMode) {
    INSCaptureModeNormal = 1,
    INSCaptureModeBulletTime = 2,
    INSCaptureModeHDR = 3,
    INSCaptureModeTimeShift = 4,
};

@interface INSCaptureOptions : NSObject

/// default is INSCaptureModeNormal.
@property (nonatomic) INSCaptureMode mode;

@property (nonatomic, nullable) INSExtraInfo *extraInfo;

- (nonnull instancetype)initWithExtraInfo:(nullable INSExtraInfo *)extraInfo;

@end

typedef NS_ENUM(uint16_t, INSCameraOptionsType) {
    /// 视频分辨率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoResolution = 1,
    
    /// 照片分辨率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypePhotoSize = 2,
    
    /// 视频码率, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoBitrate = 3,
    
    /// 音频码率, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeAudioBitrate = 4,
    
    /// 音频采样率, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeAudioSampleRate = 5,
    
    /// 初始 OFFSET, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeOriginalOffset = 6,
    
    /// 最长录像时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeCaptureTimeLimit = 7,
    
    /// 获取GPS 超时时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeGPSTimeout = 8,
    
    /// 剩余录像时间, readonly. @available Nano, ONE X
    INSCameraOptionsTypeRemainingCaptureTime = 9,
    
    /// 剩余可拍摄照片数量, readonly. @available Nano, ONE X
    INSCameraOptionsTypeRemainingPictures = 10,
    
    /// 当前电池等级, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeBatteryStatus = 11,
    
    /// 本地时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeLocalTime = 12,
    
    /// 本地时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeTimeZone = 13,
    
    /// 静音, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeMute = 14,
    
    /// 设备序列号, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeSerialNumber = 15,
    
    /// UUID, readonly. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeUUID = 16,
    
    /// 激活时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeActivateTime = 19,
    
    /// 存储状态, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeStorageState = 20,
    
    /// 镜头类型, readonly. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeLensIndex = 21,
    
    /// 相机Offset, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeMediaOffset = 22,
    
    /// 定时拍摄时间, readwrite. @available Nano, ONE, Nano S, ONE X
    INSCameraOptionsTypeSelfTimer = 23,
    
    /// 照片数据格式, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypePhotoDataFormat = 27,
    
    /// 视频Gamma 模式, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeVideoGamma = 28,
    
    /// 相机预览流时间戳, readwrite. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeMediaTime = 29,
    
    /// 固件版本, readonly. @available ONE, Nano S, ONE X
    INSCameraOptionsTypeFirmWareRevision = 30,
    
    /// 相机适配的系统, readwrite. @available ONE, ONE X
    INSCameraOptionsTypeAdoptionSystem = 31,
    
    /// 相机Wi-Fi信息,readwrite. @available ONE X
    INSCameraOptionsTypeWifiInfo = 36,
    
    /// Wi-Fi 5G支持的信道列表. @available ONE X
    INSCameraOptionsTypeWifiChannelList = 37,
    
    /// 访问相机权限的手机ID(手机的IDFV). @available ONE X
    INSCameraOptionsTypeAuthorizationId = 38,
    
    /// 标定offset. @available ONE X
    INSCameraOptionsTypeCalibrationOffset = 39,
    
	/// 拍照子模式. @available ONE X
    INSCameraOptionsTypePhotoSubMode = 40,
    
    /// 录像子模式. @available ONE X
    INSCameraOptionsTypeVideoSubMode = 41,
	
    /// 副码流分辨率. @available ONE X
    INSCameraOptionsTypeSecondStreamResolution = 42,
    
    /// wifi模块状态. @available ONE X
    INSCameraOptionsTypeWifiStatus = 43,
    
    /// 相机名称/类型, read-only. @available EVO
    INSCameraOptionsTypeCameraType = 48,
    
    /// 机内防抖开关. @available ONE R
    INSCameraOptionsTypeInternalFlowstate = 65,

    /// 视频编码格式. @available ONE R
    INSCameraOptionsTypeVideoEncode = 66,

    /// 镜头模组信息. @available ONE R
    INSCameraOptionsTypeSensor = 67,

    /// 镜头正反插信息. @available ONE R
    INSCameraOptionsTypeSelfie = 68,
    
    /// 快门时间. @available ONE R
    INSCameraOptionsTypeRollingShutterTime = 69,
    
    /// 陀螺仪时间戳. @available ONE R
    INSCameraOptionsTypeGyroTimestamp = 70,
    
    /// 视频视野. @available ONE R
    INSCameraOptionsTypeVideoFovType = 71,
    
    /// 静止视野. @available ONE R
    INSCameraOptionsTypeStillFovType = 72,
    
    /// 相机offset V2. @available ONE X2
    INSCameraOptionsTypeMediaOffsetV2 = 80,
    
    /// 相机offset V3. @available ONE X2
    INSCameraOptionsTypeMediaOffsetV3 = 81,
    
    /// 聚焦镜头, readwrite. @available ONE X2
    INSCameraOptionsTypeFocusSensor = 82,
    
    /// 期望的渲染导出方式, readwrite. @available ONE X2
    INSCameraOptionsTypeExpectOutputType = 83,
    
    /** App机外防抖预览流所需的窗口裁剪信息 */
    INSCameraOptionsTypeWindowCropInfo = 124,
    
    /** 网格线 */
    INSCameraOptionsTypeAssistiveGrid = 128,

    /** 自由比例画幅辅助线 */
    INSCameraOptionsTypeFreeframeGrid = 129,
    
    /** 暗光增稳开关 */
    INSCameraOptionsTypeDarkEisEnableGlobal = 133,
    
    /** 人脸检测开关 */
    INSCameraOptionsTypeMeteringEnableGlobal = 134,
    
    /** 机内拼接开关 */
    INSCameraOptionsTypeInternalSplicing = 135,
    
};

typedef NS_ENUM(NSUInteger, INSCameraPowerType) {
    INSCameraPowerTypeBattery = 0,
    INSCameraPowerTypeAdapter = 1,
};

typedef NS_ENUM(NSUInteger, INSCameraInfoBatteryType) {
    INSCameraInfoBatteryTypeThick = 0,
    INSCameraInfoBatteryTypeThin = 1,
    INSCameraInfoBatteryTypeVertical = 2,
    INSCameraInfoBatteryTypeNone = 100,
};

@interface INSCameraBatteryStatus : NSObject

@property (nonatomic) INSCameraPowerType powerType;

@property (nonatomic) NSInteger batteryLevel;

@property (nonatomic) NSInteger batteryScale;

@property (nonatomic) INSCameraInfoBatteryType batteryType;

@end

typedef NS_ENUM(NSUInteger, INSCameraCardState) {
    /// 正常
    INSCameraCardStateNormal = 0,
    
    /// 无卡
    INSCameraCardStateNoCard = 1,
    
    /// 卡满了
    INSCameraCardStateNoSpace = 2,
    
    /// 错误格式
    INSCameraCardStateInvalidFormat = 3,
    
    /// 写保护
    INSCameraCardStateWriteProtectCard = 4,
    
    /// 未知错误
    INSCameraCardStateUnknownError = 5,
};

@interface INSCameraStorageStatus : NSObject

@property (nonatomic) INSCameraCardState cardState;

@property (nonatomic) int64_t freeSpace;

@property (nonatomic) int64_t totalSpace;

@end

typedef NS_ENUM(NSUInteger, INSAdoptionSystem) {
    INSAdoptionSystemIos = 0,
    INSAdoptionSystemAndroid = 1,
};

typedef NS_ENUM(NSUInteger, INSCameraWifiStatus) {
    INSCameraWifiStatusAuto = 0,
    INSCameraWifiStatusOn,
    INSCameraWifiStatusOff,
};

typedef NS_ENUM(NSUInteger, INSPhotoSubMode) {
    INSPhotoSubModeSingle = 0,
    INSPhotoSubModeHdr,
    INSPhotoSubModeInterval,
    INSPhotoSubModeBurst,
    INSPhotoSubModeNightscape,
    INSPhotoSubModeInstaPano,
    INSPhotoSubModeInstaPanoHdr,
    INSPhotoSubModeStarlapse,
    INSPhotoSubModeNone = 100,
};

typedef NS_ENUM(NSUInteger, INSVideoSubMode) {
    INSVideoSubModeNormal = 0,
    INSVideoSubModeBulletTime,
    INSVideoSubModeTimelapse,
    INSVideoSubModeHDR,
    INSVideoSubModeTimeShift,
    INSVideoSubModeSuperVideo,
    INSVideoSubModeLoopRecording,
    INSVideoSubModeFPV,
    INSVideoSubModeMovieRecording,
    INSVideoSubModeSlowMotion,
    INSVideoSubModeSelfie,
    INSVideoSubModePure,
    INSVideoSubModeLiveview,
    INSVideoSubModeNone = 100,
};


typedef NS_ENUM(NSUInteger, INSCameraExpectOutputType) {
    INSCameraExpectOutputTypeDefault,
    INSCameraExpectOutputTypeInstaPano,
    INSCameraExpectOutputTypeMultiCamera,
    INSCameraExpectOutputTypeOneTake,
};

@interface INSWindowCropInfo : NSObject

@property (nonatomic) uint32_t srcWidth;

@property (nonatomic) uint32_t srcHeight;

@property (nonatomic) uint32_t dstWidth;

@property (nonatomic) uint32_t dstHeight;

/** 自拍模式偏移量 */
@property (nonatomic) int32_t cropOffsetX;

@property (nonatomic) int32_t cropOffsetY;

@end

@interface INSLiveStreamParamsUpdate : NSObject

@property (nonatomic) INSVideoEncode videoEncodeType;

@property (nonatomic) uint32_t resWidth;

@property (nonatomic) uint32_t resHeight;

@property (nonatomic) uint32_t resFps;

@property (nonatomic) BOOL flowstateBaseEnable;

@property (nonatomic) INSWindowCropInfo *windowCropInfo;

@end

@interface INSDetectFace : NSObject

@property (nonatomic) NSInteger detectFaceNum;

@end

typedef NS_ENUM(NSUInteger, INSDarkEisStatus) {
    INSDarkEisStatusDarkeisEnableShow = 0,
    INSDarkEisStatusDarkeisEnableHide = 1,
    INSDarkEisStatusDarkeisDisableShow = 2,
    INSDarkEisStatusDarkeisDisableHide = 3,
};
@interface INSNoticDarkEisStatus : NSObject

@property (nonatomic) INSDarkEisStatus darkeisStatus;

@end

typedef NS_ENUM(NSUInteger, INSSetAccessCameraFileStateAccessState) {
  INSSetAccessCameraFileStateAccessStateUnknown = 0,

  /**没在在访问文件 */
  INSSetAccessCameraFileStateAccessStateIdle = 1,
  INSSetAccessCameraFileStateAccessStateExport = 2,
  INSSetAccessCameraFileStateAccessStateDownload = 3,
  INSSetAccessCameraFileStateAccessStatePlayback = 4,
  INSSetAccessCameraFileStateAccessStateLiveView = 5,
};


@interface INSCameraOptions : NSObject

@property (nonatomic) INSVideoResolution videoResolution;

@property (nonatomic) INSPhotoSize photoSize;

@property (nonatomic) uint32_t videoBitrate;

@property (nonatomic) uint32_t audioBitrate;

@property (nonatomic) INSAudioSampleRate audioSampleRate;

@property (nonatomic) NSString *originalOffset;

@property (nonatomic) NSString *mediaOffset;

/// 以s 为单位
@property (nonatomic) uint32_t captureTimeLimit;

/// 以min 为单位
@property (nonatomic) uint32_t gpsTimeout;

/// 以min 为单位
@property (nonatomic) float remainingCaptureTime;

@property (nonatomic) uint32_t remainingPictures;

@property (nullable, nonatomic) INSCameraBatteryStatus *batteryStatus;

/// 当前时间戳
@property (nonatomic) uint64_t localTime;

/// 当前时区与GMT 相差的秒数
@property (nonatomic) NSInteger timeZoneSecondsFromGMT;

@property (nonatomic) bool mute;

/*!
 * @discussion  "INSWWYYNXXXXXX"	{ IN=Insta360, S=Sky light, WW=week, YY=year, N=reserved, XXXXXX=unique ID }
 *              MAXSIZE	(32)
 *
 */
@property (nonatomic) NSString *serialNumber;

/// size 37, "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'\0'"
@property (nonatomic) NSString *UUID;

/// 激活时间戳
@property (nonatomic) uint64_t activateTime;

/// 存储状态
@property (nullable, nonatomic) INSCameraStorageStatus *storageStatus;

@property (nonatomic) uint32_t lensIndex;

/// 3, 5, 10 seconds
@property (nonatomic) uint32_t selfTimer;

@property (nonatomic) INSPhotoDataFormat photoDataFormat;

@property (nonatomic) INSCameraGammaMode videoGamma;

@property (nonatomic) int64_t mediaTime;

@property (nullable, nonatomic) NSString *firmwareRevision;

@property (nonatomic) INSAdoptionSystem adoptionSystem;

@property (nullable, nonatomic) INSCameraWifiInfo *wifiInfo;

@property (nonatomic) INSCameraWifiChannelList *wifiChannelList;

@property (nullable, nonatomic) NSString *authorizationId;

@property (nullable, nonatomic) NSString *calibrationOffset;

@property (nullable, nonatomic) NSString *mediaOffsetV2;

@property (nullable, nonatomic) NSString *mediaOffsetV3;

@property (nonatomic) INSPhotoSubMode photoSubMode;

@property (nonatomic) INSVideoSubMode videoSubMode;

@property (nonatomic) INSVideoResolution secondStreamResolution;

@property (nonatomic) INSCameraWifiStatus wifiStatus;

/*
 *  @discussion camera name, read-only for app
 *  @available ONE X, EVO
 */
@property (nonatomic) NSString *cameraType;

/*
 *  @discussion The switch of internal flowstate.
 *  @available ONE R
 */
@property (nonatomic) BOOL enableInternalFlowstate;

/*
 *  @discussion Setting or getting the encode of video.
 *  @available ONE R
 */
@property (nonatomic) INSVideoEncode videoEncode;

/*
 *  @discussion The serial numbers of camera sensor(s)
 *  @available ONE R
 */
@property (nonatomic) INSCameraSensor *sensor;

/*
*  @discussion The orientation of camera lens.
*  @available ONE R
*/
@property (nonatomic) BOOL isSelfie;

// @available ONE R
@property (nonatomic) double rollingShutterTime;

// @available ONE R
@property (nonatomic) double gyroTimestamp;

// @available ONE R
@property (nonatomic) INSCameraFovType videoFovType;

// @available ONE R
@property (nonatomic) INSCameraFovType stillFovType;

// indicate the focus sensor when taking photo. @available ONE X2
@property (nonatomic) INSSensorDevice focusSensor;

// indicate the recommend render and output type. @available ONE X2
@property (nonatomic) INSCameraExpectOutputType expectOutputType;

/** App机外防抖预览流所需的窗口裁剪信息 */
@property(nonatomic, nullable) INSWindowCropInfo *windowCropInfo;

// 网格线
@property(nonatomic, readwrite) BOOL assistiveGridEnable;

// 自由比例画幅辅助线
@property(nonatomic, readwrite) BOOL freeframeGridEnable;
// 暗光增稳开关
@property(nonatomic, readwrite) BOOL darkEisEnableGlobal;

// 人脸优先测光开关
@property(nonatomic, readwrite) BOOL meteringEnableGlobal;

// 机内拼接开关
@property(nonatomic, readwrite) BOOL enableInternalSplicing;

@end

typedef NS_ENUM(NSUInteger, INSCameraFileType) {
    INSCameraFileTypePhoto,
};

@interface INSCameraWriteFileOptions : NSObject

/// file type of data to write
@property (nonatomic) INSCameraFileType fileType;

/// data of a file. if fileType is photo, data should be encoded in JPG format.
@property (nonatomic) NSData *data;

/// destinate path of the file in camera, if nil, camera will decide the uri with fileType.
@property (nonatomic, nullable) NSString *uri;

@end

typedef NS_ENUM(NSUInteger, INSTimelapseMode) {
    
    /// Timelapse mode for moving scenes.
    INSTimelapseModeVideo = 1,
    
    /// Timelapse mode for producing the effect of image interval shooting.
    INSTimelapseModeImage = 2,
    
    /// Timelapse mode for non-moving scenes. @available GO
    INSTimelapseModeStaticVideo = 3,
    
    /// Timelapse mode for producing the effect of video interval shooting. @available GO
    INSTimelapseModeIntervalVideo = 4,
    
    /// Startlapse mode. @available GO2
    INSTimelapseModeStarlapse = 5,
};

@interface INSTimelapseOptions : NSObject

/// 拍摄时长，以s 为单位
@property (nonatomic) NSUInteger duration;

/// 一帧时长，以ms 为单位
@property (nonatomic) NSUInteger lapseTime;

@end

@interface INSStartCaptureTimelapseOptions : NSObject

@property (nonatomic) INSTimelapseMode mode;

/// @available ONE X, and in image timelapse mode.
@property (nonatomic, nullable) INSExtraInfo *extraInfo;

/*
 *  current timelapseOptions, only be used to calculate timeout, will not be set.
 *  You should call `setTimelapseOptions:forMode:completion:` first.
 */
@property (nullable, nonatomic) INSTimelapseOptions *timelapseOptions;

- (nonnull instancetype)initWithExtraInfo:(nullable INSExtraInfo *)extraInfo mode:(INSTimelapseMode)mode;

@end;

@interface INSStopCaptureTimelapseOptions : NSObject

@property (nonatomic) INSTimelapseMode mode;

/// @available ONE X, and in video timelapse mode.
@property (nonatomic, nullable) INSExtraInfo *extraInfo;

- (nonnull instancetype)initWithExtraInfo:(nullable INSExtraInfo *)extraInfo mode:(INSTimelapseMode)mode;

@end;

typedef NS_ENUM(NSUInteger, INSCameraBTPeripheralType) {
    INSCameraBTPeripheralTypeAll = 0,
    INSCameraBTPeripheralTypeRemoteController = 1,
};

@interface INSCameraBTPeripheral : NSObject

@property (nullable, nonatomic) NSString *name;
@property (nullable, nonatomic) NSData *macAddr;

@end

@interface INSCameraCalibrateGyroOptions : NSObject

@property (nonatomic) NSUInteger gyroCount;

@end

@interface INSGetFileListOptions : NSObject

@property (nonatomic) NSUInteger start;

@property (nonatomic) NSUInteger limit;

@end

typedef NS_ENUM(NSUInteger, INSGyroRangeType) {
    INSGyroRangeTypeIndex = 0,
    INSGyroRangeTypeTimestamp = 1,
};

@interface INSGetGyroOptions: NSObject

- (instancetype)initWithRangeType:(INSGyroRangeType)rangeType range:(NSRange)range;

@property (nonatomic) INSGyroRangeType rangeType;

@property (nonatomic) NSRange range;

@end

@interface INSGetFileMndOptions : NSObject

@property (nonatomic) NSString *uri;

@property (nonatomic) INSFileMndType type;

@property (nullable, nonatomic) INSGetGyroOptions *gyroOptions;

@end

@interface INSSyncMediaTimeResult : NSObject

@property (nonatomic) NSTimeInterval localMediaTime;

@property (nonatomic) NSTimeInterval cameraMediaTime;

@property (nonatomic) NSTimeInterval accuracy;

@property (nonatomic, readonly) NSTimeInterval timeOffset;

@end

@interface INSHeartbeatsSenderOptions : NSObject

@end

typedef NS_ENUM(NSUInteger, INSDownLoadInfoStatus) {
    INSDownLoadInfoStatusUnknow = 0,
    INSDownLoadInfoStatusSuccess = 1,
    INSDownLoadInfoStatusFail = 2,
    INSDownLoadInfoStatusPause = 3,
    INSDownLoadInfoStatusDownloading = 4,
    INSDownLoadInfoStatusCancel = 5,
};


@interface INSDownLoadInfo : NSObject

@property(nonatomic, readwrite) NSUInteger totalNum;

@property(nonatomic, readwrite) NSUInteger currentNum;

@property(nonatomic, readwrite) double percentage;

@property(nonatomic, readwrite) INSDownLoadInfoStatus status;

@property(nonatomic, readwrite) NSUInteger successNum;

@end

typedef NS_ENUM(NSUInteger, INSDownloadListResultSyncAddListResult) {

    INSDownloadListResultSyncAddListResultAddListResultUnknow = 0,

  /** 全部添加到APP的下载列表中 */
    INSDownloadListResultSyncAddListResultAllSuccess = 1,

  /** 所有列表添加到APP中均失败 */
    INSDownloadListResultSyncAddListResultFail = 2,

  /** 快传列表部分添加到APP下载列表中 */
    INSDownloadListResultSyncAddListResultPartiallySuccess = 3,
};

typedef NS_ENUM(NSUInteger, INSDownloadListResultSyncDownloadError) {
  /** 无错误 */
    INSDownloadListResultSyncDownloadErrorErrNone = 0,

  /** 未知错误类型 */
    INSDownloadListResultSyncDownloadErrorErrUnknow = 1,

  /** 存储空间不足 */
    INSDownloadListResultSyncDownloadErrorErrNoSpace = 2,

  /** 不支持下载的文件类型 */
    INSDownloadListResultSyncDownloadErrorErrNotSupportFile = 3,

  /** 用户权限不足 */
    INSDownloadListResultSyncDownloadErrorErrNoPermission = 4,
};

@interface INSDownloadListResultSync : NSObject

@property(nonatomic, readwrite) INSDownloadListResultSyncAddListResult addListResult;

/** add_list_result为FAIL和PARTIALLY_SUCCESS时有效 */
@property(nonatomic, readwrite) INSDownloadListResultSyncDownloadError error;

/** 是否需要清除相机的快传列表缓存 */
@property(nonatomic, readwrite) BOOL isClearList;

@end

NS_ASSUME_NONNULL_END
