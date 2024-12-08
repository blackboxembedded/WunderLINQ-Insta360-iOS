//
//  INSCameraPreviewPlayer+Utils.h
//  INSCameraSDK
//
//  Created by Leo wang on 2021/10/22.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <INSCameraSDK/INSCameraSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraPreviewPlayer (Utils)

/**
 *  fetch realtime camera posture
 */
- (INSGyroRealtimeCameraPosture)fetchRealtimeCameraPosture;

@end

NS_ASSUME_NONNULL_END
