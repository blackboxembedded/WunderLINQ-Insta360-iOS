//
//  INSOrientationPlayer.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSTrackerSequence;
@interface INSOrientationPlayer : NSObject

- (nullable instancetype)initWithTrackerSequence:(INSTrackerSequence *)trackerSequence startTime:(double)startTimeMs endTimeMs:(double)endTimeMs;

- (GLKQuaternion) orientationAtTimestampMs:(double)timestamp;

@end

NS_ASSUME_NONNULL_END
