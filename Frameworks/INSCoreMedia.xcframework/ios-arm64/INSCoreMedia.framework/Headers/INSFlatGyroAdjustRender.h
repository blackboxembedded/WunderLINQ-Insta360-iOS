//
//  INSFlatGyroAdjustRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/3/4.
//  Copyright © 2018年 insta360. All rights reserved.
//


#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFlatGyroAdjustRender : INSRender

/**
 是否允许手指滑动，默认NO
 */
@property (nonatomic) BOOL enableFingerSliding;

/// 全景图片需要裁减掉的边缘，单位:弧度，默认值UIEdgeInsetsZero
@property (nonatomic)UIEdgeInsets cropEdgeInset;

/// 背景色
@property(nonatomic)GLKVector4 backgroundColor;

@end

NS_ASSUME_NONNULL_END
