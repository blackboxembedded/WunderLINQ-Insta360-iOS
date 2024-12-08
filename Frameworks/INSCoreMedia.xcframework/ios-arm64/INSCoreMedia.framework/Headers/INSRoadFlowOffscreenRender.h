//
//  INSRoadFlowOffscreenRender.h
//  INSCoreMedia
//
//  Created by Mac on 2021/9/29.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSRoadFlowRenderConfiguration;

@interface INSRoadFlowOffscreenRender : INSOffscreenRender

// 属性和函数说明见INSRoadFlowRender.h
- (nullable NSError *) loadConfiguration:(INSRoadFlowRenderConfiguration *)config;

@end

NS_ASSUME_NONNULL_END
