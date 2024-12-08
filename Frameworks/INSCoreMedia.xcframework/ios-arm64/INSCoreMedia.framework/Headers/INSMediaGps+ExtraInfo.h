//
//  INSMediaGps+ExtraInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSMediaGps.h"

extern const int kExtraGpsDataFrameLen;
extern const int kExtraGpsStarNumDataFrameLen;

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaGps (ExtraInfo)

- (nullable instancetype)initWithGpsInfo:(NSData*)gpsInfo;

/**
 *  当前持有的CLLocation 对象转为gpsinfo data
 */
- (nullable NSData *)toGpsData;

/**
 *  CLLocation转为gpsinfo data
 */
+ (NSData *)gpsDataFromCLLocation:(CLLocation *)location;

/**
 *  工具，按位生成一个gpsinfo data
 */
+ (NSData *)gpsDataWithTimestampS:(int64_t)timestamp_s
                   timestampMs:(uint16_t)timestamp_ms
                         valid:(char)valid
                      latitude:(double)latitude
                            ns:(char)n_s
                     longitude:(double)longitude
                            ew:(char)e_w
                         speed:(double)speed
                        course:(double)course
                      altitude:(double)altitude;

//+ (ins_gps_info)gyroInfoFromData:(NSData *)data

@end


@interface INSMediaGpsStarNum (ExtraInfo)

- (nullable instancetype) initWithGpsStarNumInfo:(NSData *)gpsStarNumInfo;

- (nullable NSData *)toGpsStarNumData;

@end

NS_ASSUME_NONNULL_END
