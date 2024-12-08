//
//  INSGyroPBPlayer+Image.h
//  INSCoreMedia
//
//  Created by yons on 5.1.21.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSGyroPBPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroPBPlayer (Image)
/// 默认获取时间戳为0下的防抖矩阵
/// @param renderType rendertype
- (GLKQuaternion) getImageOrientationWithRenderType:(INSRenderType)renderType;


/// 获取任意时间戳下的防抖矩阵，这个时间戳需要是解码时间戳，也即文件尾记录的时间戳 - firstFrameTimestamp
/// @param renderType render type
/// @param timestamp timestamp in ms
- (GLKQuaternion) getImageOrientationWithRenderType:(INSRenderType)renderType timestamp:(int64_t)timestamp;

@end

NS_ASSUME_NONNULL_END
