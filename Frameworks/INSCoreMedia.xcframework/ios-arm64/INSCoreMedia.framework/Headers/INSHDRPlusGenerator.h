//
//  INSHDRPlusGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/1/1.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSHDRPlusGeneratorError) {
    INSHDRPlusGeneratorErrorUnDefinedDngs = -4001,
    INSHDRPlusGeneratorErrorNoJpg = -4002,
    INSHDRPlusGeneratorErrorLoadTinyDNG = -4003,
    INSHDRPlusGeneratorErrorOpenCV = -4004,
};

@interface INSHDRPlusGenerator : NSObject


/// 每次输入一张dng图片路径
/// @param imagePath dng图片路径
/// @param error error
- (void)processWithImagePath:(NSString *)imagePath error:(NSError * _Nullable * _Nullable)error;

/// 所有图片经过process之后，调用该方法输出经过处理的jpg到指定路径
/// @param jpgPath 输出路径
/// @param error error
- (void)outputJPGImageToPath:(NSString *)jpgPath error:(NSError * _Nullable * _Nullable)error;


/// 取消操作，异步线程调用
- (void)cancel;

/// 暂时不支持
///- (void)outputDNGImageToPath:(NSString *)dngPath error:(NSError * _Nullable * _Nullable)error;


/// dng file to jpg
/// @param dngPath dngPath
/// @param jpgPath out jpg path
/// @param error error
+ (void)convertDng:(NSString *)dngPath toJpg:(NSString *)jpgPath error:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
