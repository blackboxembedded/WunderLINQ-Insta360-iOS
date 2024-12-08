//
//  INSGyroPBPlayer.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/23.
//  Copyright © 2017年 insta360. All rights reserved.
//


#import "INSGyroPlayer.h"
#import <UIKit/UIKit.h>

@class INSExposurePlayer;
@class INSExtraGyroData;
@class INSEmSegment;

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroPBPlayer : INSGyroPlayer

@property (nonatomic, readonly) INSGyroDataType gyroDataType;

/**
 用于普通视频输入防抖数据，默认正向+反向输入

 @param pbGyro 防抖数据
 @return INSGyroPlayer
 */
- (nullable instancetype) initWithPBGyroData:(INSExtraGyroData *)pbGyro;


/**
 用于普通视频输入防抖数据，可选正向输入或者反向输入

 @param pbGyro 防抖数据
 @param reverseInput YES-有反向输入 NO-无反向输入
 @return INSGyroPlayer
 */
- (nullable instancetype) initWithPBGyroData:(INSExtraGyroData *)pbGyro reverseInput:(BOOL)reverseInput;

/**
 optimize batch算法输入防抖数据，加载速度比较慢，适用于导出

 @param pbGyro 防抖数据
 @param reverseInput YES-有反向输入 NO-无反向输入
 @return INSGyroPlayer
 */
- (nullable instancetype) initWithNewVersionPBGyroData:(INSExtraGyroData *)pbGyro reverseInput:(BOOL)reverseInput;

/**
 用于定点延时摄影，这类文件的陀螺仪数据是多个图片的陀螺仪数据连接在一起，时间戳不是一直连续的，所以规定这类陀螺仪数据，每段用timestap=-1为flag，gravity_x为序号，表示这段数据所属的帧

 @param pbGyro 陀螺仪数据
 @return INSGyroPlayer
 */
- (nullable instancetype) initWithMultipleBatchPBGyroData:(INSExtraGyroData *)pbGyro;

/**
 是否正在进行流式加载,cancelInputOverflowGyroData 之前可作为判定条件 YES:流式输入中 NO:没有输入
 */
@property (nonatomic) BOOL inputing;


@property (nonatomic, readonly) int64_t endVideoTimestamp;

@end


@interface INSGyroPBPlayer (GyroDataOverFlow)
/**
 流式加载陀螺仪数据的初始化方法，不要同时调用同步和异步加载的接口

 @return INSGyroPlayer
 */
- (nullable instancetype) initOverFlowPBGyroPlayer;

/**
 异步流式填充算法库

 @param pbGyro 陀螺仪信息
 @param process 加载过程的回调
 */
- (void)startInputOverflowGyroData:(INSExtraGyroData *)pbGyro progress:(nullable void (^)(NSError * _Nullable error, NSInteger expectedCount, NSInteger inputedCount, BOOL inputing))process;


/**
 同步流式填充算法库，调用cancel可以立即返回，并抛出错误

 @param pbGyro 陀螺仪信息
 @param error 错误处理
 */
- (void)inputOverflowGyroData:(INSExtraGyroData *)pbGyro error:(NSError * _Nullable *)error;

/**
 取消流式加载
 */
- (void) cancelInputOverflowGyroData;

@end


@interface INSGyroPBPlayer (EmPlay)

/// 用循环录影的列表来初始化
- (nullable instancetype) initWithEmSegment:(NSArray<INSEmSegment*>*)emSegments;

/// 要把每个视频的陀螺仪信息加载到gyroPlayer实例中
- (void)appendGyroData:(INSExtraGyroData *)pbGyro;

/// 所有数据全部append之后，添加
- (BOOL)load DEPRECATED_MSG_ATTRIBUTE("Please use loadCacheData:");

/// 所有数据全部append之后调用，如果没有缓存数据，则传递nil
- (BOOL)loadCacheData:(NSData * _Nullable)cacheData;

@end


@interface INSGyroPBPlayer (Serializer)

- (nullable instancetype)initWithPBGyroData:(INSExtraGyroData *)pbGyro gyroStabilizerData:(NSData *)gyroStabilizerData  multipleBatch:(BOOL)multipleBatch DEPRECATED_MSG_ATTRIBUTE("Please use -initWithPBGyroData:gyroStabilizerData:gyroStabilizerDataExt:");
- (instancetype)initWithPBGyroData:(INSExtraGyroData *)pbGyro gyroStabilizerData:(NSData *)gyroStabilizerData gyroStabilizerDataExt:(NSData * _Nullable)gyroStabilizerDataExt multipleBatch:(BOOL)multipleBatch;

- (void)serializeStabilizerFilterCompletion:(void(^)(NSData * _Nullable gyroStabilizerData, NSError * _Nullable error))completion DEPRECATED_MSG_ATTRIBUTE("Please use -serializeStabilizerWithExtCompletion");
- (void)serializeStabilizerWithExtCompletion:(void(^)(NSData * _Nullable gyroStabilizerData,NSData * _Nullable gyroStabilizerDataExt, NSError * _Nullable error))completion;

@end

@interface INSGyroPBPlayer (BulletTime)


/// for bullet_time video anti-shake, you should call this first
/// @return YES if the bullet time adaptor can be use; NO if the video's gyro data feature is not typical bullet time
- (BOOL)onUseBulletTimeAdaptor;

/// update bullet adaptor setting, you should call onUseBulletTimeAdaptor first
/// @param bulletMode mode
/// @param extraPitch For RemovePitch mode, to add extra pitch, in radian
- (BOOL)setBulletTimeAdaptorWithMode:(INSGyroStabilizerBulletMode)bulletMode extraPitch:(double)extraPitch;
                  

@end

NS_ASSUME_NONNULL_END
