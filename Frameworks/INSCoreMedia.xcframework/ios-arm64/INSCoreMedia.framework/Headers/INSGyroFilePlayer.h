//
//  INSGyroFilePlayer.h
//  INSMediaSDK
//
//  Created by pengwx on 17/2/9.
//  Copyright © 2017年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSGyroPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroFilePlayer : INSGyroPlayer

- (instancetype) initWithFileURL:(NSURL*)url;

@end

NS_ASSUME_NONNULL_END
