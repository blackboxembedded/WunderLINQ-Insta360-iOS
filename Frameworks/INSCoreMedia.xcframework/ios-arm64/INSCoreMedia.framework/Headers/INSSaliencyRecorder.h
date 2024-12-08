//
//  INSSaliencyRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2019/11/12.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@class INSTrackerSequence;
@interface INSSaliencyRecorder : INSScreenRecorder

- (nullable instancetype)initWithTrackerSequence:(INSTrackerSequence *)sequence;

@property (nonatomic) BOOL openRollAnimation;

@end

NS_ASSUME_NONNULL_END
