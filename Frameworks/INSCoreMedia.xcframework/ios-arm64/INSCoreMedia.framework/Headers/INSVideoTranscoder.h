//
//  INSVideoTranscoder.h
//  testAVFoundation
//
//  Created by pengwx on 2019/5/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSVideoTranscoderState){
    INSVideoTranscoderStateError,
    INSVideoTranscoderStateCancel,
    INSVideoTranscoderStateEnd,
};


@class INSVideoTranscoder;
@class INSTimeScale;
@protocol INSVideoTranscoderDelegate <NSObject>

- (void) videoTranscoder:(INSVideoTranscoder*)transcoder progress:(float)progress;
- (void) videoTranscoder:(INSVideoTranscoder*)transcoder state:(INSVideoTranscoderState)state error:(nullable NSError*)error;

@end


@interface INSVideoTranscoder : NSObject

- (instancetype) initWithInputURL:(NSURL*)inputURL outputURL:(NSURL*)outputURL width:(int)width height:(int)height bitrate:(int)bitrate;

- (instancetype) initMJPEGDecorderWithInputURL:(NSURL*)inputURL mediaFileSize:(int64_t)mediaFileSize outputURL:(NSURL*)outputURL width:(int)width height:(int)height bitrate:(int)bitrate;

- (void) run;

- (void) cancel;

/**
 预测的视频大小
 */
- (NSUInteger) estimateSizeWithDurationMs:(double)durationMs;

@property(nonatomic, weak)id<INSVideoTranscoderDelegate> deletage;


/**
 导出fps，默认为0.0, 即导出计算以原始视频的帧率计算
 */
@property(nonatomic) float exportFps;

/**
 开始时间，默认0
 */
@property(nonatomic) double startTimeMs;

/**
 结束时间，默认0，表示到输入视频的结尾
 */
@property(nonatomic) double endTimeMs;

/**
 倍数播放
 */
@property(nonatomic, strong, nullable)NSArray<INSTimeScale*> *timeScales;

/**
 进度回调间隔 默认值：0.5   单位：秒
 */
@property (nonatomic) float progressInterval;

+ (BOOL) isMovFile:(NSURL*)inputURL;

@end

NS_ASSUME_NONNULL_END
