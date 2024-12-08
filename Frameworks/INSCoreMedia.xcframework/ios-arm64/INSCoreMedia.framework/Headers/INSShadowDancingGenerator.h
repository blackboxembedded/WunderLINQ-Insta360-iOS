//
//  INSShadowDancingGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorderModel.h"
#import "INSTimeScale.h"
NS_ASSUME_NONNULL_BEGIN

@class INSShadowDancingConfiguration;
@class INSAppletVideoInfo;
@class INSAppletTrackerEnv;
@class INSScreenRecorder;


typedef NS_ENUM(NSInteger, INSShadowDancingGeneratorError) {
    INSShadowDancingGeneratorErrorParam = -1,
    INSShadowDancingGeneratorErrorTrackDataEmpty = -2,
    INSShadowDancingGeneratorErrorInitAlgo = -3,
    INSShadowDancingGeneratorErrorFlatRenderFailed = -4,
    INSShadowDancingGeneratorErrorSphericalRenderFailed = -5,
    INSShadowDancingGeneratorErrorWaitTimeout = -6,
    INSShadowDancingGeneratorErrorCVMatToAVFrameFailed = -7,
    INSShadowDancingGeneratorErrorExporterInfoNotSet = -8,
    INSShadowDancingGeneratorErrorCacheDirSetFailed = -9,
    
    INSShadowDancingGeneratorErrorUnknown = -100,
};

typedef void (^ShadowDancingCompleteBlk)(NSError * _Nullable);

@interface INSShadowDancingGenerator : NSObject



- (instancetype)init NS_UNAVAILABLE;

/**
 @param configuration 小程序参数，需全部配置（bgmClip可为nil）
 @param videoInfo 输入视频的属性，除primaryUrls外均需配置
 @param trackerEnv 追踪参数及recorder，需全部配置
 */
- (instancetype)initWithConfiguration:(INSShadowDancingConfiguration *)configuration videoInfo:(INSAppletVideoInfo *)videoInfo trackerEnv:(INSAppletTrackerEnv *)trackerEnv;

/**
 执行小程序：分析追踪数据、生成全景预览视频
 
 @param progress 进度回调
 @param completion 后处理回调
 */
- (void)runShadowDancingWithProgress:(void (^)(double value))progress completion:(ShadowDancingCompleteBlk)completion;

/**
 获取recorder
 
 @param rollOpen 是否翻转
 @return recorder
 */
- (nullable INSScreenRecorder *)sdScreenRecorderWithRollOpen:(BOOL)rollOpen;

// 获取播放倍速
- (nullable INSTimeScale *)getTimeScale;

// 中途关闭
// 这是一个异步方法，需要在回调中获取状态，才能退出
- (void)shutdownWithCompletion:(void (^)(BOOL cacheFinished))completion;

@end

NS_ASSUME_NONNULL_END
