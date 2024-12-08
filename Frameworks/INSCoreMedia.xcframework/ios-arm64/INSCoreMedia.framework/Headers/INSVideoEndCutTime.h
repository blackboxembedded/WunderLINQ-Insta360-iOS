//
//  INSVideoEndCutTime.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/31.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSVideoEndCutTime : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype) initWithURL:(NSURL*)url exportFps:(double)fps;


/// 重新计算timescale的start time （使用在clip有尾部转场的加速上）
/// @param timeScaleStartTimeMs 转场加上的timescale   start time
/// @param timeScaleFactor 转场加上的timescale  factor
/// @param srcTimeMs 转场开始要定位到帧的时间戳
-(double)recalculateTimeScaleStartTime:(double)timeScaleStartTimeMs timeScaleFactor:(double)timeScaleFactor srcTimeMs:(double)srcTimeMs;


/// 获取clip有头部转场的start time
/// @param timeScaleFactor 当前转场加上的timescale   factor
/// @param previousEndCutDurationMs 上一个clip的转场时长
/// @param srcTimeMs 转场开始要定位到帧的时间戳
-(double)getHeadTransformClipStartTimeMs:(double)timeScaleFactor previousEndCutDurationMs:(double)previousEndCutDurationMs srcTimeMs:(double)srcTimeMs;


/// 获取clip有尾部转场的end time
/// @param timeScaleFactor 当前转场加上的timescale   factor
/// @param endCutDurationMs 当前clip的转场时长
/// @param srcTimeMs   转场开始要定位到帧的时间戳
-(double)getTailTransformClipEndTimeMs:(double)timeScaleFactor endCutDurationMs:(double)endCutDurationMs srcTimeMs:(double)srcTimeMs;

@end

NS_ASSUME_NONNULL_END
