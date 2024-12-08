//
//  INSOneTakeRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/24.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorder.h"


NS_ASSUME_NONNULL_BEGIN

@class INSOneTakeAnimation;
@interface INSOneTakeRecorder : INSScreenRecorder

- (nullable instancetype)initWithOneTakeAnimation:(INSOneTakeAnimation *)onetakeAnimation
                                   startTimestamp:(double)startTimestamp
                                     endTimestamp:(double)endTimestamp;

@end

NS_ASSUME_NONNULL_END
