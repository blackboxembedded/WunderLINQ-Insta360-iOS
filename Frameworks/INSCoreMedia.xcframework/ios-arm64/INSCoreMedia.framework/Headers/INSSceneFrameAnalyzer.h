//
//  INSSceneFrameAnalyzer.h
//  INSCoreMedia
//
//  Created by HFY on 2019/4/1.
//  Copyright © 2019年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
//API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0)) __attribute__((visibility("hidden")))

extern NSString *const kINSSceneFrameAnalyzerError;
extern NSString *const kINSSceneFrameAnalyzerFrameIndex;
extern NSString *const kINSSceneFrameAnalyzerJsonFilePath;
extern NSString *const kINSSceneFrameAnalyzerJsonFilePathAdd;

typedef NS_ENUM(NSInteger, INSSceneFrameAnalyzerState) {
    
    // 发生错误 userInfo = @{kINSSceneFrameAnalyzerError : NSError}
    INSSceneFrameAnalyzerStateErrorOccur = -1,
    // 初始化状态 userInfo = nil
    INSSceneFrameAnalyzerStateNotStart = 0,
    // 一帧分析结束 userInfo = {kINSSceneFrameAnalyzerFrameIndex : NSNumber<int>}
    INSSceneFrameAnalyzerStateOneFrameAnalyzed,
    // 分析结束 将结果写入json成功 userInfo = {kINSSceneFrameAnalyzerJsonFilePath : NSString}
    INSSceneFrameAnalyzerStateAllSuccess,
};

@class INSSceneFrame;
@class INSSceneFrameAnalyzer;
@class INSVideoInfoConfiguration;
@class INSSceneAnalyzerConfiguration;

@protocol INSSceneFrameAnalyzerDelegate <NSObject>
@optional
/**
 按照INSSceneFrameAnalyzerState 更新状态, 部分信息携带userInfo
 
 @param sceneFrameAnalyzer self
 @param state 当前更新到何种状态
 @param userInfo 对应状态下，携带的信息，部分为nil
 */
- (void)sceneFrameAnalyzer:(INSSceneFrameAnalyzer *)sceneFrameAnalyzer
            didUpdateState:(INSSceneFrameAnalyzerState)state
                  userInfo:(nullable NSDictionary *)userInfo;

@end

@interface INSSceneFrameAnalyzer : NSObject

// 视频基本信息
@property (nonatomic, strong, readonly) INSVideoInfoConfiguration *videoConfig;

// 分析器配置
@property (nonatomic, strong, readonly) INSSceneAnalyzerConfiguration *analyzerConfig;

- (id)init NS_UNAVAILABLE;

// Could be nil if the configuration is wrong
- (nullable instancetype)initWithVideoInfoConfiguration:(INSVideoInfoConfiguration *)videoConfig
                         analyzerConfiguration:(INSSceneAnalyzerConfiguration *)analyzerConfig NS_DESIGNATED_INITIALIZER;

/**
 *  Analyze
 */
- (BOOL)analyzeSceneFrame:(INSSceneFrame *)sceneFrame;

- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer timestampMs:(double)timestampMs frameIndex:(int)frameIndex;

- (BOOL)analyzeUIImage:(UIImage *)image timestampMs:(double)timestampMs frameIndex:(int)frameIndex;

/**
 *  Call when all frames are analyzed. when it returns to YES, means json file has be writen to file.
 *  对不同的分析原文件，必须使用不同的analyzer对象来finish
 */
- (BOOL)finish;

/**
 * 监听分析状态需实现代理
 */
@property(nonatomic, weak) id <INSSceneFrameAnalyzerDelegate> delegate;

/**
 * 当前状态，与上一次代理方法所回调的状态一致
 */
@property (nonatomic, readonly) INSSceneFrameAnalyzerState state;

@end


@interface INSSceneFrameAnalyzer (Extension)

- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer pixelBufferAdd:(CVPixelBufferRef _Nullable)pixelBufferAdd timestampMs:(double)timestampMs frameIndex:(int)frameIndex;

@end

NS_ASSUME_NONNULL_END
