//
//  INSAppletWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "INSRenderType.h"

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;
@class INSScreenRecorder;
@interface INSAppletWrapData : NSObject

@end

@interface INSAppletVideoInfo : NSObject

@property (nonatomic) NSArray <NSURL *> *urls;

@property (nonatomic) int64_t mediaFileSize;

@property (nonatomic) double frameRate;

@property (nullable, nonatomic) NSString *offset;

@property (nullable, nonatomic) INSGyroPBPlayer *gyroPlayer;

// 某些流程配置主码流的url，会优先使用主码流的url，否则使用'urls'属性指定的素材文件
@property (nullable, nonatomic) NSArray <NSURL *> *primaryUrls;

@end

@interface INSAppletTrackerEnv : NSObject

/// 追踪时，使用的rendertype，只有可能是INSRenderTypeSphericalRender或者INSRenderTypeSphericalPanoRender
@property (nonatomic) INSRenderType renderType;

/// 用来追踪render的 高:宽 比，
@property (nonatomic) CGFloat renderHeightWidthRatio;

/// 重要信息，追踪设置离屏渲染的尺寸
@property (nonatomic) int trackerWidth;

/// 智能追踪的数据，已经执行完screen tracker之后的结果
@property (nullable, nonatomic) INSScreenRecorder *resultRecorder;

@end

NS_ASSUME_NONNULL_END
