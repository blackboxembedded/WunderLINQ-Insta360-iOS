//
//  INSInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/9.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSPovInfo : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initSrcAspect:(double)srcAspect desAspect:(double)desAspect;

/// 原始图像的宽高比率，值为宽/高
@property(nonatomic, readonly)double srcAspect;

/// 目标图像（即要显示的图像）的宽高比率，值为宽/高
@property(nonatomic, readonly)double desAspect;

@end


@interface INSSmoothInfo : NSObject

-(instancetype)initWithOffset:(NSString*)offset angle:(double)angle;

// 设置gyro四元数平滑使用的强度，angle越大平滑力度越大，反之则跟随力度越大
@property(nonatomic, readonly)double angle;

// 设置gyro四元数平滑使用的offset
@property(nonatomic, copy, readonly)NSString* offset;

@end

NS_ASSUME_NONNULL_END
