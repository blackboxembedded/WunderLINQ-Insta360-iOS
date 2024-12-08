//
//  INSMediaHighlight+Orientation.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/10/30.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSMediaHighlight.h"
#import <GLKit/GLKit.h>
#import "INSExtraMetadata.h"

NS_ASSUME_NONNULL_BEGIN

@class INSGyroPlayer;
@interface INSMediaHighlight (Orientation)

-(GLKQuaternion)lens1FrontOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer;
-(GLKQuaternion)lens2FrontOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer;
-(GLKQuaternion)lensTopOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer;

+(GLKQuaternion)lens1FrontOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;
+(GLKQuaternion)lens2FrontOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;
+(GLKQuaternion)lensTopOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;
+(GLKQuaternion)lensBottomOrientationWithGyroPlyaer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;
//当屏幕指向拍摄者时，相机机身的左侧
+(GLKQuaternion)lensLeftOrientationWithgyroPlayer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;
//当屏幕指向拍摄者时，相机机身的右侧
+(GLKQuaternion)lensRightOrientationWithGyroPlyaer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;

// 永远指向机身底部
+(GLKQuaternion)lensBottomOrientationWithgyroPlayerWithRoll:(INSGyroPlayer *)gyroPlayer timestamp:(double)timestamp;

+ (GLKQuaternion)lensRawOrientationWithgyroPlayer:(INSGyroPlayer *)gyroPlayer timestamp:(double)timestamp;

+ (GLKQuaternion)lensTopOrientationWithgyroPlayerWithRoll:(INSGyroPlayer *)gyroPlayer timestamp:(double)timestamp;

+(INSCameraPosture)cameraPostureWithGyroPlyaer:(INSGyroPlayer*)gyroPlayer timestamp:(double)timestamp;

+(GLKQuaternion)lens1FrontOrientationWithGyroOrientation:(GLKQuaternion)gyroOrientation;
+(GLKQuaternion)lens2FrontOrientationWithGyroOrientation:(GLKQuaternion)gyroOrientation;


/// 判断两个四元数，是否对应的orientation近似相等
/// @param quaternion param
/// @param quaternion param
/// @param precision precision in angle
+(BOOL)quaternion:(GLKQuaternion)quaternion1 isEqualTo:(GLKQuaternion)quaternion2 precision:(float)precision;

+(float)angleBetweenOrientation:(GLKQuaternion)orientation1 orientation:(GLKQuaternion)orientation2;

@end

NS_ASSUME_NONNULL_END
