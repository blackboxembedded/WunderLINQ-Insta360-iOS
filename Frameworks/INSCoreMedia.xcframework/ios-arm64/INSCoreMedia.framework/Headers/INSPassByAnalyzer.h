//
//  INSPassByAnalyzer.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/17.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN
@class INSPassByAnalyzerConfiguration;
@class INSPassByFilterConfiguration2;
@class INSPassByFilterConfiguration;
@class INSAppletVideoInfo;
@class INSTrackerSequence;
@class INSExtraGyroData;

typedef NS_ENUM(NSInteger, INSPassByAnalyzerErrorCode){
    INSPassByAnalyzerErrorCodeNormalFilterConfig = -1,
    INSPassByAnalyzerErrorCodeJsonFileIO = -2,
    INSPassByAnalyzerErrorCodeCarPoseFilterInit = -3,
    INSPassByAnalyzerErrorCodeProcess = -4,
};

@interface INSPassByAnalyzer : NSObject

@property (nonatomic, readonly)INSPassByAnalyzerConfiguration *configuration;

@property (nonatomic, readonly) INSAppletVideoInfo *videoInfo;

@property (nonatomic, readonly) INSTrackerSequence *forwardTrackSequence;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConfiguration:(INSPassByAnalyzerConfiguration *)configuration
                            videoInfo:(INSAppletVideoInfo *)videoInfo
                 forwardTrackSequence:(INSTrackerSequence *)forwardTrackSequence;


/// 返回nil表示没有错误
- (BOOL)setup;

// analyze should be in the same thread as init method, fish eye
// 需要每隔100ms输入一帧
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;

/// 将analyze后的结果存储在configuration.analyzerResultJsonPath路径下
- (BOOL)finish;


- (void)filterPassbyResult:(INSPassByFilterConfiguration *)filterConfig
           progressHandler:(void (^ _Nullable) (float progress))progressHandler
                completion:(void (^ _Nullable ) (NSError * _Nullable error))completion;

/// 同步方法，耗时很小，对分析的结果做过滤，输入一个json文件路径，经过这个方法处理以后，过滤后的结果可以输出到另一个路径下。其中，过滤前与过滤后的数据结构和json格式不变，但这个数据结果对调用者是透明的
/// @param filterConfig 必须配置输入路径，以及过滤后的输出路径，其中，输入路径下必须能够找到analyze的结果文件
/// @param forwardTrackSequence 行进方向数据，可以用INSTrackSequenceParser获取
/// @param gyroData 文件尾解析出的陀螺仪数据
/// @return NO 表示过滤失败，可以查看log
+ (BOOL)filterPassbyResult:(INSPassByFilterConfiguration2 *)filterConfig
      forwardTrackSequence:(INSTrackerSequence *)forwardTrackSequence
                  gyroData:(INSExtraGyroData *)gyroData;

@end

NS_ASSUME_NONNULL_END
