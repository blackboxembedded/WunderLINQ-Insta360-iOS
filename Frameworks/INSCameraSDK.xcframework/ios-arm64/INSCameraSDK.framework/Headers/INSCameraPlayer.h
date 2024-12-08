//
//  INSCameraPlayer.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2019/9/25.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "INSCameraMediaSession.h"
#import "INSCameraMediaBasic.h"
#import "INSCameraVideoFrame.h"

NS_ASSUME_NONNULL_BEGIN

@class INSCameraPlayer;

@protocol INSCameraPlayerDelegate <NSObject>

/*!
 *  @method onStitchedPixelBuffer:timestamp:
 *  @brief  on stitched frame picture
 *
 *  @param  player INSCameraPlayer
 *  @param  stitchedFrame the pixelBuffer of this frame.
 */
- (void)player:(INSCameraPlayer *)player onStitchedFrame:(INSCameraVideoFrame *)stitchedFrame;

@end

@interface INSCameraPlayer : NSObject <INSCameraMediaPluggable>

@property (nonatomic, weak) id<INSCameraPlayerDelegate> delegate;

/*!
 * The video output pixel format.
 *
 * Right now, supported value are kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_32BGRA
 * default is kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
 */
@property (nonatomic) OSType outputPixelFormat;

@end

NS_ASSUME_NONNULL_END
