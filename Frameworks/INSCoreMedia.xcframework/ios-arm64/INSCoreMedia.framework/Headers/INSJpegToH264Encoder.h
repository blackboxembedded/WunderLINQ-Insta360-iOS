//
//  INSJpegToH264Encoder.h
//  INSCoreMedia
//
//  Created by Mac on 2021/5/26.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSJpegToH264EncoderConfiguration : NSObject

/// 设置为YES， 如果只编码单帧
@property (nonatomic) BOOL singleFrame;

/// 目标h264的帧的宽
@property (nonatomic) int h264Width;

/// 目标h264的帧的高
@property (nonatomic) int h264Height;

/// 解码帧序列的fps，算法会根据fps对质量作优化
@property (nonatomic) double preferredFPS;

@property (nonatomic, nullable) NSString *debugDir;

@end

@interface INSJpegToH264Encoder : NSObject

/// 输入一张原始的图片文件，编码为H264一帧数据， 如果失败，会返回nil，且抛出error
/// @param filePath 用于编码的原始图片的路径
/// @param error error
- (nullable NSData *)encodeWithSourceFilePath:(NSString *)filePath
                                configuration:(INSJpegToH264EncoderConfiguration *)configuration
                                        error:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
