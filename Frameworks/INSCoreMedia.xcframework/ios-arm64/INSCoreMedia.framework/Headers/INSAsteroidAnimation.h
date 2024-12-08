//
//  INSAsteroidAnimation.h
//  INSCoreMedia
//
//  Created by pengwx on 17/5/2.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSAnimation.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSAsteroidAnimation : INSAnimation


/**
 初始化函数, 此动画效果一直持续，无停止退出时间
 @param angle 每秒旋转角度（度），
 @return 实例化对象
 */
- (instancetype) initWithRotatioRate:(float)angle;

@end

NS_ASSUME_NONNULL_END
