//
//  INSExtraMetadata.h
//  INSCoreMedia
//
//  Created by zeng bin on 5/2/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSMediaGps.h"
#import "INSMediaGyro.h"
#import "INSMediaOrientation.h"
#import "INSMediaEuler.h"
#import "INSMediaCropWindow.h"
//#import "INSFilter.h"
#import "INSFilterType.h"
#import "INSGyroType.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef INSTA360_CAMERA_NAMES
#define INSTA360_CAMERA_NAMES

/// name of insta360 Nano
extern NSString *const kInsta360CameraNameNano;

/// name of insta360 ONE
extern NSString *const kInsta360CameraNameOne;

/// name of insta360 Nano S
extern NSString *const kInsta360CameraNameNanoS;

/// name of insta360 One2(OneX)
extern NSString *const kInsta360CameraNameOne2;

/// name of insta360 EVO
extern NSString *const kInsta360CameraNameEVO;

/// name of insta360 Wearable/Go
extern NSString *const kInsta360CameraNameGo;

/// name of insta360 Akiko/OneR
extern NSString *const kInsta360CameraNameOneR;

/// name of insta360 OneX2
extern NSString *const kInsta360CameraNameOneX2;

/// name of insta360 OneH
extern NSString *const kInsta360CameraNameOneH;

/// name of insta360 Go 2
extern NSString *const kInsta360CameraNameGo2;

/// name of insta360 OneRS
extern NSString *const kInsta360CameraNameOneRS;

/// name of Invisible Drone 360 Camera (Sphere)
extern NSString *const kInsta360CameraNameSphere;

/// name of insta360 X3
extern NSString *const kInsta360CameraNameX3;

#endif
/// name of insta360 Lite
extern NSString *const kInsta360CameraNameLite;


typedef NS_ENUM(NSUInteger, INSPhotoHDRState) {
    INSPhotoHDRStateNotHDR = 0,
    INSPhotoHDRStateNeedProcess = 1,
    INSPhotoHDRStateProcessed = 2,
};

typedef NS_ENUM(NSUInteger, INSTriggerSource) {
    INSTriggerSourceUnknown = 0,
    INSTriggerSourceCameraButton = 1,
    INSTriggerSourceRemoteControl = 2,
    INSTriggerSourceUSB = 3,
    INSTriggerSourceBtRemote = 4,
};

typedef NS_ENUM(NSUInteger, INSExtraLogoType) {
    INSExtraLogoTypeUnknown = 0,
    INSExtraLogoTypeNoLogo = 1,
    INSExtraLogoTypeInstaLogo = 2,
};

typedef NS_ENUM(NSUInteger, INSSubMediaType) {
    INSSubMediaTypeVideoNormal = 0,
    INSSubMediaTypeVideoBulletTime = 1,
    INSSubMediaTypeVideoTimelapse = 2,
    INSSubMediaTypePhotoNormal = 3,
    INSSubMediaTypePhotoHdr = 4,
    INSSubMediaTypePhotoIntervalShooting = 5,
    INSSubMediaTypeVideoHdr = 6,
    INSSubMediaTypePhotoBurst = 7,
    INSSubMediaTypeVideoStaticTimelapse = 8,
    INSSubMediaTypeVideoTimeshift = 9,
    INSSubMediaTypePhotoAebNightMode = 10,
    INSSubMediaTypeVideoSuperNormal = 11,
    INSSubMediaTypeVideoLooprecording = 12,
    INSSubMediaTypePhotoStarlapse = 13,
    INSSubMediaTypePhotoPanoMode = 14,
    INSSubMediaTypeVideoFpv = 15,
    INSSubMediaTypeVideoMovie = 16,
    INSSubMediaTypeVideoSlowMotion = 17,
    INSSubMediaTypeVideoSelfie = 18,//是一种特殊的视频格式，并不意味着是反插视频
};

typedef NS_ENUM(NSUInteger, INSOffsetConvertState) {
    INSOffsetConvertStateWaterProof = 0,
    INSOffsetConvertStateDivingWater,
    INSOffsetConvertStateDivingAir,
    INSOffsetConvertStateStitchOptimization,
    INSOffsetConvertStateProtect,// 保护壳, one r新增
    INSOffsetConvertStateSphereProtect,
    INSOffsetConvertStateFpvProtect,
};

typedef NS_ENUM(NSUInteger, INS3DCameraEVOMode) {
    INS3DCameraEVOModeUnknown = 0,
    INS3DCameraEVOModeDegree180,
    INS3DCameraEVOModeDegree360,
};

typedef NS_ENUM(NSUInteger, INSGPSSource) {
    INSGPSSourceGSV = 0,
    INSGPSSourceDashboard,
    INSGPSSourceRemote,
};

typedef NS_ENUM(NSUInteger, INSCameraBatteryType) {
    INSCameraBatteryTypeThick = 0,  // 薄电池
    INSCameraBatteryTypeThin = 1, // 厚电池
    INSCameraBatteryTypeVertical = 2, // 竖拍电池
};

typedef NS_ENUM(NSUInteger, INSCameraPosture) {
    INSCameraPosture0 = 0,
    INSCameraPosture90 = 1,
    INSCameraPosture180 = 2,
    INSCameraPosture270 = 3,
};

typedef NS_ENUM(NSUInteger, INSImageFovType) {
    INSImageFovTypeUnknown = 0,
    INSImageFovTypeWide = 1,
    INSImageFovTypeLinear = 2,
    INSImageFovTypeUltrawide = 3,
    INSImageFovTypeNarrow = 4,
    INSImageFovTypePov = 5,
    INSImageFovTypeLinearPlus = 6,
    INSImageFovTypeLinearHorizontal = 7,
    INSImageFovTypeFpv = 8,
    INSImageFovTypeSuper = 9,
    INSImageFovTypeTinyPlanet = 10,
    INSImageFovTypeMaxView = 11,
    INSImageFovTypeNum = 12,
};

typedef NS_ENUM(NSUInteger, INSFWGyroStabMode) {
    INSFWGyroStabModeUnknown = 0,
    INSFWGyroStabModeBrute = 1,
    INSFWGyroStabModeAkf = 2,
};

typedef NS_ENUM(NSUInteger, INSSensorDeviceType) {
    INSSensorDeviceTypeUnknown = 0,
    INSSensorDeviceTypeFront = 1,
    INSSensorDeviceTypeRear = 2,
    INSSensorDeviceTypeAll = 3,
};

typedef NS_ENUM(NSUInteger, INSExpectOutputType) {
    INSExpectOutputTypeDefault = 0,
    INSExpectOutputTypeInstaPano = 1,
    INSExpectOutputTypeMultiCamera = 2,
    INSExpectOutputTypeOneTake = 3,
};

typedef NS_ENUM(NSUInteger, INSAudioModeType) {
    INSAudioModeTypeUnknown = 0,
    INSAudioModeTypeFocus = 1,
    INSAudioModeTypeStereo = 2,
    INSAudioModeTypeCircle360 = 3,
    INSAudioModeTypeRsStere0 = 4,
    INSAudioModeTypeExtmicdev = 5,
    INSAudioModeTypeAirpoddev = 6,
    INSAudioModeTypeReserve1 = 7,
    INSAudioModeTypeReserve2 = 8,
};

typedef NS_ENUM(NSUInteger, INSRawCaptureType) {
    INSRawCaptureTypeOff = 0,
    INSRawCaptureTypeDNG = 1,
    INSRawCaptureTypeRAW = 2,
    INSRawCaptureTypePureshot = 3,
};

typedef NS_ENUM(NSUInteger, INSVideoPtsMapType) {
    //default case, should use decoder with fisrt frame timestamp
    INSVideoPtsMapTypeUnknown = 0,
    //decoder with fisrt-frame-timestamp
    INSVideoPtsMapTypeDecoderWithFFT = 1,
    //reading in exposure data, finding with the decode-time\frame-index as well
    INSVideoPtsMapTypeReadingInExposureFile = 2,
};

typedef NS_ENUM(NSUInteger, INSLens283MType) {
    INSLens283MTypeUnknown = 0,
    INSLens283MTypeLowTransparency = 1,
    INSLens283MTypeHighTransparency = 2,
};

@interface INSDynamicGyroAccRangeInfo : NSObject

@property (nonatomic) double accelerometerRange;

@property (nonatomic) double gyrovelocitymeterRange;

@end

@interface INSExtraMetadata : NSObject

/**
 *  version
 */
@property (nonatomic) NSInteger version;

/**
 *  v1，offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *offset;

/**
 *  v1，原始的offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *originalOffset;

/**
 *  v2，offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *offsetV2;

/**
 *  v2，原始的offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *originalOffsetV2;

/**
 *  v3，offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *offsetV3;

/**
 *  v3，原始的offset参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *originalOffsetV3;

/**
 *  serialNumber参数，可以为nil
 */
@property (nullable, nonatomic, copy) NSString *serialNumber;

/**
 *  gps参数，可以为nil
 */
@property (nullable, nonatomic) INSMediaGps *gps;

/**
 *  gyro参数， 可以为nil，所有数据应为标准坐标系下的数据（Nano 正常使用时为标准）
 */
@property (nullable, nonatomic) INSMediaGyro *gyro;


/**
 * 文件中携带的一组陀螺仪裸数据，是未经任何旋转转换的gyro（后面的版本会删除）
 */
@property (nullable, nonatomic) NSData *mediaGyroData;

/**
 *  orientation参数， 可以为nil
 */
@property (nullable, nonatomic) INSMediaOrientation *orientation;

/**
 *  滤镜，无滤镜时返回 INSFilterTypeNull
 */
@property (nonatomic) INSFilterType filterType;

/**
 *  滤镜比例，如果滤镜是lut表实现，该值记录滤镜效果所占的比重，0.0f~1.0f,如果不是lut文件生成的滤镜，或者未被修改过，默认值为-1.0
 */
@property (nonatomic) CGFloat filterScale;

/**
 *  美颜滤镜，无滤镜时返回 INSFilterTypeNull
 */
@property (nonatomic) INSFilterType beautifyFilterType;

/**
 *  新版调色滤镜, 多个滤镜用 "\n" 进行分隔，格式为 "filter1_parameter1\nfilter2_parameter2"
 */
@property (nullable, nonatomic) NSString *adjustFilters;

/**
 *  lut 调色, 默认返回 INSFilterTypeNull, 无滤镜时返回INSFilterType3DLutOff
 */
@property (nonatomic) INSFilterType lutFilterType;

/**
 欧拉角，可以为nil
 */
@property (nullable, nonatomic) INSMediaEuler *euler;


/**
 去除紫边
 */
@property (nonatomic) BOOL removePurple;


/**
 陀螺仪防抖类型
 */
@property (nonatomic) INSGyroPlayMode gyroPlayMode;

/**
 *  创建时间, GMT时间
 */
@property (nullable, nonatomic, strong) NSDate *createDate;

/**
 *  文件的导出时间, GMT时间
 */
@property (nullable, nonatomic, strong) NSDate *exportTime;

/// 相机类型
@property (nullable, nonatomic, copy) NSString *cameraType;

/// 固件版本
@property (nullable, nonatomic, copy) NSString *fwVersion;

/// 文件类型, insp、insv文件默认无，导出jpg、mp4文件值为"stitch", 依此判断文件类型
@property (nullable, nonatomic, copy) NSString *fileType;

/// ip
@property (nullable, nonatomic, copy) NSString *ip;

/// 文件大小
@property (nonatomic) uint64_t fileSize;

/// 时长, 照片为0
@property (nonatomic) uint32_t totalTime;

/// 是否为HDR 照片，且是否已经拼接
@property (nonatomic) INSPhotoHDRState hdrState;

/// 如果hdrState 为INSPhotoHDRStateNeedProcess，则需根据hdrIdentifier 来区分不同组合的照片
@property (nullable, nonatomic) NSString *hdrIdentifier;

/// 触发来源，相机按键、USB、远程遥控器等
@property (nonatomic) INSTriggerSource triggerSource;

/// 图像的尺寸
@property (nonatomic) CGSize dimension;

/// 视频帧率, 照片应该设置为0. (e.g. 30, 60, 120)
@property (nonatomic) NSInteger frameRate;

/// 后得到图像与原始图像的偏移 (如120 fps 的视频，为 (0, 24))
@property (nonatomic) CGPoint imageTranslate;

/// "linear", "log"，如果为空，认定为"linear"
@property (nullable, nonatomic) NSString *gammaMode;

@property (nonatomic) int32_t thumbnailGyroIndex;

@property (nonatomic) int64_t thumbnailGyroTimestamp;

@property (nonatomic) INSExtraLogoType logoType;

/// 第一帧对应的相机系统时间，单位 ms
@property (nonatomic) double firstFrameTimestamp;

// 对应分辨率rolling shutter时间
@property (nonatomic) double rollingShutterTime;

//file group info
@property (nonatomic) INSSubMediaType fileGroupSubMediaType;

//file group info
@property (nonatomic) uint32_t fileGroupSubMediaIndex;

//file group info
@property (nonatomic) uint32_t fileGroupSubMediaTotal;

//file group info 
@property (nullable, nonatomic) NSString *fileGroupSubMediaIdentify;

// crop window
@property (nullable, nonatomic) INSMediaCropWindow *cropWindow;

// 对应分辨率的gyro timestamp
@property (nonatomic) double gyroTimestampAdjust;

// 是否支持gyro timestamp
@property (nonatomic) BOOL hasGyroTimestampAdjust;

// indicate which type the current `offset` is converted from. see INSOffsetConvertState, 仅对v1版本的offset有效
@property (nullable, nonatomic) NSMutableSet<NSNumber *> *offsetConvertStates;

// timelapse 文件每帧的拍摄间隔, 单位:秒
@property (nonatomic) double timelapseInterval;

// 陀螺仪矫正数据，上层无需关心，故使用裸数据类型，添加至此是为了防止文件尾写回到文件时这部分数据丢失
@property (nullable, nonatomic) NSData *gyroCalib;

// 3D相机折叠状态, 非3D相机为unknown
@property (nonatomic) INS3DCameraEVOMode evoStatusMode;

// 3d相机折叠状态ID，用时间戳表示:YYYYMM HHMMSS
@property (nullable, nonatomic) NSString *evoStatusId;

// 3d相机平铺状态下的初始offset
@property (nullable, nonatomic) NSString *originalOffset3D;

// gps数据来源，可为多个. 见INSGPSSource
@property (nullable, nonatomic) NSMutableSet<NSNumber *> *gpsSources;

// 第一帧视频对应的UTC时间戳，表示的是世界时间，可以用来定位GPS数据位置
@property (nonatomic) double firstGpsTimestamp;

// orientationCalib参数, 可以为nil, go才有
@property (nullable, nonatomic) INSMediaOrientation *orientationCalib;

// 文件是否在app收藏夹 go才有
@property (nonatomic) BOOL isCollected;

/**
 *  文件回收日期, GMT时间, go才有
 */
@property (nullable, nonatomic, strong) NSDate *recycleDate;

// 视频文件总帧数, go才有
@property (nonatomic) uint32_t frameNumber;

// 屏幕与镜头朝相同的方向, 该值为true; 反之为false
@property (nonatomic) BOOL lensSelfies;

// 是否机内防抖 YES:是  NO:否. One R 才有
@property (nonatomic) BOOL isFlowstateOnline;

// 在做机内防抖时，是否进行了畸变矫正
@property (nonatomic) BOOL isDewarp;

// 分辨率的尺寸，该尺寸并不是文件的真实尺寸，而是用户最终通过渲染或者导出时宽高信息. 如，在用户设置16:9时，实际上生成文件的demension(4000,3000)，此时该变量则为(3840,2160). OneR才有
@property (nonatomic) CGSize resolutionSize;

// 577鱼眼需要知道电池类型: 厚电池、薄电池、竖拍电池. One R 才有
@property (nonatomic) INSCameraBatteryType batteryType;

// 相机的姿态，旋转量. One R 才有
@property (nonatomic) INSCameraPosture cameraPosture;

// 图像视角类型，视频与图片文件都存在. One R才有
@property (nonatomic) INSImageFovType fovType;

// 固件调延迟时间使用的防抖模式
@property (nonatomic) INSFWGyroStabMode fwGyroStabMode;

// One X2才有
@property (nonatomic) INSSensorDeviceType sensorDevice;

// One X2才有
@property (nonatomic) INSExpectOutputType expectedOutput;

// 标记文件尾中PB文件记录的timelapse interval 时间戳单位是否为ms，为了解决历史遗留问题
@property (nonatomic) BOOL timelapseIntervalInMillisecond;

// repeated float photo_rot = 60;    // 保存拍照时刻照片的旋转量，用于本机回放使用

// AudioModeType = 61
@property (nonatomic) INSAudioModeType audioMode;

///是否为2khz陀螺仪数据
@property (nonatomic) BOOL isRawGyro;

/// raw模式拍摄的子格式
@property (nonatomic) INSRawCaptureType rawCaptureType;

/// 推荐使用的不同时间戳映射机制，可能需要在解码时间戳与获取防抖矩阵的时间戳做一次映射。当（videoPtsMapType == .readingInExposureFile）
@property (nonatomic) INSVideoPtsMapType videoPtsMapType;

/// 加速度计与角速度计的量程信息
@property (nonatomic, nullable) INSDynamicGyroAccRangeInfo *dynamicGyroAccRange;

@property (nonatomic) INSLens283MType lens283MType1;

@property (nonatomic) INSLens283MType lens283MType2;

@end

NS_ASSUME_NONNULL_END
