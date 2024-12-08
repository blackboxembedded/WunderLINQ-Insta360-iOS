//
//  INSFlatMask.h
//  INSMediaApp
//
//  Created by pengwx on 16/11/14.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import "INS3DObject.h"

NS_ASSUME_NONNULL_BEGIN

@class INSMaskInfo;
@class INSTexureRGBA;
@interface INSFlatMask : INS3DObject

- (instancetype) initWithMaskInfo:(INSMaskInfo*)info width:(float)width height:(float)height;

- (void) setAdjustOrientation:(GLKQuaternion)adjustOrientation;

@end

NS_ASSUME_NONNULL_END
