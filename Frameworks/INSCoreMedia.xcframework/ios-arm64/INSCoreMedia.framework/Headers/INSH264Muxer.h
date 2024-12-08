//
//  INSH264Muxer.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/27.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSMuxer.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, INSH264MuxerType) {
    INSH264MuxerTypeMP4 = 0, // write to local file
    INSH264MuxerTypeFLV = 1, // write to stream such as rtmp
};

@interface INSH264Muxer : NSObject

// type is INSH264MuxerTypeMP4
- (instancetype) initWithURL:(NSURL*)url offset:(NSString* _Nullable)offset width:(NSInteger)width height:(NSInteger)height fps:(NSInteger)fps error:(void(^_Nullable)(NSError *error))errorBlock;

- (instancetype) initWithURL:(NSURL *)url offset:(NSString* _Nullable)offset width:(NSInteger)width height:(NSInteger)height fps:(NSInteger)fps error:(void (^)(NSError * _Nonnull))errorBlock type:(INSH264MuxerType)type;

- (void) stop;

- (void) cancel;

- (void) interrupt;

- (void) setAudioStartTimestamp:(int64_t)timestamp;

- (void) setVideoStartTimestamp:(int64_t)timestamp;

- (BOOL) addSps:(const uint8_t *)sps spsSize:(size_t)spsSize pps:(const uint8_t *)pps ppsSize:(size_t)ppsSize;

- (BOOL) addAACHeader:(const uint8_t *)header size:(size_t)size;

- (void) writeHeader;

- (void) writeH264Nalu:(const uint8_t *)nalu size:(size_t)size keyFrame:(BOOL)isKey timestamp:(int64_t)timestamp;

- (void) writeAACAdts:(const uint8_t *)adts size:(size_t)size timestamp:(int64_t)timestamp;

@property (nonatomic) int audioSampleRate;              //音频采样率，默认48000

@end

NS_ASSUME_NONNULL_END
