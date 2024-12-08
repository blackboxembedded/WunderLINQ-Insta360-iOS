//
//  INSDoubleAsteroidOffscreenRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/5/27.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSMultipleConverter;
@interface INSDoubleAsteroidOffscreenRender : INSOffscreenRender

/// 内外小行星分割圆的半径,  取宽高中最短那一条边的比例， 默认值：1/4
@property(nonatomic)float circleRadiusRatio;

@property(nonatomic, strong, nullable) INSMultipleConverter *insideAsteroidConverter;
@property(nonatomic, strong, nullable) INSMultipleConverter *outsideAsteroidConverter;

@end

NS_ASSUME_NONNULL_END


