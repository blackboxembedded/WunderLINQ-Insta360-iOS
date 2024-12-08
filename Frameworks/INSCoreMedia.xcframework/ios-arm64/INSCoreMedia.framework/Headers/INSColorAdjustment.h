//
//  INSColorAdjustment.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/9/6.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSColorAdjustment : NSObject

- (instancetype) initWithOffset:(NSString*)offset width:(NSInteger)width height:(NSInteger)height;

- (UIImage*) adjust:(UIImage*)image;

@end

NS_ASSUME_NONNULL_END
