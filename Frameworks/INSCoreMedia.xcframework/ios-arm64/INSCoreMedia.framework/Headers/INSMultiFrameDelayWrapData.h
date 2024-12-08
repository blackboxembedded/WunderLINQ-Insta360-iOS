//
//  INSMultiFrameDelayWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSBgmClip;
@interface INSMultiFrameDelayWrapData : NSObject

@end

typedef NS_ENUM (NSInteger, INSMultiFrameDelayCacheType) {
    INSMultiFrameDelayCacheType48 = 0,
    INSMultiFrameDelayCacheType54 = 1,
    INSMultiFrameDelayCacheType64 = 2,
    INSMultiFrameDelayCacheType80 = 3,
    INSMultiFrameDelayCacheType96 = 4,
};

@interface INSMultiFrameDelayConfiguration : NSObject

/*
 
 info->url
 info->cacheBaseUrl
 info->videoWidth;
 info->videoHeight;
 info->bitrate;
 info->fps;
 info->useX264Encoder;
 info->videoType
 */

/// 输入的素材是否是拼接好的素材；如果输入的是双鱼眼，则设置为NO；如果输入的是拼接好的全景图，则设置为YES；默认为NO
@property (nonatomic) BOOL isInputVideoFlat;


/// 成片从原始视频的startFrameTimeMs开始
@property (nonatomic) double startFrameTimeMs;

/// 成片从原始视频的endFrameTimeMs结束
@property (nonatomic) double endFrameTimeMs;

/// 默认为INSMultiFrameDelayCacheType80
@property (nonatomic) INSMultiFrameDelayCacheType cacheType;

/// 是否使用磁盘cache， 默认为NO，设置为NO时，不会缓存帧，运算结果都在内存中进行；如果设置为YES，必须设置并创建cacheImageDir
@property (nonatomic) BOOL cacheImageMode;

/// 缓存到磁盘的文件夹路径，必须配置，由调用者维护这个文件夹的创建、销毁；如果文件夹不存在会报错
@property (nonatomic) NSString *cacheImageDir;

/// 导出成片的exporter info，是flat 2:1的视频
@property (nonatomic) INSExporterInfo *outputExporterInfo;

/// 如果导出的视频添加bgm，则配置该项，目前算法使用的weight = 1 ，repeat = true这两个属性是固定的，这里是为了确认bgm的url和开始时间
@property (nonatomic, nullable) INSBgmClip *bgmClip;

/// 只跑算法，不生成视频，默认为NO
@property (nonatomic) BOOL discardExportVideo;

@end

NS_ASSUME_NONNULL_END
