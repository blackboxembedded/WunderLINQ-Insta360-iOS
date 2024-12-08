//
//  INSPlayerImage.h
//  INSCoreMediaIOS
//
//  Created by jerett on 16/12/19.
//  Copyright © 2016年 jerett. All rights reserved.
//
#import <CoreVideo/CVPixelBuffer.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSPlayerImageType){
    INSPlayerImageTypeVideo,
    INSPlayerImageTypeImage,
};

@interface INSPlayerImage : NSObject<NSCopying>

@property (nonatomic, assign) INSPlayerImageType type;
@property (nonatomic, assign) int clipIndex;
@property (nonatomic, assign) CVPixelBufferRef pixelBuffer;
@property (nonatomic, assign, nullable) CVPixelBufferRef pixelBufferRight;
@property (nonatomic, assign) double pts_ms;
@property (nonatomic, assign) double origin_pts;
@property (nonatomic, assign) double repeatPtsMs;
@property (nonatomic, assign) double clipMediaTimeMs;
@property (nonatomic, assign) BOOL hasGyroOrientation;
@property (nonatomic, assign) GLKQuaternion gyroOrientation;
@property (nonatomic, assign) double rotate;
@property (nonatomic, strong, nullable) INSPlayerImage* cutPlayerImage;
//will retain img
-(instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer pts:(double)pts_ms;
-(instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer pts:(double)pts_ms originPts:(double)origin_pts;
-(instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer right:(CVPixelBufferRef)pixelbufferRight pts:(double)pts_ms;
-(instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer right:(CVPixelBufferRef)pixelbufferRight pts:(double)pts_ms originPts:(double)origin_pts;
-(instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer right:(CVPixelBufferRef)pixelbufferRight pts:(double)pts_ms originPts:(double)origin_pts segmentIndex:(int)segmentIndex;

@end

NS_ASSUME_NONNULL_END
