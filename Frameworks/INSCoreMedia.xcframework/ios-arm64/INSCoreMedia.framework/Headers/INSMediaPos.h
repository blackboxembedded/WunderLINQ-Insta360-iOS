//
//  INSMediaPos.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/9/8.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface INSMediaPos : NSObject<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initWithSrcTimeMs:(double)srcTimeMs;
- (instancetype) initWithSrcTimeMs:(double)srcTimeMs repeatSrcTimeMs:(double)repeatSrcTimeMs srcProgressTimeMs:(double)srcProgressTimeMs;
- (instancetype) initWithSrcTimeMs:(double)srcTimeMs repeatSrcTimeMs:(double)repeatSrcTimeMs srcProgressTimeMs:(double)srcProgressTimeMs clipIndex:(double)clipIndex;

@property (nonatomic, readonly) double srcTimeMs;
@property (nonatomic, readonly) double repeatSrcTimeMs;

@property (nonatomic, readonly) double srcProgressTimeMs;
@property (nonatomic, readonly) int clipIndex;

-(BOOL)lessThan:(INSMediaPos*)pos;
-(BOOL)greaterThan:(INSMediaPos*)pos;
-(BOOL)equalTo:(INSMediaPos*)pos;

@end

NS_ASSUME_NONNULL_END
