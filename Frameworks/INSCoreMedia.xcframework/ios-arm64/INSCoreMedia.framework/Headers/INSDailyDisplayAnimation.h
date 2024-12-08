//
//  INSDailyDisplayAnimation.h
//  INSCoreMedia
//
//  Created by pengwx on 17/5/2.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSAnimation.h"

NS_ASSUME_NONNULL_BEGIN

@class INSAnimationState;

@interface INSDailyDisplayAnimation : INSAnimation


/**
 初始化函数
 @param beginState 动画初始状态, 当为nil时表示，以当前画面的状态作为起始状态
 @param endState 动画结束状态
 @param duration 动画持续时间
 @return 实例对象
 */
- (instancetype) initWithBeginState:(INSAnimationState*_Nullable)beginState endState:(INSAnimationState*)endState duration:(double)duration;

@end

NS_ASSUME_NONNULL_END
