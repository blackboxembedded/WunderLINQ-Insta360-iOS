//
//  INSSphericalFlatOffscreenRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/2/23.
//  Copyright © 2018年 insta360. All rights reserved.
//


#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSSphericalFlatOffscreenRender : INSOffscreenRender

/**
 *  以圆形方式初始化
 *  @param width   渲染生成的图片的宽度
 *  @param height  渲染生成的图片的高度
 *  @param minEdge 图形与左边缘或下边缘的最小距离
 *  @return 完成初始化后的INSSphericalOffscreenRenderOld对象
 */
- (instancetype) initCenterCircleWithWidth:(int)width height:(int)height minEdge:(int)minEdge;

@end

NS_ASSUME_NONNULL_END
