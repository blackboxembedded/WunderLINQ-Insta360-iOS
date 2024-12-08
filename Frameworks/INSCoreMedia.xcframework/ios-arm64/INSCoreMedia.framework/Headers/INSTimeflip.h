//
//  INSTimeflip.h
//  INSCoreMedia
//
//  Created by HFY on 2020/8/11.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSDisplayConfigManager.h"

NS_ASSUME_NONNULL_BEGIN

@class INSExtraGyroData;
@class INSScreenRecorder;
@class INSGyroPBPlayer;
@class INSExtraMetadata;

@interface INSTimeflip : NSObject

- (nullable instancetype)initWithURLs:(NSArray <NSURL *> *)videoURLs
                               offset:(NSString *)offset
                      videoDurationMs:(int64_t)videoDurationMs
                           gyroPlayer:(INSGyroPBPlayer *)gyroPlayer
                             gyroData:(INSExtraGyroData *)gyroData
                             metaData:(INSExtraMetadata *)metaData
                       detectorThresh:(float)detectorThresh
                              display:(INSDisplay*)display
                         displayValue:(INSDisplayValue*)displayValue
                            debugMode:(BOOL)debugMode;

@property(nonatomic, strong, nullable)NSArray<INSScreenRecorder*> *clockwiseRecorder;
@property(nonatomic, strong, nullable)NSArray<INSScreenRecorder*> *anticlockwiseRecorder;

/// 最小roll旋转的偏移值，默认2.356(135度），单位：弧度
@property(nonatomic)double minRollOffset;

@end

NS_ASSUME_NONNULL_END
