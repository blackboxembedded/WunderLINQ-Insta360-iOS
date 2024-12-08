//
//  INSMultiViewRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/24.
//  Copyright © 2017年 insta360. All rights reserved.
//


#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSMultiviewScheme;
@class INSMultipleConverter;

@interface INSMultiviewRender : INSRender


/// 与multiview小窗交换视图，默认NO
@property(nonatomic)BOOL exchangeView;

@property(nonatomic, strong, nullable)INSMultipleConverter *view2Converter;
@property(nonatomic, strong, nullable)INSMultipleConverter *view3Converter;
@property(nonatomic, strong, nullable)NSArray<INSMultiviewScheme*>* multiviewSchemes;

-(BOOL)getCenterPoint:(CGPoint*)center identity:(NSString*)identity;
-(BOOL)setCenterPoint:(CGPoint)center identity:(NSString*)identity;
-(BOOL)getSize:(CGSize*)size identity:(NSString*)identity;
//-(BOOL)setSize:(CGSize)size identity:(NSString*)identity;

@end

NS_ASSUME_NONNULL_END
