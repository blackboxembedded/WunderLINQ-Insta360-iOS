//
//  INSHDRGenerator.h
//  INSCoreMedia
//
//  Created by zeng bin on 7/4/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, INSHDRGeneratorError) {
    INSHDRGeneratorErrorWrongParameters,
    INSHDRGeneratorErrorFusionFailed,
    INSHDRGeneratorErrorProcessCanceled,
    INSHDRGeneratorErrorProcessWarningShake,
    INSHDRGeneratorErrorOpencv,
};


typedef NS_ENUM(NSUInteger, INSHDRImageDataType) {
    INSHDRImageDataTypeUnknown = 0,
    INSHDRImageDataTypeRawRGB,  // A color component is arranged in RGB order, which we use for now.
    INSHDRImageDataTypeRawBGR,
    INSHDRImageDataTypeUIImage,  // A HDR UIImage Data
};

NS_ASSUME_NONNULL_BEGIN

@interface INSHDRImageDataModel : NSObject

@property (nonatomic, readonly, nullable) NSData * data;

@property (nonatomic, readonly) int cols;

@property (nonatomic, readonly) int rows;

@property (nonatomic, readonly) INSHDRImageDataType type;

@property (nonatomic, nullable) NSData *extraData; //extrainfo<INSExtraInfo> data of hdr image, appending during hdr process

@property (nonatomic, readonly) BOOL shaked;

- (instancetype _Nullable)initWithMatData:(NSData *_Nullable)data
                                     cols:(int)cols
                                     rows:(int)rows
                                     type:(INSHDRImageDataType)type;

- (instancetype _Nullable)initWithMatData:(NSData *_Nullable)data
                                     cols:(int)cols
                                     rows:(int)rows
                                     type:(INSHDRImageDataType)type
                                   shaked:(BOOL)shaked;

@end

@interface INSHDRGenerator : NSObject

/**
 using `OpenCV` to generate HDR image
 */
- (nullable NSData *)generateOpenCVHDRImageWithImages:(nonnull NSArray <NSData *>*)images
                                          error:(NSError * _Nullable * _Nullable)errorPtr;


/**
 using `InsImgProcLib` to generate HDR image

 @param images Three image data in the order of normal exposure, underexposure, overexposure, underexposure, overexposure ... and so on.
 @param isPano normally is true, means that the input images come from panorama. you should have blended input images seamlessly before hdr. On the other side, isPano = false , means the input images are normal or vr180 maybe.
 @param errorPtr error
 @return the HDR Jpeg data
 */
- (nullable NSData *)generateHDRImageWithImages:(nonnull NSArray <NSData *>*)images
                                          error:(NSError * _Nullable * _Nullable)errorPtr;
- (nullable NSData *)generateHDRImageWithImages:(nonnull NSArray <NSData *>*)images
                                 exposureLambda:(double)lambda
                                          error:(NSError * _Nullable * _Nullable)errorPtr;
- (nullable NSData *)generate123HDRImageWithImages:(nonnull NSArray <NSData *>*)images
                                          error:(NSError * _Nullable * _Nullable)errorPtr;


- (nullable INSHDRImageDataModel *)generateHDRImageWithImages:(nonnull NSArray <NSData *>*)images
                                         alignOffset:(nonnull NSString *)offset
                                               error:(NSError * _Nullable * _Nullable)errorPtr;



/**
 using `InsImgProcLib` to generate HDR image, return the data converted from the cmMat bytes

 @param images images Three image data in the order of normal exposure, underexposure, overexposure
 @param isPano normally is true, means that the input images come from panorama. you should have blended input images seamlessly before hdr. On the other side, isPano = false , means the input images are normal or vr180 maybe.
 @param errorPtr error
 @return the HDR Mat rgb data model
 */
- (nullable INSHDRImageDataModel *)generateHDRMatDataWithImages:(nonnull NSArray <NSData *>*)images
                                                         isPano:(BOOL)isPano
                                            error:(NSError * _Nullable * _Nullable)errorPtr;

/**
 cancel `generateHDRImageWithImages:isPano:error:` , an errorPtr with code `INSHDRGeneratorErrorProcessCanceled`  will call back.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
