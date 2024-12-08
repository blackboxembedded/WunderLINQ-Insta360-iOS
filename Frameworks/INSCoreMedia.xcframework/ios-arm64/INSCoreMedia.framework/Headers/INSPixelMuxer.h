//
//  INSPixelMuxer.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/27.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSMuxer.h"


@class INSPlayerImage;

NS_ASSUME_NONNULL_BEGIN

@interface INSPixelMuxer : NSObject

- (instancetype) initWithURL:(NSURL*)url offset:(NSString*)offset width:(NSInteger)width height:(NSInteger)height fps:(NSInteger)fps bitrate:(NSInteger)bitrate error:(void(^_Nullable)(NSError *error))errorBlock;

- (void) start;

- (void) stop;

- (void) cancel;

- (void) setAudioStartTimestamp:(int64_t)timestamp;

- (void) setVideoStartTimestamp:(int64_t)timestamp;

- (void) addAACHeader:(const uint8_t *)header size:(size_t)size;

- (void) writeAACAdts:(const uint8_t *)adts size:(size_t)size timestamp:(int64_t)timestamp;

- (void) writeVideoImage:(INSPlayerImage*)img;

@property (nonatomic) BOOL enableGyroStabilizer;
@property (nonatomic) int audioSampleRate;              //音频采样率，默认48000

@end

NS_ASSUME_NONNULL_END
