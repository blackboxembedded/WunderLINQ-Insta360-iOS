//
//  INSRoadFlowPersonSegmentor.h
//  INSCoreMedia
//
//  Created by HFY on 2022/6/2.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class INSPlayerImage;
@interface INSRoadFlowPersonSegmentor : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype) initWithCacheImageDir:(NSString *)cacheImageDir;
- (nullable NSError *) prepare;  // 初始化，有可能失败
- (bool) checkHasCache; // 检查是否已有缓存
- (nullable NSError *) feedFrame:(INSPlayerImage *)playerImage;
- (nullable NSError *) finish;

@end


NS_ASSUME_NONNULL_END
