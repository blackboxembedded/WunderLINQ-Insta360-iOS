//
//  INSFaceSDK.h
//  INSCoreMedia
//
//  Created by pengwx on 17/4/20.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSFaceSDK : NSObject

/** 获取版本号 */
+ (NSString *_Nullable)getVersion;


/**
 获取SDK授权时间，只有联网授权版本，该SDK可用
 
 @return 授权时间
 */
+ (NSDate *_Nullable)getApiExpiration;

/**
 获取 SDK 相关信息
 
 @param modelData model data
 @return sdk 相关信息
 */
//+ (MGAlgorithmInfo *)getSDKAlgorithmInfoWithModel:(NSData *)modelData;;



/**
 获取 SDK 联网授权所需要信息
 
 @return 联网授权信息
 */
+ (NSUInteger)getAPIName;



@end

NS_ASSUME_NONNULL_END
