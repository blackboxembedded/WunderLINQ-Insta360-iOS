//
//  INSFlatRTMPStreamer.h
//  INSCameraSDK
//
//  Created by pengwx on 17/1/11.
//  Copyright © 2017年 com.insta360. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "INSRTMPStreamer.h"
#import "INSCameraFlatPanoOutput.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 * @discussion streamer for flat stitched panorama video. Call INSCameraMediaSession's plug: method for receiving camera's live stream
 *
 * 直播平铺的全景图像. 调用 INSCameraMediaSession 的 plug: 方法以接收相机的数据
 */
@interface INSFlatRTMPStreamer : NSObject <INSRTMPStreamer, INSCameraMediaPluggable>

/// represent the camera's audio & video outputs. 表示相机拼接后全景图的输出内容
@property (nonatomic, readonly) INSCameraFlatPanoOutput *flatPanoOutput;

/// indicate whether the streamer is running. 暗示当前是否在推流
@property (nonatomic, readonly) BOOL running;

- (instancetype)init NS_UNAVAILABLE;

/*!
 * init the rtmp streamer
 *
 * @param URL destinate RTMP server's URL. RTMP 服务器的地址. e.g. rtmp://192.168.1.2/live/12345
 * @param width the output video's width to be pushed to the RTMP server.
 * @param height the output video's height to be pushed to the RTMP server.
 * @param fps the output video's frame rate to be pushed to the RTMP server.
 * @param bitrate the output video stream's bitrate to be pushed to the RTMP server.
 */
- (instancetype)initWithURL:(NSURL *)URL width:(NSInteger)width height:(NSInteger)height
                        fps:(NSInteger)fps bitrate:(NSInteger)bitrate;


@end

NS_ASSUME_NONNULL_END
