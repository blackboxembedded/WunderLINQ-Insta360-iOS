//
//  INSBigboomCreator.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/18.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSBigboomRecorder;
@class INSLeadRoleRecorder;
@class INSDirectionRecorder;
@class INSSaliencyRecorder;
@class INSOrientationPlayer;
@class INSTrackerSequence;
@class INSDisplay;
@class INSDisplayConfigManager;
@class INSExtraTimeMapperData;
@interface INSTrackerSeqDistributor : NSObject

@property (nonatomic, readonly) NSString *trackerJsonString;

@property (nonatomic, readonly) float xFovStatic;

@property (nonatomic, readonly) float distanceStatic;

@property (nonatomic, copy, readonly) NSArray <INSTrackerSequence *> *trackerSequences;

- (nullable instancetype) initWithTrackerSequence:(NSArray <INSTrackerSequence *> *)trackerSequence;

- (nullable instancetype) initWithTrackerJsonFilePath:(NSString *)trackerJsonFilePath;

- (void)setDisplay:(INSDisplay *)display displayConfigManager:(INSDisplayConfigManager *)manager;

- (nullable INSBigboomRecorder *)bigboomRecorderWithTrackerSequence:(INSTrackerSequence *)sequence;

- (nullable INSLeadRoleRecorder *)leadRoleRecorderWithTrackerSequence:(INSTrackerSequence *)sequence;

- (nullable INSDirectionRecorder *)directionRecorderWithTrackerSequence:(INSTrackerSequence *)sequence;

- (nullable INSSaliencyRecorder *)timeshiftRecorderWithTrackerSequence:(INSTrackerSequence *)sequence;

- (nullable INSOrientationPlayer *)orientationReaderWithTrackerSequence:(INSTrackerSequence *)sequence;


/// 对大爆炸，主角视角，saliency，行进方向的track序列作trim。
/// timeReset如果为YES，则从trimStartMs到trimEndMs中pick出追踪序列，
/// 每个新序列的所有时间戳将减去trimStartMs作为新的时间戳，json中记录的duration也将相应变化，为newTrimEndMs - newTrimStartMs
/// timeReset如果为NO， 则只是把非[trimStartMs, trimStartMs]的部分删除
/// @param trimStartMs trim起始节点
/// @param trimEndMs trim结束节点
/// @param srcJsonPath 原json
/// @param outJsonPath 输出json
/// @param timeReset 如果为YES，
+ (BOOL)trimJsonWithStart:(double)trimStartMs end:(double)trimEndMs srcJsonPath:(NSString *)srcJsonPath outJsonPath:(NSString *)outJsonPath timeReset:(BOOL)timeReset;

+ (BOOL)remapTimestampJsonWithTimeMapperData:(INSExtraTimeMapperData *)timeMapperData  srcJsonPath:(NSString *)srcJsonPath outJsonPath:(NSString *)outJsonPath;


@end

NS_ASSUME_NONNULL_END
