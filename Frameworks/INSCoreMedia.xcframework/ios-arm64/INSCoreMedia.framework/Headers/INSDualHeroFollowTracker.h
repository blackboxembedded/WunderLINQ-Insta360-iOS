//
//  INSDualHeroFollowAnalyzer.h
//  INSCoreMedia
//
//  Created by Mac on 2021/3/15.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import 

NS_ASSUME_NONNULL_BEGIN

@interface INSDualHeroFollowTrackerConfiguration : NSObject

@property (nonatomic) NSString *outputJsonPath;

/// 640
@property (nonatomic) int frameWidth;

/// 320
@property (nonatomic) int frameHeight;

@property (nonatomic) double duration;

@property (nonatomic) BOOL visualDebug;

/// 分析左侧、右侧、中间的主角 INSTrackerSequenceHandSide
/// INSTrackerSequenceHandSideNone 表示mid的主角， 如果配置为nil，则会三种视角都分析
@property (nonatomic, nullable) NSSet <NSNumber *> *heroTypes;

@end

@interface INSDualHeroFollowTracker : NSObject

@property (nonatomic, readonly) INSDualHeroFollowTrackerConfiguration *config;

- (nullable instancetype)initWithConfiguration:(INSDualHeroFollowTrackerConfiguration *)config;


//以下所有方法，按照顺序依次访问

/**
analyze一帧

@param pixelBuffer 2:1 pano image
@param timestampMs timestamp in MS
@return 是否成功
*/
- (BOOL) analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs;

/// 所有帧执行完analyzePixelBuffer后，调用一次该方法
- (void)finishAnalyze;

/**
refine一帧

@param pixelBuffer 2:1 pano image
@param timestampMs timestamp in MS
@return 是否成功
*/
- (BOOL) refinePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs;

/// 所有帧执行完refinePixelBuffer后，调用一次该方法
- (void)finishRefine;

/// 结束分析，会生成json文件，格式与LeadRoleTracker一样
- (int)finish;

/// 不要调用！！！用来调试
- (void) debugPixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs;

@end

NS_ASSUME_NONNULL_END
