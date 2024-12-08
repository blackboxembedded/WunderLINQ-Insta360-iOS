//
//  INSExtraInfoParser.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/18.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSExtraInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef  NS_OPTIONS(NSUInteger, INSExtraInfoFetchType) {
    INSExtraInfoFetchTypeMetadata       = 0,

    INSExtraInfoFetchTypeThumbnail      = 1 << 0,

    INSExtraInfoFetchTypeGyro           = 1 << 1,

    INSExtraInfoFetchTypeExposure       = 1 << 2,
    
    INSExtraInfoFetchTypeExtThumbnail   = 1 << 3,
    
    INSExtraInfoFetchTypeFramePtsData   = 1 << 4,
    
    INSExtraInfoFetchTypeGPS            = 1 << 5,
    
    INSExtraInfoFetchTypeAAAData        = 1 << 6,
    
    INSExtraInfoFetchTypeHighlight      = 1 << 7,
    
    INSExtraInfoFetchTypeAAASimData     = 1 << 8,
};

@protocol INSHttpCacheProxy;
@interface INSExtraInfoParser : NSObject

-(instancetype)initWithURLs:(NSArray<NSURL*>*)URLs;

-(instancetype)initWithURLs:(NSArray<NSURL*>*)URLs httpProxy:(nullable id<INSHttpCacheProxy>)httpProxy;

-(BOOL)open;

/**
 * 只会返回基本信息mediaFileSize等，不会返回extraInfo
 */
-(BOOL)parseHeader;

-(void)cancel;

/**
 去除文件尾的媒体文件长度, 单位：字节
 */
@property (nonatomic, readonly) int64_t mediaFileSize;

/**
 * 文件尾信息的长度
 */
@property (nonatomic, readonly) int64_t extraInfoSize;

/**
 文件总尺寸，包括文件尾在内, 单位：字节
 */
@property (nonatomic, readonly) int64_t fileTotalSize;

/**
 *  拓展信息，修改滤镜信息使用改变量
 */
@property (nullable, nonatomic, strong, readonly) INSExtraInfo *extraInfo;

@end

NS_ASSUME_NONNULL_END
