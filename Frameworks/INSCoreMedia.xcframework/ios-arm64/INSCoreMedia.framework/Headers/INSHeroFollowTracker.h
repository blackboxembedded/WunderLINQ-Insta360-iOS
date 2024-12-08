//
//  INSHeroFollowTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/30.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSHeroFollowTrackerConfiguration : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) int frameWidth;

@property (nonatomic) int frameHeight;

@property (nonatomic) double duration;

@property (nonatomic) BOOL visualDebug;

@end

@interface INSHeroFollowTracker : NSObject

@property (nonatomic, readonly) INSHeroFollowTrackerConfiguration *config;

- (nullable instancetype)initWithConfiguration:(INSHeroFollowTrackerConfiguration *)config;

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
