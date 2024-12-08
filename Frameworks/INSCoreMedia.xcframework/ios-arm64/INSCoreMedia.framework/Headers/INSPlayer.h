//
//  INSPlayer.h
//  INSMediaApp
//
//  Created by jerett on 16/6/3.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSPlayerProtocol.h"

@class AVPlayer;

NS_ASSUME_NONNULL_BEGIN

@interface INSPlayer : NSObject<INSPlayControl>

/**
 设置INSPlayer类型
 必须在setDataSource函数之前调用，如果不调用此函数，表示自动选择播放器
 @param useSystemPlayer 是否使用IOS系统的播放器
 */
- (void) setPlayerType:(BOOL)useSystemPlayer;

@property (nonatomic, assign, readonly) BOOL useSystemPlayer;


/**
 当播放器useSystemPlayer为YES，可在setDataSource调用后通过此属性访问底层使用的AVPlayer对象
 */
@property (nullable, nonatomic, strong, readonly) AVPlayer *avplayer;

@end

NS_ASSUME_NONNULL_END
