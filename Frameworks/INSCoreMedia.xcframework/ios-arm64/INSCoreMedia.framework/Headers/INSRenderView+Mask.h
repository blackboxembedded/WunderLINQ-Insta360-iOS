//
//  INSRenderView+Mask.h
//  INSMediaApp
//
//  Created by pengwx on 16/12/1.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import "INSRenderView.h"
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMask;
@class INSMaskRes;
@class INSMaskInfo;


@interface INSRenderView (Mask)


/**
 添加INSMask对象
 @param info INSMaskInfo参数
 @return 添加到3D场景中的INSMask对象
 */
- (INSMask*_Nullable) addMaskWithMaskInfo:(INSMaskInfo*)info;

/**
 添加INSMask对象
 @param point 视图view的坐标点
 @param angle INSMask的大小, 单位角度
 @param res 生成mask所用的资源
 @return 添加到3D场景中的INSMask对象
 */
- (INSMask*_Nullable) addMaskWithViewPoint:(CGPoint)point size:(float)angle resource:(INSMaskRes*)res;

/**
 移除指定的INSMask对象
 @param mask 需要移除的INSMask对象
 */
- (void) removeMask:(INSMask*)mask;

/**
 移除所有的INSMask对象
 */
- (void) removeAllMask;

/**
 移动mask到顶层
 @param mask 需要移动到顶层的对象
 */
- (void) moveMaskToTop:(INSMask*)mask;

/**
 获取给定视图view的坐标点下最上层的INSMask对象
 @param point 视图view的坐标点
 @return INSMask对象
 */
- (INSMask*_Nullable) getTopsideMaskWithViewPoint:(CGPoint)point;

/**
 获取所有的INSMask对象
 @return INSMask对象数组
 */- (NSArray*_Nullable) getAllMask;

/**
 获取给定视图view的坐标点下所有的INSMask对象
 @param point 视图view的坐标点
 @return INSMask对象数组
 */
- (NSArray*_Nullable) getAllMaskWithViewPoint:(CGPoint)point;

/**
 获取mask在编辑视图中位置信息
 @param mask 需要获取位置信息的mask
 @param center mask在view上的中心点位置，坐标系为view视图的坐标系
 @param size mask在view上的大小
 @return center在view的可见范围内为YES，否则为NO
 */
- (BOOL) getMaskEditPosition:(INSMask*)mask centerInView:(CGPoint*)center size:(CGSize*)size;

/**
 设置mask在编辑视图中的位置信息
 @param mask 需要设置位置信息的mask
 @param center mask在view上的中心点位置，坐标系为view视图的坐标系
 @return 设置成功为YES， 否则为NO
 */
- (BOOL) setMaskEditPosition:(INSMask*)mask centerInView:(CGPoint)center;

/**
 获取mask在编辑视图中的旋转方向
 @param mask 需要获取旋转方向的mask
 @return 旋转的方向，单位：弧度
 */
- (CGFloat) getMaskEditRotation:(INSMask*)mask;

/**
 设置mask在编辑视图中的旋转方向
 @param rotation 旋转的方向，单位：弧度
 @param mask 需要设置旋转方向的mask
 */
- (void) setMaskEditRotation:(CGFloat)rotation mask:(INSMask*)mask;

- (BOOL) viewPoint:(CGPoint)viewPoint toRawImagePoint:(CGPoint*)imagePoint;
- (INSMask*_Nullable) addMaskWithFlatImagePoint:(CGPoint)point rotation:(float)rotation size:(float)angle resource:(INSMaskRes *)res;


@end


NS_ASSUME_NONNULL_END
