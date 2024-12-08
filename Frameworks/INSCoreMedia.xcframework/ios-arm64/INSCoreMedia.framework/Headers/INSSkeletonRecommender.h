//
//  INSSkeletonRecommender.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/7.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSSkeletonConfiguration.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSSkeletonPreferredMode) {
    INSSkeletonPreferredModeStill = 0,              // 静态
    INSSkeletonPreferredModeForward = 1,            // 向前迈步
    INSSkeletonPreferredModeBackward = 2,           // 向后迈步
    INSSkeletonPreferredModeStand = 4,              // 站姿
};

@interface INSSkeletonRecommender : NSObject

/// 以下数据，在加载骨骼数据时候，可以获取到
@property (nonatomic, readonly) NSString *skeletonPath;

/// 从skeleton data 读出的所有骨骼数据的起始点
@property (nonatomic, readonly) int64_t skeletonFirstTs;

/// 从skeleton data 读出的所有骨骼数据的结束点
@property (nonatomic, readonly) int64_t skeletonLastTs;

/// 骨骼数据总数
@property (nonatomic, readonly) uint32_t skeletonCount;

/// 骨骼数据版本
@property (nonatomic, readonly) uint32_t skeletonVersion;

- (instancetype)initWithSkeletonPath:(NSString *)skeletonPath;


/// stop motion1.0
/// @param preferredMode 位移状态
/// @param error error
- (nullable INSSkeletonRecommendInfo *)recommendSkeletonWithPreferredMode:(INSSkeletonPreferredMode)preferredMode error:(NSError * _Nullable * _Nullable)error;


/// 甩干跳
/// @param startFramePadding 向前扩展的帧数，建议100
/// @param endFramePadding 向后扩展的帧数，建议50
/// @param error error
- (nullable INSSkeletonRecommendInfo *)spinSkeletonWithStartFramePadding:(NSUInteger)startFramePadding endFramePadding:(NSUInteger)endFramePadding error:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
