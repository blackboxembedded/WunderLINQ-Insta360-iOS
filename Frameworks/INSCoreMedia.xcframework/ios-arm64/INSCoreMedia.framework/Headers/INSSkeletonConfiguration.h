//
//  INSSkeletonConfiguration.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/9.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;
@class INSRender;
@class INSProjectionInfo;
@class INSScreenTrackerFovParam;

typedef NS_ENUM(NSUInteger, INSSkeletonCheckRule) {
    INSSkeletonCheckRuleStopMotion1 = 1,
    INSSkeletonCheckRuleStopMotion2 = 2,
};

@interface INSSkeletonConfiguration : NSObject

@property (nonatomic) NSString *skeletonSavePath;

@property (nonatomic) double durationMs;

/// 是否在追踪过程中，每500帧检测一次可用性，默认为YES， 只用于stopmotion； 甩干跳 \ 站姿 算法需要设置为NO
@property (nonatomic) BOOL checkValidDuringTrack;

/// checkValidDuringTrack为YES时生效，以stopmotion1.0的规则check，还是stopmotion2.0的规则check， 默认按照1.0
@property (nonatomic) INSSkeletonCheckRule checkValidRule;

@property (nonatomic) BOOL visualDebug;

@end

/// 骨骼识别的前置条件;可能是全景，可能是广角，且不确定当前视角，所以要把当前render的信息传进来，去做离屏渲染（这里要验证，用当前信息，配置的离屏渲染与主屏幕是否相同）
@interface INSSkeletonExtraConfig : NSObject

@property (nonatomic, readonly) CGRect roi;

@property (nonatomic, readonly) int trackerWidth;

@property (nonatomic, readonly) NSString *offset;

@property (nonatomic, readonly) INSRenderType renderType;

@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic, readonly) INSProjectionInfo *projectionInfo;

@property (nonatomic, readonly) INSScreenTrackerFovParam *fovParam;

/// 当前render 的宽度 ，注意并不是renderview的尺寸
@property (nonatomic, readonly) int renderWidth;

/// render 的高度
@property (nonatomic, readonly) int renderHeight;

/// 屏幕尺寸
@property (nonatomic, readonly) CGFloat screenScale;


/// 分别设置属性，推荐使用这种方法，前提是你能都正确拿到信息，且清楚每个属性的含义
- (instancetype) initWithOffset:(NSString *)offset
                     renderType:(INSRenderType)renderType
                     gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                 projectionInfo:(INSProjectionInfo *)projectionInfo
                       fovParam:(INSScreenTrackerFovParam *)fovParam
                    renderWidth:(int)renderWidth
                   renderHeight:(int)renderHeight
                    screenScale:(CGFloat)screenScale roi:(CGRect)roi trackerWidth:(int)trackerWidth;

/// 传入当前render，会生成属性列表中的数据
- (instancetype) initWithRender:(INSRender *)render fovParam:(INSScreenTrackerFovParam *)fovParam roi:(CGRect)roi trackerWidth:(int)trackerWidth;

@end


@interface INSSkeletonPair : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double timestamp;

@property (nonatomic) GLKQuaternion quat;

/// fov 只有在INSSkeletonRecommendInfoVersionV2才生效
@property (nonatomic) float xFov;

///distance 只有在 INSSkeletonRecommendInfoVersionV2
@property (nonatomic) float distance;

/// skeleton track过程中的全身box，经过归一化
@property (nonatomic) CGRect rect;

/// skeleton track过程中的头部box，经过归一化
@property (nonatomic) CGRect headRect;

- (instancetype)initWithTimestamp:(double)timestamp quat:(GLKQuaternion)quat xFov:(float)xFov distance:(float)distance rect:(CGRect)rect;
- (instancetype)initWithTimestamp:(double)timestamp quat:(GLKQuaternion)quat xFov:(float)xFov distance:(float)distance rect:(CGRect)rect headRect:(CGRect)headRect;
@end


typedef NS_ENUM(NSUInteger, INSSkeletonRecommendInfoVersion) {
    // 骨骼数据做了版本控制，version1版本的skeleton pair 中fov distance均为无效值
    INSSkeletonRecommendInfoVersion1 = 1,
    // version2版本的skeleton pair中fov， distance可以使用
    INSSkeletonRecommendInfoVersion2 = 2,
};

/// 骨骼推荐信息
@class INSScreenRecorder;
@interface INSSkeletonRecommendInfo : NSObject

@property (nonatomic, readonly) INSSkeletonRecommendInfoVersion version;

@property (nonatomic, readonly) double firstPairTimestamp;

@property (nonatomic, readonly) double lastPairTimestamp;

@property (nonatomic, readonly) NSArray <INSSkeletonPair *> *skeletonPairs;

@property (nullable, nonatomic, readonly) NSArray<NSString *> *sourceVideoPath;

- (instancetype)initWithVersion:(INSSkeletonRecommendInfoVersion)version
                  skeletonPairs:(NSArray <INSSkeletonPair *> *)skeletonPairs
                sourceVideoPath:(NSArray<NSString *> * _Nullable)sourceVideoPath;

/// 生成recorder数据，以当前skeletonPairs的时间戳为时间戳
- (nullable INSScreenRecorder *)screenRecorderWithXFov:(float)fov distance:(float)distance;

/// 生成recorder数据，按照传入的URL计算该视频的解码时间戳序列
+ (nullable INSScreenRecorder *)screenRecorderWithVideoUrl:(NSURL *)videoUrl
                                             skeletonPairs:(NSArray <INSSkeletonPair *> *)skeletonPairs
                                                       fov:(float)fov
                                                  distance:(float)distance;

@end


/// 已经分析过的骨骼视频信息
@interface INSSkeletoVideoInfo : NSObject

// 视频url，5.7K有两个文件
@property (nonatomic) NSArray <NSString *> *videoPath;

// 由INSSkeletonTracker 获取的skeleton data 路径
@property (nonatomic) NSString *skeletonDataPath;


@end


NS_ASSUME_NONNULL_END
