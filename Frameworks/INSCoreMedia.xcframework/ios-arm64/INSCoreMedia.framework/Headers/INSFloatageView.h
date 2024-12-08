//
//  INSFloatageView.h
//  INSTextVideo
//
//  Created by pengwx on 2018/11/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSFloatageCellManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFloatageView : UIView

@property (nonatomic, strong, readonly) INSFloatageCellManager *cellManager;

@end

NS_ASSUME_NONNULL_END
