//
//  INSFileDownloader.h
//  INSCoreMedia
//
//  Created by HFY on 2021/11/12.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSCacheCategory) {
    INSCacheCategoryDefault = 0,  // default.
    INSCacheCategoryBgm = 1,
    INSCacheCategoryExtraInfo = 2,
    INSCacheCategoryFormatParse = 3,
};

typedef void (^FileDownloadProgressBlk)(float progress);
typedef void (^FileDownloadCompleteBlk)(NSURL *url, NSError * _Nullable error);

@interface INSFileDownloader : NSObject

- (instancetype)init NS_UNAVAILABLE;

// 将cacheDir全权交给INSFileDownloader管理（缓存的生成与移除）
- (instancetype) initWithCacheDir:(NSURL*)cacheDir cacheCategory:(INSCacheCategory)cacheCategory;

// 设置并开始一项下载任务，当前有活动下载时无效并返回false
// 将url下载到outputDir/rename，rename为nil时使用默认文件名
- (bool) downloadURL:(NSURL*)url outputDir:(NSURL*)outputDir rename:(nullable NSString*)rename progress:(FileDownloadProgressBlk)progress completion:(FileDownloadCompleteBlk)completion;

// 中断当前下载
- (void) interrupt;

// 移除url对应的缓存（下载中的延后移除）
- (void) removeCacheOfURL:(NSURL*)url;

// 移除缓存目录下全部缓存（下载占用的缓存延后移除）
- (void) removeCacheAll;

// 返回是否有活动下载
- (bool) isDownloading;

@end

NS_ASSUME_NONNULL_END
