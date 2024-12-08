//
//  INSGyroRecorder.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/23.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>



@class INSExtraGyroData;
@class INSGyroDataSource;

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroRecorder : NSObject

- (instancetype) initWithGyroDataSource:(INSGyroDataSource*)dataSource;

- (void) startRecord;

- (void) stopRecord;

- (INSExtraGyroData * _Nullable) getGyroData;

@property (nonatomic) int64_t timeOffset;

@end

NS_ASSUME_NONNULL_END
