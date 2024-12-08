//
//  INSDeepAutoBgmAnalyzer.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/23.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSDeepAutoBgmAnalyzerErrorCode) {
    /// 一般发生在setup的时候，模型或者算法对象生成失败
    INSDeepAutoBgmAnalyzerErrorCodeInit = -1010,
    /// 获取结果时错误，一般没有任何分析结果返回时会报该错误；或者输入的全部帧不是15帧也会返回错误
    INSDeepAutoBgmAnalyzerErrorCodeGetResult = -1011,
    /// 算法报错，意义暂时不明
    INSDeepAutoBgmAnalyzerErrorCodeObjectEmpty = -1012,
    /// 如果连续送帧超过15帧，会报该错误
    INSDeepAutoBgmAnalyzerErrorCodeImageNumExceed = -1013,
    /// 没有正确初始化用于渲染的offscreen render
    INSDeepAutoBgmAnalyzerErrorCodeRender = -1014,
    /// OpenCV捕获异常
    INSDeepAutoBgmAnalyzerErrorCodeOpenCV = -1015,
    /// 其他位置错误
    INSDeepAutoBgmAnalyzerErrorCodeUnknown = -1100,
};

@class INSOffscreenRender;
@class INSDeepAutoBgmConfiguration;
@class INSDeepAutoBgmResult;
@class INSDeepAutoBgmOutputConfig;
@class INSDeepAutoBgmAnalyzer;
@protocol INSDeepAutoBgmAnalyzerDelegate <NSObject>
@optional
/**
发生错误时，会通过该回调在 主线程 抛出错误
 */
- (void)autoBgmAnalyzer:(INSDeepAutoBgmAnalyzer *)autoBgmAnalyzer progressError:(NSError *)error;

@end


@interface INSDeepAutoBgmAnalyzer : NSObject

@property(nonatomic, readonly)INSDeepAutoBgmConfiguration *configuration;

@property(nullable, nonatomic, readonly) INSOffscreenRender *offscreenRender;

@property(nonatomic, weak, nullable) id<INSDeepAutoBgmAnalyzerDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConfiguration:(INSDeepAutoBgmConfiguration *)configuration
                  offscreenRender:(INSOffscreenRender *)offscreenRender;
/**
 1.以下方法均为同步方法，如果执行出现错误，返回值会返回NO或者nil；
 2.错误码会通过INSDeepAutoBgmAnalyzerDelegate提供的方法抛出
 3.对于异常的处理，建议在以下方法返回之后再进行后续处理
 */

/// 必须调用，如果setup返回NO，则后续流程会执行失败
- (BOOL)setup;

/// analyze should be in the same thread as init method, fish eye or 机内防抖视频； not support flat pano；you need only input 15 frames, the gap between two frames is videoDurationMs / 15
/// @param pixelBuffer 双鱼眼（4K），单鱼眼（go系列、x2等）、机内防抖
/// @param rightPixelBuffer 5.7k文件的第二个鱼眼，可以为nil
/// @param timestampMs 当前帧的时间戳
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;


/// 获取结果，如果出错，将返回nil，同时通过代理抛出错误码
/// @param outputConfig 获取结果时使用的参数
- (nullable INSDeepAutoBgmResult *)getDeepBgmResultWithOutputConfig:(INSDeepAutoBgmOutputConfig *)outputConfig;

/// 如果已经获取到结果，可以通过该方法，释放占用的资源
- (void)close;

@end

NS_ASSUME_NONNULL_END
