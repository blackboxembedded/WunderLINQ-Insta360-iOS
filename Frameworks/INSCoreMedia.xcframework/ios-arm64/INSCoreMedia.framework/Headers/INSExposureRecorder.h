//
//  INSExposureRecorder.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/4/19.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSExposureRecorder : NSObject

- (void) pushExposureData:(int64_t)timestamp shutterSpeed:(double)shutterSpeed;

- (NSData * _Nullable) getExposureData;

@end

NS_ASSUME_NONNULL_END
