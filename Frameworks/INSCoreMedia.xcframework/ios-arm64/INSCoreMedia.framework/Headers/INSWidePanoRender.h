//
//  INSWidePanoRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSRender.h"
#import "INSNormalRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSSphericalPanoRender;
@class INSProjectionConverter;
@interface INSWidePanoRender : INSRender

@property(nonatomic, strong, readonly)INSSphericalPanoRender *panoRender;
@property(nonatomic, strong, nullable)INSProjectionConverter *panoConverter;

/// panoRender渲染的  width / height     默认1.0
@property(nonatomic)float panoAspect;

/**
 默认值为INSContentModeScaleToFill
 */
@property (nonatomic) INSContentMode contentMode;

/**
 * 美摄效果添加到PanoRender层: 渲染球画面->球上图像作为美摄效果输入->放到normalrender上填充高斯模糊
 * 否则，添加到NormalRender层: 渲染球画面->放到normalrender上填充高斯模糊->添加模糊后的整体作为美摄的输入
 * 默认为NO
 */
@property (nonatomic) BOOL addNvEffectOnPanoRender;

/**
 默认值为(0.0, 0.0, 0.0, 1.0)
 */
@property (nonatomic) GLKVector4 contentBackgroundColor;

///背景填充方案，默认值INSBackgroundModeColor
@property (nonatomic) INSBackgroundMode backgroundMode;

@property (nonatomic, readonly) CGRect contentRect;

/// 视频帧的尺寸，实际为videoFrameWidth\videoFrameHeight
@property (nonatomic) int contentWidth;
@property (nonatomic) int contentHeight;

@end

NS_ASSUME_NONNULL_END
