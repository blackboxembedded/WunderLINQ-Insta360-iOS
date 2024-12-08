//
//  INSWatermark.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/30.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSWatermark : NSObject

- (instancetype) initWithImage:(UIImage*)image rect:(CGRect)rect;

@property (nonatomic, strong, readonly) UIImage *image;
@property (nonatomic, readonly) CGRect rect;


@end

NS_ASSUME_NONNULL_END
