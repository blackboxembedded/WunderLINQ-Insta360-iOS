//
//  INSVideoInfoParser+Compatible.h
//  INSCoreMedia
//
//  Created by Mac on 2021/5/28.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSVideoInfoParser.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    /**
     *  未知的图片类型
     */
    INSVideoOffsetUnknown,
    /**
     *  第一代4K相机
     */
    INSVideoOffset4KV1,
    /**
     *  nano的V1版本
     */
    INSVideoOffsetNanoV1,
    
    /**
     *  nano的V2版本
     */
    INSVideoOffsetNanoV2,
    
} INSVideoOffsetVersion;

@interface INSVideoInfoParser ()

/// 视频宽度,  demuxerInfo recommended
@property (nonatomic, assign, readonly) NSInteger width;

/// 视频高度
@property (nonatomic, assign, readonly) NSInteger height;

/// 视频时长，为dumex数据，单位：秒（s）
@property (nonatomic, assign, readonly) double duration;

/// rotation
@property (nonatomic, assign, readonly) double rotation;

/// 视频帧率
@property (nonatomic, assign, readonly) double framerate;

/// total stream bitrate in bit/s, 0 if not available
@property (nonatomic, assign, readonly) int64_t bitrate;

/// total stream bitrate in bit/s, 0 if not available
@property (nonatomic, assign, readonly) BOOL isExistAudio;

/// 判断是否是全景声
@property (nonatomic, assign, readonly) BOOL isSpatialAudio;

/// 判断是否存是H265的视频
@property (nonatomic, assign, readonly) BOOL isH265Codec;

/// 判断是否是全景视频
@property (nonatomic, assign, readonly) BOOL isSpherical;

/// offset
@property (nullable, nonatomic, readonly) NSString *offset;

/// video dffset version
@property (nonatomic, assign, readonly) INSVideoOffsetVersion videoOffsetVersion;

/// 应该渲染的类型,目前支持区分双球和全景
@property (nonatomic, assign, readonly) INSRenderType supposedRenderType;

/// 序列号
@property (nullable, nonatomic, readonly) NSString *serialNumber;

/// 是否获得到GPS数据,没有返回nil
@property (nullable, nonatomic, strong, readonly) INSMediaGps *gpsData;

/// 以下三个方法，可以对parser进行提速，但是会牺牲部分信息的获取
/**
 *  同步打开媒体fast版本，只取视频头部信息，而不去解码，会提升效率；如果有截图等操作还是用open
 *  该方法相当于openDumuxer + openExtraInfo
 *  @return 是否成功
 */
- (BOOL)openFast
DEPRECATED_MSG_ATTRIBUTE("Please use -setOpenMode:INSVideoInfoParserOpenModeAllFast and -open");

/**
    只打开ffmpeg，此时没有文件尾数据。此时拿到width, height, duration, rotation, framerate,bitrate,mediaFileSize,fileTotalSize，并且不能使用updateLocalFileExtraInfo，offset等文件尾的接口
 */
- (BOOL)openDemuxer
DEPRECATED_MSG_ATTRIBUTE("Please use -setOpenMode:INSVideoInfoParserOpenModeDemuxerOnly and -open");


/// 只加载extrainfo数据，此时只能拿到extraInfo属性，并且不能使用截图涉及音视频解码等的接口
- (BOOL)openExtraInfo
DEPRECATED_MSG_ATTRIBUTE("Please use -setOpenMode:INSVideoInfoParserOpenModeExtrainfoOnly and -open");

/**
 *  异步打开媒体，对于网络数据可能需要很长时间
 *
 *  @param successBlock 打开成功后回调，发生在global线程
 *  @param errorBlock   失败回调，回调在global线程
 */
-(void)openOnSuccess:(dispatch_block_t)successBlock onError:(dispatch_block_t)errorBlock;

/**
 *  异步截图关键帧，调用者需要记得手动释放内存
 *
 *  @param position     截图的时间
 *  @param successBlock 成功回调
 *  @param errorBlock   失败互调
 */
-(void)screenShotAt:(double)position onSuccess:(void(^)(CVPixelBufferRef _Nullable))successBlock onError:(dispatch_block_t)errorBlock
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate:completion: instead");

-(void)screenShotAtPosition:(double)position onSuccess:(void(^)(INSPlayerImage* _Nullable))imageBlock onError:(dispatch_block_t)errorBlock
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate:completion: instead");

/**
 *  同步截图关键帧，只能截取self.videoURL 下的视频帧，即对于self.videoURL2下的视频流，无法截取
 *  @param position 截图的时间点   [0.0, video_duration], 单位 秒
 *  @return 截图，需要调用者释放内存
 */
-(nullable CVPixelBufferRef)screenShotAt:(double)position
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate: instead");

/**
 *  同步截图关键帧
 *  @param position 截图的时间点   [0.0, video_duration], 单位 秒
 *  @return 截图，需要调用者释放内存
 */
-(nullable INSPlayerImage *)screenShotAtPosition:(double)position
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate: instead");

/**
 *  同步截图精准帧，只能截取self.videoURL 下的视频帧，即对于self.videoURL2下的视频流，无法截取
 *  @param position 截图的时间点  [0.0, video_duration], 单位 秒
 *  @return 截图, 需要调用者释放内存
 */
-(nullable CVPixelBufferRef)screenShotAccurateAt:(double)position
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate: instead");

/**
 *  同步截图精准帧，调用者需要记得手动释放内存
 *  @param position 截图的时间点  [0.0, video_duration], 单位 秒
 *  @return 截图, 需要调用者释放内存
 */
-(nullable INSPlayerImage *)screenShotAccurateAtPosition:(double)position
DEPRECATED_MSG_ATTRIBUTE("Use -screenShotAtPosition:accurate: instead");

/**
 *  根据视频重新计算offset
 *
 *  @param positions 截取图片的时间
 *
 *  @return 如果成功则返回计算得到的offset，如果parser 没有open、指定时间取不到视频帧、原offset 为空，则会导致生成失败
 */
- (nullable NSString *)recalculateOffsetWithPositions:(nonnull NSArray <NSNumber * >*)positions
DEPRECATED_MSG_ATTRIBUTE("Use -recalculateOffsetWithPositions:shouldFixExtraInfo:oldOffset: instead");

/**
 *  根据视频重新计算offset
 *
 *  @param positions 截取图片的时间
 *  @param shouldFixExtraInfo 是否修复文件尾
 *  @param lensType 镜头类型
 *
 *  @return 如果成功则返回计算得到的offset，如果parser 没有open、指定时间取不到视频帧，则会导致生成失败
 */
- (nullable NSString *)recalculateOffsetWithPositions:(nonnull NSArray <NSNumber * >*)positions
                                   shouldFixExtraInfo:(BOOL)shouldFixExtraInfo
                                             lensType:(INSLensType)lensType
DEPRECATED_MSG_ATTRIBUTE("Use -recalculateOffsetWithPositions:shouldFixExtraInfo:oldOffset: instead");

/**
 * 根据镜头类型修复文件尾的数据
 *
 * @param lensType 镜头类型
 */
- (BOOL)fixExtraInfoWithLensType:(INSLensType)lensType
DEPRECATED_MSG_ATTRIBUTE("Use -fixExtraInfoWithOldOffset: instead");

/**
 *  传入key获得value，早起相机
 *
 *  @param key metadata key
 *
 *  @return value
 */
-(NSString *)getMetadata:(NSString *)key
DEPRECATED_MSG_ATTRIBUTE("Use parser.extrainfo to get metadata");
-(INSMetadata *)getMetadata
DEPRECATED_MSG_ATTRIBUTE("Use parser.extrainfo to get metadata");

@end

NS_ASSUME_NONNULL_END
