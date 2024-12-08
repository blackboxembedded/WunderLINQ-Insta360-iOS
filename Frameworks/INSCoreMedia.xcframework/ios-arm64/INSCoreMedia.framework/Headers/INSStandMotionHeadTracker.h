//
//  INSStandMotionHeadTracker.h
//  INSCoreMedia
//
//  Created by Mac on 2021/8/13.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSSkeletonConfiguration.h"
NS_ASSUME_NONNULL_BEGIN

@interface INSStandMotionHeadTrackerParam : NSObject
// 常规
@property (nonatomic, strong) NSArray <NSURL *> *urls; // 双鱼眼视频路径
@property (nonatomic, copy) NSString *offset;
@property (nonatomic, strong) INSGyroPBPlayer *gyroPlayer; // 须由initWithNewVersionPBGyroData接口初始化
@property (nonatomic, copy) NSArray <INSSkeletonPair *> *skeletonPairs; // 须由[INSSkeletonRecommender recommendSkeletonWithPreferredMode:INSSkeletonPreferredModeStand error:]筛选
@property (nonatomic) double personBoxHeightRatio; // 人像框高度占屏幕高度的比例，取值[0.5, 0.9], 默认0.7
@property (nonatomic) int width; // width与height分别为头部追踪所用图像的宽与高，默认1920*1080；调整需保持比例（否则人像难以垂直居中），且不低于768*432
@property (nonatomic) int height;
@property (nonatomic, copy) void(^progressNotifier)(double progress, int errorCode); // 进度回调，progress取值0到1, errorCode非0说明出错
// debug配置
@property (nonatomic) bool debug_mode;
@property (nonatomic, copy) NSURL *cacheDir; // 若debug_mode开启，须同时配置此项，最后带斜杠'/'
@end



@interface INSStandMotionHeadTracker : NSObject
// 初始化方法1(有缓存): 通过init初始化，然后调用inputSmoothedSkeletonPairs传入从文件读取的缓存skeletonPairs，无需对人头追踪
// 可以处理多个视频（多次调用inputSmoothedSkeletonPairs传入不同视频的缓存即可）
- (instancetype) init;
- (void) inputSmoothedSkeletonPairs:(NSArray <INSSkeletonPair *> *)skeletonPairs;
// 初始化方法2(无缓存): 通过initWithParam配置urls、offset、gyroPlayer、skeletonPairs、personBoxHeightRatio、width、height、progressNotifier，需要对人头追踪
// 只能处理单个视频（context切换的开销 >> 创建新tracker的开销）
- (instancetype) initWithParam:(INSStandMotionHeadTrackerParam *)param;
// 使用方法: setPersonBoxHeightRatio与process搭配，process返回的skeletonPairs用于缓存（由于内部数据转换的浮点数误差，有缓存的情况下尽量避免再次缓存）
- (void) setPersonBoxHeightRatio:(double) ratio; // 设置人像框高度占屏幕高度的比例
- (NSArray <INSSkeletonPair *> *) process; // 对于使用初始化方法1、第一次调用process的的情况，需要对人头追踪，较为耗时；其他情况都不耗时。
@end
NS_ASSUME_NONNULL_END
