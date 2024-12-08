//
//  INSViewOrientation.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/16.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

typedef NS_ENUM(NSInteger, INSViewOrientationType){
    /// 以ONER为例，拍摄按键朝上，屏幕指向拍摄者为标准姿态
    INSViewOrientationTypeLens1Front,
    INSViewOrientationTypeLens2Front,
    INSViewOrientationTypeBottom,
    INSViewOrientationTypeTop,
    INSViewOrientationTypeLeft,
    INSViewOrientationTypeRight,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSViewOrientation : NSObject

+(GLKQuaternion)viewOrientation:(GLKQuaternion)orientation type:(INSViewOrientationType)type;

+(GLKQuaternion)viewOrientation:(INSViewOrientationType)type DEPRECATED_MSG_ATTRIBUTE("Use -viewOrientation:type: instead");

+(GLKQuaternion)viewOrientationBottom:(GLKQuaternion)q DEPRECATED_MSG_ATTRIBUTE("Use -viewOrientation:type: instead");;

+(GLKQuaternion)viewOrientationTop:(GLKQuaternion)q DEPRECATED_MSG_ATTRIBUTE("Use -viewOrientation:type: instead");;

+(GLKQuaternion)transformRectToSphereCenterWithROI:(CGRect)roiRect width:(float)width height:(float)height;

+ (GLKVector3) eulerFromQuaternion:(GLKQuaternion)q;
+ (GLKQuaternion) quaternionFronEuler:(GLKVector3)euler;

+(GLKVector3)eulerFromQuaternion2:(GLKQuaternion)q;
+ (GLKQuaternion) quaternionFronEuler2:(GLKVector3)euler;

+(GLKQuaternion)oritationFromDirectional:(GLKQuaternion)direction apply:(GLKQuaternion)apply;

@end

NS_ASSUME_NONNULL_END
