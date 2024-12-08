//
//  INSDeepAutoEditorAnalyzer.h
//  INSCoreMedia
//
//  Created by yons on 7.11.20.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSDeepAutoEditorConfiguration;
@class INSDeepAutoEditorOutputConfiguration;
@class INSDeepAutoEditorResult;
@class INSOffscreenRender;

typedef NS_ENUM(NSInteger, INSDeepAutoEditorAnalyzerErrorCode) {
    // prepare error
    INSDeepAutoEditorAnalyzerErrorCodePrepare = 501,
    // 算法对象出错
    INSDeepAutoEditorAnalyzerErrorCodeEditorEmpty = 502,
    // 图片为空，检查抽帧和与渲染
    INSDeepAutoEditorAnalyzerErrorCodeMatEmpty = 503,
    // 没有初始化算法，也就是没有调用prepare
    INSDeepAutoEditorAnalyzerErrorCodeNotInit = 504,
    // 算法执行出错
    INSDeepAutoEditorAnalyzerErrorCodeProgress = 505,
    // 获取结果出错
    INSDeepAutoEditorAnalyzerErrorCodeGetResult = 506,
    // 算法执行出错
    INSDeepAutoEditorAnalyzerErrorCodeIndexOversize = 507,
    // 没有缓存就直接调用了getResult；也就是没有进行analyze
    INSDeepAutoEditorAnalyzerErrorCodeNoCacheFile = 508,
    
    INSDeepAutoEditorAnalyzerErrorCodeUnknown = 600,
};

@interface INSDeepAutoEditorAnalyzer : NSObject

@property (nonatomic, readonly) INSDeepAutoEditorConfiguration *configuration;

@property (nonatomic, readonly) INSOffscreenRender *offscreenRender;

- (instancetype)init NS_UNAVAILABLE;

/**
 * 有关线程的说明：
 * 1. 以下所有方法，需要在同一个线程执行
 * 2. 在销毁对象时请注意，做好线程同步，如调用close释放资源时，要保证analyze语句已经执行完成，否则可能造成野指针错误
 */
///

/// 构造方法
/// @param configuration 配置项
/// @return 对象实例，对算法的一些初始化操作如果失败的话，会返回nil
- (nullable instancetype)initWithConfiguration:(INSDeepAutoEditorConfiguration *)configuration;


/// 用来判断当前configuration下指的素材，在磁盘中是否存在分析结果的缓存
- (BOOL)hasCachedResult;

/// 这是一个同步方法，如果需要逐帧分析，则需要首先调用这个函数
/// @param offscreenRender 更具需求传入不同的render， 如果普通全景的，用sphericalPanoOffscreenRender，注意配置offset，fov，distance，以及gyroPlayer；
/// 如果是机内防抖的视频，则使用normalOffscreenRender，注意有些机型拍出来的视频可能需要做一些roll方向的旋转（如go2），这些都遵循播放页的设置即可
/// @param error error指针
- (void)prepareAnalyzerWithOffscreenRender:(INSOffscreenRender *)offscreenRender error:(NSError * _Nullable * _Nullable)error;

// analyze should be in the same thread as init method, fish eye or 机内防抖视频； not support flat pano
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;

/// get result
- (nullable INSDeepAutoEditorResult *)getDeepAutoEditorResultWithOutputConfig:(INSDeepAutoEditorOutputConfiguration *)outputConfig
                                                        error:(NSError * _Nullable * _Nullable)error;
/// should call this method when cancel analyze process and finish get result
- (void)close;

@end

NS_ASSUME_NONNULL_END
