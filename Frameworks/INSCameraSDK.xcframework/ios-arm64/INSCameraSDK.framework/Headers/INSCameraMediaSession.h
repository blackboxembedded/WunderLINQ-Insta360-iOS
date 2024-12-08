//
//  INSCameraMediaSession.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/11/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraMediaBasic.h"
#import <INSCoreMedia/INSGyroType.h>
#import <INSCoreMedia/INSGyroPlayerWrapData.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCameraMediaSession;
@class INSCameraMediaConfiguration;
@class INSH264DecoderConfig;
@protocol INSCameraDevice;

@interface InsGyroInfo : NSObject
@property (nonatomic) int64_t timestamp;      //millisecond
@property (nonatomic) double gravity_x;
@property (nonatomic) double gravity_y;
@property (nonatomic) double gravity_z;
@property (nonatomic) double rotation_x;
@property (nonatomic) double rotation_y;
@property (nonatomic) double rotation_z;
@end

/// it will work only after starting the media session or commitChanges if it is running already
@protocol INSCameraMediaPluggable <NSObject>

@property (nullable, nonatomic, readonly) NSArray <id<INSCameraMediaPluggable>>* subPluggables;

/// add the outputs to the mediaSession here
- (void)willPlugToSession:(INSCameraMediaSession *)mediaSession;

/// remove the outputs from the mediaSession here
- (void)willUnplugFromSession:(INSCameraMediaSession *)mediaSession;

@optional

/// the mediaSession will receive media data from camera.
- (void)mediaSession:(INSCameraMediaSession *)mediaSession
    willRunWithConfiguration:(INSCameraMediaConfiguration *)configuration;

/// the mediaSession did start to receive media data from camera.
- (void)mediaSession:(INSCameraMediaSession *)mediaSession
    didRunWithConfiguration:(INSCameraMediaConfiguration *)configuration;

/// the mediaSession stops running
- (void)mediaSessionDidStopRunning:(INSCameraMediaSession *)mediaSession;

- (void)mediaSession:(INSCameraMediaSession *)mediaSession shouldRunGyroWithConfiguration:(INSCameraMediaConfiguration *)configuration;

- (void)mediaSessionShouldStopGyro:(INSCameraMediaSession *)mediaSession;

- (void)resetGyroPlayerWithMediaSession:(INSCameraMediaSession *)mediaSession
                          configuration:(INSCameraMediaConfiguration *)configuration;

@end

/*!
 *  @class  INSCameraMediaSession.
 *
 *  @brief  Entry point to manage camera audio & video live stream. the API is AVFoundation like.
 *
 *  @discussion you should configure input(video resolution, audio sample rate).
 *              plug pluggables before start running the media session.
 */
@interface INSCameraMediaSession : NSObject

/*!
 *  The expected audio sample rate. if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *
 *  如果在开启预览时发送录像请求，相机会以当前预览的采样率进行录像，如果需要切换采样率，需要调用commitChangesWithCompletion:
 */
@property (nonatomic) INSAudioSampleRate expectedAudioSampleRate;

/*!
 *  For one、nano s,  The expected video resolution, if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *  For one x, you should set resolution for both Main and Secondary stream. use 'INSPreviewStreamType' to choose which is used for preview stream.
 *
 *  如果在开启预览时发送录像请求，相机会以当前预览的分辨率进行录像，如果需要切换分辨率，需要调用commitChangesWithCompletion:
 *
 *  注意:对one x, 预览流需分别设置主、副码流的分辨率. 录像的分辨率为主码流. 用‘previewStreamNum’设置用主码流还是副码流来作为预览.
 */
@property (nonatomic) INSVideoResolution expectedVideoResolution;

/*!
 *  The expected video resolution, if you want to change the value when mediaSession is running, you need to invoke commitChangesWithCompletion:
 *
 *
 */
@property (nonatomic) INSVideoResolution expectedVideoResolutionSecondary;

/*!
 *  For one X, use this to choose whether the main or secondary stream should be used as preview stream.
 *  INSPreviewStreamTypeMain : preview with main stream
 *  INSPreviewStreamTypeSecondary : preview with secondary stream
 *
 *  对one X, 用这个变量来决定使用主码流还是副码流来作为预览流. 录像时，相机还是会用主码流的分辨率.
 *  INSPreviewStreamTypeMain : 使用主码流作为预览流
 *  INSPreviewStreamTypeSecondary : 使用副码流作为预览
 */
@property (nonatomic) INSPreviewStreamType previewStreamType;

/*!
 *  VR180 and gyroPlayMode == RemoveYawRotations, this should be set to INSPreviewStreamRotationRaw180
 */
@property (nonatomic) INSPreviewStreamRotation previewStreamRotation;

/*!
 * The mode used to calibrate the video, default is INSGyroPlayModeDefault.
 *
 * 矫正图像的模式，默认为 INSGyroPlayModeDefault
 */
@property (nonatomic) INSGyroPlayMode gyroPlayMode;

/*!
 * Camera preview stream stability parameters
 *
 * INSGyroStabFilterSetting.gravityCalibrate: indicated whether gravity correction is enabled in free footage mode. Default no.
 */
@property (nonatomic, nullable) INSGyroStabFilterSetting *gyroFilterSetting;

/*!
 *  The encoding format of video real-time stream, default is INSVideoEncodeH264.
 */
@property (nonatomic) INSVideoEncode videoStreamEncode;

/*!
 * indicate whether the session is running
 */
@property (nonatomic, readonly) BOOL running;

/*!
 *  start the media session. if succeeds, error will be nil. if fails, error will be set, and the error codes are list at <i>INSCameraErrorCode</i>
 */
- (void)startRunningWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)shouldRunGyroWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)startRunningWithCameraDevice:(id<INSCameraDevice>)cameraDevice
                          completion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  stop the media session. if succeeds, error will be nil. if fails, error will be set, and the error codes are list at <i>INSCameraErrorCode</i>
 */
- (void)stopRunningWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)shouldStopRunGyroWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

- (void)resetGyroPlayerWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;
/*!
 *  stop the media session. if succeeds, error will be nil. if fails, error will be set, and the error codes are list at <i>INSCameraErrorCode</i>
 */
- (void)stopRunningCommitingWithCompletion:(void (^)(NSError * _Nullable, BOOL commiting))completion;

/*!
 *  commit changes to the running media session. if succeeds, error will be nil. if fails, error will be set, and the error codes are list at <i>INSCameraErrorCode</i>
 */
- (void)commitChangesWithCompletion:(nullable void (^)(NSError * _Nullable error))completion;

/*!
 *  plug an INSCameraMediaPluggable to the media session.
 */
- (void)plug:(id<INSCameraMediaPluggable>)pluggable;

/*!
 *  unplug an INSCameraMediaPluggable from the media session.
 */
- (void)unplug:(id<INSCameraMediaPluggable>)pluggable;

/*!
 *  unplug all INSCameraMediaPluggables from the media session.
 */
- (void)unplugAll;

- (void)openWithHandle:(void (^)(InsGyroInfo * _Nullable, NSError * _Nullable))handle;

- (void)setDecoderConfig:(INSH264DecoderConfig *)config;

@end

NS_ASSUME_NONNULL_END
