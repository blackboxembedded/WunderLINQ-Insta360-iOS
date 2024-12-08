//
//  UIImage+INSMediaSDK.h
//  INSMediaApp
//
//  Created by pengwx on 16/7/28.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (INSMediaSDK)

/**
 *  将图片保存到手机
 *  @param fileName 文件名称
 */
- (void) saveImageToFile:(NSString*)fileName;

/**
 *  将CVPixelBufferRef图像转换为UIImage
 *  @param pixelBuffer 输入图像 BGRA格式
 *  @return RGBA图片
 */
+ (UIImage*) imageWithPixelBuffer:(CVPixelBufferRef)pixelBuffer;

+ (UIImage*) imageWithPixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightRixelBuffer;

+ (UIImage*) imageWithImage:(UIImage*)left rightImage:(UIImage*)right;

+ (UIImage*) imageWithPixelBuffer:(CVPixelBufferRef)pixelBuffer context:(CIContext*)context;
+ (UIImage*) imageWithPixelBuffer:(CVPixelBufferRef)pixelBuffer context:(CIContext*)context size:(CGSize)size;
/**
 *  将RGBA的位图数据转为UIImage
 *  @param width  图片宽
 *  @param height 图片高
 *  @param data   像素数据
 *  @param ignore 转换时是否忽略alpha数据
 *  @return RGBA图片
 */
+ (UIImage*__nullable) imageWithBitmapWidth:(int)width height:(int)height RGBAData:(NSData*)data ignoreAlpha:(BOOL)ignore;


/**
 使用opencv对图片进行双边滤波处理(如果编译选项关闭了opencv库的编译，那么此函数将不会起效果)
 @param image 待处理图片
 @param d 模糊的直径, 为非零值
 @return 处理完成后图片
 */
+ (UIImage*) bilateralFilterUseOpencv:(UIImage*)image diameter:(int)d;


/**
 将图片转为位图数据
 @param image 原始图像
 @return 位图数据
 */
+ (NSData*) transformImageToBitmapData:(UIImage*)image;

@end


NS_ASSUME_NONNULL_END
