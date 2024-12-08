//
//  INSExtraInfoCombine.h
//  INSCoreMedia
//
//  Created by Mac on 2021/3/3.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSEmSegment;
@class INSExtraInfo;
@class INSExtraGPSData;
@class INSExtraAAAData;
@class INSExtraHighlightData;
@class INSExtraSpeedData;
@interface INSExtraInfoEmuTool : NSObject

- (nullable instancetype) initWithEmSegment:(NSArray<INSEmSegment*>*)emSegments;



- (nullable INSExtraHighlightData *)highlightDataWithDatas:(NSArray<INSExtraHighlightData *> *)highlightDatas;

- (nullable INSExtraGPSData *)gpsDataWithDatas:(NSArray<INSExtraGPSData *> *)gpsDatas;

- (nullable INSExtraAAAData *)aaaDataWithDatas:(NSArray<INSExtraAAAData *> *)aaaDatas;

- (nullable INSExtraSpeedData *)speedDataWithDatas:(NSArray<INSExtraSpeedData *> *)speedDatas;

@end

NS_ASSUME_NONNULL_END
