//
//  INSRenderManager.h
//  INSVideoPlayApp
//
//  Created by pwx on 24/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"
#import "INSInfo.h"

NS_ASSUME_NONNULL_BEGIN

@class INSRender;

@interface INSRenderManager : NSObject

//初始化函数
- (instancetype) initWithRender:(INSRender*)render;

//准备渲染
- (void) prepareRender;

//设置陀螺仪的开始方位
- (void) setGyroOrientation:(UIInterfaceOrientation)gyroOrientation;

@property (nonatomic, strong) INSRender *render;          //图形渲染器

/**
 *  画面交互模式，默认INSInteractiveModeFinger
 */
@property (nonatomic) INSViewInteractiveMode interactiveMode;

/**
 *  陀螺仪模式下手势滑动方式，X，Y坐标体系为View的坐标体系
 *  属性interactiveMode=INSViewInteractiveModeFingerAndGyro时，此属性值起作用
 */
@property (nonatomic) INSGyroSlipType gyroSlipType;

/**
 *  陀螺仪暂停
 */
@property (nonatomic) BOOL gyroPause;

/**
 物体方向
 */
@property (nonatomic) GLKQuaternion objectOrientation;

@property (nonatomic) GLKQuaternion panGestureOrientation;

/**
 是否可以分离陀螺仪垂直方向
 */
@property (nonatomic) BOOL enableSplitVerticalDirection;
@property (nonatomic) float targetPitchUp;
@property (nonatomic) float targetPitchDown;

/**
 分离垂直方向后，使用的设置比例（0-1）
 */
@property (nonatomic) float splitVerticalRatio;


/**
 roll方向是否可用，默认YES
 */
@property (nonatomic) BOOL enableGyroRoll;


/**
 yaw转动方向切换的临界值
 默认为nil，表示360方向环形转动，
 设置为double类型的弧度时，表示转动超过此角度后，会重置yaw方向, 一般配置为小于M_PI
 */
@property (nonatomic, nullable) NSNumber *yawSwitchCriticalValue;

@property (nonatomic, strong, nullable)INSSmoothInfo * smoothInfo;

@property(nonatomic)BOOL enableSmoothGesture;

@end

NS_ASSUME_NONNULL_END
