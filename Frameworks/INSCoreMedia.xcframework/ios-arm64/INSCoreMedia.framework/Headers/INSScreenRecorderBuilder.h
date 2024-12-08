//
//  INSScreenRecorderBuilder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/3/21.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSScreenRecorderModel;
@interface INSScreenRecorderBuilderTimePair : NSObject

@property (nonatomic) int64_t source;

@property (nonatomic) int64_t target;

@property (nonatomic, nullable) INSScreenRecorderModel *interModel;

- (instancetype)initWithTimeSource:(int64_t)source target:(int64_t)target;

@end


@class INSScreenRecorder;
@interface INSScreenRecorderBuilder : NSObject

// 在原recorder查找相应时间戳下投影数据，替换时间戳，仅此而已
- (INSScreenRecorder *)rebuildWithRecorder:(INSScreenRecorder *)recorder timePairs:(NSArray <INSScreenRecorderBuilderTimePair *> *)timePairs;


- (INSScreenRecorder *)rebuildWithRecorder:(INSScreenRecorder *)recorder models:(NSArray <INSScreenRecorderModel *> *)models;

- (nullable INSScreenRecorder *)rebuildWithRecorderModels:(NSArray <INSScreenRecorderModel *> *)models;

@end

NS_ASSUME_NONNULL_END
