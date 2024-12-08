//
//  INSLiteDetector.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/30.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSLiteDetector : NSObject

- (BOOL) detectImage:(UIImage*)image;

- (BOOL) detectPixelBuffer:(CVPixelBufferRef)pixelBuffer;

@property (nonatomic, copy, nullable) NSString *message;

@end

NS_ASSUME_NONNULL_END
