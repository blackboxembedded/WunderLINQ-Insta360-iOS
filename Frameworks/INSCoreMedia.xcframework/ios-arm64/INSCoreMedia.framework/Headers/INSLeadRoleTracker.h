//
//  INSLeadRoleTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/10.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSLeadRoleTrackerMode) {
    INSLeadRoleTrackerModeOffLine = 0,
    INSLeadRoleTrackerModeOnLine,
};

@class INSProjectionInfo;
@interface INSLeadRoleTrackerConfigration : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) int frameWidth;

@property (nonatomic) int frameHeight;

@property (nonatomic) double duration;

@property (nonatomic) INSLeadRoleTrackerMode trackerMode;

// 主角的切换延迟，表示新主角出现heroChangeThresh 毫秒后，再切换，默认为3000
@property (nonatomic) double heroChangeThresh;

// 检测间隔，表示在所有帧序列帧每detectInterval帧检测一帧，默认为30，表示关键帧检测
@property (nonatomic) int detectInterval;

@property (nonatomic) BOOL visualDebug;

@end

@interface INSLeadRoleTracker : NSObject

@property (nonatomic, readonly) INSLeadRoleTrackerConfigration *config;

- (instancetype)initWithConfig:(INSLeadRoleTrackerConfigration *)config;

/**
 分析一帧

 @param pixelBuffer 2:1 pano image
 @param timestampMs timestamp in MS
 @return 是否成功
 */
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs;

/**
 获取任意时间下direction的旋转量，如果还没有analyze到当前时间戳，则返回GLKQuaternionIdentity
 
 @param timestamp timestamp in ms
 @return 行进方向旋转量
 */
- (GLKQuaternion)fetchQuaternion:(double)timestamp;

/**
 所有帧分析结束之后，可以获得多目标识别结果：每个目标出现的时间以及位置的序列，每个序列代表一个物体的track路径
 
 @return 追踪到的目标序列个数，0表示没有追踪到序列或者写json时发生错误，在主角视角模块，成功时返回值最大为1
 */
- (int)finish;


- (INSProjectionInfo *)getProjectionInfo:(double)timestamp;

@end

NS_ASSUME_NONNULL_END
