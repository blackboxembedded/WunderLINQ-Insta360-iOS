//
//  INSCameraFileInfo.h
//  INSCameraSDK
//
//  Created by insta360 on 2023/5/10.
//  Copyright © 2023 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraFileInfo : NSObject

@property (nonnull, nonatomic) NSString *uri;

- (nonnull instancetype)initWithURI:(nonnull NSString *)uri;

+ (nullable instancetype)fileInfoWithJSONDict:(nonnull NSDictionary *)jsonDict;

- (nonnull NSDictionary *)toJSONDict;

@end

NS_ASSUME_NONNULL_END
