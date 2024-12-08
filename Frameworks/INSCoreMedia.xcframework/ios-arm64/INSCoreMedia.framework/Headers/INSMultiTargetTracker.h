//
//  INSMultiTargetTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/8/31.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSTrackerSequence;
@class INSMultiTargetTracker;
@class INSExtraGyroData;

@protocol INSMultiTargetTrackerDelegate <NSObject>
@optional

- (void)multiTargetTracker:(INSMultiTargetTracker *)tracker didUpdateSequences:(NSArray<INSTrackerSequence *> *)trackerSequences;

@end

@interface INSMultiTrackerFilterParam : NSObject

@property (nonatomic) double peopleNum;         // default 0.51;
@property (nonatomic) double angleLower;        // default 0.2;
@property (nonatomic) double angleUpper;        // default 1.6;
@property (nonatomic) double passerbySize;      // default 0.015;
@property (nonatomic) double distantSize;       // default 0.02;
@property (nonatomic) double mergeMaxAngle;     // default 0.66;
@property (nonatomic) double mergeMeanAngle;    // default 0.3;
@property (nonatomic) double mergeMeanIou;      // default 0.05;

@end


@interface INSMultiTrackerConfiguration : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) int frameWidth;

@property (nonatomic) int frameHeight;

@property (nonatomic) double duration;

@property (nonatomic) int minTrackerSeqNum;

@property (nonatomic) int maxMergeSeq;

@property (nonatomic) double mergeMeanAngle; //default 1.0 / 6,  PI/6=30 degree

@property (nonatomic) double mergeMaxAngle; // default 0.4, PI*0.4=72 degree

@property (nonatomic) double mergeMeanIou; // default 0.05

@property (nonatomic) double filterMinSize; // default 200, discard tracks smaller than {filter_min_size}

@property (nonatomic) double filterMinLength; // default 30, discard tracks shorter than {filter_min_length}

@property (nonatomic) BOOL visualDebug;

@property (nonatomic) BOOL highLevelFilter; // 是否打开高级条件过滤，默认为NO； 如果置为YES，需要把文件的d陀螺仪数据传入

@property (nullable, nonatomic) INSExtraGyroData *gyroData;// 文件的陀螺仪数据，如果highLevelFilter为YES，则需要赋值

@property (nullable, nonatomic) INSMultiTrackerFilterParam *highLevelFilterParam; // highLevelFilter打开时起作用，如果传入nil，使用默认值

@end





@interface INSMultiTargetTracker : NSObject

@property (nonatomic, readonly) INSMultiTrackerConfiguration *config;

@property(nonatomic, weak) id <INSMultiTargetTrackerDelegate> delegate;

- (nullable instancetype)initWithConfig:(INSMultiTrackerConfiguration *)config;


/**
 渲染

 @param pixelBuffer bgra panorama image
 @param timestampMs pts
 @return success or not
 */
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs;



/**
 所有帧分析结束之后，可以获得多目标识别结果：每个目标出现的时间以及位置的序列，每个序列代表一个物体的track路径

 @return 追踪到的目标序列个数，0表示没有追踪到序列或者写json时发生错误
 */
- (int)finish;


/**
 可以在分析过程中，获取当前可用的sequence

 @return sequence数组
 */
//- (NSArray<INSTrackerSequence *> *)getActiveTrackeSequences;

@end

NS_ASSUME_NONNULL_END
