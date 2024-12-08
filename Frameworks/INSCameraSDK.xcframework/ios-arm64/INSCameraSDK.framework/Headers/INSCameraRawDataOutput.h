//
//  INSCameraRawDataOutput.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraMediaSession.h"

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraRawDataOutputDelegate;

@interface INSCameraRawDataOutput : NSObject <INSCameraMediaPluggable>

- (void)setDelegate:(nullable id<INSCameraRawDataOutputDelegate>)delegate
    onDispatchQueue:(nullable dispatch_queue_t)dispatchQueue;

@property (nullable, nonatomic, readonly, weak) id<INSCameraRawDataOutputDelegate> delegate;

@property (nullable, nonatomic, readonly) dispatch_queue_t dispatchQueue;

@end

@protocol INSCameraRawDataOutputDelegate <NSObject>

@optional

- (void)rawDataOutput:(INSCameraRawDataOutput *)rawDataOutput didOutputAudio:(NSData *)audioData timestamp:(int64_t)timestamp;

- (void)rawDataOutput:(INSCameraRawDataOutput *)rawDataOutput didOutputVideo:(NSData *)videoData timestamp:(int64_t)timestamp;

- (void)rawDataOutput:(INSCameraRawDataOutput *)rawDataOutput didOutputGyro:(NSData *)gyroData timestamp:(int64_t)timestamp;

@end

NS_ASSUME_NONNULL_END
