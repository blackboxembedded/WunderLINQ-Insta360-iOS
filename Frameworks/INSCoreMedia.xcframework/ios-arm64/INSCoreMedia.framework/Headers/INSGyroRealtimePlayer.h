//
//  INSGyroRealtimePlayer.h
//  INSMediaApp
//
//  Created by pengwx on 17/2/10.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSGyroPlayer.h"

@class INSGyroDataSource;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSGyroRealtimeRotation) {
    INSGyroRealtimeRotationNone = 0,
    INSGyroRealtimeRotationHorizontal180,
};

typedef NS_ENUM(NSInteger, INSGyroRealtimeCameraPosture) {
    INSGyroRealtimeCameraPostureUnknown      = -1,
    INSGyroRealtimeCameraPostureRotation0    = 0,
    INSGyroRealtimeCameraPostureRotation90   = 1,
    INSGyroRealtimeCameraPostureRotation180  = 2,
    INSGyroRealtimeCameraPostureRotation270  = 3,
    INSGyroRealtimeCameraPostureRotationUp   = 4,
    INSGyroRealtimeCameraPostureRotationDown = 5,
};

@interface INSGyroRealtimePlayer : INSGyroPlayer

@property (nonatomic) int64_t latestTimestamp;

@property (nonatomic) int64_t frontTimestamp;

/**
 gyro时间校正，当gyro时间滞后于视频时间时为正值，反之为负值
 */
@property (nonatomic) double gyroTimestampAdjust;

/**
 是否使用预览流曝光时间数据
 */
@property (nonatomic) BOOL enableExposure;

/**
 是否需要旋转
 */
@property (nonatomic) INSGyroRealtimeRotation rotationMode;

/**
防抖库提供的参数，平滑的角度余量，取值(0, 90), 默认为25，在非INSGyroPlayModeNormal模式下生效
*/
@property (nonatomic) double slidingWinMaxAngleLimit;

/**
 初始化

 @param dataSource 陀螺仪数据源
 @return self
 */
- (instancetype) initWithGyroDataSource:(INSGyroDataSource *)dataSource;


/**
 处理曝光时间数据

 @param exposure 曝光时间
 @param timestamp 曝光时间对应时间戳
 */
- (void) handleExposureTime:(double)exposure timestamp:(int64_t)timestamp;


@end

@interface INSGyroRealtimePlayer (Utils)


- (float)fetchRealtimeMainRotationAngle;

- (INSGyroRealtimeCameraPosture)fetchRealtimeCameraPosture;

@end

NS_ASSUME_NONNULL_END
