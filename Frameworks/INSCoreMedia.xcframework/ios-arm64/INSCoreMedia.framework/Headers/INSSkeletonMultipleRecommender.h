//
//  INSSkeletonMultipleRecommender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/16.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSSkeletonConfiguration.h"

NS_ASSUME_NONNULL_BEGIN


typedef void(^SkeletonMultipleRecommenderBlk)(NSError * _Nullable error, NSUInteger index, NSUInteger expectedCount);

typedef NSString* SkeletonMultipleExportKeys;

@interface INSSkeletonMultipleRecommenderConfiguration : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCacheDir:(NSString *)cacheDir;

/// 必须设置，默认空字符串“”, 通过构造方法传入
@property (nonatomic, readonly) NSString* cacheDir;

///是否检测人体, 默认为YES
@property (nonatomic) BOOL shouldDetectPerson;

///人体检测置信度阈值， 默认为0.4
@property (nonatomic) float detectPersonThresh;

///是否检测人头, 默认为YES
@property (nonatomic) BOOL shouldDetectHead;

///人体检测置信度阈值， 默认为0.6
@property (nonatomic) float detectHeadThresh;

// 重复连续帧的最后一帧，默认为YES
@property (nonatomic) BOOL shouldRepeatLastFrame;

///片段循环的次数，默认为0
@property (nonatomic) int cycleNum;

///每个片段有几个连续帧，默认为2
@property (nonatomic) int framePreFragment;

// 片段的长度，默认为10
@property (nonatomic) int fragmentLength;


//是否开启debug, 默认为NO
@property (nonatomic) BOOL debugEnable;

@property (nonatomic) NSString* debugSaveDir;

@end

@interface INSSkeletonMultipleRecommender : NSObject

@property(nonatomic, readonly) INSSkeletonMultipleRecommenderConfiguration *config;

- (instancetype)init NS_UNAVAILABLE;

/// 初始化接口，传入一个文件夹目录作为cache文件夹，需要自己创建一个干净的目录，否则会返回nil
/// @param config config
- (nullable instancetype)initWithConfiguration:(INSSkeletonMultipleRecommenderConfiguration *)config;

/// 输入已经进行过骨骼分析的视频地址信息

/// 输入已经进行过骨骼分析的视频信息，包括骨骼数据地址和视频原地址
/// @param skeletonVideos 视频信息
/// @return 返回成功解析的视频个数
- (NSUInteger)inputVideoInfos:(NSArray<INSSkeletoVideoInfo *> *)skeletonVideos;


/// 获取skeleton 推荐信息
/// @param error error
- (nullable NSArray<INSSkeletonRecommendInfo *> *)recommendInfosWithError:(NSError * _Nullable * _Nullable)error;


/// 耗时方法，在当前线程执行抽帧与渲染，在磁盘生成缓存帧，每个视频的recommend info调用一次
/// @param recommendInfo 相应视频的recommend Info，仅支持INSSkeletonRecommendInfoVersion2版本的info
/// @param renderWidth 渲染宽度，和最后导出的帧宽度相同
/// @param renderHeight 渲染高度，和最后导出的帧高度相同
/// @param progressHandler 执行进度
/// @param mediaFileSize videoInfo parser 获取媒体大小
/// @param gyroPlayer 防抖
/// @param offset offset
/// @param distance 最终渲染的distance
/// @return 返回NO表示执行流程失败，YES表示成功
- (BOOL)prepareFrameWithRecommendInfo:(INSSkeletonRecommendInfo *)recommendInfo
                          renderWidth:(int)renderWidth
                         renderHeight:(int)renderHeight
                        mediaFileSize:(int64_t)mediaFileSize
                           gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                               offset:(NSString *)offset
                             distance:(float)distance
                      progressHandler:(void (^)(NSError * _Nullable error, NSProgress *progress))progressHandler;


/// 所有prepareFrame执行结束后，调用该方法获取缓存key
/// @param error error
/// @return cache frame keys
- (nullable NSArray<SkeletonMultipleExportKeys> *)exportFrameKeysWithError:(NSError * _Nullable * _Nullable)error;


/// 通过key获取一帧，用INSSequentialExporter来做导出
/// @param exportFrameKey cache frame key
/// @return Apple pixel if success, nullptr if failed
- (nullable CVPixelBufferRef)pixelBufferWithExportFrameKey:(SkeletonMultipleExportKeys)exportFrameKey;

/// 一旦取消，会释放资源，所有流程需要重新开始
- (void)cancelProgress;


@end

NS_ASSUME_NONNULL_END
