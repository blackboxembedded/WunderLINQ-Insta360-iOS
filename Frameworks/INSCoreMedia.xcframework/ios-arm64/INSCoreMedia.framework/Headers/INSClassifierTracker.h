//
//  INSClassifierTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSClassifierTrackerDetectType) {
    // 识别天空
    INSClassifierTrackerDetectTypeUpview = 0,
    // 识别对称性
    INSClassifierTrackerDetectTypeSymmetric
};

@interface INSClassifierTrackerConfig : NSObject

@property (nonatomic, readonly) NSString *outputJsonPath;

@property (nonatomic, readonly) INSClassifierTrackerDetectType detectType;

@property (nonatomic, readonly) double durationMS;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOutputJsonPath:(NSString *)outputJsonPath detectType:(INSClassifierTrackerDetectType)detectType durationMS:(double)durationMS;

@end


@class INSGyroPBPlayer;
@class INSOrientationPlayer;
@interface INSClassifierTracker : NSObject

@property (nonatomic, readonly) INSClassifierTrackerConfig *config;

@property (nonatomic, readonly) NSString *offset;

@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic, readonly) INSOrientationPlayer *directionPlayer;//传入 行进方向的分析结果

- (nullable instancetype)initWithConfig:(INSClassifierTrackerConfig *)config
                                 offset:(NSString *)offset
                             gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                        directionPlayer:(INSOrientationPlayer *)directionPlayer;

/**
 分析一帧结果，这里传入的pixelBuffer是双鱼眼，则为YUV格式， 如果是渲染后的格式，则为BGRA格式, 目前算法仅支持双鱼眼

 @param pixelBuffer 可能为单鱼眼（go、5.7k左眼）可能为双鱼眼（全景4k）
 @param rightPixelBuffer 5.7k右眼，可能为空
 @param timestampMs 视频解码时间戳
 @return 是否成功
 */
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;

/// 所有的classifIier追踪段落，记录在一个文件中
- (int)finish;


@end

NS_ASSUME_NONNULL_END
