//
//  INSProjectionParam.h
//  INSMediaApp
//
//  Created by pengwx on 16/11/11.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCamera;

@interface INSProjectionParam : NSObject<NSCoding>


/// 初始化
/// @param xFov xfov值
/// @param distance distance值
/// @param ascpet 宽/高比例
-(instancetype)initWithXFov:(float)xFov distance:(float)distance aspect:(float)aspect;

- (instancetype) initWithCamera:(INSCamera*_Nullable)camera orientation:(GLKQuaternion)orientation origin:(GLKQuaternion)origin rotation:(GLKQuaternion)rotation;

- (instancetype) initWithCamera:(INSCamera*_Nullable)camera orientation:(GLKQuaternion)orientation origin:(GLKQuaternion)origin rotation:(GLKQuaternion)rotation preRoll:(GLfloat)preRoll;

@property (nonatomic, strong, nullable) INSCamera *camera;

//object3D
@property (nonatomic) GLKQuaternion orientation;                    //方向
@property (nonatomic) GLKQuaternion originOrientation;              //初始方向
@property (nonatomic) GLKQuaternion rotationOrientation;            //旋转方向
@property (nonatomic) GLfloat preRoll;                              //roll 方向的旋转量

- (INSProjectionParam*) copyValue;

@end

NS_ASSUME_NONNULL_END
