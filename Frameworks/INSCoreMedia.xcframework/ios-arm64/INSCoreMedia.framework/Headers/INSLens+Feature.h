//
//  INSLens+Feature.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/26.
//  Copyright © 2019 insta360. All rights reserved.
//



#import "INSLens.h"
#import <GLKit/GLKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface INSLens (Feature)

//获取矩阵
- (GLKMatrix4) getLensMatrix;

/**
 *  映射曲线
 *  @param angle 角度   （单位：弧度）
 *  @return 角度对应的半径R
 */
- (double) map:(double)angle;

- (double) radiusFromFov:(double)angle;

- (double) fovFromRadius:(double)radius;

//解一元四次方程,coeff[5]
+ (double) solveQuarticEquation:(double*)coeff min:(double)min max:(double)max;

/**
 输入一个半径长度，输出该半径对应的fov角度

 @param radiusMax offset中获取的radius(单位：像素， crop后)
 @param radius 输入的图像对角线长度的一半(单位：像素， crop后)
 @param lensType lensType
 @return 返回对应的source fov
 */
+ (double) fovWithRadiusMax:(float)radiusMax radius:(float)radius lensType:(int)lensType;


@end

NS_ASSUME_NONNULL_END
