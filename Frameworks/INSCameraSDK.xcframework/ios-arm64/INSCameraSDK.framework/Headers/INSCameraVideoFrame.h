//
//  INSCameraVideoFrame.h
//  INSCameraSDK
//
//  Created by zeng bin on 12/22/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraVideoFrame : NSObject

@property (nonatomic) CVPixelBufferRef pixelBuffer;

@property (nonatomic) NSTimeInterval timestamp;

@property (nonatomic) BOOL isKeyFrame;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                          timestamp:(NSTimeInterval)timestamp
                         isKeyFrame:(BOOL)isKeyFrame;

@end


NS_ASSUME_NONNULL_END
