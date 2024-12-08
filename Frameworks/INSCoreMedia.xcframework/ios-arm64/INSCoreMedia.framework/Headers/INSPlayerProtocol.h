//
//  INSVideoDemux.h
//  DebugApp
//
//  Created by pwx on 25/11/15.
//  Copyright © 2015年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSGyroType.h"

typedef enum : NSUInteger {
    INSPlayerStatusUnknown,
    INSPlayerStatusPrepared,
    INSPlayerStatusPlaying,
    INSPlayerStatusBuffering,
    INSPlayerStatusPaused,
    INSPlayerStatusEnd,
    INSPlayerStatusFailed
} INSPlayerStatus;

typedef NS_ENUM(NSInteger, INSPlayerActionStatus){
    INSPlayerActionStatusUnknown,
    INSPlayerActionStatusPrepare,
    INSPlayerActionStatusPlay,
    INSPlayerActionStatusPause,
    INSPlayerActionStatusRelease,
};

@class INSPlayerImage;
@class INSPlayer;
@protocol INSPlayDisplay;

NS_ASSUME_NONNULL_BEGIN

@protocol INSPlayControl <NSObject>

@required

@property (nonatomic, readonly) INSPlayerStatus status;
@property (nonatomic, readonly) INSPlayerActionStatus actionStatus;
@property (nonatomic, weak, readwrite, nullable) id<INSPlayDisplay> displayDelegate;

-(void)setDataSource:(NSURL*)URL;

-(void)prepare;

-(void)play;

-(void)setVolume:(double)volume;

-(void)setPlayRate:(double)rate;

-(void)seek:(int64_t)position;
-(void)seek:(int64_t)position toKey:(BOOL)isToKey;

-(void)pause;

-(void)shutdown;

-(int64_t)currentPositionInMs;

-(int)getVideoWidth;

-(int)getVideoHeight;

-(int64_t)getVideoDuration;

-(void)setOption:(NSString*)key value:(NSString*)val;

@end


typedef struct {
    float heading;
    float pitch;
    float bank;
} STSpatialAudioRotation;

@protocol INSPlayDisplay <NSObject>

- (void) player:(id<INSPlayControl>_Nullable)player onDisplay:(INSPlayerImage*)img;
- (void) previewerDisplay:(INSPlayerImage*)img;
- (STSpatialAudioRotation) getSpatialAdudioRotation;
- (void) setIsHoldPlayImage:(BOOL)isHold;
@property (nonatomic) BOOL enableGyroStabilizer;

@optional
- (BOOL) enableUpdatePlayerImage;

@end


NS_ASSUME_NONNULL_END
