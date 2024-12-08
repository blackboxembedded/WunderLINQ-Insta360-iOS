//
//  INSSkySegOffscreenRender.h
//  INSCoreMedia
//
//  Created by Mac on 2021/9/29.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSSkySegConfiguration;

@interface INSSkySegOffscreenRender : INSOffscreenRender

// 属性和函数说明见INSSkySegRender.h
@property (nonatomic) double skyAlpha;
@property (nonatomic) double colorAdjust;
- (nullable NSError *) loadConfiguration:(INSSkySegConfiguration *)config;

@end

NS_ASSUME_NONNULL_END
