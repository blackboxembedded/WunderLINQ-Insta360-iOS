//
//  INSCameraAVOutput.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>
#import "INSCameraMediaSession.h"

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraAVOutputDelegate;

@protocol INSCameraAVOutput <INSCameraMediaPluggable>

/*!
 *
 * @param delegate the delegate to process the output data
 * @param dispatchQueue the dispatch queue that the delegate methods will be called, main queue if it is nil
 */
- (void)setDelegate:(nonnull id<INSCameraAVOutputDelegate>)delegate onDispatchQueue:(nullable dispatch_queue_t)dispatchQueue;

/// the delegate to process the output data
@property (nullable, nonatomic, readonly, weak) id<INSCameraAVOutputDelegate> delegate;

/// the dispatch queue that the delegate methods will be called, default is the main queue
@property (nullable, nonatomic, readonly) dispatch_queue_t dispatchQueue;

@end

@class INSCameraAudioPacket;
@class INSCameraVideoPacket;
@class INSCameraVideoFrame;

@protocol INSCameraAVOutputDelegate <NSObject>

@optional

/*!
 * Notifies the delegate that an audio frame has arrived.
 * For ONE, Nano S, Nano (fw >= 190) devices, the timestamp is synchronized to the iOS system's media clock.
 *
 * 通知代理接收到音频数据，对于 ONE, Nano S, Nano (固件 >= 190) 的设备，时间戳已经被同步到了iOS 系统的时间戳
 *
 * @param   audioPacket Audio Packet
 */
- (void)avOutput:(id<INSCameraAVOutput>)avOutput
    didOutputAudioPacket:(INSCameraAudioPacket *)audioPacket;

/*!
 * Notifies parse  the delegate that sequence parameter set and picture parameter set parsed
 *
 * 通知代理接收到sps和pps数据
 */
- (void)avOutput:(id<INSCameraAVOutput>)avOutput
    didOutputH264Sps:(NSData *)sps pps:(NSData *)pps;

/*!
 * Notifies the delegate that an video frame has arrived.
 *
 * 通知代理接收到视频数据
 *
 * @param   videoPacket Video Packet
 */
- (void)avOutput:(id<INSCameraAVOutput>)avOutput
    didOutputVideoPacket:(INSCameraVideoPacket *)videoPacket;

/*!
 * Notifies the delegate that an video frame has arrived.
 * For ONE, Nano S, Nano (fw >= 190) devices, the timestamp is synchronized to the iOS system's media clock.
 *
 * 通知代理接收到视频帧数据，对于 ONE, Nano S, Nano (固件 >= 190) 的设备，时间戳已经被同步到了iOS 系统的时间戳
 *
 * @param   videoFrame video frame
 */
- (void)avOutput:(id<INSCameraAVOutput>)avOutput
    didOutputVideoFrame:(INSCameraVideoFrame *)videoFrame;

@end

NS_ASSUME_NONNULL_END
