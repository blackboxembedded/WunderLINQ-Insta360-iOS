//
//  INSAnimation.h
//  INSCoreMedia
//
//  Created by pengwx on 17/5/2.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSRender;
@class INSFrameListener;
@class INSAnimationState;

@interface INSAnimation : NSObject

@property (nonatomic, strong) INSAnimationState *beginState;
@property (nonatomic, strong) INSAnimationState *endState;
@property (nonatomic, copy) void(^complete)();

/**
 是否使用yFov, 默认YES, 为NO时使用xFov
 */
@property (nonatomic) BOOL isYFov;

- (INSFrameListener*_Nullable) getListener:(INSRender*)render;

@end

NS_ASSUME_NONNULL_END
