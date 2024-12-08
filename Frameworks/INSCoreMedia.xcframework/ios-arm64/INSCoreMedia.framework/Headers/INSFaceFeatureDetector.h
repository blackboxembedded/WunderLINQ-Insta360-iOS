//
//  INSFaceFeatureDetector.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/18.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSFaceDetectEngineConfig;
@class INSFaceInfo;
@interface INSFaceFeature : NSObject

/// 人脸置信度
@property(nonatomic)float confidence;

@end

@interface INSFaceFeatureDetector : NSObject

/// 使用默认参数，识别人脸信息，等价于调用[self initWithConfig:nil]
- (instancetype)init;

/// 通过参数传递人脸识别的阈值信息，可以根据需要调整结果
/// @param config 传入nil则使用默认值
- (nullable instancetype) initWithConfig:(INSFaceDetectEngineConfig * _Nullable)config;


/// 识别是否有人脸而已，废弃
/// @param pixelBuffer 渲染后，待识别的图像
/// @param timestampMs 时间戳
- (nullable NSArray<INSFaceFeature*>*)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs DEPRECATED_MSG_ATTRIBUTE("Please use -analyzePixelBuffer: or -analyzeUIImage:");


/// 识别人脸信息
/// @param pixelBuffer 渲染后，待识别人脸属性的图像
- (nullable NSArray<INSFaceInfo *> *)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer;


/// 识别人脸信息
/// @param image UIImage
- (nullable NSArray<INSFaceInfo *> *)analyzeUIImage:(UIImage *)image;

/// 识别人脸信息
/// @param pixelBuffer 渲染后，待识别人脸属性的图像
/// @param fileName 原始图像的文件名，可用于调试
- (nullable NSArray<INSFaceInfo *> *)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer fileName:(NSString * _Nullable)fileName;


/// 识别人脸信息
/// @param image UIImage
/// @param fileName 原始图像的文件名，可用于调试
- (nullable NSArray<INSFaceInfo *> *)analyzeUIImage:(UIImage *)image fileName:(NSString * _Nullable)fileName;

@end

NS_ASSUME_NONNULL_END
