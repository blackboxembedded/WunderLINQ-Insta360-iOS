//
//  INSBluetoothManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/25/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "INSCameraCommands.h"
#import "INSBluetoothDevice.h"

typedef NS_ENUM(NSUInteger, INSBluetoothManageState) {
    /// bluetooth is not enabled, look at <i>centralManager.state</i> for details.
    /// if centralManager.state is equal to CBManagerStateUnauthorized, plz ask for permission.
    /// if centralManager.state is equal to CBManagerStatePoweredOff, wait some milliseconds for powering on. Once powered on, the state will chnaged to INSBluetoothManageStateNoConnection.
    INSBluetoothManageStateBluetoothDisabled,
    
    /// bluetooth is enabled without connection, or connection is disconnected.
    INSBluetoothManageStateReady,
};

typedef NS_ENUM(NSUInteger, INSBluetoothConnectionState) {
    /// an insta360 camera is found, but not connected, will not response
    INSBluetoothConnectionStateFound,
    
    /// an insta360 camera is synchronized, but not connected, will not response
    INSBluetoothConnectionStateSynchronized,
    
    /// the nano device is connected, app is able to send requests
    INSBluetoothConnectionStateConnected,
    
    /// connect failed
    INSBluetoothConnectionStateFailed,
    
    /// default state, no insta360 camera is found
    INSBluetoothConnectionStateNoConnection,
};

NS_ASSUME_NONNULL_BEGIN

@protocol INSBluetoothManagerDelegate <NSObject>

@optional

- (void)deviceDidConnected:(INSBluetoothDevice *)device;

- (void)device:(INSBluetoothDevice *)device didDisconnectWithError:(nullable NSError *)error;

@end

/**
 *  @class  INSBluetoothManager
 *
 *  @discussion make sure state is not equal to INSBluetoothManageStateBluetoothDisabled before scanning or connecting.
 *
 *  You can get a bluetooth command manager with <code>commandManagerByPeripheral:</code>, then send commands.
 *
 *  For notifications, unlike INSCameraManager, the notifications will be distributed on <code>NSNotificationCenter.defaultCenter</code>
 */
@interface INSBluetoothManager : NSObject

@property (nonatomic, weak) id<INSBluetoothManagerDelegate> delegate;

/// CBCentralManager instance
@property (nonatomic, readonly) CBCentralManager *centralManager;

/// current state
@property (nonatomic, readonly) INSBluetoothManageState state;

/// current connectionState
@property (nonatomic, readonly) INSBluetoothConnectionState connectionState;

/// current state
@property (nonatomic, readonly) NSArray <INSBluetoothDevice *> *connectedDevices;

/// scaned device repeat callback
@property (nonatomic) BOOL scanedDeviceRepeatCallback;

#if TARGET_OS_IOS
/// advertising
@property (nonatomic, readonly) BOOL isAdvertisingPackage;
#endif

/*!
 * scan for insta360 camera. It seems that the same peripheral still may be received several times although the duplicate filter has been enabled.
 *
 * @param   handler the callback for receiving a camera's signal
 *              cameraPeripheral the peripheral object.
 *              RSSI    the current received signal strength indicator of the peripheral, in decibels. value varies from -100 to 0, the closer the value is to 0, the stronger the received signal has been. 127 means
 */
- (void)scanCamerasWithHandler:(void (^)(INSBluetoothDevice * _Nonnull device,
                                         NSNumber * _Nonnull RSSI,
                                         NSDictionary<NSString *, id> * _Nonnull advertisementData))handler;

/*!
 * scan for insta360 camera. It seems that the same peripheral still may be received several times although the duplicate filter has been enabled.
 *
 * @param   retryTimeSequence Array of time point that rescan.
 * @param   handler the callback for receiving a camera's signal
 *              cameraPeripheral the peripheral object.
 *              RSSI    the current received signal strength indicator of the peripheral, in decibels. value varies from -100 to 0, the closer the value is to 0, the stronger the received signal has been. 127 means
 */
- (void)scanCamerasWithRetryTimeSequence:(NSArray<NSNumber *> *)retryTimeSequence
                                 handler:(void (^)(INSBluetoothDevice * _Nonnull device,
                                                   NSNumber * _Nonnull RSSI,
                                                   NSDictionary<NSString *, id> * _Nonnull advertisementData))handler;

/*!
 * rescan
 */
- (void)rescanCameras;

/*!
 * stop scan
 */
- (void)stopScan;

/*!
 * connect to a camera with its CBPeripheral instance, which maybe returned by scanCamerasWithHandler.
 *
 * availability(ONE)
 *
 * @param   device  the device to connect.
 * @param   completion  callback block, if success, error would be nil.
 *
 * @return  an object can be used by cancelConnect:
 */
- (id)connectDevice:(INSBluetoothDevice *)device
         completion:(void(^)(NSError  * _Nullable error))completion;

/*!
 * connect a insta360 camera with saved UUID
 *
 * availability(ONE)
 *
 * @param   UUID    the identifier of a peripheral instance
 *
 * @return  an object can be used by cancelConnect:
 */
- (id)connectWithUUID:(NSUUID *)UUID
           completion:(void(^)(NSError  * _Nullable error, INSBluetoothDevice * _Nullable device))completion;

/*!
 * connect a insta360 camera with its advertise name
 *
 * @param   name    the advertise name of a camera. For ONE, it should be "Insta360 ONE xxxxxx"
 *
 * @return  an object can be used by cancelConnect:
 */
- (id)connectWithName:(NSString *)name
           completion:(void(^)(NSError  * _Nullable error, INSBluetoothDevice * _Nullable device))completion;

/*!
 * cancel a connection which create by connectPeripheral::, connectWithUUID:: or connectWithName::
 *
 * @param   task    the object return by the connect method
 */
- (void)cancelConnect:(id)task;

/*!
 * disconnect the device
 *
 * @param device camera connected with bluetooth
 */
- (void)disconnectDevice:(INSBluetoothDevice *)device;

/*!
 * get all current connected devices from system api
 */
- (NSArray<INSBluetoothDevice *> *)connectedDevicesFromSystem;

/*!
 * disconnect all current connected devices
 */
- (void)disconnectConnectedDevices:(BOOL)containFlow;

/*!
 * get commandManager by camera device
 */
- (id<INSAllBluetoothCommands>)commandManagerByDevice:(INSBluetoothDevice *)device;


/*!
 * read RSSI
 *
 * @param device camera connected with bluetooth
 * @param completion completion
 */
- (void)readRSSI:(INSBluetoothDevice *)device
      completion:(void (^)(NSError * _Nullable error, NSNumber * _Nullable RSSI))completion;


#if TARGET_OS_IOS
/*!
 * wake up camera.DO ensure the 'state' is on 'INSBluetoothManageStateReady',otherwise maybe the bluetooth is powered off.
 *
 * @param completion completion
 */
- (void)wakeUpWithCompletion:(void (^)(NSError * _Nullable))completion;

/*!
 * wake up Specific camera.DO ensure the 'state' is on 'INSBluetoothManageStateReady',otherwise maybe the bluetooth is powered off.
 *
 * @param cameraId You should get the camera's serial number last six character. AND change them to ascii code one by one using HEX. For example ,the serial number is "ABCDEF",you should change it into "414243444546" , but not "656667686970"
 * @param completion completion
 */
- (void)wakeUpSpecificCamera:(NSString *)cameraId completion:(void (^)(NSError * _Nullable))completion;

/*!
 * stop advertising wake-up packet.
 */
- (void)stopWakeUpAdvertising;
#endif

@end

NS_ASSUME_NONNULL_END
