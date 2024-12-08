//
//  INSMultiviewFlatOffscreenRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/7.
//  Copyright © 2017年 insta360. All rights reserved.
//



#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSMultipleConverter;
@class INSMultiviewScheme;
@interface INSMultiviewFlatOffscreenRender : INSOffscreenRender

@property(nonatomic, strong, nullable)INSMultipleConverter *view2Converter;
@property(nonatomic, strong, nullable)INSMultipleConverter *view3Converter;
@property(nonatomic, strong, nullable)NSArray<INSMultiviewScheme*>* multiviewSchemes;

@end

NS_ASSUME_NONNULL_END
