//
//  INSAutoEditRecommender.h
//  INSCoreMedia
//
//  Created by HFY on 2019/4/5.
//  Copyright © 2019年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct AutoEditOutParam {
    int iterateIndex;
    int iterateTotal;
} AutoEditOutParam;

@class INSAutoEditTemplate;
@class INSAutoEditLogic;
@class INSAutoEditSegment;
@class INSEditRecommenderConfiguration;
@class INSVideoInfoUniqueKey;

/**
 推荐接口的返回结果，调用换一批接口时，iterateIndex 属于[1,iterateTotal]中的整数，其他情况iterateIndex为0

 @param segmentInfos 推荐信息
 @param error 错误信息
 @param autoEditOutParam 当前change batch查询的次数, 以及change batch可以查询的总次数,超过这个次数，iterateIndex将返回0，表示返回了与全自动推荐相同的结果
 */
typedef void(^AutoEditRecommenderBlock)(NSArray <INSAutoEditSegment *>  * _Nullable segmentInfos, NSError * _Nullable error, AutoEditOutParam autoEditOutParam);

@interface INSAutoEditRecommender : NSObject

- (id)init NS_UNAVAILABLE;

- (instancetype) initWithConfiguration:(INSEditRecommenderConfiguration *)recommenderConfig NS_DESIGNATED_INITIALIZER;

/**
 Must be called first and pass the json files path which come from scene frame analyzer. And if return error, you should terminate the whole process

 @param analyzeFiles Json files
 @param errorPtr Error pointer
 */
- (void)feedWithAnalyzeFiles:(NSArray<NSString *> *)analyzeFiles error:(NSError * _Nullable * _Nullable)errorPtr;

/**
要确定的是，全自动推荐完了之后，是否需要更新，还是只有在用户手动更换推荐素材时更新

 @param keySet video key set
 */
- (void)modifySelectedVideosWithKeySet:(NSSet<INSVideoInfoUniqueKey *> * _Nullable)keySet;

// 全自动
- (void)fullyAutoEditWithEditTemplate:(INSAutoEditTemplate *)editTemplate
                             completion:(AutoEditRecommenderBlock)completion;

// 半自动
- (void)semiAutoEditWithEditTemplate:(INSAutoEditTemplate *)editTemplate
                        lensIndex:(int)lensIndex
                       completion:(AutoEditRecommenderBlock)completion;

// 质量评分
- (void)qualityAutoEditWithDurationMs:(int64_t)durationMs
                           completion:(AutoEditRecommenderBlock)completion;

// 全自动之后换一批
- (void)changeBatchWithEditTemplate:(INSAutoEditTemplate *)editTemplate
                         completion:(AutoEditRecommenderBlock)completion;

// 销毁内部使用的算法状态，下次feed是会重新创建
- (void)clear;

@end

NS_ASSUME_NONNULL_END
