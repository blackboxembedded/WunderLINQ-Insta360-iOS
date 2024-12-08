//
//  INSMediaGps.h
//  INSMediaApp
//
//  Created by pengwx on 16/8/10.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN

@interface INSMediaGps : NSObject


- (instancetype) initWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)alitude;

/**
 *  使用json格式的NSDictionary初始化对象, 只包含[经度, 纬度, 海拔]
 *  @param dic NSDictionary
 *  @return 成功返回对象，失败返回nil
 */
- (instancetype __nullable) initWithJsonDictionary:(NSDictionary*)dic;

/**
 *  获取对象的json格式的NSDictionary, 只包含[经度, 纬度, 海拔]
 *  @return NSDictionary
 */
- (NSDictionary*)jsonDictionary;


/**
 *  使用CLocation 生成对象, 如果使用该方法初始化，则通过self.location属性访问位置信息，而不是self.latitude/self.longitude/self.altitude
 */
- (instancetype)initWithCLLocation:(CLLocation *)location isValidLocation:(BOOL)isValidLocation;


/**
 * 纬度
 */
@property (nonatomic) double latitude;

/**
 * 经度
 */
@property (nonatomic) double longitude;

/**
 * 海拔高度
 */
@property (nonatomic) double altitude;


/**
 *  直接传入CLLocation, One X 谷歌街景才有
 */
@property (nonatomic, readonly) CLLocation *location;

/**
 *  当前CLLocation位置是否合法
 */
@property (nonatomic, readonly) BOOL isValidLocation;

@end

@interface INSMediaGpsStarNum : NSObject

@property (nonatomic) uint8_t starNum;

@property (nonatomic) NSDate *timestamp;

- (instancetype)initWithStarNum:(uint8_t)starNum timestamp:(NSDate *)timestamp;

@end

NS_ASSUME_NONNULL_END
