//
//  INSOneTakeUtils.h
//  INSCoreMedia
//
//  Created by yons on 10.11.20.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSOneTakeTimeParam;
@interface INSOneTakeUtils : NSObject

+ (nullable NSArray<NSNumber *> *)getAllTimestampsWithURLs:(NSArray<NSURL *> *)urls;

/// 修复转场时间
/// @param urls 视频地址
/// @param srcTimeParams 原始params
/// @param completion completion(修复转场时间后的param，error )
+ (void)fixOneTakeCutSceneWithURLs:(NSArray<NSURL *> *)urls
                     srcTimeParams:(NSArray<INSOneTakeTimeParam *> *)srcTimeParams
                        completion:(void(^)(NSArray<INSOneTakeTimeParam *> * _Nullable, NSError * _Nullable))completion;

/// 识别重叠区段，并且把其在srcTimeParams中删除，返回剩余的src param，用来配置INSOneTakeAnimation
/// @param srcTimeParams 原始params
/// @param completion completion(删除重叠后的params, 删除元素索引,  error)
+ (void)fixOneTakeCoincideWithSrcTimeParams:(NSArray<INSOneTakeTimeParam *> *)srcTimeParams
                                 completion:(void(^)(NSArray<INSOneTakeTimeParam *> * _Nullable, NSArray<NSNumber *> * _Nullable, NSError * _Nullable))completion;


@end

NS_ASSUME_NONNULL_END
