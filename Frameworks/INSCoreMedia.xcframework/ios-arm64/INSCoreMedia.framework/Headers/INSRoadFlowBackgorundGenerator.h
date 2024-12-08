//
//  INSRoadFlowBackgorundGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2022/6/2.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class INSAppletVideoInfo;
@class INSExporterInfo;
@class INSPlayerImage;

@interface INSRoadFlowBackgorundGeneratorConfiguration : NSObject
@property (nonatomic) int width;    // 输入视频帧的宽
@property (nonatomic) int height;   // 输入视频帧的高
@property (nonatomic) int frameNum; // 输入视频的估算帧数（parser.framerate * parser.duration）
/// 拖影参数，有默认值
@property (nonatomic) bool isPreview; // 预览置为true，bcv使用耗时低效果略差的算法；导出反之。
/// 导出成片的exporter info，是普通mp4
@property (nonatomic) INSExporterInfo *outputExporterInfo;
@end


@interface INSRoadFlowBackgorundGenerator : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype) initWithConfiguration:(INSRoadFlowBackgorundGeneratorConfiguration *)configuration;
- (nullable NSError *) feedFrame:(INSPlayerImage *)playerImage;
- (nullable NSError *) finish;

@end

NS_ASSUME_NONNULL_END
