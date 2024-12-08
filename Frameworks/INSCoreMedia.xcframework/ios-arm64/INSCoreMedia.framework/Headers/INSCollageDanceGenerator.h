//
//  INSCollageDanceGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCollageDanceConfiguration;
@class INSAppletVideoInfo;
@class INSAppletTrackerEnv;
@class INSScreenRecorder;


typedef NS_ENUM(NSInteger, INSCollageDanceGeneratorError) {
    INSCollageDanceGeneratorErrorParam = -1,
    INSCollageDanceGeneratorErrorTrackDataEmpty = -2,
    INSCollageDanceGeneratorErrorInitAlgo = -3,
    INSCollageDanceGeneratorErrorFlatRenderFailed = -4,
    INSCollageDanceGeneratorErrorSphericalRenderFailed = -5,
    INSCollageDanceGeneratorErrorWaitTimeout = -6,
    INSCollageDanceGeneratorErrorCVMatToAVFrameFailed = -7,
    INSCollageDanceGeneratorErrorExporterInfoNotSet = -8,
    INSCollageDanceGeneratorErrorCacheDirSetFailed = -9,
    
    INSCollageDanceGeneratorErrorUnknown = -100,
};

typedef void (^CollageDanceCompleteBlk)(NSError * _Nullable);

@interface INSCollageDanceGenerator : NSObject

@property (nonatomic, readonly) INSCollageDanceConfiguration *configuration;

@property (nonatomic, readonly) INSAppletVideoInfo *videoInfo;

@property (nonatomic, readonly) INSAppletTrackerEnv *trackerEnv;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConfiguration:(INSCollageDanceConfiguration *)configuration videoInfo:(INSAppletVideoInfo *)videoInfo trackerEnv:(INSAppletTrackerEnv *)trackerEnv;

- (void)runCollageDanceWithProgress:(void (^)(double value))progress completion:(CollageDanceCompleteBlk)completion;

- (nullable INSScreenRecorder *)screenRecorderWithFov:(float)fov distance:(float)distance;

// 这是一个异步方法，需要在回调中获取状态，才能退出
- (void)shutdownWithCompletion:(void (^)(BOOL cacheFinished))completion;



//- (void)runOneTakeWithProgress:(void (^)(double value))progress warning:(void (^)(INSOneTakeWrapWarningCode warningCode, id warninValue))warning completion:(void (^)(NSError * _Nullable error, NSArray <INSOneTakeResult *> * _Nullable results))completion;

@end

NS_ASSUME_NONNULL_END
