//
//  INSCycleCloneGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class INSCycleCloneConfiguration;
@class INSAppletVideoInfo;
@class INSAppletTrackerEnv;
@class INSScreenRecorder;
@class INSDisplay;

typedef NS_ENUM(NSInteger, INSCycleCloneGeneratorError) {
    INSCycleCloneGeneratorErrorParam = -1,
    INSCycleCloneGeneratorErrorTrackDataEmpty = -2,
    INSCycleCloneGeneratorErrorInitAlgo = -3,
    INSCycleCloneGeneratorErrorFlatRenderFailed = -4,
    INSCycleCloneGeneratorErrorSphericalRenderFailed = -5,
    INSCycleCloneGeneratorErrorWaitTimeout = -6,
    INSCycleCloneGeneratorErrorCVMatToAVFrameFailed = -7,
    INSCycleCloneGeneratorErrorExporterInfoNotSet = -8,
    INSCycleCloneGeneratorErrorCacheDirSetFailed = -9,
    INSCycleCloneGeneratorErrorMovingDistanceInvalid = -10,
    INSCycleCloneGeneratorErrorExporterFailed = -11,
    
    INSCycleCloneGeneratorErrorUnknown = -100,
};

typedef void (^CycleCloneCompleteBlk)(NSError * _Nullable);

@interface INSCycleCloneGenerator : NSObject

@property (nonatomic, readonly) INSCycleCloneConfiguration *configuration;

@property (nonatomic, readonly) INSAppletVideoInfo *videoInfo;

@property (nonatomic, readonly) INSAppletTrackerEnv *trackerEnv;

- (instancetype)init NS_UNAVAILABLE;

/**
 @param configuration 小程序参数，需全部配置（bgmClip可为nil）
 @param videoInfo 输入视频的属性，除primaryUrls外均需配置
 @param trackerEnv 追踪参数及recorder，需全部配置
 */
- (instancetype)initWithConfiguration:(INSCycleCloneConfiguration *)configuration videoInfo:(INSAppletVideoInfo *)videoInfo trackerEnv:(INSAppletTrackerEnv *)trackerEnv;

/**
 执行小程序：分析追踪数据、生成全景预览视频
 
 @param progress 进度回调
 @param completion 后处理回调
 */
- (void)runCycleCloneWithProgress:(void (^)(double value))progress completion:(CycleCloneCompleteBlk)completion;

/**
 获取静止/旋转视角recorder
 
 @param needMoving true表示需要旋转视角，否则返回静止视角；不满足条件返回nil
 @param aspect 宽高比，影响recorder的转动范围
 @param rollOpen 是否翻转
 @param fov 强制覆盖recorder的fov，大于0有效
 @param distance 强制覆盖recorder的distance，大于0有效
 @return recorder
 */
- (nullable INSScreenRecorder *)GetScreenRecorderMoving:(BOOL) needMoving display:(INSDisplay *)display WithRollOpen:(BOOL)rollOpen fov:(float)fov distance:(float)distance;

// 中途关闭
// 这是一个异步方法，需要在回调中获取状态，才能退出
- (void)shutdownWithCompletion:(void (^)(BOOL cacheFinished))completion;

@end

NS_ASSUME_NONNULL_END
