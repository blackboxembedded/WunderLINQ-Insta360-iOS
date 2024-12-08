//
//  INSShadowCloneGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/22.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSCloneGeneratorConfiguration.h"
#import "INSCloneGeneratorProcotol.h"

NS_ASSUME_NONNULL_BEGIN


@class INSScreenRecorder;
@class INSCloneTrailConfiguration;
@interface INSCloneTrailGenerator : NSObject

@property (nonatomic, readonly) NSArray <NSURL *> *videoURLs;

@property (nonatomic, readonly) INSCloneTrailConfiguration *config;

@property (nonatomic, readonly) INSTrackerEnvironment *trackerConfig;

@property (nonatomic, weak) id<INSCloneTrailGeneratorDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

/// 需要用该方法做初始化
/// @param videoURLs 视频文件 4K为一个URL, 5.7K为两个URL
/// @param config 配置项 主要针对导出过程
- (nullable instancetype)initWithURLs:(NSArray <NSURL *> *)videoURLs config:(INSCloneTrailConfiguration *)config trackerConfig:(INSTrackerEnvironment *)trackerConfig;


/// 这是一个异步方法，，进度在回调抛出；在导出之前，至少调用一次该方法，按照配置获取分身信息
/// @param thickness 分身间隔参数，可控制两个分身的间隔：参数与ROI宽度乘积，该值越大，分身之间的间隔越大
/// @param progress 进度回调
- (void)prepareWithThickness:(float)thickness progress:(CloneGeneratorProgressBlk)progress;

/// 这是一个异步方法，如果prepare没有问题， 则可以调用该方法，进行帧的合成与导出。
/// @param exportUrl 导出的URL
/// @param mode 分身模式
/// @return 是否正常开启流程，如果返回NO，则INSShadowCloneGeneratorDelegate中提供的方法全部不会执行
- (BOOL)runExporterWithExportUrl:(NSURL *)exportUrl mode:(INSCloneTrailExportMode)mode;

/// 取消当前正在进行的步骤，可以发生在prepare或者export的过程中
- (void)cancelAllProgress;

/// 对已经导出的分身视频生成recorder
/// @param videoUrl 分身视频地址
/// @param fov fov
/// @param distance distance
- (nullable INSScreenRecorder *)shadowScreenRecorderWithVideoUrl:(NSURL *)videoUrl fov:(float)fov distance:(float)distance;

@end

NS_ASSUME_NONNULL_END
