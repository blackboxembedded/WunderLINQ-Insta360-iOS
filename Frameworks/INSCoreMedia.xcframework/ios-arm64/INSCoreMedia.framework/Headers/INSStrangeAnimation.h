//
//  Header.h
//  INSCoreMedia
//
//  Created by dml on 2022/4/26.
//  Copyright © 2022 insta360. All rights reserved.
//

#import "INSAnimationRecorder.h"
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSAppletTrackerEnv;
@class INSAppletVideoInfo;
@class INSExtraGyroData;
@class INSScreenRecorder;
@class INSTimeScale;

#pragma mark - INSStrangeInfo
@interface INSStrangeInfo : NSObject<NSCoding, NSMutableCopying, NSCopying>

@property (nonatomic) float fov;
@property (nonatomic) float distance;
@property (nonatomic) float pitchOffset;

@property (nonatomic) float startTimeMs;
@property (nonatomic) float endTimeMs;

@property (nonatomic) float totalTimeMs;

@property (nonatomic) NSArray<INSScreenRecorderModel*> *recorderModels;

@end


@interface INSStrangeAnimation : NSObject <INSPlugableAnimation, NSCoding>

@property (nonatomic, strong, readonly) INSStrangeInfo *strangeInfo;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithInfo:(INSStrangeInfo*)info;

- (INSTimeScale *)getTimescale;

- (void)changePitchWithTimeStamp:(double)timeStamp quaternion:(GLKQuaternion)quat;

- (void)setFov:(float)fov distance:(float)distance;


@end

NS_ASSUME_NONNULL_END

