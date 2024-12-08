//
//  INSCycleCloneWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCoreMedia/INSStitchingInfo.h"

NS_ASSUME_NONNULL_BEGIN
static const int CycleCloneCacheFlatRenderWidth = 3840;
static const int CycleCloneCacheFlatRenderHeight = 1920;

@class INSExporterInfo;
@class INSBgmClip;
@class INSOffscreenRender;
@interface INSCycleCloneWrapData : NSObject

@end
@interface INSCycleCloneConfiguration : NSObject

/// 是否使用磁盘cache， 默认为NO，设置为NO时，不会缓存帧，运算结果都在内存中进行；如果设置为YES，必须设置并创建cacheImageDir
@property (nonatomic) BOOL cacheImageMode;

/// 缓存到磁盘的文件夹路径，必须配置，由调用者维护这个文件夹的创建、销毁；如果文件夹不存在会报错
@property (nonatomic) NSString *cacheImageDir;

/// 导出成片的exporter info，是flat 2:1的视频
@property (nonatomic) INSExporterInfo *outputExporterInfo;

/// 拼接、消色差、防抖设置
@property (nonatomic) INSStitchType stitchType;
@property (nonatomic) BOOL colorFusion;
@property (nonatomic) BOOL enableRollingShutter;
/// render
@property (nonatomic, strong) INSOffscreenRender *render;

/// 获取静态防抖矩阵使用的时间戳，默认值为0
@property (nonatomic) int64_t gyroTimestampMs;

@end

NS_ASSUME_NONNULL_END
