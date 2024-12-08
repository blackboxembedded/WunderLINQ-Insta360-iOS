//
//  INSAnimationRecorder.h
//  INSCoreMedia
//
//  Created by Mac on 2021/3/10.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"



NS_ASSUME_NONNULL_BEGIN

@class INSProjectionInfo;
@class INSMediaPos;
@protocol INSPlugableAnimation <NSObject>
@required

- (BOOL)serializable;

- (INSProjectionInfo *)fetchAnimatedProjection:(INSMediaPos*)mediaPos;

@end


@interface INSAnimationRecorder : INSScreenRecorder

@property (nonatomic, readonly) BOOL serializable;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAnimation:(id<INSPlugableAnimation >)animation startTimestamp:(double)startTimestamp endTimestamp:(double)endTimestamp;

- (id)getAnimation;

- (void)setAnimation:(id<INSPlugableAnimation >)animation;

@end

NS_ASSUME_NONNULL_END
