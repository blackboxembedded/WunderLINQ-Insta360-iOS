//
//  INSVideoFrameExtracter.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/13.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

@class INSPlayerImage;
@class INSEmSegment;

NS_ASSUME_NONNULL_BEGIN

@interface INSVideoFrameExtracter : NSObject


/**
 创建对象
 @param url 文件url
 @param mediaFileSize 去除文件尾的文件大小，单位：字节,,如果传入0，表示无文件尾
 @return 对象实例
 */
- (instancetype) initWithURL:(NSURL*)url mediaFileSize:(int64_t)mediaFileSize;


/**
 创建对象
 @param urls 文件url
 @param mediaFileSize urls[0]的去除文件尾的文件大小，单位：字节，,如果传入0，表示无文件尾
 @return 创建对象
 */
- (instancetype) initWithURLs:(NSArray<NSURL*>*)urls mediaFileSize:(int64_t)mediaFileSize;

/**
 创建对象
 @param emSegments 循环录影文件列表
 @param mediaFileSize urls[0]的去除文件尾的文件大小，单位：字节，,如果传入0，表示无文件尾
 @return 创建对象
 */
- (instancetype) initWithEmSegments:(NSArray<INSEmSegment*>*)emSegments mediaFileSize:(int64_t)mediaFileSize;

/**
 打开
 */
- (NSError*_Nullable) open;

/// 关闭，释放资源，调用此函数后，不能再调用其他任何功能函数
- (void) close;

/**
 seek
 @param srcTimeMs seek的时间点,单位ms
 @param accurate 为YES时表示seek到最近的frame，为NO时表示seek到 key frame
 @return 成功返回nil，失败返回error
 */
- (NSError*_Nullable) seek:(double)srcTimeMs accurate:(BOOL)accurate;

/**
 not only key frame
 @param error 如果error code为100 表示文件结束，其他为查找错误
 @return 所需要的frame
 */
- (INSPlayerImage * _Nullable) nextFrame:(NSError *_Nullable*)error;

/**
 only key frame 若是seek后执行，将会返回seek position的前一个key frame
 @param error 如果error code为100 表示文件结束，其他为查找错误
 @return 所需要的key frame
 */
- (INSPlayerImage * _Nullable) nextVideoKeyFrame:(NSError *_Nullable*)error;

@end

NS_ASSUME_NONNULL_END
