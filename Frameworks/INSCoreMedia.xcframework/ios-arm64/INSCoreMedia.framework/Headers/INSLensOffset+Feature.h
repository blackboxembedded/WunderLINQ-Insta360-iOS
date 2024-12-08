//
//  INSLensOffset+Feature.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/26.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSLensOffset.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSLensOffset (Feature)

/**
 返回原始视频fov

 @param cropWidth 视频crop后宽
 @param cropHeight 视频crop后高
 @return source fov
 */
- (double)sourceFovWithCropWidth:(uint32_t)cropWidth cropHeihgt:(uint32_t)cropHeight;

@end

NS_ASSUME_NONNULL_END
