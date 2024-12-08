//
//  INSVisionField.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/4/26.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSVisionField : NSObject


@property (nonatomic) float minFov;
@property (nonatomic) float maxFov;
@property (nonatomic) float minDistance;
@property (nonatomic) float maxDistance;
//@property (nonatomic) float minPitch;
//@property (nonatomic) float maxPitch;

@end

NS_ASSUME_NONNULL_END

