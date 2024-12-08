//
//  INSCoreMediaSDK.h
//  INSCoreMedia
//
//  Created by Mac on 2021/2/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const INSCoreMediaErrorDomain;

@interface INSCoreMediaSDK : NSObject

+ (instancetype)sharedInstance;

/// 配置INSMedia.bundle的全路径
/// @param path INSMedia.bundle的全路径
/// @return 是否配置成功，NO表示失败，请检查路径下是否有相应文件，以及子文件夹
- (BOOL)insMediaResourcePath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
