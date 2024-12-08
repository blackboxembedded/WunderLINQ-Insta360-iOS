//
//  INSExtraSpeedData.h
//  INSCoreMedia
//
//  Created by HFY on 2022/5/16.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class INSExtraTimeMapperData;
@class INSFramePtsPlayer;
@class INSMediaSpeed;
@interface INSExtraSpeedData : NSObject

- (instancetype)initWithRawData:(NSData *)rawData
                  isMicroSecond:(BOOL)isMicroSecond
                      frameRate:(double)frameRate
                     timeOffset:(double)timeOffset
                   framePtsData:(NSData * _Nullable)framePtsData
                 timeMapperData:(INSExtraTimeMapperData * _Nullable)timeMapperData;


@property (nonatomic, readonly) NSData *rawData;

@property (nonatomic, readonly) double timeOffset;

@property (nonatomic, readonly) BOOL isMicroSecond;

@property (nonatomic, readonly) NSData *framePtsData;

@property (nonatomic, readonly) double frameRate;

@property (nonatomic, readonly) NSArray<INSMediaSpeed *> *speeds;

/// TODO: 支持trim. 当前版本无需支持，因为,但是会支持循环录影的相关处理逻辑. see INSExtraInfoEmuTool

@end

NS_ASSUME_NONNULL_END
