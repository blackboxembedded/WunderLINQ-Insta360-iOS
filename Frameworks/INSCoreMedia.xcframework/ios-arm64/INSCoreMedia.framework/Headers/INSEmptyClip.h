//
//  INSEmptyClip.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSClip.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSEmptyClipInitType){
    INSEmptyClipInitDuration,
    INSEmptyClipInitStartEnd,
};


@class INSTimeScale;
@interface INSEmptyClip : INSClip<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initWithDurationMs:(double)durationMs;
- (instancetype) initWithStartTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs endCutDurationMs:(double)endCutDurationMs timeScales:(NSArray<INSTimeScale*>* _Nullable)timescales;

@property (nonatomic, readonly) INSEmptyClipInitType initType;
@property (nonatomic, readonly) double durationMs;
@property (nonatomic, readonly) double startTimeMs;
@property (nonatomic, readonly) double endTimeMs;
@property (nonatomic, readonly) double endCutDurationMs;
@property (nonatomic, readonly, nullable) NSArray<INSTimeScale*>* timescales;

@end

NS_ASSUME_NONNULL_END
