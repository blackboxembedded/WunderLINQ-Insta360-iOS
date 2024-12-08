//
//  INSFlatPanoPreviewRender.h
//  INSCoreMedia
//
//  Created by HFY on 2021/12/7.
//  Copyright © 2021 insta360. All rights reserved.
//


#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFlatPanoPreviewRender : INSRender

/// 背景色
@property(nonatomic)GLKVector4 backgroundColor;

///背景模糊， 默认NO
@property(nonatomic)BOOL backgroundBlur;

/// 2:1经纬图全景绘制区域，其中origin.x, size.width为实际大小与整个视图View的width的比例，origin.y, size.height为实际大小与整个视图View的height的比例，范围为0~1.0
@property(nonatomic)CGRect flatPanoFrame;


@end

NS_ASSUME_NONNULL_END
