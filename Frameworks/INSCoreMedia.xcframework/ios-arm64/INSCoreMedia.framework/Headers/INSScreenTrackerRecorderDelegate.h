//
//  INSScreenTrackerRecorderDelegate.h
//  INSCoreMedia
//
//  Created by HFY on 2020/3/23.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol INSScreenTrackerRecorderDelegate <NSObject>

- (void) recorderTrackerOrientation:(GLKQuaternion)orientation
                          targetRoi:(CGRect)targetRoi
                               xFov:(float)xFov
                           distance:(float)distance
                          timestamp:(double)timestamp;

@end

NS_ASSUME_NONNULL_END
