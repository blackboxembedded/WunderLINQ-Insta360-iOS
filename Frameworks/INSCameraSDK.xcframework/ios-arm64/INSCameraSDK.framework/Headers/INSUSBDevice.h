//
//  INSUSBDevice.h
//  INSCameraSDK
//
//  Created by zeng bin on 12/29/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <ExternalAccessory/ExternalAccessory.h>
#endif
#import "INSCameraDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSUSBDevice : NSObject <INSCameraDevice>

#if TARGET_OS_IOS
@property (nonatomic, nullable, readonly) EAAccessory *accessory;
#endif

@property (nonatomic, nullable, readonly) NSString *sessionProtocol;

@property (nonatomic) BOOL connected;

@property (nonatomic, readonly) NSUInteger connectionID;
@property (nonatomic, readonly) NSString *manufacturer;
@property (nonatomic, readonly) NSString *modelNumber;
@property (nonatomic, readonly) NSString *hardwareRevision;

@property (nonatomic, readonly) NSArray<NSString *> *protocolStrings;

#if TARGET_OS_IOS
+ (nullable NSString *)protocolStringForAccessory:(EAAccessory *)accessory;

- (instancetype)initWithAccessory:(EAAccessory *)accessory;
#endif

- (instancetype)initWithDict:(NSDictionary *)dict;

- (NSDictionary *)toDict;

@end


NS_ASSUME_NONNULL_END
