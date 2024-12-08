//
//  INSExtraGyroDataGroup.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/5.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSExtraGyroData.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  对于微秒时间戳，这里不做转换，只是记录在isMicroSecond中，交给调用者pb_player统一转换
 */
@class INSExtraGyroData;
@class INSDynamicGyroAccRangeInfo;
@interface INSExtraGyroDataGroup : NSObject

@property (nonatomic, readonly) int64_t groupCount;

@property (nonatomic, readonly) INSGyroDataType type;

@property (nonatomic, readonly) BOOL isMicroSecond;

@property (nonatomic, readonly) BOOL hasSecondary;

@property (nonatomic, readonly) int64_t gyroCount;

@property (nonatomic, readonly) int64_t gyroCountExt;

@property (nonatomic, readonly) NSMutableArray<NSNumber *> *timeOffsetGroup;

@property (nonatomic, nullable) INSDynamicGyroAccRangeInfo *dynamicGyroAccRangeInfo;

@property (nonatomic) INSVideoPtsMapType ptsMapType;

@property (nonatomic) NSInteger roundedFrameRate;

- (BOOL)appendGyroData:(INSExtraGyroData *)gyroData;

// 获取本次输入的data，会删除结尾处于上一段重合的部分
- (NSData *)getLatestGyroValidData;

- (NSData *)getGyroTotalData;

- (nullable NSData *)getGyroTotalDataExt;

// 获取当前已经获取的所有曝光时间数据；
- (NSData *)getExposureTotalData;


@end

NS_ASSUME_NONNULL_END
