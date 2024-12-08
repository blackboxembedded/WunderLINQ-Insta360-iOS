//
//  INSCameraPhotoInfo.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/3/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSCameraPhotoInfo : NSObject

@property (nonnull, nonatomic) NSString *uri;

@property (nullable, nonatomic) NSData *sThumbnail;

@property (nullable, nonatomic) NSArray <NSString *> *hdrUris;

@property (nullable, nonatomic) NSArray <NSString *> *burstUris;

- (nonnull instancetype)initWithURI:(nonnull NSString *)uri;

+ (nullable instancetype)photoInfoWithJSONDict:(nonnull NSDictionary *)jsonDict;

- (nonnull NSDictionary *)toJSONDict;

@end
