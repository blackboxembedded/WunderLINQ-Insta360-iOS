//
//  INSMediaGyro+ExtraInfo.h
//  INSCoreMedia
//
//  Created by zeng bin on 7/17/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import "INSMediaGyro.h"
#import "INSExtraGyroData.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaGyro (ExtraInfo)

- (instancetype)initWithGyroInfo:(ins_gyro_info)gyroInfo;

- (ins_gyro_info)toGyroInfo;

//- (instancetype)initWithGyroInfoRaw:(ins_gyro_info_raw)gyroInfoRaw;

//- (ins_gyro_info_raw)toGyroInfoRaw;

@end

NS_ASSUME_NONNULL_END
