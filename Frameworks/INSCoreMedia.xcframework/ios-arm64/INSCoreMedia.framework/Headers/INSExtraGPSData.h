//
//  INSExtraGPSData.h
//  INSCoreMedia
//
//  Created by HFY on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSMediaGps.h"

CF_EXTERN_C_BEGIN

/**
 *  不要用struct 去读取data, 仅用来打印信息
 */
struct ins_gps_info {
    int64_t timestamp_s; //ts的整数位
    uint16_t timestamp_ms;// 完整ts的小数位(十分位、百分位、千分位)
    char valid; // 有效v，无效n
    double latitude; //纬度
    char n_s;//南北纬
    double longitude;//经度
    char e_w;//东西经
    double ground_speed;//对地速度
    double ground_crouse;//航向
    double altitude;//海拔
};

typedef struct ins_gps_info ins_gps_info;

CF_EXTERN_C_END

NS_ASSUME_NONNULL_BEGIN

@interface INSExtraGPSData : NSObject

/**
 *  所有gps信息二进制数据
 */
@property (nullable, nonatomic, readonly) NSData *gpsData;

/**
 *  gpsData 全部解析为INSMediaGps元素类型的数组
 */
@property (nullable, nonatomic, readonly) NSArray<INSMediaGps *> *gpsArray;


/**
 *  所有gps信号强度星标数据信息
 */
@property (nullable, nonatomic, readwrite) NSData *gpsStartNumData;

/**
 * 星标数据的解析结果
 */
@property (nullable, nonatomic, readonly) NSArray<INSMediaGpsStarNum *> *gpsStartNumArray;


- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithGPSData:(NSData *)gpsData;

@end

NS_ASSUME_NONNULL_END
