//
// Created by jerett on 16/6/3.
// Copyright (c) 2016 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSPlayerProtocol.h"

@class AVPlayer;

NS_ASSUME_NONNULL_BEGIN

@interface INSAVPlayer: NSObject <INSPlayControl>

@property (nullable, nonatomic, strong, readonly) AVPlayer *player;

@end

NS_ASSUME_NONNULL_END
