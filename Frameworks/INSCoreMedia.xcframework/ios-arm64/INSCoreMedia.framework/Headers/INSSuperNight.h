//
//  INSSuperNight.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/8/29.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, INSSuperNightErrorCode) {
    INSSuperNightErrorCodeCancel = 100,
    INSSuperNightErrorCodeRunProgress = 101,
    INSSuperNightErrorCodeOpenCV = 102,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSSuperNight : NSObject

- (nullable NSData *)generateSuperNightImageWithImages:(NSArray <NSData *>*)images
                                          error:(NSError * _Nullable * _Nullable)error;


/// 取消函数，需要在另一个线程中调用，调用后等待generateSuperNightImageWithImages函数返回，此时有可能返回错误
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
