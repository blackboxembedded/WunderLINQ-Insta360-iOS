//
//  INSHDRTask.h
//  INSCameraSDK
//
//  Created by zeng bin on 7/21/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraCommands.h"

NS_ASSUME_NONNULL_BEGIN

@class INSHDRTask;
@class INSHDRImageDataModel;

typedef NS_ENUM(NSUInteger, INSHDRTaskState) {
    /// start to download images. userInfo: nil
    INSHDRTaskStateStartDownload,
    
    /// download images completed. userInfo: nil
    INSHDRTaskStateEndDownload,
    
    /// start to generate HDR image. userInfo: nil
    INSHDRTaskStateStartGenerateHDR,
    
    /// generate HDR image completed. userInfo: @{"data": NSData}
    INSHDRTaskStateEndGenerateHDR,
    
    /// delete original photos. userInfo: nil
    INSHDRTaskStateDeleteOriginalPhotos,
    
    /// start to write to camera. userInfo: nil
    INSHDRTaskStateStartWriteFile,
    
    /// write to camera complete. userInfo: {@"photo": INSCameraPhotoInfo}
    INSHDRTaskStateEndWriteFile,
    
    /// task process failed. userInfo: {@"error": NSError}
    INSHDRTaskStateFailed,
};

typedef NS_ENUM(NSUInteger, INSHDRLib) {
    /// using `OpenCV` to generate hdr image
    INSHDRLibOpenCV,
    
    /// using `InsImgProLib` to generate hdr image
    INSHDRLibInsImgProc,
};

typedef NS_ENUM(NSUInteger, INSSeamlessType) {
    /// default type
    INSSeamlessTypeTemplate,
    
    /// using Optical flow
    INSSeamlessTypeOpticalFlow,
};

@protocol INSHDRTaskDelegate <NSObject>

- (void)task:(INSHDRTask *)task updateState:(INSHDRTaskState)state
    userInfo:(nullable NSDictionary *)userInfo;

@end

@interface INSHDROptions : NSObject

/**
 *  Array of file urls (e.g. Camera: http://Host:Port/DCIM/Camera01/xxx, Local: file:///...)
 *
 *  It is recommended that URL be transformed using the following methods:
 *
 *  To url: NSURL *INSHTTPURLForResourceURI(NSString *uri);
 *
 *  To string:  NSString *INSResourceURIFromHTTPURL(NSURL *url);
 */
@property (nonatomic, strong) NSArray <NSURL *>*urls;

/// Indicate the hdr processing lib. Default is INSHDRLibInsImgProc.
@property (nonatomic) INSHDRLib lib;

/// Indicate the hdr stitching algorithm. Default is INSSeamlessTypeTemplate.
@property (nonatomic) INSSeamlessType seamlessType;

/**
 *  Indicate the hdr image output resolution.
 *  If you want to use the original size of image, set CGSizeZero. Default is CGSizeZero.
 */
@property (nonatomic) CGSize outputSize;

/// Indicate the hdr image output will be optimized. Default is NO.
@property (nonatomic) BOOL imageOptimization;

@end

@interface INSHDRTask : NSObject

@property (nonatomic, weak) id<INSHDRTaskDelegate> delegate;

- (instancetype)initWithCommandManager:(id<INSCameraUSBCommands>)commandManager;

/*!
 * using `OpenCV` to generate hdr image base on source image in camera, delete original files and upload hdr image to camera.
 *
 * availability(Nano, ONE, ONE X)
 *
 * @param   uris        array of uri (/DCIM/Camera01/xxx)
 * @param   completion  both delegate method and completion will be invoked.
 */
- (void)processWithURIs:(NSArray <NSString *>*)uris
             completion:(nullable void(^)(NSError * _Nullable error, INSCameraPhotoInfo * _Nullable photo))completion;

/*!
 * using `OpenCV` to generate hdr image base on source images.
 *
 * availability(Nano, ONE, ONE X)
 *
 * @param   imageDatas  array of image's data
 * @param   completion  both delegate method and completion will be invoked.
 */
- (void)processWithImages:(NSArray<NSData *> *)imageDatas
               completion:(nullable void(^)(NSError * _Nullable error, NSData * _Nullable photoData))completion;

/*!
 * generate hdr image base on source image, using `InsImgProcLib` to generate HDR image
 *
 * availability(ONE X)
 *
 * @param   urls        array of url (part of the URI - Camera: /DCIM/Camera01/xxx, Local: file:///...)
 * @param   type        indicate the stitching algorithm
 * @param   completion  A block called with the HDR Mat rgb data model result.
 */
- (void)processWithURLs:(NSArray <NSURL *>*)urls seamlessType:(INSSeamlessType)type
             completion:(nullable void(^)(NSError * _Nullable error, INSHDRImageDataModel * _Nullable dataModel))completion;

/*!
 * generate hdr image base on source image.
 *
 * availability(ONE X)
 *
 * @param   options     INSHDROptions to be set
 * @param   completion  both delegate method and completion will be invoked.
 */
- (void)processWithOptions:(INSHDROptions *)options
                completion:(nullable void(^)(NSError * _Nullable error, NSData * _Nullable photoData))completion;

/*!
 * write to generate HDR image to camera's sd card
 *
 * availability(Nano, ONE, ONE X)
 *
 * @param   photoData   the photo's data
 * @param   uri     the target place to write
 * @param   uris    the original photos to delete
 * @param   completion  the callback block.
 */
- (void)writeToCamera:(NSData *)photoData uri:(NSString *)uri
         originalURIs:(NSArray <NSString *>*)uris
           completion:(nullable void(^)(NSError * _Nullable error, INSCameraPhotoInfo * _Nullable photo))completion;

@end

NS_ASSUME_NONNULL_END
