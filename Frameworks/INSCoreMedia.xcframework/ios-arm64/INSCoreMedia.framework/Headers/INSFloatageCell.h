//
//  INSFloatageCell.h
//  INSTextVideo
//
//  Created by pengwx on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>
#import "INSFloatagePosition.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, INSFloatageTimeType) {
    INSFloatageTimeTypeClipTime,
    INSFloatageTimeTypeClipMediaTime,
    INSFloatageTimeTypeMediaTime,
};


@interface INSFloatageCell : NSObject

// a value that affects layer's scale transform when exporting. default is YES.
@property (nonatomic) BOOL allowBoundsAffineTransform;
@property (nonatomic) BOOL hidden;
@property (nonatomic) INSFloatageTimeType timeType;
@property (nonatomic) int clipIndex;
@property (nonatomic) double startTimeMs;
@property (nonatomic) double endTimeMs;
@property (nonatomic, readonly) double durationMs;
@property (nonatomic, strong, nullable) INSFloatagePosition *currentPosition;
@property (nonatomic, strong) NSMutableArray<CALayer*> *layers;
@property (nonatomic, strong) NSMutableArray<UIView*> *views;

- (instancetype) init NS_UNAVAILABLE;
- (instancetype) initWithTimeType:(INSFloatageTimeType)timeTime clip:(int)clipIndex startTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs;

- (void) layoutExportDrawWidth:(int)width height:(int)height;
- (void) layoutSubLayer:(CGRect)viewFrame contentScale:(CGFloat)contentScale;
- (BOOL) isNeedShow:(INSFloatagePosition*)position;
- (float) positionToFactor:(INSFloatagePosition*)position;
- (void) willShowAnimationFromHide:(INSFloatagePosition*)positon;
- (void) showAnimation:(INSFloatagePosition*)position;
- (void) willHideAnimationFromShow:(INSFloatagePosition*)position;
- (void) hideAnimation;
- (void) hideCell;

@end

NS_ASSUME_NONNULL_END
