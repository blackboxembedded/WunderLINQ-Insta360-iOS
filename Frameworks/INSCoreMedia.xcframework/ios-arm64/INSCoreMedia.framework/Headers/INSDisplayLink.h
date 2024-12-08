//
//  INSDisplayLink.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/6/3.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QuartzCore/CADisplayLink.h"

NS_ASSUME_NONNULL_BEGIN

@protocol INSDisplayLinkProtocol <NSObject>

- (void) displayLinkRefresh;

@end


@interface INSDisplayLink : NSObject

@property (nonatomic, strong) CADisplayLink *displayLink;                  //显示
@property (nonatomic, weak) id<INSDisplayLinkProtocol> delegate;

- (void)removeDisplayLinkFromRunLoop;

@end

NS_ASSUME_NONNULL_END
