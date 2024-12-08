//
//  INSMultipleConverter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/12.
//  Copyright © 2018年 insta360. All rights reserved.
//


#import "INSProjectionConverter.h"
#import "INSRenderType.h"

NS_ASSUME_NONNULL_BEGIN

@class INSMultipleInfo;
@class INSLookHerePoint;
@class INSProjectionParam;
@class INSProjectionInfo;
@class INSScreenRecorder;
@class INSDisplay;
@class INSDisplayConfigManager;

@interface INSMultipleConverter : INSProjectionConverter

-(instancetype)init NS_UNAVAILABLE;
- (instancetype) initWithMultipleInfo:(INSMultipleInfo*)multipleInfo display:(INSDisplay*)display displayConfigManager:(INSDisplayConfigManager*)manager;


@property (nonatomic) double transitionAnimationDuration;                       //过渡动画时间, 单位s, 默认:2s
@property (nonatomic) BOOL hasScreenRecorderTransitionAnimation;                //screenrecorder 数据是否应用过渡动画，默认:NO
//@property (nonatomic) BOOL enableAnimationBeginStateValueCompare;               //是否开启动画的开始状态值比较，开启时，如果开始状态变化不大，不开启动画， 默认：NO

@property (nonatomic, strong, readonly) INSMultipleInfo *multipleInfo;

/**
 获取某个时间点的视图投影信息
 @param timestamp 视频时间点， 单位ms
 @return 投影信息
 */
//- (INSProjectionInfo* __nullable) getProjectionInfoWithTimestamp:(int64_t)timestamp;
- (INSProjectionInfo* __nullable) getProjectionInfoWithTimestamp:(INSMediaPos*)mediaPos;

/**
 开始过渡动画
 */
- (void) beginTransitionAnimation:(BOOL)compareBeginState;

/**
 结束过渡动画
 */
- (void) endTransitionAnimation;

@end

NS_ASSUME_NONNULL_END
