//
//  INSTrim.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTrim : NSObject<NSCoding>

- (instancetype) initWithLeftTime:(int64_t)leftTime rightTime:(int64_t)rightTime;

@property (nonatomic) int64_t leftTime;      //开始时间，单位：ms
@property (nonatomic) int64_t rightTime;     //截止时间，单位：ms

@end

NS_ASSUME_NONNULL_END
