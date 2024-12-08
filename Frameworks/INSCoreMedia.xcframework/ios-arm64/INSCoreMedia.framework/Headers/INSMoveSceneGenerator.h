//
//  INSMoveSceneGenerator.h
//  INSCoreMedia
//
//  Created by dml on 2021/12/21.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@class INSExtraGyroData;
@class INSAppletTrackerEnv;
@class INSAppletVideoInfo;
@class INSGyroPBPlayer;
@class INSTimeScale;
@class INSMoveSceneAnimation;
@class INSMoveSceneClip;

typedef NS_ENUM(NSInteger, INSMoveSceneStatus);


#pragma mark - INSMoveSceneGeneratorInfo
@interface INSMoveSceneGeneratorInfo : NSObject

@property (nonatomic, strong) NSArray<NSURL*>* urls;
@property (nonatomic, strong) NSString *offset;
@property (nonatomic, strong) INSExtraGyroData* gyroData;
@property (nonatomic, strong) INSAppletTrackerEnv* trackEnv;

@end

#pragma mark - INSMoveSceneTrackerTimes
@interface INSMoveSceneTrackerTimes : NSObject

@property (nonatomic) double startTimeMs;
@property (nonatomic) double endTimeMs;

@end;
#pragma mark - INSMoveSceneTrackerFragment
@interface INSMoveSceneTrackerFragment : NSObject

@property (nonatomic, strong) NSArray<INSMoveSceneTrackerTimes*> *trackerTimes;
@property (nonatomic) INSMoveSceneStatus status;

@end

#pragma mark - INSMoveSceneGenerator

@interface INSMoveSceneTrackerInfo : NSObject

@property (nonatomic) NSArray<INSAppletTrackerEnv*> *trackers;

@property (nonatomic) INSMoveSceneStatus status;


@end


#pragma mark - INSMoveSceneGenerator

@interface INSMoveSceneGenerator : NSObject

- (instancetype)initWithMoveSceneInfos:(NSArray<INSMoveSceneGeneratorInfo*>*)infos;

- (NSArray<INSMoveSceneTrackerFragment*> *)getTrackerFragment;

- (BOOL)setTrackerEnvs:(NSArray<INSMoveSceneTrackerInfo*>*)trackerEnvs;

- (NSArray<INSMoveSceneAnimation*> *)getAnimations;


@end
