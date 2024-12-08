//
//  INSAnimationFlyOutEarth.h
//  INSCoreMedia
//
//  Created by dml on 2021/9/13.
//  Copyright © 2021 insta360. All rights reserved.
//
#import "INSAnimationRecorder.h"
#import "INSFlyOutEarthGenerator.h"


NS_ASSUME_NONNULL_BEGIN


@interface INSFlyOutEarthInfo : NSObject<NSCopying,NSMutableCopying,NSCoding>

@property (nonatomic) double startTime;
@property (nonatomic) double endTime;
@property (nonatomic) double throwTime;
@property (nonatomic) double catchTime;
@property (nonatomic) double repeatBeginTime;
@property (nonatomic) double repeatEndTime;
@property (nonatomic) NSArray<INSScreenRecorderModel*> *recorderModels;


@end


@interface INSFlyOutEarthAnimation : NSObject

@property(nonatomic) double fov;
@property(nonatomic) double distance;

- (instancetype)initWithFlyOutEarthInfo:(INSFlyOutEarthInfo*)recordInfo;

- (nullable INSAnimationRecorder *)getRecorder;

- (INSTimeScale*)getTimescale;

- (void)getThrowTime:(double*)throwTime catchTime:(double*)catchTime repeatTimeBegin:(double*)repeatTimeBegin repeatEndTime:(double*)repeatEndTime;

@end

NS_ASSUME_NONNULL_END
