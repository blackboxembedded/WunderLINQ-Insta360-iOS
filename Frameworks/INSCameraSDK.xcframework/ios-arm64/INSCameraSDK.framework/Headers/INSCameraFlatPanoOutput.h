//
//  INSCameraFlatPanoOutput.h
//  INSCameraSDK
//
//  Created by zeng bin on 9/26/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraAVOutput.h"
#import <INSCoreMedia/INSFilter.h>
#import <INSCoreMedia/INSCoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@class INSLogo;

/// an instance will produces flat panorama video and camera's audio for you.
@interface INSCameraFlatPanoOutput : NSObject <INSCameraAVOutput>

- (instancetype)init NS_UNAVAILABLE;

/*!
 * constructor with output width and height
 *
 * @param   width   the expected output image dimension's width. Normally, your may set it to be equal to the dimension of INSCameraMediaSession's expectedVideoResolution, but it can be other values as well. 拼接后视频图像的宽，一般情况下你会把它设置为与 INSCameraMediaSession 的 expectedVideoResolution 相同的大小。
 *
 * @return  height  the expected output image dimension's height. Normally, your may set it to be equal to the dimension of INSCameraMediaSession's expectedVideoResolution, but it can be other values as well. 拼接后视频图像的宽，一般情况下你会把它设置为与 INSCameraMediaSession 的 expectedVideoResolution 相同的大小。
 */
- (instancetype)initWithOutputWidth:(NSInteger)width outputHeight:(NSInteger)height;


- (instancetype)initWithOutputWidth:(NSInteger)width
                       outputHeight:(NSInteger)height
                        enableAudio:(BOOL)enableAudio;

/*!
 * snapshot an unstitched image (fisheye image). the completion would be invoked once the output receive an unstitched image from the camera. 截取未拼接的图像, 一旦这个output 接受到相机传过来的原始图片，completion 会被调用
 *
 * @param   completion the callback. 回调函数
 */
- (void)snapshotUnstitchedImage:(void(^)(UIImage * image))completion;

/// The width of stitch output dimension.
@property (nonatomic, readonly) NSInteger outputWidth;

/// The height of stitch output dimension.
@property (nonatomic, readonly) NSInteger outputHeight;

/// whether to enable audio
@property (nonatomic, readonly) BOOL enableAudio;

///  whether to enable gyro stabilization, default YES
@property (nonatomic) BOOL enableGyroStabilization;

/*!
 * The video output pixel format.
 *
 * Right now, supported value are kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_32BGRA
 * default is kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
 */
@property (nonatomic) OSType outputPixelFormat;

/// removePurple, default NO
@property (nonatomic) BOOL removePurple;

/// logo
@property (nullable, nonatomic) INSLogo *logo;

/// filter, default None
@property (nonatomic) INSFilterType filter;

/// beautify Filter, default None
@property (nonatomic) INSFilterType beautifyFilter;

@property(nonatomic, strong, nullable) INSStitchingInfo *stitchingInfo;

@property (nonatomic, assign) INSStitchType stitchType;

@property(nonatomic, strong, nullable) NSString *offset;

@property(nonatomic, assign) BOOL colorFusion;

/// gyroTimestampAjust, default 0.0
@property (nonatomic) double gyroTimestampAjust;

@end

NS_ASSUME_NONNULL_END
