//
//  INSRenderView+LookHere.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/26.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSRenderView.h"

NS_ASSUME_NONNULL_BEGIN

@class INSLookHerePoint;

@interface INSRenderView (LookHere)

- (INSLookHerePoint*_Nullable) lookHerePointWithViewPoint:(CGPoint)pt;
- (INSLookHerePoint*_Nullable) lookHerePointWithViewPoint:(CGPoint)pt1 toPoint:(CGPoint)pt2;
- (void) lookHerePointWithViewPoint:(CGPoint)pt1 toPoint:(CGPoint)pt2 duration:(double)second complete:(void(^)(INSLookHerePoint*_Nullable lookHerePoint))block;
- (BOOL) viewPoint:(CGPoint*)point fromLookHerePoint:(INSLookHerePoint*)lookHerePoint;

@end

NS_ASSUME_NONNULL_END
