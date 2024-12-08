//
//  INSMediaGyro+Feature.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/27.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSMediaGyro.h"
#import <GLKit/GLKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface INSMediaGyro (Feature)


/**
 *  获取由gyro数据转换成的四元数
 *  @return 四元数
 */
- (GLKQuaternion) getRotateQuaternion;

@end

NS_ASSUME_NONNULL_END
