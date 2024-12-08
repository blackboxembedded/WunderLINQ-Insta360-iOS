//
//  INSTrackerSequence.h
//  INSCoreMedia
//
//  Created by HFY on 2019/10/11.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorderModel.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, INSTrackerSequenceHandSide) {
    INSTrackerSequenceHandSideNone = 0,
    INSTrackerSequenceHandSideLeft,
    INSTrackerSequenceHandSideRight
};

@class INSScreenRecorderModel;
@interface INSTrackerSequence : NSObject <NSCoding, NSCopying, NSMutableCopying>

// 目标名称
@property (nonatomic) NSString *targetName;

// 目标id
@property (nonatomic) int64_t targetId;

// 该目标一共在多少帧内出现过
@property (nonatomic) int64_t targetShowCount;

// 当前目标出现时间区间的最小值
@property (nonatomic) double targetStartTimestamp;

// 当前目标出现时间区间的最大值
@property (nonatomic) double targetEndTimestamp;

// std::vector<ins::orientationState> data in ins::trackerSequence
//@property (nonatomic) NSData *orientationStateDatas;

@property (nonatomic) NSArray<INSScreenRecorderModel *> *recorderModels;

@property (nonatomic) INSTrackerSequenceHandSide handSide;

- (void)resetStartTimestamp:(double)timestamp;

- (void)discardHeaderDataWithTimestamp:(double)timestamp;

- (void)discardTailDataWithTimestamp:(double)timestamp;

@end

NS_ASSUME_NONNULL_END
