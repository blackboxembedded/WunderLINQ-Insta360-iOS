//
//  INSOpencvException.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/11.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSOpencvException : NSObject

+ (void)registerExceptionCallback:(void(^)(int status, NSString *funcName, NSString *message, NSString *fileName, int line))block;
+ (void)unregisterExceptionCallback;

@end

NS_ASSUME_NONNULL_END
