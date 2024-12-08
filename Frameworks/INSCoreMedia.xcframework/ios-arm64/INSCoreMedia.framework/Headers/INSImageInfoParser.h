//
//  INSImageInfoParser.h
//  INSMediaApp
//
//  Created by jerett on 16/6/17.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSMediaGyro.h"
#import "INSMediaGps.h"
#import "INSExtraInfo.h"
#import "INSLensOffset.h"

typedef enum : NSUInteger {
    /**
     *  未知的图片类型
     */
    INSImageOffsetUnknown,
    /**
     *  第一代4K相机
     */
    INSImageOffset4kV1,
    /**
     *  nano的V1版本
     */
    INSImageOffsetNanoV1,
    /**
     *  nano的V2版本
     */
    INSImageOffsetNanoV2,
} INSImageOffsetVersion;

NS_ASSUME_NONNULL_BEGIN

@interface INSImageInfoParser : NSObject

/**
 *  会下载URL的数据到NSData，如果是网络数据会堵塞
 *
 *  @param URL 图片URL，对于网络图片只读打开；对于本地文件对写打开，可以修改里面的滤镜等数据
 *
 *  @return 如果下载失败，返回nil
 */
-(instancetype)initWithURL:(NSURL *)URL;

/**
 *
 *  @param imgData 图像数据，只读打开
 *
 *  @return parser对象
 */
-(instancetype)initWithData:(NSData *)imgData;

-(BOOL)open;

-(NSString*_Nullable)getMetadata:(NSString*)key;

@property (nonatomic, assign) NSInteger width;

@property (nonatomic, assign) NSInteger height;

/**
 *  图片的二进制数据
 */
@property (nullable, nonatomic, strong, readonly) NSData *imgData;

/**
 *  offst数据
 */
@property (nullable, nonatomic, strong, readonly) NSString *offset;

/**
 *  陀螺仪数据
 */
@property (nullable, nonatomic, strong) INSMediaGyro *gyroData;

/**
 *  gps数据
 */
@property (nullable, nonatomic, strong) INSMediaGps *gpsData;

/**
 *  序列号
 */
@property (nullable, nonatomic, strong) NSString *serialNumber;

/**
 *  图片的信息版本
 */
@property (nonatomic, assign, readonly) INSImageOffsetVersion imageOffsetVersion;

/**
 *  拓展信息，修改滤镜信息使用改变量
 */
@property (nonatomic, strong, readonly, nullable) INSExtraInfo *extraInfo;

/**
 去除文件尾的媒体文件长度, 单位：字节
 */
@property (nonatomic) int64_t mediaFileSize;

/**
 文件总尺寸，包括文件尾在内, 单位：字节
 */
@property (nonatomic) int64_t fileTotalSize;

/**
 *  更新本地文件的滤镜信息，参考initWithURL和initWithData的doc
 *
 *  @return 是否更新成功
 */
-(BOOL)updateLocalFileExtraInfo;

/**
 * 根据镜头类型修复文件尾的数据
 *
 * @param lensType 镜头类型
 */
- (BOOL)fixExtraInfoWithLensType:(INSLensType)lensType;


/**
 修复文件尾，如果上层因为文件尾丢失而没有拿到oldOffset，则传入默认值
 
 @param oldOffset 原有offset，不为空
 @return 是否修复成功
 */
- (BOOL)fixExtraInfoWithOldOffset:(NSString *)oldOffset;

/**
 *  更新修复的文件尾信息
 */
-(BOOL)updateLocalFileWithFixedExtraInfo;


@end

NS_ASSUME_NONNULL_END
