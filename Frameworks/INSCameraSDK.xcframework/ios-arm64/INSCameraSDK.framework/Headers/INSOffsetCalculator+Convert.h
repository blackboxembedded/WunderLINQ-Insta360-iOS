//
//  INSOffsetCalculator+Convert.h
//  INSCameraSDK
//
//  Created by Hkwkelvin on 2022/6/23.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <INSCoreMedia/INSCoreMedia.h>
#import "INSCameraMediaBasic.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSOffsetCalculator (Convert)

+ (NSString *)convertLens283PanoOffset:(NSString *)offset resolution:(INSVideoResolution)resolution;

@end

NS_ASSUME_NONNULL_END
