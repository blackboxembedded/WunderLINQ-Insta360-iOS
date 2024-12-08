//
//  INSAutoFind.h
//  INSCoreMedia
//
//  Created by dml on 2022/8/8.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSAnimationRecorder.h"

@class INSAnimationRecorder;

@interface INSAutoFindAnimation : NSObject

- (instancetype)initWithStartTimeMs:(double)startTimeMs endTime:(double)endTimeMs;

- (BOOL)setPath:(NSString*)path;

- (BOOL)setQuat:(GLKQuaternion)quat flag:(BOOL)flag;

- (nullable INSAnimationRecorder *)getRecorder;


@end
