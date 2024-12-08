//
//  INSFileClip.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/2.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSClip.h"
#import "INSClipConfig.h"
#import "INSEmSegment.h"



NS_ASSUME_NONNULL_BEGIN

@class INSTimeScale;
@interface INSFileClip : INSClip<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initWithURL:(NSURL*)url startTimeMs:(double)startTime endTimeMs:(double)endTime totalSrcDurationMs:(double)totalSrcDuration timeScales:(NSArray<INSTimeScale*>* _Nullable)timeScales hasAudio:(BOOL)hasAudio mediaFileSize:(int64_t)mediaFileSize;
- (instancetype) initWithURLs:(NSArray<NSURL*>*)urls startTimeMs:(double)startTime endTimeMs:(double)endTime totalSrcDurationMs:(double)totalSrcDuration timeScales:(NSArray<INSTimeScale*>* _Nullable)timeScales hasAudio:(BOOL)hasAudio mediaFileSize:(int64_t)mediaFileSize;

-(instancetype)initWithEmSegment:(NSArray<INSEmSegment*>*)emSegments startTimeMs:(double)startTime endTimeMs:(double)endTime totalSrcDurationMs:(double)totalSrcDuration timeScales:(NSArray<INSTimeScale*>* _Nullable)timeScales hasAudio:(BOOL)hasAudio mediaFileSize:(int64_t)mediaFileSize;

@property(nonatomic, readonly)BOOL isEmSegments;
@property(nonatomic, strong, nullable)NSArray<INSEmSegment*>* emSegments;

/**
 是否存在音频轨
 */
@property (nonatomic) BOOL hasAudio;

/**
 视频文件总时长
 单位：毫秒ms
 */
@property (nonatomic) double totalSrcDurationMs;


/**
 静音临界值
 当timeScale设置的factor小于此值时，视频的声音将会被静音
 */
@property (nonatomic) double muteBgmForRangeTimeScaleLessThan;  //default 1.

/**
 资源URL
 */
@property (nonatomic, strong, nullable) NSArray<NSURL*> *urls;

/**
 视频是否静音
 默认为NO, 仅导出时视频文件FileClip有效，音频文件忽略此属性
 */
@property (nonatomic) BOOL videoSilent;

/**
 仅isLoopAudio属性为YES有效，表示其实音频偏离startTimeMs的值
 */
@property (nonatomic) int64_t firstClipTimeOffsetMs;

/**
 trim开始时间
 单位：毫秒MS
 */
@property (nonatomic) double startTimeMs;

/**
 trim结束时间
 单位：毫秒MS
 */
@property (nonatomic) double endTimeMs;

/**
 时间缩放片段
 当timeScales的factor不为1时，片段将会强制静音，factor为1时，使用silent值进行设置
 仅视频文件FileClip有效，音频文件忽略此属性
 */
@property (nonatomic, strong, nullable) NSArray<INSTimeScale*> *timeScales;


/**
 末尾剪切参与过场动画的时长
 此时长为最后形成视频的时长，与timescale无关
 */
@property (nonatomic) double endCutDurationMs;


/**
 开始参与过场动画的时间，此时间为视频原始时间
 */
@property (nonatomic, readonly) double startCutTimeMs;

@property (nonatomic) double minTimeScaleApplyed;
@property (nonatomic) double audioVolume;
@property (nonatomic) double afadeInDurationMs;
@property (nonatomic) double afadeOutDurationMs;

/// 声音降噪，默认：NO
@property (nonatomic) BOOL enableAudioDenoise;


/// 声音降噪的bgm权重，默认0.8
@property (nonatomic) float audioDenoiseBgmWeight;

/// 声音降噪的voice权重，默认2.0
@property (nonatomic) float audioDenoiseVoiceWeight;

/**
 默认factor，用作函数getAllTimeScales补全用，初始值为1.0
 */
@property (nonatomic) double defaultFactor;

/// 原始视频的帧率，不设置时默认值为0
@property (nonatomic) double framerate;

/// urls数据里面的视频是否来自不同的源，默认值为NO，即5.7k视频，为YES时表示为组合视频
@property (nonatomic) BOOL urlsFromDifferentSources;

///指明来自不同源的文件采用哪个文件的音频, 默认值INSDifferentSourcesAudioTypeAudio1
@property(nonatomic)INSDifferentSourcesAudioType differentSourcesAudioType;


/// 指明使用什么音频模式播放，默认值INSClipAudioModeNone
@property(nonatomic)INSClipAudioMode audioMode;

/// 视频宽, 默认值0
@property(nonatomic)int videoWidth;

/// 视频高，默认值0
@property(nonatomic)int videoHeight;

/// 视频码率 单位：bits/seconds  默认值：0
@property(nonatomic)int64_t videoBitrate;

/// 自定义播放buffer时长，单位：bytes   默认值：0
@property(nonatomic)int64_t customBufferSizeInBytes;

- (double) getDuration;

- (NSArray<INSTimeScale*>*) getAllTimeScales;

- (NSArray<INSTimeScale*>*) getTimeScalesWithFactor:(double)factor;

@end


NS_ASSUME_NONNULL_END
