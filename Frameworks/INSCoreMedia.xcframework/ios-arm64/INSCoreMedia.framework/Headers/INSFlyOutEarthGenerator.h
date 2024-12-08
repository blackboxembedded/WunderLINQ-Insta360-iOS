//
//  INSFlyOutEarth.h
//  INSCoreMedia
//
//  Created by dml on 2021/9/13.
//  Copyright © 2021 insta360. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "INSAppletWrapData.h"
#import "INSExporterInfo.h"
@class INSTimeScale;
@class INSExtraGyroData;
@class INSFlyOutEarthInfo;
@class INSAnimationRecorder;
@interface INSFlyOutEarthGenerator : NSObject

- (instancetype)init NS_UNAVAILABLE;

// 初始化
-(instancetype)initWithVideoInfo:(INSAppletVideoInfo*)videoInfo extraGyroData:(INSExtraGyroData*)gyroData trackEnv:(INSAppletTrackerEnv*)trackEnv;

// RUN
- (BOOL)runFlyOutEarth;

// 获取recorder
- (nullable INSAnimationRecorder *)getRecorder;

@end
