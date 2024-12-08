//
//  INSCameraOptions.h
//  INSCameraSDK
//
//  Created by insta360 on 2022/5/6.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSUInteger const kRequestRetryCount;
extern NSTimeInterval const kRequestRetryTimeOut;

@interface INSCameraRequestOptions : NSObject
///重试次数
@property (nonatomic, assign) NSUInteger repeatCount;
///单次重试超时时间
@property (nonatomic, assign) NSTimeInterval timeout;
@end

NS_ASSUME_NONNULL_END
