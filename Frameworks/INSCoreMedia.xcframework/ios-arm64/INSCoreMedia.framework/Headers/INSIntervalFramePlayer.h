//
//  INSIntervalFramePlayer.h
//  INSCoreMedia
//
//  Created by 那强 on 2019/4/17.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSPlayerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class INSIntervalFramePlayer;
@protocol INSIntervalFramePlayerDelegate <NSObject>
@optional
- (void) framePlayer:(INSIntervalFramePlayer *)framePlayer process:(float)process;
@end


@interface INSIntervalFramePlayer : NSObject

@property(nonatomic, readonly) NSArray <NSString *> *framePaths;

@property(nonatomic, readonly) int fps;

@property(nonatomic, readonly) double timeOffset;

@property (nonatomic, weak) id<INSPlayDisplay> displayDelegate;
@property (nonatomic, weak) id<INSIntervalFramePlayerDelegate> delegate;

- (instancetype)initWithFramePaths:(NSArray <NSString *> *) framePaths fps:(int)fps timeOffset:(double)timeOffset;

- (void)play;

- (void)pause;

- (void)shutdown;

// 1 ~ 30
- (void)changeFpsTo:(int)fps;

// 0.0 ~ 1.0
- (void)seekToProcess:(float)process;

- (float)getProcess;
@end

NS_ASSUME_NONNULL_END
