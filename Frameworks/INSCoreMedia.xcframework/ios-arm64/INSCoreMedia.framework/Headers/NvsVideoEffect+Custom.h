//
//  NvsVideoEffect+Custom.h
//  INSCoreMedia
//
//  Created by Mac on 2021/6/2.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <NvEffectSdkCore/NvsEffectRenderCore.h>
#import <NvEffectSdkCore/NvsEffectSdkContext.h>

NS_ASSUME_NONNULL_BEGIN

/// 必须设置进、出点，使滤镜特效能够支持进入和结束的时间点；当帧的时间戳在inPoint与outPoint之外时， 效果不生效；
@interface NvsVideoEffect (Custom)

/// 进入的时间点，视频的解码时间，单位微妙（为了与美摄sdk内部的单位统一）
@property (nonatomic) int64_t inPoint;

/// 结束的时间点，视频的解码时间，单位微妙（为了与美摄sdk内部的单位统一）
@property (nonatomic) int64_t outPoint;

@end

NS_ASSUME_NONNULL_END
