//
//  INSProjectionStrategy.h
//  INSMediaApp
//
//  Created by pengwx on 16/7/1.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSRenderType.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSProjectionStrategy : NSObject

/**
 初始化为小行星投影的参数

 @param width      渲染宽
 @param height      渲染高

 @return 实例化的对象
 */
- (instancetype) initAsteroidWithWidth:(float)width height:(float)height;

/**
 初始化函数

 @param projection 投影模式
 @param present    展示模式
 @param width      渲染宽
 @param height      渲染高

 @return 实例化的对象
 */
- (instancetype) initWithProjectionMode:(INSViewProjectionMode)projection presentMode:(INSViewPresentMode)present width:(float)width height:(float)height;

@property (nonatomic) float yFov;
@property (nonatomic) float yFovMin;
@property (nonatomic) float yFovMax;

@property (nonatomic) float distance;
@property (nonatomic) float distanceMin;
@property (nonatomic) float distanceMax;

@property (nonatomic) float eulerAngleX;
@property (nonatomic) float eulerAngleY;
@property (nonatomic) float eulerAngleZ;

@property (nonatomic) float scale;

//@property (nonatomic) float width;
//@property (nonatomic) float height;
/**
 旋屏时转换fov值
 @param yFov    转换前fov值, 单位：度数
 @param width   渲染宽
 @param height  渲染高
 @return  转换后的fov值
 */
+ (float) statusBarChangeOrientationYFov:(float)yFov width:(float)width heigh:(float)height;


/**
 *  计算球模型相切的distance
 *  @param r      球模型的半径
 *  @param width  渲染宽
 *  @param height 渲染高
 *  @param yFov   相机yFov
 *  @return 相机移动的距离
 */
+ (double) calculateTangencyDistanceWithSphereModelR:(float)r width:(float)width height:(float)height yFov:(float)yFov;

- (STProjectionParam) getViewProjectionParam;

@end


NS_ASSUME_NONNULL_END
