//
//  INSPassByRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/22.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN
@class INSPassBySequence;
@interface INSPassByRecorder : INSScreenRecorder

- (nullable instancetype)initWithPassbySequence:(INSPassBySequence *)passBySequence
                                 startTimestamp:(double)startTimestamp
                                   endTimestamp:(double)endTimestamp;

@end

NS_ASSUME_NONNULL_END
