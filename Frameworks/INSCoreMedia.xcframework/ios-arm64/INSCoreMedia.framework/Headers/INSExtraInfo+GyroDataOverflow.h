//
//  INSExtraInfo+GyroDataOverflow.h
//  INSCoreMedia
//
//  Created by HFY on 2018/11/28.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSExtraInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSGyroOverflowErrorCode) {
    INSGyroOverflowErrorCodeFileUnknown = 0,
    INSGyroOverflowErrorCodeFileNoExit = 1,
    INSGyroOverflowErrorCodeFileTooShort = 2,
    INSGyroOverflowErrorCodeNoMetadata = 3,
    INSGyroOverflowErrorCodeDownloadTask = 4,
    INSGyroOverflowErrorCodeDownloadLocation = 5,
};

@interface INSExtraInfo (GyroDataOverflow)

/**
 DEPRECATED! use method in INSExtraInfoTrim
 在指定文件的文件尾插入信息陀螺仪信息. 如果陀螺仪比较大，远程parser 时不会读取陀螺仪数据，trim 的最后阶段，需要把这段陀螺仪数据写回到沙盒中已经保存的文件
 
 @param filePath 目标文件, trim 过后文件
 @param data trim 过后除去gyro 的文件尾信息
 @param gyroFile parse 阶段存储的陀螺仪文件信息, 包含了文件在存储卡的路径，陀螺仪在整个文件中的索引
 @param completion 完成时回调,error 为nil时表示成功, 具体错误参见INSGyroOverflowErrorCode
 */
//+ (void)copyGyroDataToFile:(NSString *)filePath
//          currentExtraData:(NSData *)currentExtraInfo
//          fromHttpGyroInfo:(INSExtraGyroFileInfo *)gyroFileInfo
//                completion:(void (^)(NSError * _Nullable))completion;


/**
 should be called when update local file with huge gyro file.
 */
+ (BOOL) writeExtraMetadataToFile:(NSString *)filePath metadata:(INSExtraMetadata *)extraMetadata;

/**
 when the extrainfo data is out of memory limit (like timelapse video), use this to drop gyro data, 暂时不需要外界调用
 */
+(nullable NSData *)extraInfoDataNoGyroWithContentsOfURL:(NSURL *)fileURL extraInfoSize:(NSUInteger)extraInfoSize gyroFileInfo:(INSExtraGyroFileInfo * _Nullable * _Nullable)gyroFileInfo;

/**
 http, 暂时不需要外界调用
*/
+(nullable NSData *)extraInfoDataNoGyroWithContentsOfHTTPURL:(NSURL *)httpURL extraInfoSize:(NSUInteger)extraInfoSize gyroFileInfo:(INSExtraGyroFileInfo * _Nullable * _Nullable)gyroFileInfo;

@end

NS_ASSUME_NONNULL_END
