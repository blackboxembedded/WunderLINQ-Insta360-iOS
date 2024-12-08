//
//  INSCameraDeviceSettings.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/18/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraMediaBasic.h"

NS_ASSUME_NONNULL_BEGIN

@class INSSyncMediaTimeResult;

@interface INSCameraDeviceSettings : NSObject

/*!
 * @discussion  the media offset which will be used to stitch
 */
@property (nonatomic, readonly) NSString *mediaOffset;

@property (nonatomic, readonly, nullable) NSString *mediaOffsetV2;

@property (nonatomic, readonly, nullable) NSString *mediaOffsetV3;

@property (nonatomic, readonly, nullable) NSString *mediaOffset3D;

@property (nonatomic, readonly) NSTimeInterval cameraMediaTime;

@property (nonatomic, readonly) NSTimeInterval mediaTimeAccuracy;

@property (nonatomic, readonly) NSTimeInterval localMediaTime;

@property (nonatomic, readonly) NSTimeInterval activeTime;

@end

@interface INSMutableCameraDeviceSettings : INSCameraDeviceSettings

@property (nonatomic) NSString *mediaOffset;

@property (nonatomic, nullable) NSString *mediaOffsetV2;

@property (nonatomic, nullable) NSString *mediaOffsetV3;

@property (nonatomic, nullable) NSString *mediaOffset3D;

@property (nonatomic) NSTimeInterval cameraMediaTime;

@property (nonatomic) NSTimeInterval mediaTimeAccuracy;

@property (nonatomic) NSTimeInterval localMediaTime;

@property (nonatomic) NSTimeInterval activeTime;


@end

NS_ASSUME_NONNULL_END
