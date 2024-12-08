//
//  INSMultiViewCircleCell.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/27.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSMultiViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSMultiViewCircleCell : INSMultiViewCell<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initCircleWithCenter:(CGPoint)center radius:(float)radius;

@property (nonatomic) CGPoint center;
@property (nonatomic) float radius;

@end

NS_ASSUME_NONNULL_END
