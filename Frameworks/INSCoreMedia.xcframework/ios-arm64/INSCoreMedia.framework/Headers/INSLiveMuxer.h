//
//  INSLiveMuxer.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/27.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSMuxer.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSLiveMuxer : NSObject

- (instancetype) initWithURL:(NSURL*)url width:(NSInteger)width height:(NSInteger)height fps:(NSInteger)fps bitrate:(NSInteger)bitrate;

- (BOOL) addAACHeader:(const uint8_t *)header size:(size_t)size;

- (BOOL) writeAACAdts:(const uint8_t *)adts size:(size_t)size timestamp:(int64_t)timestamp;

- (BOOL) writeFlatPixelBuffer:(CVPixelBufferRef)pixelBuffer withTimesTamp:(int64_t)timestamp;

- (void) interrupt;

- (void) resetDynamicFps;

- (void) stop;

@property (nonatomic, readonly) double dynamicFps;      //动态帧率， 单位：帧/s
@property (nonatomic, readonly) double totalTime;      //总时间，单位s
@property (nonatomic, readonly) int64_t frameCount;     //帧数量,
@property (nonatomic, readonly) BOOL hasAACHeader;
@property (nonatomic) int audioSampleRate;              //音频采样率，默认48000

/**
 是否使用软编码, 默认为NO
 */
@property (nonatomic) BOOL useX264Encoder;

@property (nonatomic) int gopSize;

@end

NS_ASSUME_NONNULL_END
