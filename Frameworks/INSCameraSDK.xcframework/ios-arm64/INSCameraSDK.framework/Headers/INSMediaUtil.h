//
//  INSMediaUtil.h
//  INSCameraSDK
//
//  Created by Leo wang on 2021/10/26.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  You can learn about the rules of file names at the following website.
 *  ( https://github.com/Insta360Develop/CameraSDK-iOS#media )
 *
 *  You can construct the URIs of the whole work through the two digits of (VIN channel) (stream Num) in the file name.
 *  FileName format: (IMG/VID)_Date_Time_(VIN Channel)(Stream Num)_Serial.Extension
 */
@interface INSMediaUtil : NSObject

/// Retrieve the URIs  of the panorama video.
+ (NSArray<NSString *> *)retrievePanoFileURIsWithURI:(NSString *)uri;

/**
 *  Retrieve the URIs  of the video.
 *
 *  @param isMultichannel   Indicates whether the panorama file is divided into multiple files.
 *                        If the file is panorama video, the isMultichannel should be YES.
 *                        And if the file is wide angle video, the isMultichannel should be NO.
 */
+ (NSArray<NSString *> *)retrieveFileURIsWithURI:(NSString *)uri
                                  isMultichannel:(BOOL)isMultichannel;

/**
 *  Retrieve the URIs of all low resolution files of the video.
 *
 *  @param isMultichannel   Indicates whether the panorama file is divided into multiple files.
 *  @param isDivided    Indicates whether the low resolution panorama file is divided into multiple files.
 */
+ (NSArray<NSString *> *)retrieveLRVURIsWithURI:(NSString *)uri
                                 isMultichannel:(BOOL)isMultichannel isDivided:(BOOL)isDivided;

/// Indicate whether the video of uri is secondary channel.
+ (BOOL)checkIfChannelSecondaryURI:(NSString *)uri;

/// Indicate whether the video of uri has low resolution video.
+ (BOOL)hasSecondaryStreamWithURI:(NSString *)uri;

/// Indicate whether uri is low resolution video uri or not.
+ (BOOL)checkIfLRVURI:(NSString *)uri;

@end

NS_ASSUME_NONNULL_END
