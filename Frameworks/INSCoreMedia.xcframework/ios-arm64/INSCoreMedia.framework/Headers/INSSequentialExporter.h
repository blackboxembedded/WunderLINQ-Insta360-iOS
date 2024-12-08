//
//  INSSequentialExporter.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/27.
//  Copyright © 2019 insta360. All rights reserved.
//


#import "INSExporter.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSBgmClip;

@class INSSequentialExporter;
@protocol INSSequentialExporterDelegate <NSObject>

-(BOOL)isEOF;
-(CVPixelBufferRef _Nullable)sequentialExporter:(INSSequentialExporter*)exporter currentIndex:(int)currentIndex;

@end

@interface INSSequentialExporter : INSExporter

- (instancetype) initWithEstimateDurationMs:(int64_t)estimateDuration bgmClip:(INSBgmClip*_Nullable)bgmClip exporterInfo:(INSExporterInfo*)exporterInfo DEPRECATED_MSG_ATTRIBUTE("sourceVideoURL and sourceVideoMediaFileSize is needed.");

/// constructor
/// @param estimateDuration 预估导出成片时长
/// @param bgmClip 背景音乐
/// @param exporterInfo 导出配置
/// @param sourceVideoURL 原始**视频**素材地址，对于图片素材，传nil即可；如果帧来自多个源文件，则传入第一个文件的URL
/// @param sourceVideoMediaFileSize 视频文件媒体部分的大小，图片传0即可
- (instancetype) initWithEstimateDurationMs:(int64_t)estimateDuration bgmClip:(INSBgmClip * _Nullable)bgmClip exporterInfo:(INSExporterInfo *)exporterInfo sourceVideoURL:(NSURL * _Nullable)sourceVideoURL sourceVideoMediaFileSize:(int64_t)sourceVideoMediaFileSize;


@property(nonatomic) int64_t estimateDuration;
@property(nonatomic) int timescaleFactor;
@property(nonatomic) NSURL *sourceVideoURL;
@property(nonatomic) int64_t sourceVideoMediaFileSize;
@property(nonatomic, strong, nullable) INSBgmClip *bgmClip;
@property(nonatomic, strong) INSExporterInfo *exporterInfo;
@property(nonatomic, weak)id<INSSequentialExporterDelegate> delegate;

// 是否优先使用709，默认为NO，按照sourceVideoURL内部解析的结果为准；为YES时，则无论sourceVideoURL解析结果，在硬件支持的情况下，都尽量使用709颜色空间导出
@property(nonatomic) BOOL colorSpace709Preferred;

@end


NS_ASSUME_NONNULL_END
