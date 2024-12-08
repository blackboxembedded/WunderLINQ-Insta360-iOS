//
//  ThumbnailDetect.h
//  INSCoreMedia
//
//  Created by ruiwen feng on 2022/7/15.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN
@class INSROIRecognition;
@interface INSThumbnailDetect : NSObject
/// 单利对象
+ (instancetype)shareThumbnailDetector;

/// 清除内部检测器，下次调用detectimage会重新生产，但是会增加耗时
- (void)cleanMemory;

/// 检测图像，并获取四元素
/// @param image 必须输入全景图片进行检测
- (GLKQuaternion)detectImage:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
