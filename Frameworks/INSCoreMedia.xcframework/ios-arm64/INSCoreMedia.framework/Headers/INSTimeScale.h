//
//  INSTimeScale.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/2.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSTimeScaleType){
    INSTimeScaleTypeDefaultValue,
    INSTimeScaleTypeInterpolateFinalFrame,
    INSTimeScaleTypeInterpolateFinalFrameAI,
    INSTimeScaleTypeInterpolateSourceFrame,
    INSTimeScaleTypeRepeatSingleSourceFrame,
};

@interface INSTimeScale : NSObject<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initWithFactor:(double)factor startTimeMs:(double)startTime endTimeMs:(double)endTime;
- (instancetype) initWithFactor:(double)factor startTimeMs:(double)startTime endTimeMs:(double)endTime repeatToFps:(double)repeatToFps videoKeyframeOnly:(BOOL)videoKeyframeOnly;

/**
 缩放因子
 */
@property (nonatomic) double factor;

/**
 开始时间
 单位：毫秒MS
 */
@property (nonatomic) double startTimeMs;

/**
 结束时间
 单位：毫秒MS
 */
@property (nonatomic) double endTimeMs;


///重复帧以期达到的目标帧率，默认30
@property (nonatomic)double repeatToFps;

/// 仅播放关键帧,  默认NO
@property(nonatomic)BOOL videoKeyframeOnly;

@property(nonatomic)INSTimeScaleType type;

@end

NS_ASSUME_NONNULL_END
