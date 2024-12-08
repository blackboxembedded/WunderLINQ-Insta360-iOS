//
//  INSCameraManager.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/1/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "INSCameraDevice.h"
#import "INSCameraCommands.h"

NS_ASSUME_NONNULL_BEGIN

/// Posted on NSNotificationCenter.defaultCenter when an insta360 camera becomes connected and available for your application to use.
extern NSString *const INSCameraDidConnectNotification;

/// Posted on NSNotificationCenter.defaultCenter when an insta360 camera becomes disconnected.
extern NSString *const INSCameraDidDisconnectNotification;

/// Posted on NSNotificationCenter.defaultCenter when an insta360 camera failed to connect.
extern NSString *const INSCameraConnectionErrorNotification;

/// Posted on NSNotificationCenter.defaultCenter when an insta360 camera becomes reconnected and available for your application to use.
extern NSString *const INSCameraDidReconnectNotification;

/// Posted on NSNotificationCenter.defaultCenter when an insta360 camera wakeup auth result.
extern NSString *const INSCameraWakeupAuthResultNotification;

typedef NS_ENUM(NSUInteger, INSCameraState) {
    /// an insta360 camera is found, but not connected, will not response
    INSCameraStateFound,
    
    /// an insta360 camera is synchronized, but not connected, will not response
    INSCameraStateSynchronized,
    
    /// the nano device is connected, app is able to send requests
    INSCameraStateConnected,
    
    /// connect failed
    INSCameraStateConnectFailed,
    
    /// default state, no insta360 camera is found
    INSCameraStateNoConnection,
};

@interface INSCameraManager : NSObject

/**
 *  a singleton usb manager.
 *  Call 'setup' when app finish launching.
 */
+ (instancetype)usbManager;

/**
 *  a singleton socket manager.
 *  If the Camera App want to use Wi-Fi mode to connect the camera when usb is disconnected,just use this instance.And call 'setup' method.And 'shutdown' if the Wi-Fi mode should be disconnected.
 */
+ (instancetype)socketManager;

/**
 *  a singleton instance of camera manager.
 *  Should NOT use this to setup any more. Use usbManager or socketManager Alternatively.
 *  It also return the instance of INSCameraManager. But can be INSCameraManager.usbManager or INSCameraManager.socketManager base on the 'cameraState'.  We retain this just for calling the 'commandManager' property to send message to cam.But in other cases,for example,if you want to use KVO to ovserver the 'currentCamera', addObserver to 'usbManager.currentCamera' or 'socketManager.currentCamera'.
 */
+ (instancetype)sharedManager;

/**
 *  repsent the current connected nano camera, nil when no camera is connected.
 */
@property (nonatomic, nullable, readonly) id<INSCameraDevice> currentCamera;

/**
 *  all the commands that the camera will handle.
 */
@property (nonatomic, nonnull, readonly) id<INSCameraAllUSBCommands> commandManager;

/**
 *  the current connection state. KVO on this property to monitor connection changes.
 */
@property (nonatomic, readonly) INSCameraState cameraState;

/**
 *  auto reconnect once when camera did disconnect.
 *  see also INSCameraDidReconnectNotification.
 */
@property (nonatomic) BOOL autoReconnect;

/**
 *  create a new object from current socket camera.
 *  only for INSSocketDevice
 */
- (nullable id<INSCameraDevice>)newCurrentCamera;

/**
 *  setup insta360 camera settings, must be called.
 */
- (void)setup;

/**
 *  must be called if you don't want to use insta360 camera any more.
 */
- (void)shutdown;

/**
 *  set respnse queue before request if you want to the response callback in your queue.
 *  otherwise, please call it with nil before request if you have called it.
 */
- (void)setResponseQueue:(NSOperationQueue * _Nullable)queue;

@end

NS_ASSUME_NONNULL_END
