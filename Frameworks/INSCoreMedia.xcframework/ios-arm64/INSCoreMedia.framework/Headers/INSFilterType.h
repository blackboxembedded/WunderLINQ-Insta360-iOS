//
//  INSFilterType.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/5.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, INSFilterType) {
    INSFilterTypeNull,                  //无滤镜
    //beautify
    INSFilterTypeBeautify1,
    INSFilterTypeBeautify2,
    INSFilterTypeBeautify3,
    INSFilterTypeBeautify4,
    INSFilterTypeBeautify5,
    
    //GPUImage
    INSFilterTypeMissEtikate,           //3
    
    
    //FW
    INSFilterTypeNashville,
    INSFilterTypeLordKelvin,
    INSFilterTypeAmaro,
    INSFilterTypeRise,                  //7
    INSFilterTypeHudson,                //8
    INSFilterType1977,                  //10
    INSFilterTypeWalden,                //12
    INSFilterTypeLomofi,                //13
    INSFilterTypeHefe,                  //20
    INSFilterTypeXproII,                //9
    INSFilterTypeInkwell,               //14
    INSFilterTypeSierra,                //15
    INSFilterTypeEarlybird,             //16
    INSFilterTypeSutro,                 //17
    //android
    INSFilterTypeValencia,              //11
    INSFilterTypeToaster,               //18
    INSFilterTypeBrannan,               //19
    //factory app
    INSFilterTypeGray,                  //灰度
    INSFilterTypeSobelEdge,             //
    INSFilterTypeSketch,                //素描
    
    INSFilterTypeSharpen,               //锐度
    
    //Log
    INSFilterType3DLutOff,              //关闭lut 28
    INSFilterType3DLut,                 //开启lut 29
    
    //INSFilterTypeLutP1 to INSFilterTypeLutUN4 为第一代lut滤镜，都可用INSFilterTypeLutStyle确认
    INSFilterTypeLutP1,              //人像
    INSFilterTypeLutP2,
    INSFilterTypeLutP3,
    INSFilterTypeLutP4,
    INSFilterTypeLutP5,
    INSFilterTypeLutCT1,             //冷色调
    INSFilterTypeLutCT2,
    INSFilterTypeLutWT1,             //暖色调
    INSFilterTypeLutWT2,
    INSFilterTypeLutWT3,
    INSFilterTypeLutN1,              //自然
    INSFilterTypeLutN2,
    INSFilterTypeLutN3,
    INSFilterTypeLutN4,
    INSFilterTypeLutA1,              //运动
    INSFilterTypeLutA2,
    INSFilterTypeLutA3,
    INSFilterTypeLutA4,
    INSFilterTypeLutUD1,             //都市
    INSFilterTypeLutUD2,
    INSFilterTypeLutUD3,
    INSFilterTypeLutUN1,
    INSFilterTypeLutUN2,
    INSFilterTypeLutUN3,
    INSFilterTypeLutUN4,
    
    
    INSFilterTypeMirrorX,          // Deprecated
    //
    INSFilterTypeConvolution,
    //
    INSFilterTypeMax,
    INSFilterTypeTiltShiftBlur,
    INSFilterTypeTiltShiftBlurMultiple,
    
    INSFilterTypeLutStyle,
};
