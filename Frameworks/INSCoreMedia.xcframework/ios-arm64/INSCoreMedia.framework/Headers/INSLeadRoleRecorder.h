//
//  INSLeadRoleRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/10.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <INSCoreMedia/INSCoreMedia.h>

NS_ASSUME_NONNULL_BEGIN
@class INSTrackerSequence;
@interface INSLeadRoleRecorder : INSScreenRecorder

- (nullable instancetype)initWithTrackerSequence:(INSTrackerSequence *)trackerSequence startTime:(double)startTimeMs endTimeMs:(double)endTimeMs;

@end

NS_ASSUME_NONNULL_END
