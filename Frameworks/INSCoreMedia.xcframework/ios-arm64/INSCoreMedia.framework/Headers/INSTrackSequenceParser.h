//
//  INSTrackSequenceParser.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class INSTrackerSequence;
@class INSExtraTimeMapperData;
@interface INSTrackSequenceParser : NSObject

@property (nonatomic, readonly) NSString *trackerJsonString;

@property (nonatomic, copy, readonly) NSArray <INSTrackerSequence *> *trackerSequences;

- (nullable instancetype) initWithTrackerJsonFilePath:(NSString *)trackerJsonFilePath;

- (BOOL)open;

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
