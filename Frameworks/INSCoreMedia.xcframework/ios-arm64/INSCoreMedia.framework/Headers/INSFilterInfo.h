//
//  INSFilterInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/11.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSFilterType.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Protocols
@protocol INSFilterParamInterface <NSObject>

@property (nonatomic, readonly) INSFilterType type;

@end

@protocol INSFilterTypeParamProtocol <INSFilterParamInterface>

@required
- (instancetype)initWithType:(INSFilterType)type;

@end

// 该协议由滤镜开发者实现，会在内部type写死
@protocol INSFilterConfigParamProtocol <INSFilterParamInterface>

@required
- (INSFilterType)type;

@end


#pragma mark - Classes
/// 这个类由上层调用者使用，用于仍然使用type来构造的render可以用这个类来作为param
@interface INSFilterTypeParam : NSObject<INSFilterTypeParamProtocol>

- (instancetype)init NS_UNAVAILABLE;

@end


/// Lut表类型的Param
@interface INSLutStyleFilterConfig : NSObject<INSFilterConfigParamProtocol>

@property (nonatomic) CGFloat lutScale;

@property (nonatomic) NSData *lutData;

@end

/// 移轴滤镜的param，确定值，不要改写！
@interface INSTiltShiftBlurFilterConfig : NSObject<INSFilterConfigParamProtocol>

@property (nonatomic) double center;

@property (nonatomic) double clearSpan;

@property (nonatomic) double blurSpan;

@property (nonatomic) int width;

@property (nonatomic) int height;

@property (nonatomic) int iteration;

@end

/// multi 移轴滤镜的param
@interface INSTiltShiftBlurMultiFilterConfig : NSObject<INSFilterConfigParamProtocol>

@property (nonatomic) INSTiltShiftBlurFilterConfig *config;

@end


@interface INSFilterInfo : NSObject

@property(nonatomic, readonly) id<INSFilterParamInterface> param;

-(instancetype)initWithParam:(id<INSFilterParamInterface>)param;

@end

NS_ASSUME_NONNULL_END
