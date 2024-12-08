//
//  INSGyroType.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/16.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, INSGyroPlayMode) {
    //默认
    INSGyroPlayModeDefault = 0,
    
    //关闭防抖
    INSGyroPlayModeNone = 1,
    
    //正常防抖, keep view still
    INSGyroPlayModeNormal = 2,
    
    //移除yaw方向的防抖, 用于directional lock, view can only move arround z-axis (pan move)
    INSGyroPlayModeRemoveYawRotations = 3,
    
    //强制聚焦于中心, 用于子弹时间类的防抖
    INSGyroPlayModeFocusedToCameraBaseRotation = 4,
    
    //校准地平线 (roll方向旋转，地平线不变), view can only move arround z-axis an y-axis (pan&tilte)
    INSGyroPlayModeLiteView = 5,
    
    //弃用，会转为全防
    INSGyroPlayModeDiffRemoveYawRotations = 6,
    
    //不校准地平线, 即free-footage, total free camera mode, camera can move through three axis
    INSGyroPlayModeFootageMotionSmooth,
    
    //开防抖、开水平矫正，即full-direcional
    INSGyroPlayModeFreeFulldirectional,
    
    //开防抖、平均姿态矫正，即relative-refine
    INSGyroPlayModeAutoGravity,
    
    //开防抖、开水平矫正，即absulute-refine
    INSGyroPlayModeAbsuluteHorizonRefine,
    
    //处理翻转
    INSGyroPlayModeFlipEffect,
    
    //使用一个全局的矩阵来作为每一帧的防抖矩阵, 用来矫正方向，没有更精确的防抖效果
    INSGyroPlayModeMainRotation,
    
    //使用一个全局的矩阵来作为每一帧的防抖矩阵，在INSGyroPlayModeMainRotation多加了一个roll的旋转量；关防抖、开水平矫正，Go2在用
    INSGyroPlayModeAlignCenter,
    
    
};

