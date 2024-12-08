//
//  INSCinelapseDatasource.h
//  INSCoreMedia
//
//  Created by HFY on 2022/1/21.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *SourceVideoIDType;

@class INSTrackerSequence;
@class INSMediaSpeed;
@interface INSCinelapseDatasource : NSObject<NSCopying, NSMutableCopying, NSCoding>

/// 原始素材的标记，结果中将会返回这里配置的，给调用者定位原始素材，可以是你能够用于匹配出原始素材的任意标记
@property (nonatomic) SourceVideoIDType sourceVideoIdentifier;

@property (nonatomic) double sourceVideoDurationMs;

@property (nonatomic) INSTrackerSequence *directionSequence;

@property (nonatomic) NSArray <INSTrackerSequence *> *saliencySequences;

@property (nullable, nonatomic) NSArray <INSTrackerSequence *> *upviewSequences;

@property (nullable, nonatomic) NSArray <INSTrackerSequence *> *symmetricSequences;

@property (nullable, nonatomic) NSArray<INSMediaSpeed *> *sourceVideoTimelapseSpeeds;

@end


@interface INSCinelapseConfiguration: NSObject<NSCopying, NSMutableCopying, NSCoding>

// debug output directory, will open debug mode if it's not nil.
@property (nonatomic, nullable) NSString *debugOutputDir;

// the width : height ratio, for your preview render or export render， default is 16/9
@property (nonatomic) double displayRatio;

@end



@class INSTimeScale;

@interface INSCinelapseClip : NSObject<NSCopying, NSMutableCopying, NSCoding>
/// The identity you set in INSCinelapseDatasource
@property (nonatomic) SourceVideoIDType sourceVideoIdentifier;
/// The source video total duration in ms you set in INSCinelapseDatasource
@property (nonatomic) double sourceVideoDurationMs;
/// The recommend start time for setting INSFileClip
@property (nonatomic) double startSrcTimeMs;
/// The recommend end time for setting INSFileClip
@property (nonatomic) double endSrcTimeMs;
/// The recommend timescale info for setting INSFileClip, The property repeatToFps = 0 and videoKeyframeOnly = NO, motify if you need. but you CANNOT motify the time info and factor
@property (nonatomic) NSArray<INSTimeScale *> *timescales;
/// The endCutDurationMs for setting INSFileClip
@property (nonatomic) double endCutsceneDurationMs;

@end

@interface INSCinelapseResult: NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) NSArray<INSCinelapseClip *> *cinelapseClips;

@end

NS_ASSUME_NONNULL_END
