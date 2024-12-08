//
//  INSRTMPStreamer.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSRTMPStreamErrorCode) {
    /// preparation on connecting destinate rtmp server failed. 准备连接rtmp 服务器失败
    INSRTMPStreamErrorCodePrepare,
    
    /// send audio packet failed, 发送音频包失败
    INSRTMPStreamErrorCodeAudio,
    
    /// send video packet failed, 发送视频包失败
    INSRTMPStreamErrorCodeVideo,
    
    /// other
    INSRTMPStreamErrorCodeOther,
};


@protocol INSRTMPStreamerDelegate;

/*!
 * RTMP streamer
 *
 * availability(Nano, ONE, Nano S)
 */
@protocol INSRTMPStreamer <NSObject>

@property (nonatomic, weak) id<INSRTMPStreamerDelegate> delegate;

/// the rtmp server address to push the stream. rtmp 服务器地址
@property (nonatomic, readonly) NSURL *URL;

/// width of the video stream's dimension to be pushed to the rtmp server to be pushed to the rtmp server. 推到rtmp 服务器的视频图像的宽
@property (nonatomic, readonly) NSInteger width;

/// height of the video stream's dimension to be pushed to the rtmp server. 推到rtmp 服务器的视频图像的高
@property (nonatomic, readonly) NSInteger height;

/// fps of the video stream to be pushed to the rtmp server. 推到rtmp 服务器的视频的帧率
@property (nonatomic, readonly) NSInteger fps;

/// bitrate of the video stream to be pushed to the rtmp server, bit per sec. 推到rtmp 服务器的视频流的码率
@property (nonatomic, readonly) NSInteger bitrate;

/// start to push the rtmp stream. 开始推流
- (void)startLive;

/// stop pushing the rtmp stream. 停止推流
- (void)stopLive;

/// interrupt pushing the rtmp steram. 中断推流
- (void)interruptLive;

@end

@protocol INSRTMPStreamerDelegate <NSObject>

/*!
 * @discussion  Live error occurres. 直播发生错误
 *
 * @param   error    error, the code is INSRTMPStreamerrorCode. 错误, 错误代码为INSRTMPStreamerrorCode
 */
- (void)streamerOnError:(NSError*)error;

@optional

/*!
 * @discussion  The live stream's fps and duration update event. 直播流的fps与duration 事件.
 *
 * @param   stitchFps The stitch fps. 拼接 fps值
 * @param   pushFps  The streamer fps value. 推流 fps值
 * @param   duration duration live duration, in seconds. 直播持续时间, 单位：秒
 */
- (void)streamerOnUpdateStitchFps:(double)stitchFps pushFps:(double)pushFps duration:(double)duration;

@end

NS_ASSUME_NONNULL_END
