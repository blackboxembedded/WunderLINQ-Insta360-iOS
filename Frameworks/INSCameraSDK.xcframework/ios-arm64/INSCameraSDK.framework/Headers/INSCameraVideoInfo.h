//
//  INSCameraVideoInfo.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSCameraVideoInfo : NSObject

@property (nonnull, nonatomic) NSString *uri;

- (nonnull instancetype)initWithURI:(nonnull NSString *)uri;

+ (nullable instancetype)videoInfoWithJSONDict:(nonnull NSDictionary *)jsonDict;

- (nonnull NSDictionary *)toJSONDict;

@end
