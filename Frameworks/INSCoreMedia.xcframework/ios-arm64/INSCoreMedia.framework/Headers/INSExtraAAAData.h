//
//  INSExtraAAAData.h
//  INSCoreMedia
//
//  Created by HFY on 2019/8/30.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSMediaAAA.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSExtraAAAData : NSObject
/**
 *  所有AAA信息二进制数据
 */
@property (nullable, nonatomic, readonly) NSData *aaaData;


/**
 ISO信息提取结果，{timestamp:isoValue},timestamp单位为毫秒，与解码时间序列相同（可能有几帧的误差）
 */
@property (nullable, nonatomic, readonly) NSArray<INSMediaAAA *> *aaaArray;


/**
 3A数据序列第一帧的时间戳。INSMediaAAA中的时间戳是经过时间戳转换的，如果需要求得AAA数据原时间戳，需要INSMediaAAA.timestamp + timeOffset
 */
@property (nonatomic, readonly) int64_t timeOffset;

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithAAAData:(NSData *)aaaData;

- (nullable instancetype)initWithAAAArray:(NSArray<INSMediaAAA *> *)aaaArray;

@end

NS_ASSUME_NONNULL_END
