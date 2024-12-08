//
//  INSHTTPSystemProxyBlackList.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/9/27.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSHTTPSystemProxyBlackList : NSObject

- (void) addValue:(NSString*)value;
- (void) removeValue:(NSString*)value;
- (void) removeAllValue;

- (BOOL) isContainedIn:(NSString*)string;

+ (INSHTTPSystemProxyBlackList*) defaultList;

@end

NS_ASSUME_NONNULL_END
