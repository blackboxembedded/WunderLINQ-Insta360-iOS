//
//  INSDirectionProcessor.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/3.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;

@interface INSDirectionProcessor : NSObject

@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic, readonly) NSString *offset;

/**
 生成对象，offset和gyroPlayer为必须，内部会做检查，如果参数不合法，会返回nil

 @param offset 镜头offset信息
 @param gyroPlayer 当前素材使用的防抖器
 @return self
 */
- (nullable instancetype)initWithOffset:(NSString *)offset gyroPlayer:(INSGyroPBPlayer *)gyroPlayer;

/**
 必须经过attach，分析一帧结果，这里传入的pixelBuffer是双鱼眼，则为YUV格式， 如果是渲染后的格式，则为BGRA格式, 目前算法仅支持双鱼眼
 
 @param pixelBuffer 可能为单鱼眼（go、5.7k左眼）可能为双鱼眼（全景4k）
 @param rightPixelBuffer 5.7k右眼，可能为空
 @param timestamp 视频解码时间戳
 */
- (void)calcDirectionWithPixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMS:(int64_t)timestamp;

/**
 序列化帧序列的分析结果，即需要调用[calcDirectionWithPixelBuffer:rightPixelBuffer:ptsMS] 分析完所有帧之后，才能调用该接口作序列化
 
 @param completion completion
 */
- (void)serializeAutoDirectionSystemCompletion:(void(^)(NSData * _Nullable systemData, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
