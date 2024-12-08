//
//  INSJPGDenoise.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/30.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 每种INSJPGDenoiseImageType可处理的原图分辨率有要求，如果分辨率当前算法不支持，可能返回错误
 * 以下列出每种文件可用的分辨率
 * Leica: (5312, 2988) (5312, 3552)
 * Wide: (4000, 2250) (4000, 3000)
 * Fisheye: (6080, 3040) (3040, 3040)
 * Snapshot:  (3840, 2160),  (2160, 3840),  (4560, 1520),  (3840, 1634),  (2000, 2000)，(5760, 2880)
            (1920, 1080),  (1008, 1792),  (3240, 1080),  (2538, 1080),  (1280, 1280),
            (1620, 1080),  (1080, 1620),  (1440, 1080),  (1080, 1440), (1080, 1920)，(2916, 1080)，(3000, 2000),
            (2000, 3000),  (4000, 3000),  (3000, 4000)
 **/

typedef NS_ENUM(NSUInteger, INSJPGDenoiseImageType) {
    // leica
    INSJPGDenoiseImageTypeLeica = 0,
    // 广角
    INSJPGDenoiseImageTypeWide = 1,
    // 单鱼眼或双鱼眼
    INSJPGDenoiseImageTypeFisheye = 2,
    // 视频文件截图
    INSJPGDenoiseImageTypeVidSnapshot = 3,
    // 图片文件截图
    INSJPGDenoiseImageTypePicSnapshot = 4,
};

typedef NS_ENUM(NSUInteger, INSJPGDenoiseErrorCode) {
    INSJPGDenoiseErrorCodeParamInvalid = 0,
    INSJPGDenoiseErrorCodeDenoiseFailed = 1,
    INSJPGDenoiseErrorCodeImageData = 2,
    INSJPGDenoiseErrorCodeOpenCV = 3,
};

@interface INSJPGDenoise : NSObject

@property (nonatomic, readonly)INSJPGDenoiseImageType imageType;

- (instancetype)initWithImageType:(INSJPGDenoiseImageType)imageType;

- (nullable NSData *)denoiseWithImage:(NSData *)image
                                  iso:(int)iso
                                error:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
