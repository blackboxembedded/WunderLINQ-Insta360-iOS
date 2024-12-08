//
//  INSGyroPBPlayer+Tools.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <INSCoreMedia/INSCoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSLookUpCameraDirection) {
    INSLookUpCameraDirectionFront = 0,
    INSLookUpCameraDirectionBack,
    INSLookUpCameraDirectionTop,
    INSLookUpCameraDirectionBottom,
    INSLookUpCameraDirectionLeft,
    INSLookUpCameraDirectionRight,
};

@class INSMediaGyro;
@interface INSGyroPBPlayer (Tools)

/// 获取朝上时所占的时间比例，来决定是否需要采用directional防抖，-1.0则为无效
/// @param thresh 算法给出的默认值0.45 * M_PI
- (double)calcLookUpDurationRateWithThresh:(double)thresh cameraDirection:(INSLookUpCameraDirection)cameraDirection;

/// 相机的旋转方向，单位：弧度.
/// @param offset 当前资源的offset
- (float)calcCameraRollWithOffset:(NSString *)offset;


/// 单个陀螺仪数据获取防抖矩阵
/// @param mediaGyro 文件为获取的单个陀螺仪数据
/// @param gyroDataType 根据镜头类型设定
/// @param renderType render type
+ (GLKQuaternion)calcQuaternionWithMediaGyro:(INSMediaGyro *)mediaGyro
                                gyroDataType:(INSGyroDataType)gyroDataType
                                  renderType:(INSRenderType)renderType;

@end

NS_ASSUME_NONNULL_END
