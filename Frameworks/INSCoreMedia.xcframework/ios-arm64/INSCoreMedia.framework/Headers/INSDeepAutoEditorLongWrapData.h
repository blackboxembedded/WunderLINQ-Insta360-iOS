//
//  INSDeepAutoEditorLongWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDeepAutoEditorLongWrapData : NSObject

@end

@interface INSDeepAutoEditorLongConfiguration : NSObject

/// 分析时渲染的宽度，400
@property(nonatomic) int frameWidth;

/// 分析时渲染的高度，400 * （9.0 / 16.0）
@property(nonatomic) int frameHeight;

/// sample rate or input frame 1.6667。表示每秒有多少关键帧：如关键帧是600ms间隔，则sampleRate = 1 / (600/1000) = 1.6667
@property(nonatomic) double sampleRate;

/// frame rate(frame per second)
@property(nonatomic) double fps;

/// video duration， in ms.  to calc total number of frames of the video to be processed
@property(nonatomic) double duration;

/// cache directory path
@property(nonatomic) NSString *cacheDir;

@property(nonatomic) BOOL visualDebug;

@property(nonatomic) BOOL forceUseMNN;

@property(nonatomic) BOOL phaseOne;
@end


@interface INSDeepAutoEditorLongTimeRange : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double startTime;

@property (nonatomic) double endTime;

@property (nonatomic) float maxScore;

@end


@interface INSDeepAutoEditorLongResult : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic, nullable) NSArray<INSDeepAutoEditorLongTimeRange *> *sections;

@end


NS_ASSUME_NONNULL_END
