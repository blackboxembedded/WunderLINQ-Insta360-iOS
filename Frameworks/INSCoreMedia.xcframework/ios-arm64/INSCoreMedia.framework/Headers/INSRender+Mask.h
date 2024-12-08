//
//  INSRender+Mask.h
//  INSMediaApp
//
//  Created by pengwx on 16/12/1.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import "INSRender.h"
#import <GLKit/GLKit.h>


NS_ASSUME_NONNULL_BEGIN

@class INSMask;
@class INSMaskRes;
@class INSMaskInfo;

@interface INSRender (Mask)


- (NSArray*_Nullable) getMaskInfo;

- (NSArray*_Nullable) getMask;

- (INSMask*_Nullable) addMaskWithMaskInfo:(INSMaskInfo*)info;

- (INSMask*_Nullable) addMaskWithScreenPoint:(CGPoint)point size:(float)angle resource:(INSMaskRes*)res;
- (INSMask*_Nullable) addMaskWithFlatImagePoint:(CGPoint)point rotation:(float)rotation size:(float)angle resource:(INSMaskRes *)res;

- (void) addMask:(INSMask*)mask;
- (void) moveMaskToTop:(INSMask*)mask;
- (void) removeMask:(INSMask*)mask;
- (void) removeAllMask;

- (CGSize) estimateMaskScreenSize:(INSMask*)mask;

- (INSMask*_Nullable) getTopsideMaskWithScreenPoint:(CGPoint)point;

- (NSArray*_Nullable) getAllMask;

- (NSArray*_Nullable) getAllMaskWithScreenPoint:(CGPoint)point;

- (BOOL) getMaskPosition:(INSMask*)mask center:(CGPoint*)center size:(CGSize*)size;

- (BOOL) transformScreenPoint:(CGPoint)point toQuaternion:(GLKQuaternion*)quaternion;
- (BOOL) transfromQuaternion:(GLKQuaternion)quaternion toScreenPoint:(CGPoint*)point;
- (BOOL) transformScreenPoint:(CGPoint)point toFlatPanoPoint:(CGPoint*)flatPt;
- (BOOL) transfromFlatPanoPoint:(CGPoint)flatPoint toScreenPoint:(CGPoint *)screenPoint;

- (BOOL) viewPoint:(CGPoint)viewPoint toRawImagePoint:(CGPoint*)imagePoint;

- (BOOL) viewPoint:(CGPoint)viewPoint toSpherePoint:(GLKVector3*)spherePoint;
- (BOOL) spherePoint:(GLKVector3)spherePoint toViewPoint:(CGPoint *)viewPoint;

@end

NS_ASSUME_NONNULL_END
