//
//  INSNormalOffscreenRender.h
//  INSCoreMedia
//
//  Created by kahn on 2018/8/8.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"
#import "INSNormalRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSNormalOffscreenRender : INSOffscreenRender

/**
 默认值为INSContentModeScaleToFill
 */
@property (nonatomic) INSContentMode contentMode;


/**
 默认值为(0.0, 0.0, 0.0, 1.0)
 */
@property (nonatomic) GLKVector4 contentBackgroundColor;


/**
 相机的旋转方向，单位：弧度
 */
@property(nonatomic)float cameraRoll;


/// 是否使用视频metadata（图片exif）中的旋转量,  默认YES
@property(nonatomic)BOOL useMetadataRotation;


@end


NS_ASSUME_NONNULL_END
