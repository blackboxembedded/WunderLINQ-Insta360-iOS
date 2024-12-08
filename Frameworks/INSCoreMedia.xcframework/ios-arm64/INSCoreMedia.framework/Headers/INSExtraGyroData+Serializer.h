//
//  INSExtraGyroData+Serializer.h
//  INSCoreMedia
//
//  Created by zeng bin on 5/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import "INSExtraGyroData.h"

@class PBGyroData;

NS_ASSUME_NONNULL_BEGIN

@interface INSExtraGyroData (Serializer)

+ (nullable instancetype)extraGyroDataWithPBGyroData:(nonnull PBGyroData *)gyro;

- (nonnull PBGyroData *)getPBGyroData;

@end

NS_ASSUME_NONNULL_END
