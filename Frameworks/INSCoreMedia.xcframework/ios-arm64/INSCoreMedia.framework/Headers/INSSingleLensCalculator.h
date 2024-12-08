//
//  INSSingleLensCalculator.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/13.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSSingleLensCalculator : NSObject

- (instancetype)initWithVersion:(NSInteger)version lensType:(NSInteger)lensType;

- (NSString* __nullable) processImage:(UIImage*)image;

- (NSString* __nullable) processPixelBuffer:(CVPixelBufferRef)pixelBuffer;

@end

NS_ASSUME_NONNULL_END
