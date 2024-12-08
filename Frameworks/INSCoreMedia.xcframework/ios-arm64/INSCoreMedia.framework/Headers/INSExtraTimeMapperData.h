//
//  INSExtraTimeMapperData.h
//  INSCoreMedia
//
//  Created by Mac on 2021/8/20.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSTimeMap.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *   |   ------ double -------   |  -----double------  |
 *   | jumpcut_src_time     |  origin_src_time  |
 */
@interface INSExtraTimeMapperData : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithTimeMap:(INSTimeMap * _Nullable)timemap;

- (nullable instancetype)initWithData:(NSData * _Nullable)data;

- (nullable NSData *)data;

- (int)timeMapCount;

- (int)rangeMapCount;

/// 寻找originSrcTime在映射表中最合理的索引： 如果落在某个range内，则返回该range中小于等于originSrcTime的元素，如果在两个range之间的空缺处，则返回右侧range的start
/// @param originSrcTime 待查找的值
/// @return -1表示查找出错， 表示查找值在列表中，找不到一个左边界，此时你需要自行决定一个有效的index，或者当做错误处理
- (int)leftBorderIndexOfOriginSrcTime:(double)originSrcTime;

/// 寻找originSrcTime在映射表中最合理的索引： 如果落在某个range内，则返回该range中大于等于originSrcTime的元素，如果在两个range之间的空缺处，则返回左侧range的end
/// @param originSrcTime 待查找的值
/// @return -1表示查找出错， 表示查找值在列表中，找不到一个右边界，此时你需要自行决定一个有效的index，或者当做错误处理
- (int)rightBorderIndexForOriginSrcTime:(double)originSrcTime;

/// 映射表的范围是否涵盖待查找的值
/// @param originSrcTime originSrcTime 待查找的值
- (BOOL)coverOriginSrcTime:(double)originSrcTime;


/// 根据originSrcTime范围，寻找目标视频的SrcTime范围，其逻辑是对left/rightBorderIndexForOriginSrcTime的封装
/// @param leftOriginSrcTime 原视频的左侧边界
/// @param rightOriginSrcTime 原视频的右侧边界
/// @param leftSrcTime 在新视频中对应的左侧边界
/// @param rightSrcTime 在新视频中对应的右侧边界
/// @return YES 为成功找到，NO 为参数错误，或者查找发生错误；或者left/rightBorderIndexForOriginSrcTime返回了-1
- (BOOL)borderWithLeftOriginSrcTime:(double)leftOriginSrcTime
                 rightOriginSrcTime:(double)rightOriginSrcTime
                        leftSrcTime:(double *)leftSrcTime
                       rightSrcTime:(double *)rightSrcTime;


/// 获取映射表指定索引下的映射信息，如果index越界则会返回NO
/// @param index 索引值 范围[0, mappedTimeCount)
/// @param srcTime 结果值，目标视频的解码时间戳
/// @param originSrcTime 原始视频的解码时间戳
- (BOOL)mappedTimeInfoWithFrameIndex:(int)index srcTime:(double *)srcTime originSrcTime:(double *)originSrcTime;


/// 获取多段trim后单个视频文件的时间解码戳，一定会返回一个合法映射值，如果没有精确对应，将会返回小于索引参数且最近的一个元素
/// @param originSrcTime 原始文件的解码时间戳
/// @return 返回当前trim后生成视频的解码时间戳
- (double)srcTimeWithOriginSrcTime:(double)originSrcTime;


/// 获取原始文件的解码时间戳，一定会返回一个合法映射值，如果没有精确对应，将会返回小于索引参数且最近的一个元素
/// @param srcTime 多段trim后单个视频文件的时间解码戳
/// @return 返回trim之前的文件的解码时间戳
- (double)originSrcTimeWithSrcTime:(double)srcTime;

@end

NS_ASSUME_NONNULL_END
