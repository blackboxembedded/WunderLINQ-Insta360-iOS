//
//  INSHeroFollowRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/17.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@class INSTrackerSequence;
@class INSScreenTrackerFovParam;
@interface INSHeroFollowRecorder : INSScreenRecorder

/// 初始化方法
/// @param trackerSequence json文件获取的tracker sequence
/// @param startTimeMs 序列的开始时间
/// @param endTimeMs 序列的结束时间
/// @param fovParam 动态fov的配置，如果传nil，则关闭动态fov，需要通过resetFov、resetDistance来重新设置fov distance；如果开启了动态fov，即FovParam不为nil，则reset fov distance方法失效，以动态fov的计算结果为准
- (nullable instancetype)initWithTrackerSequence:(INSTrackerSequence *)trackerSequence startTime:(double)startTimeMs endTimeMs:(double)endTimeMs fovParam:(INSScreenTrackerFovParam * _Nullable)fovParam;

@end

NS_ASSUME_NONNULL_END
