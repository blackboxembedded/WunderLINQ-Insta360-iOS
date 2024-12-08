//
//  INSSequenceExporter.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/6/12.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSExporter.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSBgmClip;

@class INSSequenceExporter;
@protocol INSSequenceExporterDelegate <NSObject>

-(CVPixelBufferRef _Nullable)sequenceExporter:(INSSequenceExporter*)exporter totalFrameCount:(int)totalCount currentIndex:(int)currentIndex;

@end

@interface INSSequenceExporter : INSExporter

- (instancetype) initWithExportTotalFrameCount:(int)totalCount bgmClip:(INSBgmClip*_Nullable)bgmClip exporterInfo:(INSExporterInfo*)exporterInfo DEPRECATED_MSG_ATTRIBUTE("sourceVideoURL and sourceVideoMediaFileSize is needed.");

/// constructor
/// @param totalCount 数量
/// @param bgmClip 背景音乐
/// @param exporterInfo 导出配置
/// @param sourceVideoURL 原始**视频**素材地址，对于图片素材，传nil即可
/// @param sourceVideoMediaFileSize 视频文件媒体部分的大小，图片传0即可
- (instancetype) initWithExportTotalFrameCount:(int)totalCount bgmClip:(INSBgmClip * _Nullable)bgmClip exporterInfo:(INSExporterInfo*)exporterInfo sourceVideoURL:(NSURL * _Nullable)sourceVideoURL sourceVideoMediaFileSize:(int64_t)sourceVideoMediaFileSize;

@property(nonatomic) int totalFrameCount;
@property(nonatomic) NSURL *sourceVideoURL;
@property(nonatomic) int64_t sourceVideoMediaFileSize;
@property(nonatomic, strong, nullable) INSBgmClip *bgmClip;
@property(nonatomic, strong) INSExporterInfo *exporterInfo;
@property(nonatomic, weak)id<INSSequenceExporterDelegate> delegate;

// 是否优先使用709，默认为NO，按照sourceVideoURL解析的结果为准；
// 为YES时，则无论sourceVideoURL解析结果，在硬件支持的情况下，都尽量使用709颜色空间导出
@property(nonatomic) BOOL colorSpace709Preferred;

@end


NS_ASSUME_NONNULL_END
