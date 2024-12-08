//
//  INSExtraMetadata+Serializer.h
//  INSCoreMedia
//
//  Created by zeng bin on 5/2/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import "INSExtraMetadata.h"

NS_ASSUME_NONNULL_BEGIN

@class INSPBExtraMetadata;

@interface INSExtraMetadata (Serializer)

// 以下三个方法，是针对NanoS之前的机器，使用json存储的V2版本metadata信息
+ (nullable instancetype)metadataWithJSONData:(NSData *)jsonData;

- (NSDictionary *)serializeToJSON;

- (NSData *)serializeToJSONData;


// 以下三个方法，可用于ONE之后的机器，使用protobuf存储的metadata

// 用从protobuf二进制数据中，解析出INSExtraMetadata实例对象
+ (nullable instancetype)metadataWithPBData:(NSData *)pbData;

// metadataWithPBData的逆运算，把当前对象按照protobuf规则序列化为二进制对象
- (NSData *)serializeToProtobufData;

// 用于把当前对象，转换为Protobuf Message对象
- (INSPBExtraMetadata *)serializeToProtobuf;

@end

NS_ASSUME_NONNULL_END
