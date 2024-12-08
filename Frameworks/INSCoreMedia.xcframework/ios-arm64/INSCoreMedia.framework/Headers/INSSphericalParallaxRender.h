//
//  INSSphericalParallaxRender.h
//  INSVideoPlayApp
//
//  Created by pwx on 29/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//


#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSScene;

@interface INSSphericalParallaxRender : INSRender

@property (nonatomic, strong) INSScene *scene;

@end

NS_ASSUME_NONNULL_END
