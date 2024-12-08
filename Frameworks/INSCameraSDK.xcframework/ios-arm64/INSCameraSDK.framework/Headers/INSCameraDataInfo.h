//
//  INSCameraDataInfo.h
//  INSCameraSDK
//
//  Created by insta360 on 2023/4/3.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraDataInfo : NSObject

@property (nonnull, nonatomic) NSString *uri;

- (nonnull instancetype)initWithURI:(nonnull NSString *)uri;

+ (nullable instancetype)videoInfoWithJSONDict:(nonnull NSDictionary *)jsonDict;

- (nonnull NSDictionary *)toJSONDict;

@end

NS_ASSUME_NONNULL_END
