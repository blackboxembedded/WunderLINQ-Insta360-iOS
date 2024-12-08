//
//  INS120FPSThumbnailRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/10.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSFilter.h"


@class INSExtraGyroData;
@class INSPlayerImage;
@class INSFilterInfo;

NS_ASSUME_NONNULL_BEGIN

@interface INS120FPSThumbnailRender : NSObject


- (instancetype) initWithWidth:(NSInteger)width height:(NSInteger)height gyroData:(INSExtraGyroData*)gyroData playerImage:(INSPlayerImage*)playerImage;
- (instancetype) initWithWidth:(NSInteger)width height:(NSInteger)height gyroData:(INSExtraGyroData*)gyroData pixelBuffer:(CVPixelBufferRef)pixelBuffer;
- (instancetype) initWithWidth:(NSInteger)width height:(NSInteger)height gyroData:(INSExtraGyroData*)gyroData image:(UIImage*)image;

@property (nonatomic) float yFov;              //默认：60
@property (nonatomic) float distance;          //默认：650
@property (nonatomic, copy) NSString *offset;
@property (nonatomic) INSFilterType filter;
@property (nonatomic) CGFloat filterScale;
@property (nonatomic) INSFilterType beautifyFilter;
@property (nonatomic) INSFilterType lutFilter;
@property (nullable, nonatomic) NSArray <CIFilter *> *ciFilters;
@property (nullable, nonatomic) NSArray <INSFilterInfo *> *filterInfo;

- (UIImage* __nullable) renderImage;


@end

NS_ASSUME_NONNULL_END
