//
//  INSTransformRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/8/8.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSProjectionConverter;
@class INSTransformRender;

@protocol INSTransformRenderDelegate <NSObject>

@optional
- (UIImage *)transformImageForTransformRender:(INSTransformRender *)transformRender transformRatio:(float)ration;

@end

@class INSNvFilter;
@interface INSTransformRender : INSRender

@property (nonatomic, strong, nullable)INSRender* render;
@property (nonatomic, strong, nullable)INSRender* cutRender;
@property (nonatomic, strong) INSProjectionConverter *projectConverter;
@property (nonatomic, strong) INSProjectionConverter *cutProjectConverter;
@property (nonatomic, weak)id<INSTransformRenderDelegate>delegate;

/**
 * 美摄的转场滤镜，只能添加NvsVideoEffectTransition，其他的会出错
 * If you want add effect, such as  NvsVideoEffect、NvsVideoEffectAnimatedSticker、NVEffectCompoundCaption，for transition frames, you should NOT add these effects to the property 'transformNvFilter'.
 * Instead, adding these effect to the 'nvfilter' property of self.render and self.cutRender is the recommended way.
 */
@property (nonatomic, strong, nullable)INSNvFilter *transformNvFilter;

//DEPRECATED!
@property (nonatomic, strong)UIImage *maskImage;

- (INSRender*) createRender:(INSRenderType)type converter:(INSProjectionConverter*_Nullable)converter;

- (INSRender*) createCutRender:(INSRenderType)type  converter:(INSProjectionConverter*_Nullable)converter;

- (void) setRender:(INSRender*)render converter:(INSProjectionConverter*_Nullable)converter;
- (void) setCutRender:(INSRender*)render converter:(INSProjectionConverter*_Nullable)converter;

- (void) setStartTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs;

- (void) setLottieJsonUrl:(NSURL *)jsonUrl;

@end

NS_ASSUME_NONNULL_END
