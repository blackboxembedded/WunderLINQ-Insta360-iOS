//
//  INSShadowCloneDivideGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/8/18.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSCloneGeneratorConfiguration.h"
#import "INSCloneGeneratorProcotol.h"

NS_ASSUME_NONNULL_BEGIN


@class INSScreenRecorder;
@class INSCloneShadowConfiguration;
@interface INSCloneShadowGenerator : NSObject

@property (nonatomic, readonly) NSArray <NSURL *> *videoURLs;

@property (nonatomic, readonly) INSCloneShadowConfiguration *config;

@property (nonatomic, readonly) INSTrackerEnvironment *trackerConfig;

@property (nonatomic, weak) id<INSCloneShadowGeneratorDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

/// 需要用该方法做初始化
/// @param videoURLs 视频文件 4K为一个URL, 5.7K为两个URL
/// @param config 配置项 主要针对导出过程
- (nullable instancetype)initWithURLs:(NSArray <NSURL *> *)videoURLs config:(INSCloneShadowConfiguration *)config trackerConfig:(INSTrackerEnvironment *)trackerConfig;


/// 获取方位数量
- (NSUInteger)clusterNum;


/// 这是一个异步方法，，进度在回调抛出；在导出之前，至少调用一次该方法，按照配置获取分身信息
/// @param progress 进度回调
- (void)prepareWithProgress:(CloneGeneratorProgressBlk)progress;

/// 这是一个异步方法，如果prepare没有问题， 则可以调用该方法，进行帧的合成与导出。
/// @param exportUrl 导出的URL
/// @return 是否正常开启流程，如果返回NO，则INSShadowCloneGeneratorDelegate中提供的方法全部不会执行
- (BOOL)runExporterWithExportUrl:(NSURL *)exportUrl;

/// 取消当前正在进行的步骤，可以发生在prepare或者export的过程中
- (void)cancelAllProgress;

/// 对已经导出的分身视频生成recorder
/// @param videoUrl 分身视频地址
/// @param fov fov
/// @param distance distance
- (nullable INSScreenRecorder *)shadowScreenRecorderWithVideoUrl:(NSURL *)videoUrl fov:(float)fov distance:(float)distance;

@end

NS_ASSUME_NONNULL_END

