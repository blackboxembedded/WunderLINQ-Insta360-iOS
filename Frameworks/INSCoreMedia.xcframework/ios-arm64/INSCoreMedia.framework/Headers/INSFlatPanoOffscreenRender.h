//
//  INSFlatPanoOffscreenRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/2/23.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFlatPanoOffscreenRender : INSOffscreenRender

@property (nonatomic) BOOL enableFingerSliding;

/// 全景图片需要裁减掉的边缘，单位:弧度，默认值UIEdgeInsetsZero
@property (nonatomic)UIEdgeInsets cropEdgeInset;

@end

NS_ASSUME_NONNULL_END
