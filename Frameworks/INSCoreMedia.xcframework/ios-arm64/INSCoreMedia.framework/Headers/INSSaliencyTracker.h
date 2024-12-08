//
//  INSTimeshiftTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/11/11.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;
@class INSOrientationPlayer;

@interface INSSaliencyConfiguration : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) int frameWidth;// 640

@property (nonatomic) int frameHeight;// 320

@property (nonatomic) double durationMs;

@property (nonatomic) double analyzeBeginTimestamp; // in ms, 当视频帧大于时间，才会开始saliency追踪，默认为1000

@property (nonatomic) float maxAngleBetweenDirection; // in degree, 与行进方向的最大角度，超过该角度则放弃track，寻找下一个目标，默认为120

@property (nonatomic) double maxSequenceTimestamp; // in ms, 最长sequenc持续的时间，超过该时长，则放弃track，寻找下一个目标. 默认为15000

@property (nonatomic) float saliencyThresh; // 0.0 ~ , thresh value used to obtain the saliency mask，默认为0.5

@property (nonatomic) int saliencyDetectInterval; // saliency识别的帧间隔，默认为5

@property (nonatomic) int saliencyTrackerInterval; // saliency 追踪的帧间隔，默认为1，即在track模式下，每帧都去track

@end

@interface INSSaliencyTracker : NSObject

@property (nonatomic, readonly) INSSaliencyConfiguration *config;

@property (nonatomic, readonly) NSString *offset;

@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic, readonly) INSOrientationPlayer *directionPlayer;

- (nullable instancetype)initWithConfig:(INSSaliencyConfiguration *)config
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

/// 所有的saliency追踪段落，记录在一个文件中
- (int)finish;

@end

NS_ASSUME_NONNULL_END
