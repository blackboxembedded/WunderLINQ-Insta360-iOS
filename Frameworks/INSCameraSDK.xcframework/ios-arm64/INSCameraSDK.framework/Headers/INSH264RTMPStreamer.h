//
//  INSH264RTMPStreamer.h
//  INSCameraSDK
//
//  Created by Mac on 2021/4/9.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraRawPacketOutput.h"
#import "INSRTMPStreamer.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSH264RTMPStreamer : NSObject<INSRTMPStreamer, INSCameraMediaPluggable>

@property (nonatomic, readonly) INSCameraRawPacketOutput *rawPacketOutput;

/// indicate whether the streamer is running. 暗示当前是否在推流
@property (nonatomic, readonly) BOOL running;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithURL:(NSURL *)URL
                      width:(NSInteger)width
                     height:(NSInteger)height
                        fps:(NSInteger)fps
                    bitrate:(NSInteger)bitrate;

@end

NS_ASSUME_NONNULL_END
