//
//  INSMultiviewScheme.h
//  INSCoreMedia
//
//  Created by HFY on 2020/7/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSMultiviewDisplay.h"

NS_ASSUME_NONNULL_BEGIN

@class INSDisplayValue;
@class INSTimeRange;
@class INSMultiviewConfiguration;
@interface INSMultiviewScheme : NSObject<NSCoding, NSCopying, NSMutableCopying>

-(instancetype)initWithMultiviewDisplay:(INSMultiviewDisplay*)display config:(INSMultiviewConfiguration*)config timeRange:(INSTimeRange*)timeRange;

@property(nonatomic, strong)INSMultiviewDisplay *display;
@property(nonatomic, strong)INSMultiviewConfiguration *config;
@property(nonatomic, strong)INSTimeRange *timeRange;

@end

NS_ASSUME_NONNULL_END

