//
//  INSOffscreenRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/7.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"
#import "INSRender.h"
#import "INSGyroPBPlayer.h"

typedef NS_ENUM(NSInteger, INSPixelFormatType){
    INSPixelFormatTypeBGRA,
    INSPixelFormatTypeNV12,
};


@class INSLogo;
@class INSFilter;
@class INSMediaGyro;
@class INSMediaEuler;
@class INSWatermark;
@class INSProjectionParam;
@class INSProjectionInfo;
@class INSMaskRes;
@class CIFilter;
@class INSPlayerImage;
@class INSFaceBeautyFilter;
@class INSTailClear;
@class INSBitmapData;

NS_ASSUME_NONNULL_BEGIN

@interface INSOffscreenRender : NSObject

- (instancetype) initWithRenderWidth:(int)width height:(int)height;
- (instancetype) initInterpolationWithWith:(int)width height:(int)height edge:(int)edge;
- (instancetype) initWithRenderWidth:(int)width height:(int)height multipleSample:(BOOL)multipleSample;
- (instancetype) initWithRenderWidth:(int)width height:(int)height multipleSample:(BOOL)multipleSample context:(EAGLContext*)context;

@property (nonatomic, strong) EAGLContext *glContext;

/**
 *  镜头offset值
 */
@property (nonatomic, copy, nullable) NSString *offset;

/**
 去除紫边
 */
@property (nonatomic) BOOL removePurple;

/**
 陀螺仪校正
 */
@property (nonatomic, strong, nullable) INSMediaGyro *gyroAdjust;

/**
 euler校正
 */
@property (nonatomic, strong, nullable) INSMediaEuler *eulerAdjust;

@property (nonatomic, strong, nullable) INSLogo *logo;
@property (nonatomic, strong, nullable) INSWatermark *watermark;

/**
 *  渲染宽度
 */
@property (nonatomic, readonly) int width;

/**
 *  渲染高度
 */
@property (nonatomic, readonly) int height;

/**
 *  滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *filter;
@property (nonatomic, strong, nullable) NSArray<INSFilterInfo *> *filterInfo;

/**
 * 调色
 */
@property (nonatomic, nullable) NSArray <CIFilter*> *ciFilters;

/**
 *  美颜滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *beautifyFilter;

/**
 *  调色表滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *lutFilter;

@property (nonatomic, strong, nullable) INSProjectionParam *projectionParam;
@property (nonatomic, strong, nullable) INSProjectionInfo *projectionInfo;

@property (nonatomic, strong, nullable) INSMediaEuler *gestureEuler;

@property (nonatomic) GLKQuaternion gyroStabilityOrientation;

@property (nonatomic) GLKVector4 backgroundColor;                                   //背景色

@property (nonatomic) INSPixelFormatType outputPixelFormat;;
@property (nonatomic, strong, readonly) INSRender *render;

@property(nonatomic, strong, nullable) INSGyroPBPlayer *gyroPlayer;
@property(nonatomic) BOOL enableRollingShutter;
@property(nonatomic) float sweepTime;
@property (nonatomic) INSObjectGeometryLevel objectGeometryLevel;
@property (nonatomic, strong, nullable) INSTailClear *tailClear;

@property (nonatomic, strong, nullable) INSFaceBeautyFilter *faceBeautyFilter;

- (void) set120Offset:(NSString*)offset;
- (void) setMaskInfo:(NSArray* __nullable)info;
- (void) addMaskWithFlatImagePoint:(CGPoint)point rotation:(float)rotation size:(float)angle resource:(INSMaskRes *)res;
- (void) setRenderImage:(UIImage*)image;
- (void) setRenderPixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(double)timestamp;
- (void) setRenderPixelBuffer:(CVPixelBufferRef)pixelBuffer right:(CVPixelBufferRef)pixelBufferRight timestamp:(double)timestamp;
- (void) setRenderPlayerImage:(INSPlayerImage*)playerImage;
- (UIImage* __nullable) renderToImage;
- (CVPixelBufferRef __nullable) renderToPixelBuffer;
- (void) setXFov:(float)xFov;
- (void) setDistance:(float)distance;

- (void) singleMinimumResourceRender;
- (UIImage* __nullable) readResultImage;
-(INSBitmapData* __nullable)readBitmapData;

@end

NS_ASSUME_NONNULL_END

