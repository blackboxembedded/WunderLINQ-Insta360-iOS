//
//  INSBgmClip.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/3/11.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSClip.h"

NS_ASSUME_NONNULL_BEGIN


@interface INSBgmClip : INSClip<NSCoding, NSCopying, NSMutableCopying>


- (instancetype) initWithURL:(NSURL*)url durationMs:(double)duration startOffsetMs:(double)startOffset weight:(double)weight;

/**
 资源URL
 */
@property (nonatomic, strong) NSURL *url;

/**
 bgm文件的时长
 单位：毫秒ms
 */
@property (nonatomic) double durationMs;

/**
 trim开始时间
 单位：毫秒ms
 */
@property (nonatomic) double startOffsetMs;


/**
 bgm与视频混音的权重
 取值范围0~1
 */
@property (nonatomic) double weight;

/**
 音量大小，默认1
 取值范围0~1
 */
@property (nonatomic) double volume;

/**
 淡入时间
 默认0ms
 */
@property (nonatomic) double afadeInDurationMs;

/**
 淡出时间
 默认1000ms
 */
@property (nonatomic) double afadeOutDurationMs;


/// 音频开始时间同步输出视频开始的时间，默认值为0，表示同步到输出视频的开始
@property(nonatomic)double synOutputVideoStartTimeMs;

/// 音频输出时长，单位：ms
@property(nonatomic)double outputDurationMs;


/// 音效是否循环，默认为YES
@property (nonatomic)BOOL repeat;

@end


NS_ASSUME_NONNULL_END
