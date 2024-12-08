//
//  INSParallaxPanoRender.h
//  spherical360
//
//  Created by pengwx on 3/24/16.
//  Copyright © 2016 insta360. All rights reserved.
//


#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSScene;

@interface INSParallaxPanoRender : INSRender

/**
 *  生成INSRenderTypeParallax180Horizontal类型的Render
 *  @param width    渲染宽
 *  @param height   渲染高
 *  @param drawable
 *  @return render对象
 */
- (instancetype) init180HorizontalWithRenderWidth:(int)width renderHeight:(int)height context:(EAGLContext*)context target:(INSRenderTarget*)target;


@property (nonatomic, strong) INSScene *scene;

@property (nonatomic) BOOL swapEye;

@end

NS_ASSUME_NONNULL_END
