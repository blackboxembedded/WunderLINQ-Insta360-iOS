//
//  INSStillRegionTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/29.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSStillRegionTrackerConfig : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) double durationMS;

/// 默认为0.7，如果加速视频，可以设置为1.5
@property (nonatomic) double algoThreshold;

/// 默认为NO，开启后，会在visualDebugDir 目录下存储用于分析的图片数据
@property (nonatomic) BOOL visualDebug;

/// 默认为Ducuments/still_track/， 无需用户创建，只需要配置路径即可
@property (nonatomic) NSString *visualDebugDir;

@end


@class INSGyroPBPlayer;
@interface INSStillRegionTracker : NSObject

@property (nonatomic, readonly) INSStillRegionTrackerConfig *config;

@property (nonatomic, readonly) NSString *offset;

/// 要使用全防模式 INSGyroPlayModeNormal
@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

- (nullable instancetype)initWithConfig:(INSStillRegionTrackerConfig *)config
                                 offset:(NSString *)offset
                             gyroPlayer:(INSGyroPBPlayer *)gyroPlayer;

/**
 分析一帧结果，这里传入的pixelBuffer是双鱼眼，则为YUV格式， 如果是渲染后的格式，则为BGRA格式, 目前算法仅支持双鱼眼

 @param pixelBuffer 可能为单鱼眼（go、5.7k左眼）可能为双鱼眼（全景4k）
 @param rightPixelBuffer 5.7k右眼，可能为空
 @param timestampMs 视频解码时间戳
 @return 是否成功
 */
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;

/// 所有的静止段落，记录在一个文件中，格式与大爆炸相同
- (int)finish;

@end

NS_ASSUME_NONNULL_END
