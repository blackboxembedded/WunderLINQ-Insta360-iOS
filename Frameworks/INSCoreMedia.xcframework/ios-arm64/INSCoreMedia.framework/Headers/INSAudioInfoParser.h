//
//  INSAudioInfoParser.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/7.
//  Copyright © 2017年 insta360. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import "INSRenderType.h"
#import "INSMediaGps.h"
#import "INSExtraInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSAudioInfoParser : NSObject


-(instancetype)initWithURL:(NSURL*)URL;


/**
 *  同步打开媒体，会阻塞线程
 *
 *  @return 是否成功
 */
-(BOOL)open;

@property (nonatomic, assign, readonly) double duration;        //单位：ms

@end

NS_ASSUME_NONNULL_END
