//
//  INSProjectExporter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/8/15.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSRenderExporter.h"
#import "INSProjectionConverter.h"
#import "INSExporterInfo.h"


NS_ASSUME_NONNULL_BEGIN

@class INSOffscreenRender;
@class INSTransformOffscreenRender;
@class INSMultipleInfo;
@class INSTimeRange;
@class INSUnderwaterInfo;
@protocol INSFloatageDrawProtocol;
@interface INSClipInfo : NSObject

@property (nonatomic) int clipIndex;
@property (nonatomic, strong, nullable) INSOffscreenRender* render;
@property (nonatomic, strong, nullable) INSTransformOffscreenRender* transformRender;
@property (nonatomic, strong, nullable) INSMultipleInfo *multipleInfo;
@property(nonatomic, strong, nullable) id<INSFloatageDrawProtocol> floatageDraw;
@property (nonatomic) BOOL enableMotionBlur;

/// 应用motionblur的时间范围，为nil时表示所有范围都应用
@property (nonatomic, strong, nullable)NSArray<INSTimeRange*> *motionBlurTimeRanges;

@property (nonatomic) BOOL enableDenoise;

/// 降噪级别，默认3.0，，值设置范围0-15.0,   当enableDenoise为YES生效
@property (nonatomic) float denoiseLevel;

/// 是否开启block降噪，默认NO
@property (nonatomic) BOOL enableBlockDenoise;
@property (nullable, nonatomic, strong) INSBlockDenoiseDataGenerator *blockDenoiseDataGenerator;

/// 是否开启super night，默认NO
@property (nonatomic) BOOL enableSuperNight;

//超级夜景降噪水平  默认值 3.0
@property (nonatomic)float superNightNoiseLevel;

///设置为YES时，慢速插帧时采用复制相同帧的方式来处理, 默认值NO
@property (nonatomic) BOOL enableTimeScaleCopySameFrame;

/// 是否开启卡通漫画效果，默认NO
@property (nonatomic)BOOL enableCartoon;

/// 是否开启水下色彩还原，默认NO
@property (nonatomic, strong, nullable)INSUnderwaterInfo *underwaterInfo;

/// 是否启用全景声, 默认NO
@property (nonatomic) BOOL enableSpatialAudio;

@end


@interface INSTransformRenderInfo : NSObject

@property (nonatomic) int cutClipIndex;
@property (nonatomic) double cutStartTime;
@property (nonatomic) double cutEndTime;

@end


@class INSProjectExporter;
@protocol INSProjectExporterDeletegate <NSObject>

/**
 将要渲染clip
 @param project project导出对象
 @param clipIndex clip索引序号
 @param transformInfo transform参数
 @return 返回clip的配置信息
 */
- (INSClipInfo*) project:(INSProjectExporter*)project willRenderNewClip:(int)clipIndex transformRenderInfo:(INSTransformRenderInfo* _Nullable)transformInfo;

@end


@interface INSProjectExporter : INSRenderExporter

- (instancetype) initWithDataSources:(INSDataSources*)dataSources exporterInfo:(INSExporterInfo*)exporterInfo;

@property (nonatomic, weak) id<INSProjectExporterDeletegate> delegate;

@end

NS_ASSUME_NONNULL_END
