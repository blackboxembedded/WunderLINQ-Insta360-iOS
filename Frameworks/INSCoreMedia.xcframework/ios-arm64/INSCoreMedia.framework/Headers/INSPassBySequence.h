//
//  INSPassBySequence.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/24.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorderModel.h"
#import "INSTrackerSequence.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSPassByTrackerModel : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double timestampMs;

@property (nonatomic) GLKQuaternion quat;

@property (nonatomic) CGPoint position;

@property (nonatomic) NSArray<NSNumber *> *rect;

@end


@interface INSPassBySequence : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double passBegin;

@property (nonatomic) double passEnd;

@property (nonatomic) double passPoint;

@property (nonatomic) BOOL onUserRight;

@property (nonatomic) double confidence;

@property (nonatomic) int64_t targetId;

@property (nonatomic) NSArray<INSPassByTrackerModel *> *passbyModels;

@property (nonatomic) NSArray<NSNumber *> *occs;

@end

NS_ASSUME_NONNULL_END
