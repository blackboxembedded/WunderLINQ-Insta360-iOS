//
//  INSPlayRateRange.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/21.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSPlayRateRange : NSObject<NSCoding>

- (instancetype) initWithPlayRate:(float)playRate beginTime:(int64_t)beginTime endTime:(int64_t)endTime;

@property (nonatomic) float playRate;
@property (nonatomic) int64_t beginTime;        //单位：ms
@property (nonatomic) int64_t endTime;          //单位：ms

@end

NS_ASSUME_NONNULL_END
