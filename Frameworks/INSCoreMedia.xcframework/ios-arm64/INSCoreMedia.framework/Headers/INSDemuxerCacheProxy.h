//
//  INSDemuxerCacheProxy.h
//  INSCoreMedia
//
//  Created by Mac on 2021/5/26.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSVideoColorSpace) {
    INSVideoColorSpaceUnknown = 0,
    INSVideoColorSpaceBT601,
    INSVideoColorSpaceBT709,
};

typedef NS_ENUM(NSUInteger, INSVideoColorRange) {
    INSVideoColorRangeUnknown = 0,
    INSVideoColorRangeFull,
    INSVideoColorRangeVideo,
};


@interface INSVideoDemuxerInfo : NSObject <NSCopying, NSMutableCopying, NSCoding>

/**
 * 视频宽度
 */
@property (nonatomic) NSInteger width;

/**
 * 视频高度
 */
@property (nonatomic) NSInteger height;

/**
 * 视频时长，为dumex数据，单位：秒（s）
 */
@property (nonatomic) double duration;

/**
 * rotation
 */
@property (nonatomic) double rotation;

/**
 * 视频帧率
 */
@property (nonatomic) double framerate;

/**
 * total stream bitrate in bit/s, 0 if not available
 */
@property (nonatomic) int64_t bitrate;


/**
 *  判断是否存在音轨
 */
@property (nonatomic) BOOL isExistAudio;
/**
 *  判断是否是全景声
 */
@property (nonatomic) BOOL isSpatialAudio;

/**
 *  判断是否存是H265的视频
 */
@property (nonatomic) BOOL isH265Codec;

/**
 *  判断是否是全景视频
 */
@property (nonatomic) BOOL isSpherical;

/**
 *  颜色空间
 */
@property (nonatomic) INSVideoColorSpace colorSpace;

/**
 *  色彩范围
 */
@property (nonatomic) INSVideoColorRange colorRange;

@end

@protocol INSDemuxerCacheProxy <NSObject>

- (nullable INSVideoDemuxerInfo *)readDemuxerInfoCacheForVideo:(NSURL *)videoURL;

- (void)writeDemuxerInfo:(INSVideoDemuxerInfo *)demuxerInfo cacheForVideo:(NSURL *)videoURL;

@end

@interface INSDemuxerCacheDefaultProxy : NSObject<INSDemuxerCacheProxy>

@end

NS_ASSUME_NONNULL_END
