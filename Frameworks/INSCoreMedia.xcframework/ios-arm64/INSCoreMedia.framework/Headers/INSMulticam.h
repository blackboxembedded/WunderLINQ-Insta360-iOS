//
//  INSMulticam.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/16.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSTimeRange.h"
#import "INSDisplayConfigManager.h"

NS_ASSUME_NONNULL_BEGIN


@class INSLookHerePoint;
@class INSExtraHighlightData;
@class INSGyroPlayer;
@interface INSMulticam : NSObject

+(nullable NSArray<INSLookHerePoint*>*)lookHerePointsWithExtraHighlightData:(INSExtraHighlightData*)data gyroPlayer:(INSGyroPlayer*)gyroPlayer display:(INSDisplay*)display displayValue:(INSDisplayValue*)displayValue transformDurationMs:(double)durationMs;
+(nullable NSArray<INSTimeRange*>*)timeRangesWithExtraHighlightData:(INSExtraHighlightData*)data;

+(NSArray<INSLookHerePoint*>*)lookHerePointsLens1WithGyroPlayer:(INSGyroPlayer*)gyroPlayer display:(INSDisplay*)display displayValue:(INSDisplayValue*)displayValue startTimeMs:(double)startTime endTimeMs:(double)endTime ;

+(NSArray<INSLookHerePoint*>*)lookHerePointsLens2WithGyroPlayer:(INSGyroPlayer *)gyroPlayer display:(INSDisplay *)display displayValue:(INSDisplayValue *)displayValue startTimeMs:(double)startTime endTimeMs:(double)endTime;

+(NSArray<INSLookHerePoint*>*)lookHerePointsLens1WithGyroPlayer:(INSGyroPlayer*)gyroPlayer display:(INSDisplay*)display displayValue:(INSDisplayValue*)displayValue startTimeMs:(double)startTime endTimeMs:(double)endTime timestep:(double)timestep;

+(NSArray<INSLookHerePoint*>*)lookHerePointsLens2WithGyroPlayer:(INSGyroPlayer *)gyroPlayer display:(INSDisplay *)display displayValue:(INSDisplayValue *)displayValue startTimeMs:(double)startTime endTimeMs:(double)endTime timestep:(double)timestep;

@end

NS_ASSUME_NONNULL_END
