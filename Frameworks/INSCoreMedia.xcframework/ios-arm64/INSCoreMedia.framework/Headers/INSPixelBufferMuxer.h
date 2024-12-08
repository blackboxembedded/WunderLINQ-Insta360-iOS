//
//  INSPixelBufferMuxer.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/18.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSPixelBufferMuxer : NSObject

- (instancetype) initWithURL:(NSURL*)url width:(NSInteger)width height:(NSInteger)height fps:(NSInteger)fps bitrate:(NSInteger)bitrate hasAudio:(BOOL)hasAudio;

- (BOOL) addAACHeader:(const uint8_t *)header size:(size_t)size;
- (BOOL) addAACHeader:(const uint8_t *)header size:(size_t)size channelNum:(int)channels sampleRate:(int)sampleRate;
- (BOOL) writeAACAdts:(const uint8_t *)adts size:(size_t)size timestamp:(int64_t)timestamp;
- (BOOL) writePixelBuffer:(CVPixelBufferRef)pixelBuffer withTimesTamp:(int64_t)timestamp;

- (void) stop;
- (void) cancel;

@property (nonatomic, strong, readonly) NSURL *url;

@end

NS_ASSUME_NONNULL_END
