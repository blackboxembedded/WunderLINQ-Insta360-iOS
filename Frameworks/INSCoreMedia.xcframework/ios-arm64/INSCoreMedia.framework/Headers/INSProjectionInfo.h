//
//  INSProjectionInfo.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/6/30.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSProjectionInfo : NSObject<NSCopying, NSCoding>

@property (nonatomic) float xFov;
@property (nonatomic) float distance;
@property (nonatomic) float preRoll;
@property (nonatomic) GLKQuaternion orientation;

@end

NS_ASSUME_NONNULL_END
