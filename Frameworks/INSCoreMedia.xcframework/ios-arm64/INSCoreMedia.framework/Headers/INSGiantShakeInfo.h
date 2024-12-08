//
//  INSGiantShakeInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/7/31.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface INSGiantShakeInfo : NSObject

-(instancetype)initWithStartTimeMs:(double)startTimeMs durationMs:(double)durationMs;

@property(nonatomic)double startTimeMs;
@property(nonatomic)double durationMs;

/// 图像震动范围，高度方向的比例，，默认值0.07
@property(nonatomic)double shakeValueOfHeightScale;

@end


