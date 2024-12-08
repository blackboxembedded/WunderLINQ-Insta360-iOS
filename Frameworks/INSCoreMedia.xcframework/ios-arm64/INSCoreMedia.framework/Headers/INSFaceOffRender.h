//
//  INSFaceOffRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/17.
//  Copyright © 2020 insta360. All rights reserved.
//


#import "INSSphericalPanoRender.h"

@interface INSFaceOffInfo : NSObject

@property(nonatomic)double startTime;
@property(nonatomic)double endTime;
@property(nonatomic)GLKQuaternion leftStartOrientation;
@property(nonatomic)GLKQuaternion rightStartOrientation;
@property(nonatomic)GLKQuaternion endOrientation;

@end


NS_ASSUME_NONNULL_BEGIN

@interface INSFaceOffRender : INSSphericalPanoRender

@property(nonnull, strong)INSFaceOffInfo *faceOffInfo;

@end

NS_ASSUME_NONNULL_END
