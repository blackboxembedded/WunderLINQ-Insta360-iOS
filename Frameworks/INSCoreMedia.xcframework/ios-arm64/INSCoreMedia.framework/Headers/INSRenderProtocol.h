//
//  INSRenderProtocol.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/6/16.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSPlayerImage;
@class INSProjectionInfo;
@class INSRenderView;
@protocol INSRenderProtocol <NSObject>

@required
- (void) renderProjectionInfo:(INSProjectionInfo*)info playerImage:(INSPlayerImage*_Nullable)playerImage timestamp:(int64_t)timestamp;

@optional
- (void) renderView:(INSRenderView*)renderView willRenderCutClip:(int)cutClipIndex clip:(int)clipIndex;
- (void) renderView:(INSRenderView*)renderView willRenderNewClip:(int)clipIndex;
- (void) renderViewWillRenderEndImage:(INSRenderView*)renderView;
@end


@protocol INSRenderViewGestureProtocol <NSObject>

/**
 执行UIPanGestureRecognizer手势
 @param gestureRecognizer 手势
 */
- (void) actionPanGestureRecognizer:(UIPanGestureRecognizer*)gestureRecognizer;

/**
 执行UIPanGestureRecognizer手势
 @param gestureRecognizer 手势
 */
- (void) actionPinchGestureRecognizer:(UIPinchGestureRecognizer*)gestureRecognizer;

@optional

/**
 开始UIPanGestureRecognizer手势的惯性加速
 */
- (void) beginPanGestureRecognizerInertial;

/**
 结束UIPanGestureRecognizer手势的惯性加速
 */
- (void) endPanGestureRecognizerInertial;

/**
 开始UIPinchGestureRecognizer手势的惯性加速
 */
- (void) beginPinchGestureRecognizerInertial;

/**
 结束UIPinchGestureRecognizer手势的惯性加速
 */
- (void) endPinchGestureRecognizerInertial;

@end

NS_ASSUME_NONNULL_END
