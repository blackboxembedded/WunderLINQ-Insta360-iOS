//
//  INSSkyMirrorRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/5.
//  Copyright © 2020 insta360. All rights reserved.
//


#import "INSSphericalPanoRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSSkyMirrorRoll : NSObject

-(instancetype)initWithStartTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs rollAngle:(double)angle;

@property(nonatomic, readonly)double startTimeMs;
@property(nonatomic, readonly)double endTimeMs;

///roll角 单位：角度
@property(nonatomic, readonly)double rollAngle;

@end


@class INSSkyMirrorCacheManager;
@interface INSSkyMirrorRender : INSSphericalPanoRender

/// 融合带的宽度，为高度方面的比例，取值范围0~1
@property(nonatomic)float blendSpace;

/// 融合线的位置，，为高度方面的比例，取值范围0~1
@property(nonatomic)float blendLine;

///图像上部分中心位置，默认值0.5
@property(nonatomic)float upImageCenter;

///图像下部分中心位置，默认值0.5
@property(nonatomic)float downImageCenter;

/// roll旋转
@property(nonatomic, strong)INSSkyMirrorRoll *skyRoll;

@property(nonatomic, strong)INSSkyMirrorCacheManager *cacheManager;

@end

NS_ASSUME_NONNULL_END
