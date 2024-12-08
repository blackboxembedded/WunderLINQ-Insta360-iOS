//
//  INSLensOffset.h
//  INSVideoPlayApp
//
//  Created by pwx on 7/12/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, INSLensType){
    INSLensTypeUnknown = 0,
    INSLensTypeC = 2,
    INSLensTypeNewLite = 3,
    INSLensTypeOne = 13,
    INSLensTypePhilips = 14,
    INSLensTypeLite = 15,
    INSLensTypeNanoS = 16,
    INSLensTypeOneWaterproof = 17,
    INSLensTypePanoClip_2 = 23,
    
    INSLensTypeOne2 =  19,
    INSLensTypeOneXDivingWater = 24,
    INSLensTypeOneXWaterproof = 27,
    INSLensTypeOneXDivingAir = 29,
    
    INSLensTypeGo = 30,
    
    INSLensTypeEVO = 32,
    
    
    INSLensTypeOneR577Wide = 34,
    INSLensTypeOneR283Wide = 35,
    INSLensTypeOneR586Wide = 58,
    INSLensTypeOneR577Pano = 33,
    INSLensTypeOneR577PanoDiving = 38,
    INSLensTypeOneR577PanoDivingWater = 40,
    INSLensTypeOneR577PanoProtect = 39,
    INSLensTypeOneR577PanoX2Protect = 51,
    INSLensTypeOneR577PanoSphereProtect = 59,
    
    INSLensTypeOneX2 = 41,
    INSLensTypeOneX2DrivingWater = 43,
    INSLensTypeOneX2SphereDrivingWater = 53,
    INSLensTypeOneX2DrivingAir = 44,
    INSLensTypeOneX2SphereDrivingAir = 54,
    INSLensTypeOneX2Protect = 52,
    INSLensTypeOneX2SphereProtect = 42,
    
    INSLensTypeOneH = 45,
    INSLensTypeGo2 = 50,
    INSLensTypeOneRS577Wide = INSLensTypeOneR577Wide,
    INSLensTypeOneRS577Pano = INSLensTypeOneR577Pano,
    INSLensTypeOneRS283Wide = INSLensTypeOneR283Wide,
    INSLensTypeOneRS283FishEye = 62,
    INSLensTypeOneRS586Pantilt = 63,
    INSLensTypeOneRS283Protect = 64,
    INSLensTypeOneRS586Wide = INSLensTypeOneR586Wide,
    INSLensTypeOneRS586WideAlias74 = 74,
    INSLensTypeOneRS586WideAlias75 = 75,
    INSLensTypeOneX3586PanoLianChuang = 70,
    INSLensTypeOneX3586PanoHongJing = 71,
    INSLensTypeOneX3586HongJingProtect = 77,
    INSLensTypeOneX3586HongJingDrivingWater = 78,
    INSLensTypeOneX3586HongJingDrivingAir = 79,
    
};

typedef NS_ENUM(NSInteger, INSOffsetVision){
    INSOffsetVisionC1 = 4,              //nano
    INSOffsetVisionC2 = 5,              //one 
    INSOffsetVisionC3 = 9,              //one 2
    INSOffsetVisionC4 = 11,             //CAM_3D
};

NS_ASSUME_NONNULL_BEGIN

@interface INSLensOffset : NSObject

- (instancetype) initWithOffset:(NSString*)offset;

//获取镜头
- (NSArray*_Nullable) getLens;

/**
 *  与offset比较是否相等
 *  @param offset offset值
 *  @param diff   比较差值，在此范围内float类型看做相等
 *  @return offset有效且相等返回YES，无效或不等返回NO
 */
- (BOOL) isEqualOffset:(NSString*)offset diff:(float)diff;


/**
 *  监测offset是否有效
 *  @param offset 相机offset
 *  @return 有效offset返回YES，无效返回NO
 */
+ (BOOL) isValidOffset:(NSString*)offset;

/**
 *  比较offset1和offset2参数是否相等
 *  @param offset1 offset1值
 *  @param offset2 offset2值
 *  @param diff    比较差值，在此范围内float类型看做相等
 *  @return offset有效且相等返回YES，无效或不等返回NO
 */
+ (BOOL) compareOffset:(NSString*)offset1 another:(NSString*)offset2 diff:(float)diff;


/**
 *  检测offset对应镜头类型
 *
 *  @param offset offset
 *  @return 镜头类型
 */
+ (INSLensType)lensTypeWithOffset:(NSString *)offset;


@property (nonatomic) BOOL isValid;                     //判断镜头是否有效
@property (nonatomic, assign) int fisheyeClipAngle;     //镜头融合使用的剪切角
@property (nonatomic, assign) int lensType;             //镜头类型
@property (nonatomic, assign) int offsetVersion;        //offset版本信息



@end

NS_ASSUME_NONNULL_END
