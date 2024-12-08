//
//  INSFloatagePosition.h
//  INSTextVideo
//
//  Created by pengwx on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSFloatagePosition : NSObject

@property (nonatomic) int clipIndex;
@property (nonatomic) double clipSrcTimeMs;
@property (nonatomic) double clipMediaTimeMs;
@property (nonatomic) double mediaTimeMs;

- (instancetype) initWithClipIndex:(int)clipIndex clipSrcTimeMs:(double)clipSrcTimeMs mediaTimeMs:(double)mediaTimeMs;
- (instancetype) initWithClipIndex:(int)clipIndex clipSrcTimeMs:(double)clipSrcTimeMs clipMediaTimeMs:(double)clipMediaTimeMs mediaTimeMs:(double)mediaTimeMs;

- (BOOL) isEqual:(INSFloatagePosition*)position;

@end

NS_ASSUME_NONNULL_END
