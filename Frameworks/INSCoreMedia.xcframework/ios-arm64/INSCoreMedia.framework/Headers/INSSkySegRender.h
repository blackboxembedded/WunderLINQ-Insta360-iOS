//
//  INSSkySegRender.h
//  INSCoreMedia
//
//  Created by Mac on 2021/6/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSPlayerImage;
// 优先级: 【error_code不为0表示失败或主动取消】 > 【finished为true表示成功完成】 > progress更新UI进度显示
// 原因: 需分割帧数由(fps * duration)估算，完成时的progress值未必恰好等于1，需结合finished判断
typedef void (^INSSkySegPreprocessingProgressCallback)(double progress, bool finished, int error_code);

@interface INSSkySegConfiguration : NSObject
/// 前景视频路径，【用于预处理】，720p即可
@property (nonatomic, nullable) NSURL *fgPath;
/// 缓存路径，存放特定前景的预处理结果（缩略图和分割mask），【无论预处理还是预览导出都必须配置】，不同的前景视频不能共享
/// 预处理向其写数据，渲染（预览和导出）从中读数据
/// 由调用者维护这个文件夹的创建、销毁；如果文件夹不存在会报错
@property (nonatomic) NSURL *cacheImageDir;

/// trim起始时间，【无论预处理还是预览导出都必须配置】
/// 每次改变都需要清空缓存目录并重新预处理
@property (nonatomic) double startTimeMs;
@property (nonatomic) double endTimeMs;

/// 背景视频路径，【用于预览和导出】
@property (nonatomic, nullable) NSURL *bgPath;
/// 进度回调，【用于预处理】
@property (nonatomic, nullable) INSSkySegPreprocessingProgressCallback progress;

@end

// 检测天空比例是否满足需求的工具类，建议每次检测任务都重新创建
@interface INSSkySegRatioChecker : NSObject
- (instancetype) initWithLock:(NSLock *)lock __attribute((deprecated ("Use the simple init instead.")));
// 手动传入insv展开后的2:1图片，和天空比例阈值ratioThresh，若这些时间戳对应天空比例>=阈值返回true，否则返回false
// playerImages分辨率只需超过512*256，在此前提下越低越好
- (bool) checkSkyRatio:(NSArray<INSPlayerImage*>*)playerImages WithThreshold:(double) thresh;
// 用户点击取消时，可以显式stop避免浪费算力
- (void) stop;

@end

@interface INSSkySegPreprocessor : NSObject
- (instancetype) initWithConfig:(INSSkySegConfiguration *)config Lock:(NSLock *)lock __attribute((deprecated ("Use the initWithConfig instead.")));
- (instancetype) initWithConfig:(INSSkySegConfiguration *)config;

- (bool) process;

- (void) stop;

@end


@interface INSSkySegRender : INSRender

// 天空不透明度，取值[0, 1]， 取0时完全为前景（用户拍摄素材）天空，取1时完全为后景（服务器分发特效视频）天空
@property (nonatomic) double skyAlpha;
// 环境色，取值[0, 1]， 取0时成片前景部分保持原始色调，取1时前景部分色调调整到与后景色调一致
@property (nonatomic) double colorAdjust;
// 传入初始化参数，成功返回nil，失败返回具体NSError
- (nullable NSError *) loadConfiguration:(INSSkySegConfiguration *)config;

@end

NS_ASSUME_NONNULL_END
