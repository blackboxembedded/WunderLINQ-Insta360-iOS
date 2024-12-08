//
//  INSOneTakeData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "INSGyroPBPlayer.h"

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;

@interface INSOneTakeData : NSObject

@end

@interface INSOneTakeWrapConfiguration : NSObject

@property (nonatomic) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic) NSString *offset;

@property (nonatomic) BOOL visualDebug; // 只在debug时可以开启

@end

@interface INSOneTakeClipInfo : NSObject

// 通过打点获取的锚点时间，这个点按照产品的需求，应该是视频通过障碍物前、后的时间点，目前通过highlight打点数据标记
@property (nonatomic) double firstAnchorTimestamp;

@property (nonatomic) double secondAnchorTimestamp;

@end

@interface INSOneTakeVideoInfo : NSObject

// 该视频的url地址，5.7有两个url
@property (nonatomic) NSArray<NSURL *> *videoFileURLs;

// 帧率
@property (nonatomic) double frameRate;

// 媒体内存，通过videoparser可以获取，单位：字节
@property (nonatomic) int64_t mediaFileSize;

// 必须配置，通过障碍物的startTime、endTime时间对
@property (nonatomic) NSArray <INSOneTakeClipInfo *> *clipInfos;

@end

/// 算法返回的最原始结果，获取结果后，不可修改
@interface INSOneTakeResult : NSObject<NSCopying, NSMutableCopying, NSCoding>

// 算法返回的前一段clip的结束时间，要配合上一个result的secondClipTimestamp，构建project的clip时间段,
@property (nonatomic) double firstClipTimestamp;

// 算法返回的后一段clip的开始时间
@property (nonatomic) double secondClipTimestamp;

// 动画使用
@property (nonatomic) GLKQuaternion quaternion;

@end



//============================以下数据结结构在构造动画的时候使用

/// 配置给INSOnetakeAnimation的时间信息，其中一些变量来自INSOneTakeResult，可以用来计算动画时间
@interface INSOneTakeTimeParam:NSObject<NSCopying, NSMutableCopying, NSCoding>

// 直接从onetake result 中获取
@property (nonatomic) double firstClipTimestamp;

// 直接从onetake result 中获取
@property (nonatomic) double secondClipTimestamp;

// 动画使用, 直接从onetake result 中获取
@property (nonatomic) GLKQuaternion quaternion;

// 默认为750，后期可以修改
@property (nonatomic) double beforeAnimationDurationMs;

// 默认为750
@property (nonatomic) double afterAnimationDurationMs;

// 默认为150
@property (nonatomic) double endCutscneDurationMs;

// 调速scale，2倍速则这里设置 1/2
@property (nonatomic) double scale;

@end


// INSOneTakeAnimation计算获取
@interface INSOneTakeAnimationTimeScale : NSObject

@property (nonatomic) double startSrcMs;

@property (nonatomic) double endSrcMs;

@property (nonatomic) double scale;

@end

// INSOneTakeAnimation计算获取
@interface INSOneTakeAnimationClip : NSObject

@property (nonatomic) double clipStartSrcMs;

@property (nonatomic) double clipEndSrcMs;

@property (nonatomic) double endCutSceneMediaMs;

@end

@interface INSOneTakeAnimationInfo : NSObject

// 调速段信息，(2 * oneTakeTimeParams.count)
@property (nonatomic, readonly) NSArray<INSOneTakeAnimationTimeScale *> *animationTimeScales;

// clip配置信息，(oneTakeTimeParams.count + 1)
@property (nonatomic, readonly) NSArray<INSOneTakeAnimationClip *> *animationClips;

- (instancetype)init NS_UNAVAILABLE;

// 上层无需调用，可以从INSOneTakeAnimation计算获取
- (instancetype)initWithAnimationTimeScales:(NSArray<INSOneTakeAnimationTimeScale *> *)animationTimeScales animationClips:(NSArray<INSOneTakeAnimationClip *> *)animationClips;

@end



NS_ASSUME_NONNULL_END
