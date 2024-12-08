//
//  INSRenderExporter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/6/23.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSExporter.h"

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSOffscreenRender;
@class INSDataSources;
@protocol INSFloatageDrawProtocol;
@interface INSRenderExporter : INSExporter

- (instancetype) initWithDataSources:(INSDataSources*)dataSources exporterInfo:(INSExporterInfo*)exporterInfo render:(INSOffscreenRender*)render;

@property(nonatomic, strong) INSDataSources* dataSources;
@property(nonatomic, strong) INSExporterInfo *exporterInfo;
@property(nonatomic, strong, nullable) INSOffscreenRender *render;
@property(nonatomic, strong) id<INSFloatageDrawProtocol> floatageDraw;
@property(nonatomic) bool enableforceFps; // 强行指定exporterInfo中的fps，不允许导出库修改

@end

NS_ASSUME_NONNULL_END
