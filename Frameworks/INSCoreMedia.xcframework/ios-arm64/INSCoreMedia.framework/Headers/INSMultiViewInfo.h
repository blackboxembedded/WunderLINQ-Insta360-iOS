//
//  INSMultiViewInfo.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/24.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

typedef NS_ENUM(NSInteger, INSMultiViewTemplateType){
    INSMultiViewTemplateTypeNone,
    INSMultiViewTemplateTypeFull,
    INSMultiViewTemplateTypeFloatingCircle,
    INSMultiViewTemplateTypeFloatingRoundedRect,
    INSMultiViewTemplateTypeTwoCell,
    INSMultiViewTemplateTypeTwoCellFloatingCircle,
    INSMultiViewTemplateTypeThreeCell,
};

typedef NS_ENUM(NSInteger, INSMultiViewAspectRatioType){
    INSMultiViewAspectRatioTypeNone,
    INSMultiViewAspectRatioTypeLive,
    INSMultiViewAspectRatioType9x16,
    INSMultiViewAspectRatioType9x16New,
    INSMultiViewAspectRatioType9x16Super,
    INSMultiViewAspectRatioType9x16Linear,
    INSMultiViewAspectRatioType1x1,
    INSMultiViewAspectRatioType1x1New,
    INSMultiViewAspectRatioType1x1Super,
    INSMultiViewAspectRatioType1x1Linear,
    INSMultiViewAspectRatioType16x9,
    INSMultiViewAspectRatioType16x9New,
    INSMultiViewAspectRatioType16x9Super,
    INSMultiViewAspectRatioType16x9Linear,
    INSMultiViewAspectRatioType4x3,
    INSMultiViewAspectRatioType235x1,
};


@class INSMultiViewCell;

NS_ASSUME_NONNULL_BEGIN

@interface INSMultiViewInfo : NSObject<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initWithTemplateType:(INSMultiViewTemplateType)templateType aspectType:(INSMultiViewAspectRatioType)aspectTyep turnnBackwards:(BOOL)backward;

@property (nonatomic) int width;
@property (nonatomic) int height;
@property (nonatomic) int outerLineWidth;
@property (nonatomic) int innerLineWidth;
@property (nonatomic) GLKVector4 lineColor;
@property (nonatomic) INSMultiViewTemplateType templateType;
@property (nonatomic) INSMultiViewAspectRatioType aspectType;
@property (nonatomic, readonly) BOOL backward;
@property (nonatomic, strong, readonly) NSMutableArray<INSMultiViewCell*> *wallCells;
@property (nonatomic, strong, readonly) NSMutableArray<INSMultiViewCell*> *floatingCells;


- (INSMultiViewCell*) addWallRectCellWithName:(NSString* _Nullable)name rect:(CGRect)rect;
- (INSMultiViewCell*) addFloatingCircleCellWithName:(NSString* _Nullable)name center:(CGPoint)center radius:(float)radius;
- (INSMultiViewCell*) addFloatingRoundedRectCellWithName:(NSString* _Nullable)name rect:(CGRect)rect radius:(float)radius;

- (INSMultiViewCell*) getWallCellWithName:(NSString*)name;
- (INSMultiViewCell*) getFloatingCellWithName:(NSString*)name;
- (INSMultiViewCell*) getCellWithPoint:(CGPoint)point;

- (void) removeAllWallCells;
- (void) removeAllFloatingCells;
- (void) updateSizeWidth:(int)width height:(int)height;


/**
 转换multiview整体视图的点到主窗口上的点
 @param viewPoint multiview整体视图的点，0~1
 @param mainCellPoint mainCell视图的点 0~1
 @return 点在主窗口上返回YES，否则返回NO
 */
- (BOOL) transformPoint:(CGPoint)viewPoint toMainCellPoint:(CGPoint*)mainCellPoint;

@end

NS_ASSUME_NONNULL_END
