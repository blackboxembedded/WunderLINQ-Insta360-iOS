//
//  INSRoboticArmGenerator.h
//  INSCoreMedia
//
//  Created by Mac on 2021/3/17.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSRoboticArmGeneratorConfiguration : NSObject

@property (nonatomic) bool is16over9;

@end

@class INSAppletTrackerEnv;
@class INSAppletVideoInfo;
@class INSScreenRecorder;
@interface INSRoboticArmGenerator : NSObject

@property (nonatomic) INSRoboticArmGeneratorConfiguration *configuration;

@property (nonatomic) INSAppletVideoInfo * videoInfo;
 
@property (nonatomic) INSAppletTrackerEnv *trackerEnv;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithConfiguration:(INSRoboticArmGeneratorConfiguration *)configuration videoInfo:(INSAppletVideoInfo *)videoInfo trackerEnv:(INSAppletTrackerEnv *)trackerEnv;

// 同步，不耗时方法
- (BOOL)process;

// xFov或disitance<0时，使用传入追踪数据trackerEnv.resultRecorder中对应的值
- (nullable INSScreenRecorder *)roboticScreenRecorderFov:(float)fov distance:(float)distance;

@end

NS_ASSUME_NONNULL_END
