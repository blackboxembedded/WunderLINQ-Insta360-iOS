//
//  INSTransitionRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/2/25.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSTransitionRecorderLayerType) {
    INSTransitionRecorderLayerUnknown = 0,
    INSTransitionRecorderLayer1 = 1,
    INSTransitionRecorderLayer2 = 2
};

@class INSProjectionParam;
@interface INSTransitionRecorder : INSScreenRecorder

// 由调速导致产生的, 调速后media时间轴的转场时间 / 调速前media时间轴的转场时间
@property (nonatomic) float timescaleConvertRatio;

// 用INSTransitonParser生成
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype) initWithKeyFramesData:(NSData *)keyFramesData
                                slerpCurvesData:(NSData *)slerpCurvesData
                                      startTime:(double)startTimeMs
                                      endTimeMs:(double)endTimeMs
                               originProjection:(INSProjectionParam *)originProjectionParam;

- (void)resetOriginOrientation:(GLKQuaternion)originOrientation;

@property (nonatomic) INSTransitionRecorderLayerType layerType;

@end

NS_ASSUME_NONNULL_END
