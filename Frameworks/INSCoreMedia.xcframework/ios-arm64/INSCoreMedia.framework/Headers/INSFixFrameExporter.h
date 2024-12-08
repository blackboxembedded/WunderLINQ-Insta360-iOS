//
//  INSFixFrameExporter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/18.
//  Copyright © 2018年 insta360. All rights reserved.
//


#import "INSRenderExporter.h"

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSOffscreenRender;
@class INSDataSources;
@class INSMultipleInfo;
@interface INSFixFrameExporter : INSRenderExporter

- (instancetype) initWithDataSources:(INSDataSources*)dataSources exporterInfo:(INSExporterInfo*)exporterInfo render:(INSOffscreenRender*)render multipleInfo:(INSMultipleInfo*)multipleInfo;

@property (nonatomic, strong) INSMultipleInfo *multipleInfo;

@end

NS_ASSUME_NONNULL_END

