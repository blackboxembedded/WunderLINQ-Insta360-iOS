//
//  INSCameraScreenOutput.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraAVOutput.h"

NS_ASSUME_NONNULL_BEGIN

@class INSRenderView;

@interface INSCameraScreenOutput : NSObject <INSCameraAVOutput>

- (instancetype)initWithRenderView:(INSRenderView *)renderView
                       outputWidth:(NSInteger)width
                      outputHeight:(NSInteger)height
                 outputPixelFormat:(OSType)pixelFormat;

- (instancetype)initWithRenderView:(INSRenderView *)renderView
                       outputWidth:(NSInteger)width
                      outputHeight:(NSInteger)height
                 outputPixelFormat:(OSType)pixelFormat
                   outputFrameRate:(NSInteger)fps
                       enableAudio:(BOOL)enableAudio;

@property (nonatomic, readonly) INSRenderView *renderView;

/// The width of output dimension.
@property (nonatomic, readonly) NSInteger outputWidth;

/// The height of output dimension.
@property (nonatomic, readonly) NSInteger outputHeight;

/// The framerate of output video, default is 30.
@property (nonatomic, readonly) NSInteger outputFps;

/// whether to enable audio
@property (nonatomic, readonly) BOOL enableAudio;

/*!
 * The video output pixel format.
 *
 * Right now, supported value are kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_32BGRA
 */
@property (nonatomic, readonly) OSType outputPixelFormat;

- (void)updateOutputWidth:(NSInteger)width height:(NSInteger)height;

- (void)updateOutputWidth:(NSInteger)width height:(NSInteger)height framerate:(NSInteger)fps;

@end

NS_ASSUME_NONNULL_END
