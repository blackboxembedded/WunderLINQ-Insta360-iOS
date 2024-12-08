//
//  INSRational.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/11/23.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSRational : NSObject

- (instancetype) initWithNum:(int)num den:(int)den;

/**
 分子Numerator
 */
@property (nonatomic) int num;

/**
 分母Denominator
 */
@property (nonatomic) int den;

@end

NS_ASSUME_NONNULL_END
