//
//  INSPassByWarpData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/17.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSTrackerSequence;
@class INSExtraGyroData;
@interface INSPassByWarpData : NSObject

@end

@interface INSPassByAnalyzerConfiguration : NSObject

/// 离屏渲染的宽 默认为640
@property (nonatomic) int frameWidth;

/// 离屏渲染的高 默认为320
@property (nonatomic) int frameHeight;

/// 分析结果输入的json路径
@property (nonatomic) NSString *analyzerResultJsonPath;

//检测器置信度的阈值，默认为0.1
@property (nonatomic) float detectorConfThresh;

//检测器mnn的阈值，默认为0.55
@property (nonatomic) float mnnConfThresh;

//最大出现角度，默认为90， in degree
@property (nonatomic) float maxAppearAngle;

@property (nonatomic) BOOL enableDebug;

/// 调试信息的存储
@property (nonatomic) NSString *debugDirPath;

@end

@interface INSPassByNormalFilterConfig : NSObject

/// 行进方向的追踪数据，必须赋值
@property (nonatomic) INSTrackerSequence *forwardSequence;

/// 原视频的陀螺仪数据，必须赋值
@property (nonatomic) INSExtraGyroData *gyroData;

/// 超车最大时长 in ms, default is 20000, in ms
@property (nonatomic) double maxPassbyDuration;

/// 超车前的最小时长，default is 200, in ms
@property (nonatomic) double minDurationBeforePassing;

/// 超车后的最小时长，default is 200, in ms
@property (nonatomic) double minDurationAfterPassing;

/// 基准时间，也是超车最短时长 default is 1.26 in second
@property (nonatomic) double benchmarkTime;

/// 超车最小面积比率 default is 0.01
@property (nonatomic) double minAreaRatio;

/// 最大时间基准的倍数 default is 4
@property (nonatomic) int maxTimesMultiple;

/// 超车最小过滤角度  default is 55
@property (nonatomic) float minFilterAngle;

/// 超车最大过滤角度  default is 135
@property (nonatomic) float maxFilterAngle;

@end


@interface INSPassByOrientationFilterConfig : NSObject

/// 车头检测的起始帧所在的比例 default is 0.15 / 1.26
@property (nonatomic) float beginRatio;

/// 车头检测的起始帧所在的比例 default is 1.11 / 1.26
@property (nonatomic) float endRatio;

/// 默认960
@property (nonatomic) int imageWidthUseInFilter;

/// 默认540
@property (nonatomic) int imageHeightUseInFilter;

@end


@interface INSPassByFilterConfiguration : NSObject

/// 在analyze过程中计算出的结果，即INSPassByAnalyzerConfiguration.analyzerResultJsonPath
@property (nonatomic) NSString *inputAnalyzeResultJsonPath;

/// 过滤后结果的存储路径
@property (nonatomic) NSString *outputFilterResultJsonPath;

/// 基础参数的过滤逻辑
@property (nonatomic) INSPassByNormalFilterConfig *normalFilterConfig;

/// 进行车头车尾序列判断的过滤算法
@property (nonatomic) INSPassByOrientationFilterConfig *orientationFilterConfig;

/// 是否开启debug 默认NO
@property (nonatomic) BOOL enableDebug;

/// 调试信息的存储
@property (nonatomic) NSString *debugDirPath;

@end








@interface INSPassByFilterConfiguration2 : NSObject

/// 在analyze过程中计算出的结果，即INSPassByAnalyzerConfiguration.analyzerResultJsonPath
@property (nonatomic) NSString *inputAnalyzeResultJsonPath;

/// 过滤后结果的存储路径
@property (nonatomic) NSString *outputFilterResultJsonPath;

/// 超车最大时长 in ms, default is 20000, in ms
@property (nonatomic) double maxPassbyDuration;

/// 超车前的最小时长，default is 200, in ms
@property (nonatomic) double minDurationBeforePassing;

/// 超车后的最小时长，default is 200, in ms
@property (nonatomic) double minDurationAfterPassing;

/// 基准时间，也是超车最短时长 default is 1.26 in second
@property (nonatomic) double benchmarkTime;

/// 超车最小面积比率 default is 0.01
@property (nonatomic) double minAreaRatio;

/// 最大时间基准的倍数 default is 4
@property (nonatomic) int maxTimesMultiple;

/// 超车最小过滤角度  default is 55
@property (nonatomic) float minFilterAngle;

/// 超车最大过滤角度  default is 135
@property (nonatomic) float maxFilterAngle;

/// 是否开启debug 默认NO
@property (nonatomic) BOOL enableDebug;

/// 调试信息的存储
@property (nonatomic) NSString *debugDirPath;

@end

NS_ASSUME_NONNULL_END
