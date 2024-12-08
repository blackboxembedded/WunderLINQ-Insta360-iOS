//
//  INSScreenRTMPStreamer.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/24/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import "INSRTMPStreamer.h"
#import "INSCameraScreenOutput.h"

NS_ASSUME_NONNULL_BEGIN

@class INSRenderView;

/*!
 * @discussion streamer for capturing screen. Call INSCameraMediaSession's plug: method for receiving camera's live stream
 *
 * 录屏直播. 调用 INSCameraMediaSession 的 plug: 方法以接收相机的数据
 */
@interface INSScreenRTMPStreamer : NSObject <INSRTMPStreamer, INSCameraMediaPluggable>

/// represent the camera's audio & captured screen's video outputs. 表示屏幕的输出内容+相机的音频
@property (nonatomic, readonly) INSCameraScreenOutput *screenOutput;

/// indicate whether the streamer is running. 暗示当前是否在推流
@property (nonatomic, readonly) BOOL running;

- (instancetype)init NS_UNAVAILABLE;

/*!
 * init the rtmp streamer
 *
 * @param URL the RTMP server's URL, e.g. rtmp://192.168.1.2/live/12345
 * @param width the output video's width
 * @param height the output video's height
 * @param fps the output video's frame rate
 * @param bitrate the output video stream's bitrate
 * @param renderView the renderView to be captured
 */
- (instancetype)initWithURL:(NSURL *)URL
                      width:(NSInteger)width
                     height:(NSInteger)height
                        fps:(NSInteger)fps
                    bitrate:(NSInteger)bitrate
                 renderView:(INSRenderView *)renderView;

@end

NS_ASSUME_NONNULL_END
