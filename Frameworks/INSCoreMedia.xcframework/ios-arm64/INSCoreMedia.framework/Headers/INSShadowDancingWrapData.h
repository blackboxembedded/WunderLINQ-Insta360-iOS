//
//  INSShadowDancingWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
static const int ShadowDancingCacheFlatRenderWidth = 1024;
static const int ShadowDancingCacheFlatRenderHeight = 512;

@class INSExporterInfo;
@class INSBgmClip;
@interface INSShadowDancingConfiguration : NSObject

/// 输入的素材是否是拼接好的素材；如果输入的是双鱼眼，则设置为NO；如果输入的是拼接好的全景图，则设置为YES；默认为NO
@property (nonatomic) BOOL isInputVideoFlat;

/// 缓存到磁盘的文件夹路径，必须配置，由调用者维护这个文件夹的创建、销毁；如果文件夹不存在会报错
@property (nonatomic) NSString *cacheImageDir;

/// 导出成片的exporter info，是flat 2:1的视频
@property (nonatomic) INSExporterInfo *outputExporterInfo;

/// 如果导出的视频添加bgm，则配置该项
@property (nonatomic, nullable) INSBgmClip *bgmClip;

/// 人像识别及导出预览2:1全景视频的的render宽度，默认为ShadowDancingCacheFlatRenderWidth
@property (nonatomic) int flatRenderWidth;

/// 人像识别及导出预览2:1全景视频的的render高度，默认为ShadowDancingCacheFlatRenderHeight
@property (nonatomic) int flatRenderHeight;

@end

NS_ASSUME_NONNULL_END
