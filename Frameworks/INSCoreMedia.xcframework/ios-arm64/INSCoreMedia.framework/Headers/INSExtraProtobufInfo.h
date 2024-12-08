//
//  INSExtraProtobufInfo.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/23.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExtraGyroData;
@class INSExtraInfo;

@interface INSExtraProtobufInfo : NSObject

- (instancetype)initWithGyroData:(INSExtraGyroData *)gyroData;

- (instancetype)initWithExtraInfo:(INSExtraInfo *)extraInfo;

- (instancetype)initWithProtobufData:(NSData*)data extraJsonDataLen:(int)jsonLen;

- (nullable NSData *)protobufData;

@property (nullable, nonatomic, strong) INSExtraGyroData *gyrodata;

@end

NS_ASSUME_NONNULL_END
