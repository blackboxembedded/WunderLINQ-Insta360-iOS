//
//  INSCameraDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 3/9/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraDeviceSettings.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef INSTA360_CAMERA_NAMES
#define INSTA360_CAMERA_NAMES

/// name of Insta360 Nano
extern NSString *const kInsta360CameraNameNano;

/// name of Insta360 ONE
extern NSString *const kInsta360CameraNameOne;

/// name of Insta360 Nano S
extern NSString *const kInsta360CameraNameNanoS;

/// name of Insta360 One X
extern NSString *const kInsta360CameraNameOneX;

/// name of Insta360 EVO
extern NSString *const kInsta360CameraNameEVO;

/// name of Insta360 GO
extern NSString *const kInsta360CameraNameGo;

/// name of Insta360 ONE R
extern NSString *const kInsta360CameraNameOneR;

/// name of Insta360 ONE X2
extern NSString *const kInsta360CameraNameOneX2;

/// name of Insta360 ONE GO 2
extern NSString *const kInsta360CameraNameGo2;

/// name of Insta360 ONE H
extern NSString *const kInsta360CameraNameOneH;

/// name of Insta360 ONE RS
extern NSString *const kInsta360CameraNameOneRS;

/// name of Insta360 Reader (Horizontal Version)
extern NSString *const kInsta360ExternalNameReaderHorizontal;

/// name of Insta360 Reader (Vertical Version)
extern NSString *const kInsta360ExternalNameReaderVertical;

/// name of Insta360 Sphere
extern NSString *const kInsta360CameraNameSphere;

/// name of Insta360 X3
extern NSString *const kInsta360CameraNameX3;

/// name of Insta360 Reader (x3)
extern NSString *const kInsta360ExternalNameReaderX3;

/// name of Invisible Sphere 360 Camera
extern NSString *const kInsta360CameraNameSphere;

/// name of Insta360 fmg
extern NSString *const kInsta360ExternalNameFlow;

/// name of Insta360 ONE GO 3
extern NSString *const kInsta360CameraNameGo3;

/// name of Insta360 Reader (go3)
extern NSString *const kInsta360ExternalNameReaderGo3;

/// name of Insta360 IAC1
extern NSString *const kInsta360CameraNameIAC1;

/// name of Insta360 Reader (IAC1)
extern NSString *const kInsta360ExternalNameReaderIAC1;

/// name of Insta360 X4
extern NSString *const kInsta360CameraNameX4;

/// name of Insta360 Reader (X4)
extern NSString *const kInsta360ExternalNameReaderX4;

/// name of Insta360 IAC2
extern NSString *const kInsta360CameraNameIAC2;

#endif

extern int64_t insFirmwareRevisionNumberOfString(NSString *firmwareRevision);

typedef NS_ENUM(NSUInteger, INSCameraDeviceType) {
    INSCameraDeviceTypeUSB = 0,
    INSCameraDeviceTypeSocket,
    INSCameraDeviceTypeBluetooth,
    INSCameraDeviceTypeLite,
    INSCameraDeviceTypeWebServer,
    INSCameraDeviceTypeFlow,
};

@class INSCameraOptions;

@protocol INSCameraDevice <NSObject>

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly, nullable) NSString *cameraType;
@property (nonatomic, readonly) NSString *serialNumber;
@property (nonatomic, readonly) NSString *firmwareRevision;
@property (nonatomic, readonly) int64_t firmwareRevisionNumber;

@property (nullable, nonatomic) INSCameraDeviceSettings *settings;

@property (nonatomic, readonly) BOOL hasGyroscope;

@property (nonatomic, readonly) BOOL hasExposure;

@property (nonatomic, readonly) INSCameraDeviceType deviceType;

@property (nonatomic, readonly) BOOL isSelfie;

// Bluetooth version of the host
@property (nullable, nonatomic, readonly) NSString *hwBleVersion;

// Host OTA version number, used for upgrade
@property (nullable, nonatomic, readonly) NSString *otaPkgVersion;

// OTA version number of box
@property (nullable, nonatomic, readonly) NSString *boxOtaPkgVersion;

// Box Bluetooth version number
@property (nullable, nonatomic, readonly) NSString *boxBTVersion;

// Firmware version of the box
@property (nullable, nonatomic, readonly) NSString *boxVersion;

// Firmware version of the host
@property (nullable, nonatomic, readonly) NSString *go3Version;

/*!
 * similar to NSString's compare:options:.
 *
 * @param aFirmwareRevision the revision string, e.g. @"1.5.30"
 *
 * @return NSOrderedAscending if camera's firmware is lower than aFirmwareRevision; NSOrderedSame if camera's firmware is equal to aFirmwareRevision; NSOrderedDescending if camera's firmware is higher than aFirmwareRevision;
 */
- (NSComparisonResult)compareFirmwareRevision:(NSString *)aFirmwareRevision;

- (void)updateWithOptions:(INSCameraOptions *)options validTypes:(nonnull NSArray<NSNumber *> *)types;

@end

NS_ASSUME_NONNULL_END
