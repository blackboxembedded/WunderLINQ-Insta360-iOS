//
//  INSTimeRange.h
//  INSCoreMedia
//
//  Created by HFY on 2020/3/27.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTimeRange : NSObject<NSCoding, NSCopying, NSMutableCopying>

-(instancetype)initWithPostionMs:(double)positionMs durationMs:(double)durationMs;
-(BOOL)hitTime:(double)timestamp;

@property(nonatomic)double positionMs;
@property(nonatomic)double durationMs;

@end

NS_ASSUME_NONNULL_END
