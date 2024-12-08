//
//  INSFileClipPos.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/3.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMediaPos;
@interface INSFileClipPos : NSObject<NSCoding>

- (instancetype) initWithIndex:(int)index srcTimeMs:(double)srcTime srcProgressTimeMs:(double)srcProgressTime srcRepeatTimeMs:(double)srcRepeatTimeMs;

/**
 序号
 用以标识当前clip在clip队列中的序号，从0开始
 */
@property (nonatomic, readonly) int index;


/**
 音视频的原始时间点 src time
 */
@property (nonatomic, readonly) double srcTimeMs;


/// 音视频的原始时间点被重复的时间
@property (nonatomic, readonly)double srcRepeatTimeMs;

/**
 音视频的原始时间点，逻辑计算上使用的，有可能超出实际的音视频的时间范围
 */
@property (nonatomic, readonly) double srcProgressTimeMs;


/// 原始时间戳对应的位置，值跟srcTimeMs与srcRepeatTimeMs相同
@property(nonatomic, readonly)INSMediaPos *srcTimePos;

@end

NS_ASSUME_NONNULL_END
