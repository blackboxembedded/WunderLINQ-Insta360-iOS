//
//  INSVideoInfoParser.h
//  INSMediaApp
//
//  Created by jerett on 16/6/17.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import "INSRenderType.h"
#import "INSMediaGps.h"
#import "INSExtraInfo.h"
#import "INSLensOffset.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, INSVideoInfoParserOpenMode) {
    
    /// info:all, abalities:all
    INSVideoInfoParserOpenModeAllDetail = 0,
    
    /// info:all, abalities:all except snapshot
    INSVideoInfoParserOpenModeAllFast,
    
    /// info:extrainfo, abalities:recalculate-offset\update-local-file\fix-extraInfo. the video must have extrainfo, otherwise open will fail
    INSVideoInfoParserOpenModeExtrainfoOnly,
    
    /// info:demuxerinfo, abalities:snapshot
    INSVideoInfoParserOpenModeDemuxerOnly,
    
    /// info:file-total-size and media-file-size, abalities:none
    INSVideoInfoParserOpenModeHeaderOnly,
    
    /// default mode if you don't call `-setOpenMode:`
    INSVideoInfoParserOpenModeDefault = INSVideoInfoParserOpenModeAllDetail,
};

@class INSMetadata;
@class INSPlayerImage;
@class INSVideoDemuxerInfo;
@protocol INSHttpCacheProxy;
@protocol INSDemuxerCacheProxy;
@interface INSVideoInfoParser : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithURL:(NSURL*)URL;
-(instancetype)initWithURLs:(NSArray<NSURL*>*)URLs;
-(instancetype)initWithURLs:(NSArray<NSURL *> *)URLs httpCacheProxy:(id<INSHttpCacheProxy> _Nullable)httpCacheProxy demuxerCacheProxy:(id<INSDemuxerCacheProxy> _Nullable)demuxerCacheProxy NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) INSVideoInfoParserOpenMode openMode;

@property (nonatomic, readonly) NSURL *videoURL;

@property (nonatomic, readonly, nullable) NSURL *videoURL2;

/// 去除文件尾的媒体文件长度, 单位：字节
@property (nonatomic, readonly) int64_t mediaFileSize;

/// 文件总尺寸，包括文件尾在内, 单位：字节
@property (nonatomic, readonly) int64_t fileTotalSize;

/// 文件尾信息
@property (nonatomic, readonly, nullable) INSExtraInfo *extraInfo;

/// demuxer信息
@property (nonatomic, readonly, nullable) INSVideoDemuxerInfo *demuxerInfo;

/// 加载extra_info时的缓存代理
@property (nonatomic, readonly, weak, nullable) id<INSHttpCacheProxy> httpCacheProxy;

/// 加载demuxer_info时的缓存代理
@property (nonatomic, readonly, weak, nullable) id<INSDemuxerCacheProxy> demuxerCacheProxy;

/// 可选，在调用`-open`前调用，设置open level，以不同的mode打开
/// @param openMode openMode
- (void)setOpenMode:(INSVideoInfoParserOpenMode)openMode;
/**
 *  同步打开媒体，会阻塞线程，获取到视频文件的所有信息
 *
 *  @return 是否成功
 */
- (BOOL)open;

/// 关闭dumexer，FFmpeg对demuxer的个数有限制，如果需要同时存在多个文件的编解码信息，请在open成功之后，优先close，不影响文件属性的获取. 线程不安全，一定要与open在同一个线程
- (void)close;

/// 在open返回前，可以取消当前没有完成的远程parser操作，为了使cancel达到目的，你可能需要在与open不同的线程执行cancel操作
- (void)cancel;

/**
 *  同步截图，调用者需要记得手动释放内存
 *  @param position 截图的时间点  [0.0, 1.0]
 *  @param accurate 是否是精准截图，如果设置为NO，将返回距离指定位置最近的一个关键帧，速度更快，但是不精准；反之，将以更慢的速度返回精准位置的帧数据
 *  @return 截图
 */
- (nullable INSPlayerImage *)screenShotAtPosition:(double)position accurate:(BOOL)accurate;


/// 异步截图
/// @param position 截图的时间点  [0.0, video_duration], 单位 秒
/// @param completion callback
- (void)screenShotAtPosition:(double)position accurate:(BOOL)accurate completion:(void (^)(INSPlayerImage * _Nullable, NSError * _Nullable))completion;

/**
 *  把self.extraInfo写回到当前videoURL指向的文件地址，直接对磁盘中的视频文件作修改，是入侵性的操作
 *  @return 是否更新成功
 */
- (BOOL)updateLocalFileExtraInfo;

/**
 *  更新修复的文件尾信息. 把self.extraInfo.metadata写回到当前指向的文件地址，直接对磁盘中的视频文件作修改，是入侵性的操作
 *  @return 是否更新成功
 */
- (BOOL)updateLocalFileWithFixedExtraInfo;

/**
 修复文件尾，如果调用者因为文件尾丢失而没有拿到oldOffset, 则传入默认值.
 这里只修改self.extraInfo的在内存中的值, 如果需要写回文件尾, 则需要另外调用`updateLocalFileExtraInfo`.
 该方法会使用拼接库重新计算offset, 默认取了0.3 0.5 0.7视频长度下的帧作为输入.

 @param oldOffset 原有offset，不为空
 @return 是否修复成功
 */
- (BOOL)fixExtraInfoWithOldOffset:(NSString *)oldOffset;

/**
 重新计算offset（拼接优化）

 @param positions 视频时间点 [0.0, 1.0]
 @param shouldFixExtraInfo 是否需要修复文件尾, 一般传入NO, 表示只更新offset, 不会修改文件尾其他字段的值. 如果传入YES, 则会重新计算文件尾有关offset的信息，仅限文件尾相关.
 @param oldOffset 原有offset，外界没有拿到需传入默认值
 @return 优化后的offset
 */
- (nullable NSString *)recalculateOffsetWithPositions:(NSArray<NSNumber *> *)positions shouldFixExtraInfo:(BOOL)shouldFixExtraInfo oldOffset:(NSString *)oldOffset;


/// 文件尾信息是否正常
/// @param url 本地文件URL
+ (BOOL)isExtraInfoValid:(NSURL *)url;


/// 将某个素材的文件尾拷贝到另一个素材的文件尾，目标文件原来的文件尾会被覆盖
/// @param fromURL 拷贝的原素材
/// @param toURL 拷贝的目标素材
+ (BOOL)copyExtraInfoFromFile:(NSURL *)fromURL toFile:(NSURL *)toURL;

@end

NS_ASSUME_NONNULL_END
