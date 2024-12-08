//
//  INSGiantAsteroidRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/7/30.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSSphericalPanoRender.h"


NS_ASSUME_NONNULL_BEGIN

@class INSGiantShakeInfo;
@interface INSGiantAsteroidRender : INSSphericalPanoRender

/// 是否开启震动效果
@property(nonatomic, strong, nullable)INSGiantShakeInfo *shakeInfo;

/// 高度方向移动图像的比例, 默认值0.3
@property(nonatomic)double verticalMoveOfHeightScale;

@end

NS_ASSUME_NONNULL_END
