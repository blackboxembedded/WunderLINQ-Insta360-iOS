//
//  INSGiantAsteroidProcessor.h
//  INSCoreMedia
//
//  Created by yons on 3.8.20.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSGyroPBPlayer;
@interface INSGiantAsteroidAnalyzerConfig: NSObject

/// offset
@property (nonatomic, readonly) NSString *offset;

/// 防抖器
@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

/// media 帧率
@property (nonatomic, readonly) double mediaFPS;

/// media size为文件总长度去掉文件尾的长度
@property (nonatomic, readonly) int64_t mediaFileSize;

/// 开始分析的时间点，默认为0
@property (nonatomic, readonly) int64_t analyzeStartTsMs;

/// 结束分析的时间点，默认为videoDurationMs，无论配置多少，都不会大于videoDurationMs
@property (nonatomic, readonly) int64_t analyzeEndTsMs;

/// 对于分析结果开始时间点，比实际识别出来的时间点提前的时间，默认为10 单位：帧数
@property (nonatomic) int64_t giantStartPadding;

/// 对于分析结果结束时间点，比实际识别出来的时间点延后的时间，默认为4 单位：帧数
@property (nonatomic) int64_t giantEndPadding;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOffset:(NSString *)offset
                    gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                      mediaFPS:(double)mediaFPS
                 mediaFileSize:(int64_t)mediaFileSize
              analyzeStartTsMs:(int64_t)analyzeStartTsMs
                analyzeEndTsMs:(int64_t)analyzeEndTsMs;

@end


@interface INSGiantAsteroidModel: NSObject<NSCoding, NSCopying, NSMutableCopying>

@property (nonatomic) int64_t giantStartTimestamp;

@property (nonatomic) int64_t giantEndTimestamp;

@property (nonatomic) GLKQuaternion giantOrientation;

@property (nonatomic) GLKVector3 giantEulerYXZ; //(Pitch, Yaw, Roll)

@end


/// Analyzer 过程回调
/// @param error 如果error不为nil，则一定发生了错误
/// @param ratio 当前分析进度
/// @param stop 当分析完成，发生错误，取消时，stop为YES
/// @param models 只有当分析完成，且没有错误，可以拿到结果， 如果视频中没有合适区段，则返回空数组; 其他情况则为nil
typedef void(^GiantAnalyzeProgressBlk)(NSError * _Nullable error, float ratio, BOOL stop, NSArray<INSGiantAsteroidModel *> * _Nullable models);



@interface INSGiantAsteroidAnalyzer : NSObject

@property (nonatomic, readonly) NSArray <NSURL *> *videoURLs;

@property (nonatomic, readonly) INSGiantAsteroidAnalyzerConfig *config;

- (instancetype)init NS_UNAVAILABLE;


- (nullable instancetype)initWithinitWithURLs:(NSArray<NSURL *> *)videoURLs config:(INSGiantAsteroidAnalyzerConfig *)config;

- (void)startWithProgress:(GiantAnalyzeProgressBlk)progress;

- (void)cancel;


@end

NS_ASSUME_NONNULL_END
