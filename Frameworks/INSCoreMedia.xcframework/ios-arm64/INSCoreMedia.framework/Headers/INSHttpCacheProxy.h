//
//  INSHttpCacheProxy.h
//  INSCoreMedia
//
//  Created by Mac on 2021/5/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSHttpCacheEntity : NSObject <NSCopying, NSMutableCopying, NSCoding>

//当前数据块的唯一标识，可以用来定位对应二进制数据的地址
@property (nonatomic) NSString *identifier;

//明文id
@property (nonatomic) NSString *plainId;

//在原始文件中的位置 loc + length
@property (nonatomic) NSRange range;

@end

typedef NS_ENUM(NSUInteger, INSHttpCacheProxyErrorCode) {
    INSHttpCacheProxyErrorCodeWriteData,
    INSHttpCacheProxyErrorCodeReadData,
};

// 上层只维护记录信息，contentdata的具体存储，由SDK存储在磁盘上
@protocol INSHttpCacheProxy <NSObject>

- (NSString *)cacheBaseDir;

- (nullable NSArray<INSHttpCacheEntity *> *)readAllEntityListForURL:(NSURL *)url;

- (BOOL)writeEntityList:(NSArray<INSHttpCacheEntity *> *)entities forURL:(NSURL *)url;

- (void)handleHttpCacheProxyError:(NSError *)error;

@end


@interface INSHttpCacheDefautProxy : NSObject<INSHttpCacheProxy>

@property (nonatomic) NSString *cacheBaseDir;

- (instancetype)initWithCacheBaseDir:(NSString *)cacheDir;

@end

NS_ASSUME_NONNULL_END
