//
//  INSMultiFrameDelayGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMultiFrameDelayConfiguration;
@class INSAppletVideoInfo;
@class INSAppletTrackerEnv;
@class INSScreenRecorder;


typedef NS_ENUM(NSInteger, INSMultiFrameDelayGeneratorError) {
    INSMultiFrameDelayGeneratorErrorParam = -1,
    INSMultiFrameDelayGeneratorErrorTrackDataEmpty = -2,
    INSMultiFrameDelayGeneratorErrorInitAlgo = -3,
    INSMultiFrameDelayGeneratorErrorFlatRenderFailed = -4,
    INSMultiFrameDelayGeneratorErrorSphericalRenderFailed = -5,
    INSMultiFrameDelayGeneratorErrorWaitTimeout = -6,
    INSMultiFrameDelayGeneratorErrorCVMatToAVFrameFailed = -7,
    INSMultiFrameDelayGeneratorErrorExporterInfoNotSet = -8,
    INSMultiFrameDelayGeneratorErrorCacheDirSetFailed = -9,
    
    INSMultiFrameDelayGeneratorErrorUnknown = -100,
};

typedef void (^MultiFrameDelayCompleteBlk)(NSError * _Nullable);

@interface INSMultiFrameDelayGenerator : NSObject

@property (nonatomic, readonly) INSMultiFrameDelayConfiguration *configuration;

@property (nonatomic, readonly) INSAppletVideoInfo *videoInfo;

@property (nonatomic, readonly) INSAppletTrackerEnv *trackerEnv;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConfiguration:(INSMultiFrameDelayConfiguration *)configuration videoInfo:(INSAppletVideoInfo *)videoInfo trackerEnv:(INSAppletTrackerEnv *)trackerEnv;

- (void)runMultiFrameDelayWithProgress:(void (^)(double value))progress completion:(MultiFrameDelayCompleteBlk)completion;

- (nullable INSScreenRecorder *)mdfScreenRecorderWithRollOpen:(BOOL)rollOpen fov:(float)fov distance:(float)distance;

// 这是一个异步方法，需要在回调中获取状态，才能退出
- (void)shutdownWithCompletion:(void (^)(BOOL cacheFinished))completion;



//- (void)runOneTakeWithProgress:(void (^)(double value))progress warning:(void (^)(INSOneTakeWrapWarningCode warningCode, id warninValue))warning completion:(void (^)(NSError * _Nullable error, NSArray <INSOneTakeResult *> * _Nullable results))completion;

@end

NS_ASSUME_NONNULL_END
