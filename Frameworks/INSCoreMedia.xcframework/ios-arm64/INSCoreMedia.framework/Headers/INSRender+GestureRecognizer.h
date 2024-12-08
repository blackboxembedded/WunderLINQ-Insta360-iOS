//
//  INSRender+GestureRecognizer.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/15.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSRender (GestureRecognizer)

- (BOOL) hasGestureRecognizerAtPoint:(CGPoint)point;

- (GLKVector3) gestureRecognizerEulerAtPoint:(CGPoint)point;

- (void) setGestureRecognizerEuler:(GLKVector3)euler atPoint:(CGPoint)point;

- (INSCamera*_Nullable) gestureRecognizerCameraAtPoint:(CGPoint)point;

- (BOOL) isMultiviewCell:(CGPoint)point;

@end


NS_ASSUME_NONNULL_END
