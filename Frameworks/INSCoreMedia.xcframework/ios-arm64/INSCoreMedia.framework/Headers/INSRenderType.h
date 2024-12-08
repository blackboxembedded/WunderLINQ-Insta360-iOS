//
//  INSRenderType.h
//  INSMediaApp
//
//  Created by pengwx on 5/10/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  陀螺仪和手势同时存在时的滑动交互方式
 */
typedef NS_ENUM(NSInteger, INSGyroSlipType) {
    INSGyroSlipTypeX,                               //X正方向滑动
    INSGyroSlipTypeInverseX,                        //X反方向滑动
    INSGyroSlipTypeY,                               //Y正方向滑动
    INSGyroSlipTypeInverseY,                        //Y反方向滑动
};

//画面交互模式
typedef NS_ENUM(NSInteger, INSViewInteractiveMode) {
    INSViewInteractiveModeFinger,                   //手指拖动模式，不允许翻转
    INSViewInteractiveModeGyro,                     //陀螺仪模式
    INSViewInteractiveModeFingerAndGyro,            //手指拖动 + 陀螺仪模式
    INSViewInteractiveModeFingerYaw,                //仅允许yaw（左右滑动）
    INSViewInteractiveModeFingerPitch,              //仅允许pitch（上下滑动）
    INSViewInteractiveModeFingerSurround,           //手指拖动模式，无方向限制
    INSViewInteractiveModeFingerSurroundAndGyro,
    INSViewInteractiveModeNone,                     //无交互，（即禁用View的手势操作）
    INSViewInteractiveModeFingerFlipped,            //手指拖动模式，允许垂直翻转
    INSViewInteractiveModeFingerFlippedPitch,       //手指拖动模式，允许垂直翻转, 值允许Pitch方向
} ;

//画面展示方式
typedef NS_ENUM(NSInteger, INSViewPresentMode){
    INSViewPresentModeSingle,                       //单屏模式
    INSViewPresentModeWidthDirectionDuplicate,      //宽度方向双屏
    INSViewPresentModeHeightDirectionDuplicate,     //高度方向双屏
} ;

//视图投影观看方式
typedef NS_ENUM(NSInteger, INSViewProjectionMode){
    INSViewProjectionModeFisheye,                   //鱼眼模式
    INSViewProjectionModeAsteroid,                  //小行星模式
    INSViewProjectionModePerspective,               //透视投影模式
    INSViewProjectionModeAsteroidRotation180,       //小行星模式，旋转180度
    INSViewProjectionModeCrystal,                   //水晶球模式
    INSViewProjectionModeCustom,                    //自定义模式，     此模式需要需要设置自定义视图投影观看方式的参数值才能够使用
} ;


//渲染器类型
typedef NS_ENUM(NSInteger, INSRenderType){
    INSRenderTypePreview,                           //相机预览流渲染器, 对应渲染器类型INSPreviewRender
    INSRenderTypeSphericalRender,                   //普通全景渲染器(已经展开为flat,mp4,jpg格式), 对应渲染器类型INSSphericalRender
    INSRenderTypeSphericalPanoRender,               //双圆全景渲染器(insv,insp格式)，对应渲染器类型INSSphericalPanoRender
    INSRenderTypeFlatPanoRender,                    //flat全景展开渲染器(insv,insp格式), 对应渲染器类型INSFlatPanoRender
    INSRenderTypeSphericalParallaxRender,           //3D 180渲染器(insv,insp格式), 对应渲染器类型INSSphericalParallaxRender
    INSRenderTypeParallaxPanoRender,                //3D 360全景渲染器(已经展开为上下两个flat,mp4,jpg格式), 对应渲染器类型INSParallaxPanoRender
    INSRenderTypeParallax180Horizontal,             //3D 180渲染器(已经展开为左右两个flat,mp4,jpg格式), 对应渲染器类型INSParallaxPanoRender, 使用相应的init函数
    INSRenderTypeNormal,                            //普通渲染器
    INSRenderTypeMultiviewPano,                     //双圆图像资源
    INSRenderTypeMultiviewFlat,                     //全景展开图像资源
    INSRenderTypeFlatGyroAdjust,                    //光流拼接后gyro校正
    INSRenderTypeTransform,                         //project转场
    INSRenderTypeVR180FlatPano,
    INSRenderTypeVR180SphericalPano,
    INSRenderTypeWidePano,                          //广角鱼眼， 对应于INSWidePanoRender
    INSRenderTypeDoubleAsteroid,                    //双重小行星
    INSRenderTypeSkyMirror,                         //天空融合
    INSRenderTypeFaceOff,                           //双人对看
    INSRenderTypeGiantAsteroid,                     //巨人小行星
    INSRenderTypeMultiScreen,                       //多屏渲染器，普通mp4
    INSRenderTypeSuperRecord,                       //快拍录像渲染器
    INSRenderTypeSkySeg,                            //天空分割
    INSRenderTypeRoboticArm,                        //机械臂
    INSRenderTypeRoadFlow,                          //车流拖影
    INSRenderTypeFlatPanoPreview,
} ;

typedef NS_ENUM(NSInteger, INSVR180FlatPanoType) {
    INSVR180FlatPanoTypeLeftCenter = 1,
    INSVR180FlatPanoTypeRightCenter = 2,
    INSVR180FlatPanoTypeLeftRight2x1 = 3,
};

typedef NS_ENUM(NSInteger, INSObjectGeometryLevel){
    INSObjectGeometryLevel50x100,
    INSObjectGeometryLevel25x50,
};

//自定义视图投影观看方式
typedef struct
{
    float yFov;                 //Y向Fov        单位：弧度
    float cameraMove;           //相机离球心距离
    float rotationX;            //X方向偏转角度   单位：弧度
    float rotationY;            //Y方向偏转角度   单位：弧度
    float rotationZ;            //Z方向偏转角度   单位：弧度
} INSCustomProjection;

//视图投影参数
typedef struct {
    float yFov;             //初始fov值
    float yFovMin;          //最小fov值
    float yFovMax;          //最大fov值
    float distance;         //camera离球心距离
    float distanceMin;      //camera离球心最小距离
    float distanceMax;      //camera离球心最大距离
    float pitch;            //x轴旋转角
    float yaw;              //y轴旋转角
    float roll;             //z轴旋转角
} STProjectionParam;
