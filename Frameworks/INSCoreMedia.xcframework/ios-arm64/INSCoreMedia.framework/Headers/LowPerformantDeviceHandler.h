//
//  LowPerformantDeviceHandler.h
//  INSCoreMedia
//
//  Created by ruiwen feng on 2022/7/12.
//  Copyright © 2022 insta360. All rights reserved.
//

#ifndef LowPerformantDeviceHandler_h
#define LowPerformantDeviceHandler_h

#import <UIKit/UIKit.h>

@interface LowPerformantDeviceHandler : NSObject

+ (void)hugeImageAdoptDecodeFrame:(int *)width height:(int *)height;
+ (void)hugeImageAdoptCalculateFrame:(int *)width height:(int *)height;

@end

#endif /* LowPerformantDeviceHandler_h */
