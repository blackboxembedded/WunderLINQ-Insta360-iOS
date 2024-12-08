//
//  INSMoveSceneAnimation.h
//  INSCoreMedia
//
//  Created by dml on 2022/1/28.
//  Copyright © 2022 insta360. All rights reserved.
//

#import "INSMoveSceneGenerator.h"



@class INSScreenRecorderModel;
@class INSAnimationRecorder;
@class INSTimeScale;

#pragma mark - INSMoveSceneStatus

typedef NS_ENUM(NSInteger, INSMoveSceneStatus){
    INSMoveSceneStatusSuccess = 0,
    INSMoveSceneStatusGyrodatesError = 156,
    INSMoveSceneStatusCircleError = 157,
    INSMoveSceneStatusPitchError = 158,
    INSMoveSceneStatusTimeShortError = 159,
    INSMoveSceneStatusOtherError = 160,
};


#pragma mark - INSMoveSceneClip

@interface INSMoveSceneClip : NSObject<NSCoding, NSCopying, NSMutableCopying>

@property (nonatomic) double startTimeMs;
@property (nonatomic) double endTimeMs;
@property (nonatomic, strong) NSArray<INSTimeScale*> *timescales;

@end

#pragma mark - INSMoveSceneAnimationResult

@interface INSMoveSceneAnimationResult : NSObject <NSCoding, NSCopying, NSMutableCopying>

@property (nonatomic) INSMoveSceneStatus status;

@property (nonatomic) double totalStartTimeMs;
@property (nonatomic) double totalEndTimeMs;

@property (nonatomic) double xfov;

@property (nonatomic, strong) NSArray<INSMoveSceneClip*> *clips;
@property (nonatomic, strong) NSArray<NSArray<INSScreenRecorderModel*>*> * _Nullable recorderModelArray2;

@end

#pragma mark - INSMoveSceneAnimation

@interface INSMoveSceneAnimation<INSPlugableAnimation, NSCoding> : NSObject

@property (nonatomic) double clipTimeMs;


- (instancetype)initWithResult:(INSMoveSceneAnimationResult*)result;

- (NSArray<INSMoveSceneClip*>*)getClips;

- (nullable INSAnimationRecorder *)getRecorder;

- (void)setFov:(double)fov;


@end

