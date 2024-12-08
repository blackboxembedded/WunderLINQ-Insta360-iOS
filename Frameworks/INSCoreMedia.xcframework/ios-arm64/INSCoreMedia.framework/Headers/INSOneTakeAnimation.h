//
//  INSOneTakeAnimation.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class INSOneTakeTimeParam;
@class INSProjectionInfo;
@class INSTrackerSequence;
@class INSOneTakeAnimationInfo;
@class INSGyroPBPlayer;

typedef NS_ENUM(NSUInteger, INSOneTakeCameraMainDirection) {
    INSOneTakeCameraMainDirectionTop = 0,
    INSOneTakeCameraMainDirectionLeft,
    INSOneTakeCameraMainDirectionRight,
    INSOneTakeCameraMainDirectionBottom
};

@interface INSOneTakeAnimation : NSObject<NSCoding, NSCopying, NSMutableCopying>

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithOnetakeTimeParams:(NSArray <INSOneTakeTimeParam *> * _Nullable)timeParams
                                     gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                                frameTimestamps:(NSArray <NSNumber *> *)frameTimestamps
srcDurationMs:(double)srcDurationMs DEPRECATED_MSG_ATTRIBUTE("Please use another init function");;

- (nullable instancetype)initWithOnetakeTimeParams:(NSArray <INSOneTakeTimeParam *> * _Nullable)timeParams
                                     gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                                frameTimestamps:(NSArray <NSNumber *> *)frameTimestamps
                                  srcDurationMs:(double)srcDurationMs
                            cameraMainDirection:(INSOneTakeCameraMainDirection)cameraMainDirection
                                cameraPreRoll:(double)cameraPreRoll;

/// 上层调用获取配置fileclip的信息
/// @param trimStartSrcMs 写0即可
/// @param trimEndSrcMs 写video duration ms即可
/// @return 用来配置FileClip信息，一定会返回对象，但内部的值可能为空
- (INSOneTakeAnimationInfo *)getAnimationInfoTrimStartSrcMs:(double)trimStartSrcMs
                                               trimEndSrcMs:(double)trimEndSrcMs;

// 上层无需调用，recorder使用
- (nullable INSProjectionInfo *)getProjectionInfo:(double)timestamp;

@end

NS_ASSUME_NONNULL_END
