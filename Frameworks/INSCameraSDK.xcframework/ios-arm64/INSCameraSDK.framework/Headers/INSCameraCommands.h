//
//  INSCameraCommands+All.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/11/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSCameraCommands.h"
#import "INSCameraCommands+Deprecated.h"
#import "INSCameraMediaBasic.h"
#import "INSCameraCommandOptions.h"
#import "INSCameraPhotoInfo.h"
#import "INSCameraVideoInfo.h"
#import "INSCameraFileMndInfo.h"
#import "INSCameraDataInfo.h"
#import "INSCameraFileInfo.h"
#import "INSCameraRequestOptions.h"

NS_ASSUME_NONNULL_BEGIN

/// convert (photo or video) resource uri to http url via http tunnel and Wi-Fi socket
extern NSURL *INSHTTPURLForResourceURI(NSString *uri);

/// convert local http url to (photo or video) resource uri
extern NSString *INSResourceURIFromHTTPURL(NSURL *url);

@class INSCameraDeviceSettings;

@protocol INSCameraBasicCommands <NSObject>

/// Take picture command
- (void)takePictureWithOptions:(nullable INSTakePictureOptions *)options
                    completion:(void(^)(NSError * _Nullable error,
                                        INSCameraPhotoInfo * _Nullable photoInfo))completion;

/*!
 * @discussion  Start capture video, if success, the camera will save video to sd card.
 *
 * @param   options Nano only.
 * @param   completion  the callback block.
 */
- (void)startCaptureWithOptions:(nullable INSCaptureOptions *)options
                     completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * @discussion  Stop capture video.
 *
 * @param   options some capture options.
 * @param   completion  the callback block.
 */
- (void)stopCaptureWithOptions:(nullable INSCaptureOptions *)options
                    completion:(void(^)(NSError * _Nullable error,
                                        INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * @discussion  Get options
 *
 * @param   optionTypes array of the INSCameraOptionsType to get.
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 *
 */
- (void)getOptionsWithTypes:(NSArray <NSNumber *>*)optionTypes
                 completion:(void(^)(NSError * _Nullable error, INSCameraOptions * _Nullable options, NSArray <NSNumber *>* _Nullable successTypes))completion;
/*!
 * @discussion  Set opitons
 *
 * @param   options the options will be set to
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setOptions:(INSCameraOptions *)options
          forTypes:(NSArray <NSNumber *>*)optionTypes
        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

- (void)getOptionsWithTypes:(NSArray <NSNumber *>*)optionTypes
             requestOptions:(INSCameraRequestOptions * _Nullable)requestOptions
                 completion:(void(^)(NSError * _Nullable error, INSCameraOptions * _Nullable options, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set opitons
 *
 * @param   options the options will be set to
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setOptions:(INSCameraOptions *)options
    requestOptions:(INSCameraRequestOptions * _Nullable)requestOptions
          forTypes:(NSArray <NSNumber *>*)optionTypes
        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Get photography options. Your app should not call this method to get the current photography options. Instead, your app should rely on the photography options that just set, or they will be as default.
 *
 * @param   functionMode the target function mode to get
 * @param   optionTypes array of the INSPhotographyOptionsType to get
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)getPhotographyOptionsWithFunctionMode:(INSCameraFunctionMode)functionMode
                                        types:(NSArray <NSNumber *>*)optionTypes
                                   completion:(void(^)(NSError * _Nullable error, INSPhotographyOptions * _Nullable options,  NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set photography opitons.
 *
 * @param   options the options will be set to
 * @param   functionMode the target function mode to get
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setPhotographyOptions:(INSPhotographyOptions *)options
              forFunctionMode:(INSCameraFunctionMode)functionMode
                        types:(NSArray <NSNumber *>*)optionTypes
                   completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;


- (void)getSubmodeOptionsWithFunctionMode:(INSCameraFunctionMode)functionMode
                                    types:(NSArray <NSNumber *>*)optionTypes
                               completion:(void(^)(NSError * _Nullable error, INSSubmodeOptions * _Nullable options,  NSArray <NSNumber *>* _Nullable successTypes))completion;


- (void)setSubmodeOptions:(INSSubmodeOptions *)options
          forFunctionMode:(INSCameraFunctionMode)functionMode
                    types:(NSArray <NSNumber *>*)optionTypes
               completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Upload gps datas and append the datas to the file. You should call this method according to a certain frequency when you are recording.
 *
 * availability(ONE)
 *
 * @param   gpsDatas    gps datas to append
 * @param   completion  callback block. if success, error would be nil
 */
- (void)uploadGpsDatas:(NSArray <INSMediaGps *> *)gpsDatas
            completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Set time lapse options
 *
 * availability(ONE, ONE X, Nano, Nano S, Go)
 *
 * @param   options INSTimeLapseOptions to be set
 * @param   mode timelapse mode
 * @param   completion  callback block.
 */
- (void)setTimelapseOptions:(INSTimelapseOptions *)options
                    forMode:(INSTimelapseMode)mode
                 completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Get time lapse options
 *
 * availability(ONE, ONE X, Nano, Nano S, Go)
 *
 * @param   mode timelapse mode
 * @param   completion  callback block.
 */
- (void)getTimelapseOptionsWithMode:(INSTimelapseMode)mode
                         completion:(void(^)(NSError * _Nullable error, INSTimelapseOptions * _Nullable options))completion;

/*!
 * Start time lapse capture. For ONE X, you can input `INSExtraInfo` via options if the `INSTimelapseMode` is image.
 *
 * availability(ONE, ONE X)
 */
- (void)startCaptureTimelapseWithOptions:(INSStartCaptureTimelapseOptions  * _Nonnull)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Start time lapse capture
 *
 * availability(ONE)
 */
- (void)stopCaptureTimelapseWithCompletion:(void(^)(NSError * _Nullable error,
                                                    INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * Stop time lapse capture. For ONE X, you can input `INSExtraInfo` via options if the `INSTimelapseMode` is video
 *
 * availability(ONE X)
 */
- (void)stopCaptureTimelapseWithOptions:(INSStopCaptureTimelapseOptions * _Nonnull)options completion:(void(^)(NSError * _Nullable error, INSCameraVideoInfo * _Nullable videoInfo))completion;

/*!
 * availability(X4)
 */
- (void)pauseInVideoWithCompletion:(void (^)(NSError * _Nullable))completion;
/*!
 * Tell camera to scan bluetooth peripherals
 *
 * availability(ONE, ONE X)
 */
- (void)scanBTPeripheralWithType:(INSCameraBTPeripheralType)type completion:(void (^)(NSError * _Nullable))completion;

/*!
 * Tell camera to connect bluetooth peripheral
 *
 * availability(ONE, ONE X)
 */
- (void)connectBTPeripheral:(INSCameraBTPeripheral *)peripheral
                 completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Tell camera to disconnect bluetooth peripheral
 *
 * availability(ONE, ONE X)
 */
- (void)disconnectBTPeripheral:(INSCameraBTPeripheral *)peripheral
                    completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Get bluetooth peripherals that connected to camera
 *
 * availability(ONE, ONE X)
 */
- (void)getConnectedBTPeripheralWithType:(INSCameraBTPeripheralType)type
                              completion:(void(^)(NSError * _Nullable error, NSArray <INSCameraBTPeripheral *>* _Nullable peripherals))completion;

/*!
 * Open camera wifi
 *
 * availability(ONE X)
 */
- (void)openCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Close camera wifi
 *
 * availability(ONE X)
 */
- (void)closeCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Reset camera wifi
 *
 * availability(Ace)
 */
- (void)resetCameraWifiWithOptions:(INSCameraRequestOptions * _Nullable)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
 * Get current capture action. return the capture operation status in which the camera is operating
 *
 * availability(ONE bluetooth, ONE X)
 */
- (void)getCurrentCaptureStatusWithCompletion:(void(^)(NSError * _Nullable error, INSCameraCaptureStatus * _Nullable status))completion;

/*!
 * Erase camera's sd card
 *
 * availability(Nano, ONE, Nano S, ONE X, Go)
 */
- (void)eraseSDCardWithCompletion:(void(^)(NSError * _Nullable error))completion;

/*!
 * call this method as soon as Socket connection has be connected
 *
 * availability(ONE X)
 *
 * @param options should be nil for now.
 */
- (void)sendHeartbeatsWithOptions:(nullable INSHeartbeatsSenderOptions *)options;

/*!
* set the camera specific lens active
*
* availability(ONE X2)
 
* @param device     the sensor type which you can set active
* @param completion the callback block. If succeed, error will be nil, and return the mediaOffset of current active lens.
*/
- (void)setActiveSensorWithDevice:(INSSensorDevice)device
                    completion:(void (^)(NSError * _Nullable, NSString * _Nullable, NSString * _Nullable))completion;

/*!
 * calibrate camera's gyro
 *
 * availability(ONE)
 */
- (void)calibrateGyroWithOptions:(nullable INSCameraCalibrateGyroOptions *)options completion:(void(^)(NSError * _Nullable error))completion;

/*!
* gets the currently active lens of the camera
*
* availability(ONE X2)
*
* @param completion device, the currently active lens of the camera; mediaOffset, the mediaOffset of current active lens.
*/
- (void)getActiveSensorWithCompletion:(void (^)(NSError * _Nullable, INSSensorDevice, NSString * _Nullable, NSString * _Nullable))completion;

/*!
 * @discussion  Get multiple photography options.
 *
 * availability(ONE X2)
 *
 * @param   device the currently active lens of the camera
 * @param   functionMode the target function mode to get
 * @param   optionTypes array of the INSMultiPhotographyOptions to get
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)getMultiPhotographyOptionsWithActiveSensorDevice:(INSSensorDevice)device
                                          functionMode:(INSCameraFunctionMode)functionMode
                                                 types:(NSArray <NSNumber *>*)optionTypes
                                            completion:(void(^)(NSError * _Nullable error,
                                                                INSMultiPhotographyOptions * _Nullable options,
                                                                NSArray <NSNumber *>* _Nullable successTypes))completion;

/*!
 * @discussion  Set multiple photography opitons.
 *
 * availability(ONE X2)
 *
 * @param   options the options will be set to
 * @param   device the currently active lens of the camera
 * @param   functionMode the target function mode to set
 * @param   optionTypes the valid option types will be set
 * @param   completion  the callback block. If all succeed, error would be nil, if partial failed, error's code would be <code>INSCameraErrorCodeAccept</code>, if all fail, error's code would be the maximum error code.
 */
- (void)setMultiPhotographyOptions:(INSMultiPhotographyOptions *)options
             forActiveSensorDevice:(INSSensorDevice)device
                      functionMode:(INSCameraFunctionMode)functionMode
                             types:(NSArray <NSNumber *>*)optionTypes
                        completion:(void(^)(NSError * _Nullable error, NSArray <NSNumber *>* _Nullable successTypes))completion;

- (void)setAppidCompletion:(void (^)(NSError * _Nullable))completion;

/*!
 * availability(go3)
*/
- (void)setAppAccessFileState:(INSSetAccessCameraFileStateAccessState)state completion:(void (^)(NSError * _Nullable))completion;

@end

@protocol INSBluetoothCommands <NSObject>

/*!
 * get current capture status
 *
 * availability(ONE)
 */
- (void)getCurrentCaptureStatusWithCompletion:(void(^)(NSError * _Nullable error, INSCameraCaptureStatus * _Nullable status))completion;

/*!
 * get mini thumbnail
 *
 * availability(ONE)
 */
- (void)getMiniThumbnailOfURI:(NSString *)uri
                   completion:(void(^)(NSError * _Nullable error, NSData * _Nullable imageData))completion;

@end

@protocol INSCameraHTTPCommands <NSObject>

- (NSURLSessionTask *)fetchFileMndsWithCompletion:(void (^)(NSError * _Nullable error,
                                                            NSArray<INSCameraFileMndInfo *>* _Nullable fileMndInfoList))completion;

- (NSURLSessionTask *)fetchPhotoWithURI:(NSString *)URI
                             completion:(void (^)( NSError * _Nullable error, NSData * _Nullable photoData))completion;

- (NSURLSessionTask *)fetchVideoWithURI:(NSString *)URI
                            saveToLocal:(NSURL *)localURL
                               progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                             completion:(void (^)( NSError * _Nullable error))completion;

- (NSURLSessionTask *)uploadFirmwareWithLocalFile:(NSURL *)localFileURL
                                          timeout:(NSTimeInterval)timeout
                                         progress:(void (^)(NSProgress * _Nonnull progress))progressHandler
                                       completion:(void (^)(NSError * _Nullable))completion;

@end

@protocol INSCameraUSBCommands <INSCameraHTTPCommands>

/// start the live stream, your app should not call this method directly, use INSCameraMediaSession instead
- (void)startLiveStreamWithOptions:(INSLiveStreamOptions *)options
                        completion:(nullable void(^)(NSError * _Nullable error))completion;

/// stop the live stream, your app should not call this method directly, use INSCameraMediaSession instead
- (void)stopLiveStreamWithCompletion:(nullable void(^)(NSError * _Nullable error))completion;

/// take picture without storing to sd card
- (void)takePictureWithoutStoringWithOptions:(nullable INSTakePictureOptions *)options
                                  completion:(void(^)(NSError * _Nullable error,
                                                      NSData * _Nullable photoData))completion;

- (void)getDeviceSettingsWithCompletion:(void(^)(NSError * _Nullable error,
                                                 INSCameraDeviceSettings * _Nullable settings))completion;

/*!
 * @discussion  synchronize the camera's media time with the phone's media time.
 *
 * @param   completion  the callback block
 */
- (void)syncMediaTimeWithCompletion:(void(^)(NSError * _Nullable error,
                                             INSSyncMediaTimeResult * _Nullable result))completion;

/*!
 * get files extra data list from camera
 *
 * availability(ONE X)
 */
- (void)fetchFileMndListWithCompletion:(void (^)(NSError * _Nullable error,
                                                 NSArray <INSCameraFileMndInfo *>* _Nullable fileMndInfoList))completion;

- (void)getFileMndWithOptions:(INSGetFileMndOptions *)options
                   completion:(void (^)(NSError * _Nullable error, NSData * _Nullable data))completion;

/// INSFileMndTypeAll is not available for nano 1.
- (void)getFileMndWithURI:(NSString *)fileURI
                     type:(INSFileMndType)mndType
               completion:(void (^)(NSError * _Nullable error, NSData * _Nullable data))completion;

- (void)fetchRawPhotoListWithCompletion:(void (^)(NSError * _Nullable error,
                                                  NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchPhotoListWithCompletion:(void (^)(NSError * _Nullable error,
                                               NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchVideoListWithCompletion:(void (^)(NSError * _Nullable error,
                                               NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

- (void)fetchFileListWithOptions:(nonnull INSGetFileListOptions *)options completion:(nonnull void (^)(NSError * _Nullable, NSUInteger, NSArray<INSCameraFileInfo *> * _Nullable))completion;

- (void)fetchFileListWithCompletion:(void (^)(NSError * _Nullable error,
                                               NSArray <INSCameraFileInfo *>* _Nullable fileInfoList))completion;

- (void)fetchMp4ListWithCompletion:(void (^)(NSError * _Nullable error,
                                                  NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

- (void)fetchRawPhotoListWithOptions:(INSGetFileListOptions *)options
                          completion:(void (^)(NSError * _Nullable error, NSUInteger totalCount,
                                               NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchPhotoListWithOptions:(INSGetFileListOptions *)options
                       completion:(void (^)(NSError * _Nullable error, NSUInteger totalCount,
                                            NSArray <INSCameraPhotoInfo *>* _Nullable photoInfoList))completion;

- (void)fetchVideoListWithOptions:(INSGetFileListOptions *)options
                       completion:(void (^)(NSError * _Nullable error, NSUInteger totalCount,
                                            NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

/*!
 * @discussion fetch the list of videos containing the files being recorded
 *
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)fetchCompleteVideoListWithCompletion:(void (^)(NSError * _Nullable error,
                                              NSArray <INSCameraVideoInfo *>* _Nullable videoInfoList))completion;

/*!
 * @discussion  delete files
 *
 * @param   fileURIs    array of URI strings.
 * @param   completion  the callback block. If succeed, error will be nil.
 */
- (void)deleteFiles:(NSArray <NSString *>*)fileURIs
         completion:(void (^)(NSError * _Nullable error))completion;

/*!
 * write photo data to camera's sd card
 *
 * availability(Nano)
 *
 * @param   options see options
 */
- (void)writeFileWithOptions:(INSCameraWriteFileOptions *)options
                  completion:(void(^)(NSError * _Nullable error, NSString * _Nullable uri))completion;

@end

/*!
 * All commands that can be sent throught bluetooth
 *
 * availability(ONE)
 */
@protocol INSAllBluetoothCommands <INSCameraBasicCommands, INSBluetoothCommands, INSCameraDeprecatedCommands, INSCameraUSBCommands>

@end

/*!
 * All commands that can be sent throught USB
 *
 * availability(Nano, ONE, Nano S)
 */
@protocol INSCameraAllUSBCommands <INSCameraBasicCommands, INSCameraUSBCommands, INSCameraDeprecatedCommands, INSBluetoothCommands>

@end


NS_ASSUME_NONNULL_END
