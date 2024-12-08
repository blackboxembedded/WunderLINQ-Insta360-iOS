//
//  INSBulletTimeMotion.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/14.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExtraTimeMapperData;
@interface INSBulletTimeMotion : NSObject


///运动的时间点，类型:double,  单位：ms
/// @param startTimeMs 开始时间，单位：ms
/// @param angle 运动的角度，单位：度
-(nullable NSNumber*)motionPositionWithStartTimeMs:(double)startTimeMs motionAngle:(float)angle DEPRECATED_MSG_ATTRIBUTE("Please use -motionPositionWithStartTimeMs:motionAngle:timeMapperData: instead");

-(nullable NSNumber*)motionPositionWithStartTimeMs:(double)startTimeMs motionAngle:(float)angle timeMapperData:(INSExtraTimeMapperData * _Nullable)timeMapperData;

@end

NS_ASSUME_NONNULL_END
