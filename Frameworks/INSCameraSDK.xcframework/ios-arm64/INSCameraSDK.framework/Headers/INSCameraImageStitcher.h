//
//  INSCameraImageStitcher.h
//  INSCameraSDK
//
//  Created by zeng bin on 10/11/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSLogo;
@class INSMediaEuler;

@interface INSCameraImageStitcher : NSObject

/// whether to enable gyroscopic stabilization. default is NO.
@property (nonatomic) BOOL enableGyroStabilization;

/// logo
@property (nonatomic, nullable) INSLogo *logo;

/// size defined to output
/// CGSizeZero indicates output the same size as input image
@property (nonatomic) CGSize outputSize;

/*
 * euler angle to adjust the output's orientation. Applied only when enableGyroStabilization is NO.
 *
 * e.g. to adjust ONE's orientation captured by iPhone, you may set it to (0, 0, -90);
 */
@property (nonatomic, nullable) INSMediaEuler *eulerAdjust;

/*!
 * stitch fisheye image to panoramic image.
 * If the image is incorrect or lacking of necessory metadata, it would fail and return nil.
 */
- (nullable UIImage *)stitchFisheyeImageWithData:(NSData *)imageData;

@end

NS_ASSUME_NONNULL_END
