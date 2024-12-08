//
//  INSGaitDetector.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 步态分析结果
 */
typedef NS_ENUM(NSInteger, INSGyroStabilizerGaitType) {
    INSGyroStabilizerGaitTypeStill = 1 << 0,
    INSGyroStabilizerGaitTypeWalking = 1 << 1,
    INSGyroStabilizerGaitTypeRunning = 1 << 2,
    INSGyroStabilizerGaitTypeDriving = 1 << 3,
    INSGyroStabilizerGaitTypeRunningWalking = INSGyroStabilizerGaitTypeWalking | INSGyroStabilizerGaitTypeRunning,
    INSGyroStabilizerGaitTypeUnknown = 1 << 8
};

@interface INSGaitStateMotion : NSObject

/// 改类的实例有INSGyroPBPlayer生成
- (instancetype)init NS_UNAVAILABLE;

/**
 某个时间点下的步态判断

 @param timestamp 时间戳，单位ms
 @return 步态
 */
- (INSGyroStabilizerGaitType)detectGaitTypeAtTimestamp:(double)timestamp;


/**
 这个视频的步态定性

 @return 步态
 */
- (INSGyroStabilizerGaitType)detectVideoGaitType;

@end

NS_ASSUME_NONNULL_END
