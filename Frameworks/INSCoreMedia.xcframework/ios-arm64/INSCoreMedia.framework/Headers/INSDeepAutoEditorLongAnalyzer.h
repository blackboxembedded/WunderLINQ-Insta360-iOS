//
//  INSDeepAutoEditorLongAnalyzer.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSDeepAutoEditorLongConfiguration;
@class INSDeepAutoEditorLongTimeRange;
@class INSDeepAutoEditorLongResult;
@class INSOffscreenRender;
@interface INSDeepAutoEditorLongAnalyzer : NSObject

@property (nonatomic, readonly) INSDeepAutoEditorLongConfiguration *configuration;

@property (nonatomic, readonly) INSOffscreenRender *offscreenRender;

- (instancetype)init NS_UNAVAILABLE;


- (nullable instancetype)initWithConfiguration:(INSDeepAutoEditorLongConfiguration *)configuration;

/// 用来判断当前configuration下指的素材，在磁盘中是否存在分析结果的缓存
- (BOOL)hasCachedResult;

/// 这是一个同步方法，如果需要逐帧分析，则需要首先调用这个函数
/// @param offscreenRender 更具需求传入不同的render， 如果普通全景的，用sphericalPanoOffscreenRender，注意配置offset，fov，distance，以及gyroPlayer；
/// 如果是机内防抖的视频，则使用normalOffscreenRender，注意有些机型拍出来的视频可能需要做一些roll方向的旋转（如go2），这些都遵循播放页的设置即可
/// @param error error指针
- (void)prepareAnalyzerWithOffscreenRender:(INSOffscreenRender *)offscreenRender error:(NSError * _Nullable * _Nullable)error;



/*
  抽帧，重复执行以下分析流程
 */

/// analyze one key frame and the its next normal frame
/// @param pixelBufferKey key frame fisheye  data
/// @param rightPixelBufferKey key frame right fisheye data,  nil if the video file doesn't have one
/// @param pixelBufferNext key frame next fisheye data
/// @param rightPixelBufferNext key frame next right fisheye data, nil if the video file doesn't have one
/// @param ptsMsKey key frame timestamp
/// @param ptsMsNext key frame next timestamp
/// @return YES if success, NO if fail
- (BOOL)analyzePixelBufferKey:(CVPixelBufferRef)pixelBufferKey
          rightPixelBufferKey:(CVPixelBufferRef _Nullable)rightPixelBufferKey
              pixelBufferNext:(CVPixelBufferRef)pixelBufferNext
         rightPixelBufferNext:(CVPixelBufferRef _Nullable)rightPixelBufferNext
                     ptsMsKey:(double)ptsMsKey
                    ptsMsNext:(double)ptsMsNext;


/// analyze one frame whose timestamp is the middle of two key frame, and its next normal frame
/// @param pixelBufferMiddle middle frame fisheye  data
/// @param rightPixelBufferMiddle middle frame right fisheye data,  nil if the video file doesn't have one
/// @param pixelBufferNext middle frame next fisheye data
/// @param rightPixelBufferNext middle frame next right fisheye data, nil if the video file doesn't have one
/// @param ptsMsMiddle middle frame timestamp
/// @param ptsMsNext middle frame next timestamp
- (BOOL)analyzePixelBufferMiddle:(CVPixelBufferRef)pixelBufferMiddle
          rightPixelBufferMiddle:(CVPixelBufferRef _Nullable)rightPixelBufferMiddle
                 pixelBufferNext:(CVPixelBufferRef)pixelBufferNext
            rightPixelBufferNext:(CVPixelBufferRef _Nullable)rightPixelBufferNext
                     ptsMsMiddle:(double)ptsMsMiddle
                       ptsMsNext:(double)ptsMsNext;

/// 当config的phaseOne参数设置为true时，才可调用getPhaseOneFrameMap、phaseTwoProcessPixelBuffer
- (nullable NSArray<NSNumber*>*)getPhaseOneFrameMap;

/// 根据getPhaseOneFrameMap返回的时间戳获取pixelbuffer作为输入
/// @param pixelbuffer key frame fisheye  data
/// @param rightPixelbuffer key frame right fisheye data,  nil if the video file doesn't have one
/// @param 当前帧的时间戳
- (BOOL)phaseTwoProcessPixelBuffer:(CVPixelBufferRef)pixelbuffer
                     rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelbuffer
                            timestamp:(double)timestamp;

/// 所有帧都分析结束后，获取分析结果
- (nullable INSDeepAutoEditorLongResult *)getDeepAutoEditorResultWithError:(NSError * _Nullable * _Nullable)error;

- (void)close;

@end

NS_ASSUME_NONNULL_END
