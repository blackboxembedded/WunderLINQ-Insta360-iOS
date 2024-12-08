//
//  INSMultipleInfo.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSRenderType.h"


NS_ASSUME_NONNULL_BEGIN

@class INSTrim;
@class INSPlayRateRange;
@class INSLookHerePoint;
@class INSProjectionParam;
@class INSScreenRecorder;
@class INSTimeScale;
@class INSDisplay;
@class INSDisplayConfigManager;

typedef NS_ENUM(NSInteger, INSMultipleInfoHandleMode) {
    INSMultipleInfoHandleModeDefault = 0,
    INSMultipleInfoHandleModeSingleRecorder = 1,
};

@interface INSMultipleInfo : NSObject<NSCoding>

- (instancetype) initWithInitialProjection:(INSProjectionParam*)initialProjection  videoDurationMs:(double)videoDuration;

@property (nonatomic) double videoDurationMs;
@property (nonatomic, strong) INSProjectionParam *initialProjection;
@property (nonatomic, strong, nullable) INSTrim *trim;
@property (nonatomic, strong, nullable) NSArray<INSLookHerePoint*>* lookHerePoints;
@property (nonatomic, strong, nullable) NSArray<INSScreenRecorder*>* screenRecords;

/**
 变速时间段
 */
@property (nonatomic, strong, nullable) NSArray<INSTimeScale*>* timeScales;

/**
 特殊的mode，如果是依赖AnimationRecorder，且只有一种，则使用INSMultipleInfoHandleModeSingleRecorder
 */
@property (nonatomic) INSMultipleInfoHandleMode handleMode;
/**
 不再使用，仅做兼容one的代码, 新的使用timeScales
 */
@property (nonatomic, strong, readonly, nullable) NSArray<INSPlayRateRange*>* playRateRanges;
@property (nonatomic, readonly) double playDuration;

- (INSMultipleInfo*) infoWithDisplay:(INSDisplay*)display displayConfigManager:(INSDisplayConfigManager*)manager;

@end



NS_ASSUME_NONNULL_END
