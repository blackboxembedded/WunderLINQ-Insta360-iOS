//
//  INSCameraCommands+Deprecated.h
//  INSCameraSDK-bluetooth
//
//  Created by Leo wang on 2021/11/2.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSCameraCommandOptions+Deprecated.h"
#import "INSCameraVideoInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol INSCameraDeprecatedCommands <NSObject>

/*!
 * @discussion  Start bullet time video, if success, the camera will save bullet time video to sd card.
 * availability(ONE X)
 *
 * @param   options For ONE X, just nil.
 * @param   completion  the callback block.
 */
- (void)startBulletTimeWithOptions:(nullable INSBulletTimeOptions *)options
                        completion:(void(^)(NSError * _Nullable error))completion
DEPRECATED_MSG_ATTRIBUTE("use 'startCaptureWithOptions:completion:' instead.");

/*!
 * @discussion  Stop capture bullet time video.
 * availability(ONE X)
 *
 * @param   options some capture options.
 * @param   completion  the callback block.
 */
- (void)stopBulletTimeWithOptions:(nullable INSBulletTimeOptions *)options
                       completion:(void(^)(NSError * _Nullable error,
                                           INSCameraVideoInfo * _Nullable videoInfo))completion
DEPRECATED_MSG_ATTRIBUTE("use 'stopCaptureWithOptions:completion:' instead.");

/*!
 * @discussion  Start HDR video, if success, the camera will save HDR video to sd card.
 * availability(ONE X)
 *
 * @param   options For ONE X, just nil.
 * @param   completion  the callback block.
 */
- (void)startHDRVideoWithOptions:(nullable INSHDRVideoOptions *)options
                      completion:(void(^)(NSError * _Nullable error))completion
DEPRECATED_MSG_ATTRIBUTE("use 'startCaptureWithOptions:completion:' instead.");

/*!
 * @discussion  Stop HDR video.
 * availability(ONE X)
 *
 * @param   options some capture options.
 * @param   completion  the callback block.
 */
- (void)stopHDRVideoWithOptions:(nullable INSHDRVideoOptions *)options
                       completion:(void(^)(NSError * _Nullable error,
                                           INSCameraVideoInfo * _Nullable videoInfo))completion
DEPRECATED_MSG_ATTRIBUTE("use 'stopCaptureWithOptions:completion:' instead.");

@end

NS_ASSUME_NONNULL_END
