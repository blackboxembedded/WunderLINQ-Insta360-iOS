//
//  INSOffsetCalculator.h
//  INSCoreMedia
//
//  Created by zeng bin on 8/1/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>
#import "INSPlayerImage.h"

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCoreMediaAutoStitchError) {
    INSCoreMediaAutoStitchErrorFindCircle,
    INSCoreMediaAutoStitchErrorGenerateOffset,
    INSCoreMediaAutoStitchErrorCalibrateOffset,
    INSCoreMediaAutoStitchErrorOldOffset,
};

typedef NS_ENUM(NSUInteger, INSOffsetConvertType) {
    //normal to one 120fps
    INSOffsetConvertTypeOneNormal_2_120Fps = 0,
    //one 120 fps to normal
    INSOffsetConvertTypeOne120Fps_2_Normal,
    //one bgr to raw
    INSOffsetConvertTypeOneBGR_2_RAW,
    //one raw to bgr
    INSOffsetConvertTypeOneRAW_2_BGR,
    //one normal to one waterproof
    INSOffsetConvertTypeOne_2_Waterproof,
    
    //onex normal to onex waterproof
    INSOffsetConvertTypeOneX_2_Waterproof,
    //onex noraml to onex diving in water
    INSOffsetConvertTypeOneX_2_DivingWater,
    //onex noraml to onex diving in air
    INSOffsetConvertTypeOneX_2_DivingAir,
    //onex normal to 100fps
    INSOffsetConvertTypeOneX1520_2_1504,
    //onex 100fps to normal
    INSOffsetConvertTypeOneX1504_2_1520,
    //window crop 3040 to 2880
    INSOffsetConvertTypeOneX3040_2_2880,
    //window crop 2880 to 3040
    INSOffsetConvertTypeOneX2880_2_3040,
    
    //ONER\RS fisheye and raw
    INSOffsetConvertTypeOneRFisheye_2_RAW,
    INSOffsetConvertTypeOneRRAW_2_Fisheye,
    //ONER\RS fisheye 577\283 lens normal mode and selfie mode offset(可以实现两者互相转换)
    INSOffsetConvertTypeOneRWideAngle_2_Selfie,
    //ONER wide 577 lens normal mode and selfie mode offset
    INSOffsetConvertTypeOneR577Fisheye_2_Selfie,
    //ONER（RS only actually） wide 283 lens normal mode and selfie mode offset
    INSOffsetConvertTypeOneR283Fisheye_2_Selfie,
    
    //ONER\RS fisheye 577 normal to 潜水壳（水上）
    INSOffsetConvertTypeOneRFisheye_2_DivingAir,
    //ONER\RS fisheye 577 normal to 潜水壳（水下）
    INSOffsetConvertTypeOneRFisheye_2_DivingWater,
    //ONER\RS fisheye 577 normal to 保护镜（卡扣式弧面镜）
    INSOffsetConvertTypeOneRFisheye_2_Protect,
    //ONER\RS fisheye 577 normal to 保护镜（黏贴式球面镜）
    INSOffsetConvertTypeOneRFisheye_2_SphereProtect,
    //ONER\RS fisheye 577 normal to 保护镜（FPV）
    INSOffsetConvertTypeOneRFisheye_2_X2Protect,
    
    //ONERS fisheye 283 normal to 保护镜（卡扣式弧面镜）
    INSOffsetConvertTypeOneRSFisheye_2_Protect,
    
    //ONEXS fisheye and raw
    INSOffsetConvertTypeOneXSFisheye_2_RAW,
    INSOffsetConvertTypeOneXSRAW_2_Fisheye,
    //ONEXS fisheye normal to 潜水壳（水上）
    INSOffsetConvertTypeOneXSFisheye_2_DivingAir,
    //ONEXS UnSupport type
    INSOffsetConvertTypeOneXSFisheye_2_SphereDivingAir,
    //ONEXS fisheye normal to 潜水壳（水下）
    INSOffsetConvertTypeOneXSFisheye_2_DivingWater,
    //ONEXS UnSupport type
    INSOffsetConvertTypeOneXSFisheye_2_SphereDivingWater,
    //ONEXS fisheye normal to 保护镜（卡扣式弧面镜）
    INSOffsetConvertTypeOneXSFisheye_2_Protect,
    //ONEXS fisheye normal to 保护镜（黏贴式球面镜）
    INSOffsetConvertTypeOneXSFisheye_2_SphereProtect,
    
    //ONEX3 fisheye normal to 保护镜（黏贴式球面镜）  ONEX3_2_SPHEREPROTECT
    INSOffsetConvertTypeOneX3Fisheye_2_SphereProtect,
    //ONEX3 fisheye normal to 潜水壳ONEX3_2_DIVING_WATER(水下)
    INSOffsetConvertTypeOneX3Fisheye_2_SphereDivingWater,
    //ONEX3 fisheye normal to 潜水壳 ONEX3_2_DIVING_AIR(水上)
    INSOffsetConvertTypeOneX3Fisheye_2_SphereDivingAir,
    
    INSOffsetConvertTypeToOffsetV1,
    INSOffsetConvertTypeToOffsetV2,
    INSOffsetConvertTypeToOffsetV3,
    
    //ONEX3 4:1 and half_Fisheye
    INSOffsetConvertTypeOneX3HalfFisheye_4to1,
};

@interface INSOffsetCalculator : NSObject

/// offset 版本
@property (nonatomic, readonly) NSInteger version;

/// 镜头类型
@property (nonatomic, readonly) NSInteger lensType;

/// 是否重新找圆
@property (nonatomic) BOOL findCircle;

/// 旧的offset
@property (nullable, nonatomic) NSString *oldOffset;

/// 旧的offset 的分数，每次process 成功后会更新
@property (nonatomic, readonly) float oldScore;

/// 新的offset，每次process 成功后会更新
@property (nullable, nonatomic, readonly) NSString *offset;

/// 新的offset 的分数，每次process 成功后会更新
@property (nonatomic, readonly) float score;

///是否计算得分，默认为YES，设置为NO是不会计算offset的score
@property (nonatomic) BOOL isCalculateScore;

///是否设置了option fixed的参数，目前调用相关的init方法才为YES，此时需在计算之前传入oldOffset
@property (nonatomic, readonly) BOOL isFixedOptionSettled;

- (instancetype)initWithVersion:(NSInteger)version lensType:(NSInteger)lensType;

- (instancetype)initWithOldOffset:(NSString *)offset;

/**
 优化拼接与拼接矫正时，用该方法初始化，重新计算offset时可选择固定相关参数——center，radius，extrinc
 全景拼接优化：true false true
 全景拼接矫正：false false false
 PS. VR180拼接优化：true true false
 */
- (instancetype)initWithOldOffset:(NSString *)offset optionCenter:(BOOL)centerFixed optionRadius:(BOOL)radiusFixed optionExtrinc:(BOOL)extrincFixed;

- (void)processPixelBuffers:(CVPixelBufferRef  _Nonnull *_Nonnull)pixelBuffers
                      count:(size_t)bufferCount
                      error:(NSError * _Nullable * _Nullable)pError;

- (void)processImages:(NSArray <UIImage *>*)images
                error:(NSError * _Nullable * _Nullable)pError;

- (void)processPlayerImages:(NSArray <INSPlayerImage *>*)playerImages
                error:(NSError * _Nullable * _Nullable)pError;

//- (void)calibrateOffsetWithImages:(NSArray<UIImage *> *)images
//                      checkImages:(NSArray<UIImage *> *)checkImages
//                         complete:(nonnull void (^)(NSError * _Nullable error, NSString * _Nullable originalOffset, NSString * _Nullable offset))completion;

+ (NSString*)compareOffset1:(NSString*)offset1
                    offset2:(NSString*)offset2
               pixelBuffers:(CVPixelBufferRef  _Nonnull *_Nonnull)pixelBuffers
                      count:(size_t)bufferCount;

+ (NSString*)compareOffset1:(NSString*)offset1
                    offset2:(NSString*)offset2
                     images:(NSArray <UIImage *>*)images;

+ (float)calculateOffsetScore:(NSString*)offset
               pixelBuffers:(CVPixelBufferRef  _Nonnull *_Nonnull)pixelBuffers
                      count:(size_t)bufferCount;

+ (float)calculateOffsetScore:(NSString*)offset
                     images:(NSArray <UIImage *>*)images;

+ (NSString *)convertOffset:(NSString * _Nonnull)offset
                     toType:(INSOffsetConvertType)type;

+ (NSString *)cropOffset:(NSString * _Nonnull)offset
                srcWidth:(int)srcWidth
               srcHeight:(int)srcHeight
                dstWidth:(int)dstWidth
               dstHeight:(int)dstHeight
                 xOffset:(int)xOffset
                 yOffset:(int)yOffset;


/// 比较offset效果, 返回效果较好的offset
/// @param offsets offset数据，offset顺序优先级遵循  正常offset > 防水壳offset > 潜水壳水下 offset
/// @param images 比较图片
/// @param useModel 是否使用模型文件去辅助识别
/// @param onerVerticalBattery 是否是oner竖拍电池的素材，非oner填写false，oner机型如实填写
+ (NSString *)compareOffsets:(NSArray<NSString *> *)offsets
                      images:(NSArray<UIImage *> *)images
                    useModel:(BOOL)useModel
         onerVerticalBattery:(BOOL)onerVerticalBattery;

/// 比较offset效果, 返回效果较好的offset
/// @param offsets offset数据，offset顺序优先级遵循  正常offset > 防水壳offset > 潜水壳水下 offset
/// @param pixelBuffers  比较图片
/// @param bufferCount 图片数量
/// @param useModel 是否使用模型文件去辅助识别
/// @param onerVerticalBattery 是否是oner竖拍电池的素材，非oner填写false，oner机型如实填写
+ (NSString *)compareOffsets:(NSArray<NSString *> *)offsets
                pixelBuffers:(CVPixelBufferRef  _Nonnull *_Nonnull)pixelBuffers
                       count:(size_t)bufferCount
                    useModel:(BOOL)useModel
         onerVerticalBattery:(BOOL)onerVerticalBattery;

/// 比较offset效果, 返回效果较好的offset
/// @param offsets offset数据，offset顺序优先级遵循  正常offset > 防水壳offset > 潜水壳水下 offset
/// @param playerImages 比较图片
/// @param useModel 是否使用模型文件去辅助识别
/// @param onerVerticalBattery 是否是oner竖拍电池的素材，非oner填写false，oner机型如实填写
+ (NSString *)compareOffsets:(NSArray<NSString *> *)offsets
                playerImages:(NSArray<INSPlayerImage *> *)playerImages
                    useModel:(BOOL)useModel
         onerVerticalBattery:(BOOL)onerVerticalBattery;

/**
 校正offset
 @param offset 旧的offset
 @param image 图像
 @return 校正后的offset, 失败返回nil
 */
+ (NSString *_Nullable)calibrateVR180Offset:(NSString*)offset image:(UIImage*)image;
+ (NSString *_Nullable)calibrateVR180Offset:(NSString*)offset pixelBuffer:(CVPixelBufferRef)pixelBuffer;

//将正反镜头offset1，offset2合并成一个完整offset，失败返回nil
+(NSString *_Nullable)mergeSubOffset:(NSString*)offset1 offset2:(NSString*)offset2;

// patch for RS 586: calculate a new offset mixing with offsetv1 and offsetv2.
+(NSString *_Nullable)mixOffsetWithOffsetV1:(NSString *)offsetv1 offsetv2:(NSString *)offsetv2 offsetv3:(NSString *)offsetv3;
@end

NS_ASSUME_NONNULL_END
