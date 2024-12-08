//
//  INSFloatageCellManager.h
//  INSTextVideo
//
//  Created by pengwx on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSFloatageCell.h"
#import "INSFloatageDrawProtocol.h"

NS_ASSUME_NONNULL_BEGIN


@protocol INSFloatageCellManagerDelegate <NSObject>

- (void) floatageCellWillAdd:(INSFloatageCell*)cell;
- (void) floatageCellWillRemove:(INSFloatageCell*)cell;
- (void) floatageNeedDisplay;

@end

@interface INSFloatageCellManager : NSObject<INSFloatageDrawProtocol>


/**
 添加cell， 内部会操作CALayer，需要在主线程调用
 @param cell cell
 */
- (void) addFloatageCell:(INSFloatageCell*)cell;
- (void) removeFloatageCell:(INSFloatageCell*)cell;
- (void) removeAllFloatagCell;
- (void) showAnimation:(INSFloatagePosition*)position;
- (void) layoutSubLayer:(CGRect)viewFrame;

@property (nonatomic, weak, nullable) id<INSFloatageCellManagerDelegate> delegate;
@property (nonatomic, strong, readonly) NSMutableArray<INSFloatageCell*> *cells;
@property (nonatomic, strong, readonly, nullable) INSFloatagePosition *currentPosition;

@end

NS_ASSUME_NONNULL_END
