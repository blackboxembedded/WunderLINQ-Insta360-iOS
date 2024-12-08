//
//  INSMediaTool.h
//  INSMediaApp
//
//  Created by pengwx on 16/12/5.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaTool : NSObject

/**
 判断是否为全景视频
 @param url 视频url地址
 @return YES为是，NO为否
 */
+ (BOOL) isPanoramicVideo:(NSURL * _Nullable)url;

@end

NS_ASSUME_NONNULL_END
