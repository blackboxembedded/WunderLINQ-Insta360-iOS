//
//  INSTailClear.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/9/28.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTailClear : NSObject

- (instancetype) initWithOffset:(NSString *)offset;
- (void) clearTail:(CVPixelBufferRef)pixelBuffer;

@end

NS_ASSUME_NONNULL_END
