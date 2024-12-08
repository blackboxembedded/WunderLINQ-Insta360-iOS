//
//  INSScreenTracker.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/6/20.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"
#import "INSScreenTrackerRecorderDelegate.h"
#import "INSCoreMedia/INSStitchingInfo.h"

NS_ASSUME_NONNULL_BEGIN
@class INSScreenTracker;
@class INSDeepTrackerInfo;
@protocol INSScreenTrackerDelegate <NSObject>

- (void) tracker:(INSScreenTracker *)tracker failedWithTimestamp:(double)timestamp;

@optional
- (void) tracker:(INSScreenTracker *)tracker didReachBoundaryFov:(float)boundaryFov;

@end


typedef NS_ENUM(NSInteger, INSScreenTrackerSmoothLevel) {
    INSScreenTrackerSmoothLevelHighest = 0, //Covariance(0.5, 40.0, 1.0)
    
    INSScreenTrackerSmoothLevelMiddle = 1, //Covariance(2.0, 40.0, 1.0)
    
    INSScreenTrackerSmoothLevelLowest = 2, //Covariance(5.5, 40.0, 1.0)
    
    INSScreenTrackerSmoothLevelOff = 3, //完全关闭滤波

    INSScreenTrackerSmoothLevelDefault = INSScreenTrackerSmoothLevelHighest,
};

typedef NS_ENUM(NSInteger, INSScreenTrackerTargetFlag) {
    
    INSScreenTrackerTargetFlagUnknown = -1,
    
    INSScreenTrackerTargetFlagPerson = 0,
    
    INSScreenTrackerTargetFlagCar = 1,
    
    INSScreenTrackerTargetFlagDog = 2,
    
    INSScreenTrackerTargetFlagBall = 3,
    
    INSScreenTrackerTargetFlagPersonOrHead = 4,
    
    INSScreenTrackerTargetFlagOthers = 100,
    
    INSScreenTrackerTargetFlagDefault = INSScreenTrackerTargetFlagUnknown,
};

@interface INSScreenTrackerFovParam : NSObject<NSCoding>

@property (nonatomic) CGFloat minFov;

@property (nonatomic) CGFloat maxFov;

@property (nonatomic) CGFloat xFov;

// 目标区域与整幅画面的占比，取值 0~1，默认为 0.5
@property (nonatomic) CGFloat idealROIRatio;

// 算法需要的平滑系数，默认为1000
@property (nonatomic) CGFloat smoothCeof;

// 当前render的distance，默认为0，可不设置
@property (nonatomic) CGFloat distance;

// 当前render窗口的宽高比，默认为1，可不设置
@property (nonatomic) CGFloat screenRatio;

- (instancetype)initWithMinFov:(CGFloat)minFov maxFov:(CGFloat)maxFov xFov:(CGFloat)xFov;

- (instancetype)initWithMinFov:(CGFloat)minFov maxFov:(CGFloat)maxFov xFov:(CGFloat)xFov idealROIRatio:(CGFloat)idealROIRatio smoothCoef:(CGFloat)smoothCeof;

@end



@interface INSScreenTrackerConfiguration : NSObject

/// 必须配置，指明tracker信息，否则init会失败
@property (nonatomic) INSDeepTrackerInfo *deepTrackerInfo;

/// 必须标记，否则某人按照unknown模式来追
@property (nonatomic) INSScreenTrackerTargetFlag targetFlag;

///
@property (nonatomic, nullable) INSScreenTrackerFovParam *fovParam;

/// 追踪时，模型旋转过程中的过滤等级，等级越低，平滑效果越差，但会减轻滤波带来的延时效应，默认为highest
@property (nonatomic) INSScreenTrackerSmoothLevel smoothLevel;

/// 追踪帧间隔， 默认为1，表示每帧都进行追踪
@property (nonatomic) NSInteger frameInterval;

/// 是否优化追踪位置，默认为NO，即把识别中心移动到屏幕开始追踪的起始位置；如果开启， 当追踪目标为“person”时，则将取整个追踪域从上至下optimiseHeightRatio为中心，计算旋转时的roi中心点，即模型会下移
@property (nonatomic) BOOL optimisePosition;

/// 默认为0.15
@property (nonatomic) float optimisePositionRatio;

/// 关闭目标固定在中心，默认为NO，即追踪的目标固定在中心，适用于智能追踪； 如果目标不局限在中心，则置为YES
/// 是否固定在中心不是tracker决定的，而是调用者决定的，如果你的应用没有把追踪的目标定在中心，则置为YES
@property (nonatomic) BOOL disableCenterFocus;

/// 是否丢弃掉完成追踪的视频帧，设置为YES时，追踪后的图片无法再实时显示预览效果，默认值为NO
@property (nonatomic) BOOL discardTrackingImage;

/// 是否在追踪过程中动态调整fov，默认为NO
@property (nonatomic) BOOL disableDynamicTrackFov;


// 是否对输入的track区域进行目标提取， 默认NO， 如果在预识别时，没有识别到结果，则置为YES
//@property (nonatomic) BOOL targetExtraction;

@end


@interface INSScreenTracker : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 实例声明
 
 @param configuration 配置，需要配置追踪方法，目标类型等
 @param roiRect 初始跟踪区域
 @param trackerWidth 跟踪离屏尺寸
 @param block 跟踪区域回调
 @return 如果返回nil，表示检测器初始化失败，需要检查模型是否放在了指定路径下"INSMedia.bundle/DLResource/coreml" 或者 "INSMedia.bundle/DLResource/mnn"
 */
- (nullable instancetype) initWithConfiguration:(INSScreenTrackerConfiguration *)configuration
                                            ROI:(CGRect)roiRect
                               trackRenderWidth:(int)trackerWidth
                                          block:(void(^)(BOOL isValid, CGRect rect))block;

@property (nonatomic, readonly) INSScreenTrackerConfiguration *configuration;

/// 用于预识别到的位置，相对屏幕render view的位置
@property (nonatomic, readonly) CGRect roiRect;
/// 用于追踪的离屏渲染的宽度
@property (nonatomic, readonly) int trackerWidth;

@property (nonatomic, copy, readonly) void(^block)(BOOL, CGRect);

@property (nonatomic, weak, nullable) id<INSScreenTrackerDelegate> delegate;

@property (nonatomic, weak, nullable) id<INSScreenTrackerRecorderDelegate> recorderDelegate;

@property (nonatomic) INSObjectGeometryLevel objectGeometryLevel;


@property (nonatomic) INSStitchType stitchType;


@property (nonatomic, readonly) int trackingImageCount;

@end


NS_ASSUME_NONNULL_END
