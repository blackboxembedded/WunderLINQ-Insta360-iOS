//
//  INSFramePtsPlayer.h
//  INSCoreMedia
//
//  Created by kahn on 2018/10/9.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSFramePtsPlayer : NSObject

@property (nonatomic, readonly) double timeOffsetMs;

@property (nonatomic, readonly) BOOL isMicroSecond;

@property (nonatomic, readonly) BOOL staticTimelapse;

/**
 处理timelapse精准时间戳，输入输出都保证为毫秒为单位，如果是isRawGyro，则内部处理单位
 @param data 每一帧的pts数据集
 @param isMicroSecond 是否是raw数据，如果为YES，时间戳的单位是微秒，否则为毫秒
 @param timeOffsetMs 第一帧pts数据, 用来计算偏移量 (当isRawGyro为YES时，单位微秒)
 @param staticTimelapse是否是静态延迟视频
 */
- (instancetype)initWithData:(NSData *)data
               isMicroSecond:(BOOL)isMicroSecond
                timeOffsetMs:(double)timeOffsetMs
             staticTimelapse:(BOOL)staticTimelapse;

/// must set the correct value before getting the result.
- (void)configFrameRate:(double)frameRate;

/// 通过解码帧的序号，计算固件时间戳；以timeOffsetMs所在位置为第一帧;
/// 如data解出来的序列为 t0 t1 t2 timeOffsetMs t3 t4, 那么t0,t1,t2是被舍弃的，当index = 0，这个接口返回timeOffsetMs， 当index = 2, 返回t4;
- (double)framePtsMsWithFrameIndex:(int)index;

/**
 类似 timestamp(s) = pts * av_q2d(st->time_base) 作逆运算
 解码时间戳 -> 固件时间戳
 
 @param timestamp 用来计算pts的序号, in ms
 @return 当前解码帧对应的固件原始时间戳，减去firstFrameTimestamp后的取值
 */
- (double)framePtsMsWithDecodeTimestampMs:(double)timestamp;

/**
 通过timelapse的原始pts，计算出该帧在解码队列中的时间戳
 固件时间戳->解码时间戳
 
 @param pts 文件尾序列记录的timelapse录制pts
 @return 解码时间戳 ms
 */
- (double)decodeTimestampMsWithFramePtsMs:(double)pts;

/// 获取当前相邻帧pts的间隔 单位毫秒；0表示正常拍摄，没有interval
- (double)timeInterval;

/// 拍摄的帧间隔，由ptsInterval 换算获取，如两帧之间间隔100ms，可知拍摄时的情况为每三帧取了一帧，故frameinterval = 3; 这里可能为小数，0表示没有interval
- (int)frameInterval;


/// 由拍摄时的时间戳跳跃间隔与帧率，可以算出跳帧间隔，也就是原始素材拍摄时的基础倍速。
+ (int)frameIntervalWithTimeIntervalMs:(double)timeIntervalMs frameRate:(double)frameRate;

@end

NS_ASSUME_NONNULL_END
