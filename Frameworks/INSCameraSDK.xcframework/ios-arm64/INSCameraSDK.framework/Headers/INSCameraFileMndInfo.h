//
//  INSCameraFileMndInfo.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2018/7/9.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraMediaBasic.h"

@interface INSCameraFileMndInfo : NSObject

@property (nonnull, nonatomic) NSString *uri;

@property (nonatomic) INSFileMndType type;

@property (nullable, nonatomic) NSData *data;

- (nonnull instancetype)initWithURI:(nonnull NSString *)uri type:(INSFileMndType)type;

+ (nullable instancetype)fileMndInfoWithJSONDict:(nonnull NSDictionary *)jsonDict;

- (nonnull NSDictionary *)toJSONDict;

@end
