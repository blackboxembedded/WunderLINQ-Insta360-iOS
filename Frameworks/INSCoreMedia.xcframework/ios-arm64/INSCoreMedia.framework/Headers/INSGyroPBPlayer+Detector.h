//
//  INSGyroPBPlayer+Detector.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/14.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSGyroPBPlayer.h"
#import "INSBulletTimeMotion.h"
#import "INSCameraFlipMotion.h"
#import "INSBulletTimePeriod.h"
#import "INSGaitStateMotion.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroPBPlayer (Detector)

#if !CONFIG_SDK
/// 构造INSBulletTimeMotion，用来计算一圈bullet时间
- (nullable INSBulletTimeMotion *)detectorBulletTimeMotion;

/// 获取bullet time时间段的检测器
- (nullable INSBulletTimePeriod *)detectorBulletTimePeriod;

/// 获取指定翻转状态的时间
- (nullable INSCameraFlipMotion *)detectorCameraFlipMotion;

/// 步态识别
- (nullable INSGaitStateMotion *)detectorStabilizerGait;

#endif

@end

NS_ASSUME_NONNULL_END
