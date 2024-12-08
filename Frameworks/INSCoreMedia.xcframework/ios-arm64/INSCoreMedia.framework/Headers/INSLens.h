//
//  INSLens.h
//  INSVideoPlayApp
//
//  Created by pwx on 7/12/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSLens : NSObject{
    double coeff[5];
}

@property (nonatomic, assign) float centerX;
@property (nonatomic, assign) float centerY;
@property (nonatomic, assign) float centerR;
@property (nonatomic, assign) float yaw;
@property (nonatomic, assign) float pitch;
@property (nonatomic, assign) float roll;

@property (nonatomic, assign) int originW;
@property (nonatomic, assign) int originH;

@property (nonatomic, readonly) int code;               //镜头号
@property (nonatomic, readonly) float fov;              //fov
@property (nonatomic, readonly) float blendAngle;       //融合角度（目前未更改好）


- (void) getParam:(float*)param;



/**
 *  比较镜头lens的参数是否相等
 *  @param lens 镜头
 *  @param diff 比较差值，在此范围内float类型看做相等
 *  @return 镜头有效且相等返回YES，无效或不等返回NO
 */
- (BOOL) isEqualLens:(INSLens*)lens diff:(float)diff;

/**
 *  创建镜头
 *  @param code 镜头代码
 *  @return 返回对应的镜头类
 */
+ (INSLens*_Nullable) lensWithCode:(int)code;

/**
 *  比较镜头lens1和lens2参数是否相等
 *  @param lens1 镜头1
 *  @param lens2 镜头2
 *  @param diff 比较差值，在此范围内float类型看做相等
 *  @return 镜头有效且相等返回YES，无效或不等返回NO
 */
+ (BOOL) compareLens:(INSLens*)lens1 another:(INSLens*)lens2 diff:(float)diff;


@end

NS_ASSUME_NONNULL_END
