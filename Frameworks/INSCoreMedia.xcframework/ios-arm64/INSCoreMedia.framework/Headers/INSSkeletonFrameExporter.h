//
//  INSSkeletonFrameExporter.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/9.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSRenderExporter.h"

NS_ASSUME_NONNULL_BEGIN

@class INSExporterInfo;
@class INSOffscreenRender;
@class INSDataSources;
@class INSSkeletonRecommendInfo;

@interface INSSkeletonFrameExporter : INSRenderExporter

- (nullable instancetype) initWithDataSources:(INSDataSources *)dataSource exporterInfo:(INSExporterInfo *)exporterInfo render:(INSOffscreenRender *)render skeletonRecommendInfo:(INSSkeletonRecommendInfo *)skeletonInfo srcDurationMs:(int64_t)srcDurationMs;

@property (nonatomic, readonly) INSSkeletonRecommendInfo* skeletonInfo;

@property (nonatomic, readonly) int64_t srcDurationMs;

@end

NS_ASSUME_NONNULL_END
