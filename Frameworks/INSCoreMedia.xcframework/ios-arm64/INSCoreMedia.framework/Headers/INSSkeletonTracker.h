//
//  INSSkeletonTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/5.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSSkeletonConfiguration.h"

NS_ASSUME_NONNULL_BEGIN


@class INSSkeletonTracker;
@protocol INSSkeletonTrackerDelegate<NSObject>

/// called when skeleton tracker failed , must finish and should stop input frame
- (void)skeleton:(INSSkeletonTracker *)skeleton failedWithTimestamp:(int64_t)timestamp;

@end


@interface INSSkeletonTracker : NSObject

@property (nonatomic, readonly) INSSkeletonConfiguration *config;

@property (nonatomic, readonly) INSSkeletonExtraConfig *extraConfig;

@property (nonatomic, readonly, weak) id<INSSkeletonTrackerDelegate> delegate;


- (instancetype)init NS_UNAVAILABLE;

/// 初始化之前，把待跟踪目标转到视野中心
/// @param config 基础配置
/// @param extraConfig 追踪的一些配置
/// @param delegate delegate
- (nullable instancetype)initWithConfig:(INSSkeletonConfiguration *)config extraConfig:(INSSkeletonExtraConfig *)extraConfig delegate:(id<INSSkeletonTrackerDelegate>)delegate;
                             
/// 追踪一帧，传入双鱼眼帧
/// @param pixelBuffer 左帧
/// @param rightPixelBuffer 右帧，5.7k文件才有
/// @param timestampMs 当前帧的时间戳
/// @return NO说明追踪失败，需要把分析停掉，可以通过recover重新开始追踪
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;

/// recover追踪状态，通过extraConfig把当前render的一些视角状态和目标状态
/// 在保留当前已经的追踪数据的情况下，继续调用analyze送帧追踪
/// @param extraConfig 开始追踪时的render信息与追踪的目标信息
/// @return 如果返回NO 则无法恢复，需要检查参数
- (BOOL)recoverTrackerWithNewConfig:(INSSkeletonExtraConfig *)extraConfig;

/// finish之后，会把序列化的文件存到config配置的路径下，且不可被recover
- (BOOL)finish;


@end

NS_ASSUME_NONNULL_END
