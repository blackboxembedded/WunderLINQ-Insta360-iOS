//
//  INSAutoEditorWrapData.h
//  INSCoreMedia
//
//  Created by yons on 7.11.20.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDeepAutoEditorWrapData : NSObject

@end

@interface INSDeepAutoEditorConfiguration : NSObject

/// 分析时渲染的宽度，400
@property(nonatomic) int frameWidth;

/// 分析时渲染的宽度，400 * (9.0 / 16.0)
@property(nonatomic) int frameHeight;

/// sample rate or input frame 1.6667
@property(nonatomic) double sampleRate;

/// frame rate(frame per second)
@property(nonatomic) double fps;

/// video duration， in ms.  to calc total number of frames of the video to be processed
@property(nonatomic) double duration;

/// cache directory path
@property(nonatomic) NSString *cacheDir;

@property(nonatomic) BOOL visualDebug;

@property(nonatomic) BOOL forceUseMNN;

@end


/// the mode to generate returned section, can be "center" or "score"
/// "center" mode return section based on center expansion, "score" mode return section to have highest score
typedef NS_ENUM(NSUInteger, INSDeepAutoEditorOutpuMode) {
    
    INSDeepAutoEditorOutpuModeCenter,
    
    INSDeepAutoEditorOutpuModeScore,
};

@interface INSDeepAutoEditorOutputConfiguration : NSObject

/// 推荐结果使用哪种mode，默认为Center
@property (nonatomic) INSDeepAutoEditorOutpuMode outputMode;

/// 推荐的时长， in ms
@property (nonatomic) double outputDuration;

@end


@interface INSDeepAutoEditorScore : NSObject <NSCopying, NSMutableCopying, NSCoding>

// the name of score module
@property(nonatomic) NSString *name;

// the score of each frame, double
@property(nonatomic) NSArray<NSNumber *> *scoreCurves;

@end

@interface INSDeepAutoEditorTimeRange : NSObject <NSCopying, NSMutableCopying, NSCoding>

// 片段起始时间戳 in ms
@property (nonatomic) double startTime;

// 片段结束时间戳 in ms
@property (nonatomic) double endTime;

@end

@interface INSDeepAutoEditorResult : NSObject <NSCopying, NSMutableCopying, NSCoding>

/// 首选的推荐区段
@property(nonatomic)INSDeepAutoEditorTimeRange *section;

/// 次要推荐区段
@property(nonatomic)INSDeepAutoEditorTimeRange *sectionSecondary;

/// int型NSNumber对象
@property(nonatomic)NSArray<NSNumber *> *changePoints;

/// name and score curve of a score module
@property(nonatomic)NSArray<INSDeepAutoEditorScore *> *scores;
    
@end

NS_ASSUME_NONNULL_END
