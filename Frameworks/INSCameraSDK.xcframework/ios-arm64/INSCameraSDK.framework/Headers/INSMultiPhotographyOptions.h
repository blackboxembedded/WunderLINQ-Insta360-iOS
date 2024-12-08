//
//  INSMultiPhotographyOptions.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2020/7/15.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "INSCameraMediaBasic.h"
#import "INSCameraPhotographyBasic.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint16_t, INSMultiPhotographyOptionsType) {
    INSMultiPhotographyOptionsTypeUnknown = 0,
    
    /// 分镜拍摄分辨率, readwrite. @available ONE X2
    INSMultiPhotographyOptionsTypeResolution = 1,
    
    /// 机内防抖, readwrite. @available ONE X2
    INSMultiPhotographyOptionsTypeInternalFlowstate = 2,
    
    /// 画幅类型(横/竖), readwrite. @available ONE X2
    INSMultiPhotographyOptionsTypeDimensionType = 3,
    
    /// 视野类型, readwrite. @available ONE X2
    INSMultiPhotographyOptionsTypeFovType = 4,
};

typedef NS_ENUM(NSUInteger, INSDimensionType) {
    INSDimensionTypeHorizontal,
    INSDimensionTypeVertical,
};

@interface INSMultiPhotographyOptions : NSObject

@property (nonatomic) INSVideoResolution recordResolution;

@property (nonatomic) BOOL internalFlowstate;

@property (nonatomic) INSDimensionType dimensionType;

@property (nonatomic) INSCameraFovType fovType;

@end

NS_ASSUME_NONNULL_END
