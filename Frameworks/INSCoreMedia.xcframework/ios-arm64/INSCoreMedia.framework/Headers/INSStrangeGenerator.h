//
//  dsad.h
//  INSCoreMedia
//
//  Created by dml on 2022/4/26.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSAppletWrapData.h"
#import "INSExporterInfo.h"


@class INSTimeScale;
@class INSExtraGyroData;
@class INSFlyOutEarthInfo;
@class INSAnimationRecorder;
@class INSStrangeAnimation;
@interface INSStrangeGenerator : NSObject



- (instancetype)init NS_UNAVAILABLE;

- (nonnull instancetype)initWithVideoInfo:(INSAppletVideoInfo*)videoInfo
                            extraGyroData:(INSExtraGyroData*)gyroData
                                srcStartTimeMs:(double)srcStartTimeMs
                                  srcEndTimeMs:(double)srcEndTimeMs;

- (BOOL)analyze;
- (nonnull INSStrangeAnimation*)getStrangeAnimation;

@end
