//
//  INSMediaSpeed.h
//  INSCoreMedia
//
//  Created by HFY on 2022/5/16.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaSpeed : NSObject <NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic, readonly) double timestamp;

@property (nonatomic, readonly) int value;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithTimestamp:(double)timestamp value:(int)value;

@end

NS_ASSUME_NONNULL_END
