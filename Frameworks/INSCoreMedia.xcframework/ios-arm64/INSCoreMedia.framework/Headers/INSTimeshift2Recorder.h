//
//  INSTimeshift2Recorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@class INSTrackerSequence;
@class INSTimeScale;
@class INSMediaSpeed;

typedef NS_ENUM(NSUInteger, INSTimeshift2RecommendMode) {
    INSTimeshift2RecommendModeNormal = 0,// 默认状态
    INSTimeshift2RecommendModeEasy, //当想要更多结果时，可以用这个模式
};


@interface INSTimeshiftStillRegionInfo : NSObject<NSCopying, NSMutableCopying, NSCoding>

//小于这个时间距离的两个still信息，会被合并，默认值为2000
@property (nonatomic) double minStillDistance;

//合并操作结束后，小于这个时间长度的still，将不被考虑，默认为5000
@property (nonatomic) double minStillDutation;

// 传入静止区间的time信息，上述操作不会对该原始数据有影响
@property (nonatomic, nullable) NSArray <INSTrackerSequence *> *stillSequences;

@end


@interface INSTimeshift2RecorderConfig : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double videoDurationMs;

/// 丢弃片段的最短时长，时长小于这个参数的saliency片段，将不会参与计算，单位 ms
@property (nonatomic) double dropSaliencyThresh;

/// 每帧数据的帧间隔 单位ms 默认为33
@property (nonatomic) double timelapseInterval;

/// 如果片段少且比较短的居多，可以选用easy模式，增加推荐量
@property (nonatomic) INSTimeshift2RecommendMode recommendMode;

/// 对静止区间的处理配置，如果传入nil，将不考虑still区间
@property (nonatomic, nullable) INSTimeshiftStillRegionInfo *stillRegionInfo;

@property (nonatomic, nullable) NSArray<INSMediaSpeed *> *sourceVideoTimelapseSpeeds;

@end


@interface INSTimeshift2Recorder : INSScreenRecorder

@property (nonatomic, readonly) INSTrackerSequence *directionSequence;

@property (nonatomic, readonly) NSArray <INSTrackerSequence *> *saliencySequences;

@property (nullable, nonatomic, readonly) NSArray <INSTrackerSequence *> *upviewSequences;

@property (nullable, nonatomic, readonly) NSArray <INSTrackerSequence *> *symmetricSequences;

@property (nonatomic, readonly) INSTimeshift2RecorderConfig *config;

- (nullable instancetype)initWithDirectionSequence:(INSTrackerSequence *)directionSequence
                                 saliencySequences:(NSArray <INSTrackerSequence *> *)saliencySequences
                                   upviewSequences:(nullable NSArray <INSTrackerSequence *> *)upviewSequences
                                symmetricSequences:(nullable NSArray <INSTrackerSequence *> *)symmetricSequences
                                            config:(INSTimeshift2RecorderConfig *)config;

- (nullable NSArray <INSTrackerSequence *> *)getResultSequences;

- (nullable NSArray <INSTimeScale *> *)getRecommendTimeScales;


/// 跟具config中传入的INSMediaSpeed点，获取整段的平均基础速度，我们用frameInterval表示
- (double)getAvgFrameInterval;


/// 工具方法，获取frameInterval的均值; 优先使用speedPoints，其次使用timelapseTsIntervalMs；如果传了speedPoints，将不会使用timelapseTsIntervalMs来计算.
/// @param speedPoints 文件尾读取的基础调速点，可以为nil，此时算法会使用timelapseTsIntervalMs计算frameInterval.
/// @param timelapseTsIntervalMs 相机录制时的时间间隔，如普通一倍速，这个值应该是33；基础6倍速的视频，这个值应该是200.
/// @param videoDurationMs 原素材的视频时长.
+ (double)frameAvgIntervalWithSpeedPoints:(NSArray<INSMediaSpeed *> * _Nullable)speedPoints timelapseTsIntervalMs:(double)timelapseTsIntervalMs videoDurationMs:(double)videoDurationMs;


+(double)frameIntervalWithTimelapseTsInterval:(double)timelapseTsIntervalMs DEPRECATED_MSG_ATTRIBUTE("Please use -frameAvgIntervalWithSpeedPoints:timelapseTsIntervalMs:videoDurationMs:");

@end

NS_ASSUME_NONNULL_END
