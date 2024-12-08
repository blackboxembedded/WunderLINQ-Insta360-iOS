//
//  INSGyroPlayer.h
//  INSMediaSDK
//
//  Created by pengwx on 17/2/9.
//  Copyright © 2017年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"
#import "INSGyroType.h"
#import "INSExtraGyroData.h"
#import "INSGyroPlayerWrapData.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroPlayer : NSObject{
    GLKQuaternion rotate_left_;
    GLKQuaternion rotate_right_;
}

/// set it correctly
@property (nonatomic) INSGyroPlayMode gyroPlayMode;

/// must be set when you are not in INSGyroPlayModeNormal
@property (nonatomic, nullable) INSGyroStabFilterSetting *filterSetting;

@property (nonatomic) double gyroTimestampAdjust;
@property (nonatomic) double exposureTimestampAdjust;

/// 消除rolling-shutter效应的参数，与render的sweepTime属性设置相同，默认为0，必须按照精确值设置，单位:ms
@property (nonatomic) double filterSweepTime;

@property (nonatomic) double timelapseInterval;
@property (nonatomic) BOOL enableTimelapseGyroStability;

/// Must set FALSE for double-fisheye media with full-directional mode
/// Must set this property After setting 'gyroPlayMode'
/// Must set this property After setting 'filterSetting' and 'feedFilterWithParam'
/// only autoFovOn == YES  && singleLens && (gyroPlayMode ==.motionSmooth || .autoGravity ||  .absuluteHorizonRefine)，auto fov will be applied.
@property (nonatomic) BOOL autoFovOn;

@property (nonatomic, readonly) BOOL enable;
@property (nonatomic, readonly) BOOL isStart;
@property (nonatomic, readonly) double gyroDelayTime;

@property (nonatomic, readonly) BOOL opticalOn;
@property (nonatomic, readonly) INSGyroStabFilterFeedParam *feedParam;

- (void) startGyroData;
- (void) stopGyroData;
- (GLKQuaternion) getOriginOrientation:(double)timestamp;
- (GLKQuaternion) getOriginOrientation:(double)timestamp gyroPlayMode:(INSGyroPlayMode)gyroPlayMode;
- (GLKQuaternion) getFilterOrientation:(double)timestamp;

/// feed accurate video decode or encode timestamp in ms. call this after setting gyroPlayMode
/// @param frameAccurateTimestampList  video timestamp. if nil，we will feed the algorithm with a timestamp list, stepping.
/// @param trimInfo just feed the timestamps within the trimInfo scope
/// @return YES success, NO failed
- (BOOL)feedFilterWithFrameAccurateTimestampList:(NSArray <INSGyroFrameAccurateTime*> * _Nullable)frameAccurateTimestampList trimInfo:(INSGyroStabFilterTrimInfo * _Nullable)trimInfo DEPRECATED_MSG_ATTRIBUTE("Please use feedFilterWithParam:");

/// feed accurate video decode or encode timestamp in ms. call this after setting gyroPlayMode
/// @param feedParam  contains INSGyroFrameAccurateTime. if nil，we will feed the algorithm with a list, where the time is by stepping.  contains INSGyroStabFilterTrimInfo to feed the timestamps within the trimInfo scope. More over, there are some setting about optical stabilization
/// @return YES success, NO failed
- (BOOL)feedFilterWithParam:(INSGyroStabFilterFeedParam *)feedParam;

/// whether open the optical mode
/// @param opticalOn YES open, NO close
- (void)switchOpticalMode:(BOOL)opticalOn;


/// call after setting all configurations to commit to the gyrostab lib， if you don't do this, gyro player will call the commit function before we get stabilizer quaternion；
/// anytime you change some setting about gyro filter, which contains INSGyroFIlterSetting\INSGyroPlayMode\OpticalMode\feedFilterWithParam:, and you forget calling this method, gyro player will try commit inside.
- (void)filterTryCommit;

/// average exposure shutter time in ms
/// @param startTimeMs trim start in ms
/// @param endTimeMs trim end，in ms.  IF endTimeMs is 0，Then calculate the average of all exposure data
- (float)getAverageExposureTimeMsWithTrimStartTimeMs:(int64_t)startTimeMs endTimeMs:(int64_t)endTimeMs;

+ (GLKQuaternion) leftRotateOrientation:(INSRenderType)type;
+ (GLKQuaternion) rightRotateOrientation:(INSRenderType)type;

@end

NS_ASSUME_NONNULL_END
