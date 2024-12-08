//
//  INSAnimationState.h
//  INSCoreMedia
//
//  Created by pengwx on 17/5/2.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface INSAnimationState : NSObject

@property (nonatomic) float fov;
@property (nonatomic) float distance;
@property (nonatomic) float pitch;
@property (nonatomic) float yaw;
@property (nonatomic) float roll;

@end

NS_ASSUME_NONNULL_END
