//
//  INSSeamlessBlender.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/7/17.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSBlender.h"

@class INSMediaGyro;

NS_ASSUME_NONNULL_BEGIN

@interface INSSeamlessBlender : INSBlender

- (instancetype) initWithOffset:(NSString *)offset;
- (instancetype) initWithOffset:(NSString *)offset outputWidth:(NSInteger)width outputHeight:(NSInteger)height;

/**
 blend a uiimage

 @param image image, insp
 @return image blended, jpg
 */
- (UIImage * _Nullable) blendImage:(UIImage*)image;

/**
 blend a group of images using the first image's map

 @param images UIImages array, insp
 @return UIImages blended, jpg
 */
- (NSArray<UIImage *> * _Nullable) blendImages:(NSArray<UIImage *> *)images;

/**
 terminate the `blendImage:` or `blendImages` process and return nil
 */
- (void) cancelBlendProcess;

@property (nonatomic, copy) NSString *offset;
@property (nonatomic) NSInteger width;
@property (nonatomic) NSInteger height;
@property (nonatomic) BOOL colorAdjustment;
@property (nullable, nonatomic, strong) INSMediaGyro *gyroAdjust;     //gyro校正

/**
 旋转180度，即交换镜头, 默认NO
 */
@property (nonatomic) BOOL rotate180;

@end

NS_ASSUME_NONNULL_END
