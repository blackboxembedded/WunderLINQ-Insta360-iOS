//
//  INSMediaAAA.h
//  INSCoreMedia
//
//  Created by HFY on 2019/8/30.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaAAA : NSObject<NSCopying, NSMutableCopying>

// 时间戳 ms
@property (nonatomic) int64_t timestamp;

// ISO值
@property (nonatomic) uint32_t isoValue;

// WB中的色温
@property (nonatomic) uint32_t wbCtValue;

// WB中rg
@property (nonatomic) uint32_t wbRgValue;

// WB中bg
@property (nonatomic) uint32_t wbBgValue;

// 某个曲线的index，用于数据统计
@property (nonatomic) uint8_t toneIndex;

// ev值
@property (nonatomic) float evValue;

// 快门时间 ms
@property (nonatomic) float shutterValue;

@end

NS_ASSUME_NONNULL_END
