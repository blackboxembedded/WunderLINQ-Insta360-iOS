//
//  INSEGGAlgorithmInfo.h
//  INSCoreMedia
//
//  Created by 那强 on 2019/10/6.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEGGAlgorithmInfo : NSObject

/**
 SDK 版本号
 */
@property (nonatomic, copy, readonly) NSString *version;

/**
 SDK 过期时间
 */
@property (nonatomic, strong, readonly) NSDate *expireDate;


/**
 是否需要联网授权
 */
@property (nonatomic, assign, readonly) BOOL needNetLicense;


/**
 SDK 功能列表
 */
@property (nonatomic, strong, readonly) NSArray *SDKAbility;


/**
 SDK 限制的bundleId
 */
@property (nonatomic, strong, readonly) NSString *bundleId;

@end

NS_ASSUME_NONNULL_END
