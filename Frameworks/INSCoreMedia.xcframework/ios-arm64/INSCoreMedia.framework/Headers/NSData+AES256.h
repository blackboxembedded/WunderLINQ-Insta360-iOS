//
//  NSData+AES256.h
//  INSCoreMedia
//
//  Created by HFY on 2021/4/25.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (AES256)

- (NSData*_Nullable)AES256EncryptWithKey:(NSString*)key;
- (NSData*_Nullable)AES256DecryptWithKey:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
