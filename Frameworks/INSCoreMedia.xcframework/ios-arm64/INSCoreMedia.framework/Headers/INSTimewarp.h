//
//  INSTimewarp.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/12.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class INSTimeScale;
@class INSExtraGyroData;

typedef NS_ENUM(NSInteger, INSTimewarpSpeed) {
    INSTimewarpSpeedLevelUnknown = -1,  //算法结果返回了除以下四种level的其他情况
    INSTimewarpSpeedLevel5 = 0,         //5x
    INSTimewarpSpeedLevel8 = 1,         //8x
    INSTimewarpSpeedLevel10 = 2,        //10x
    INSTimewarpSpeedLevel20 = 3,        //20x
};

@interface INSTimewarpResult : NSObject<NSCoding, NSCopying, NSMutableCopying>

@property(nonatomic) double startTimeMs;

@property(nonatomic) double endTimeMs;

@property(nonatomic) INSTimewarpSpeed speed;

@end

@interface INSTimewarp : NSObject

// 使用陀螺仪时间算出来的结果，由于陀螺仪数据相对于视频是溢出的，所以得到的时间可能超出[0, video_duration], 上层要自行对结果做调整
+ (NSArray<INSTimewarpResult*>* _Nullable)timescaleWithGyroData:(INSExtraGyroData*)gyroData;

+ (BOOL)isStillWithGyroData:(INSExtraGyroData*)gyroData;


/// 获取timelapse视频相邻帧pts的间隔
/// @param gyroData 防抖数据 如果不存在或者传入的gyroData来自非timelapse的素材，返回0, 表示该视频没有interval
+ (double)timelapseIntervalMs:(INSExtraGyroData *)gyroData;

/// 对于30fps的视频文件， 如两帧之间拍摄间隔100ms，可知拍摄时的情况为每三帧取一帧，故frameinterval = 3; 是四舍五入的结果，0表示没有interval
+ (int)timelapseFrameInterval:(INSExtraGyroData *)gyroData videoFrameRate:(double)videoFrameRate;

/// 按照30fps计算
+ (int)timelapseFrameInterval:(INSExtraGyroData *)gyroData DEPRECATED_MSG_ATTRIBUTE("Please use -timelapseFrameInterval:videoFrameRate:");;

@end

NS_ASSUME_NONNULL_END
