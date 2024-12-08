//
//  INSFaceTrackerConfig.h
//  INSCoreMedia
//
//  Created by HFY on 2019/6/15.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSFaceBeautyParam : NSObject

+ (instancetype)defaultConfig;

/**
 如果所有美颜参数都为0，则说明关闭了美颜功能，在filter中可以不去处理
 */
@property (nonatomic, readonly, getter=isCloseALL) BOOL closeALL;

/**
 * beauty: face whitening effect degree
 * FloatRange(from = 0, to = 1.0), if you don't need to pass null
 * 美白 初始值0，建议值0.6
 */
@property(nonatomic, strong) NSNumber *beautyFaceWhiteningDegree;
/**
 * beauty: face blur effect degree
 * FloatRange(from = 0, to = 1.0), if you don't need to pass null
 * 磨皮 初始值0，建议值0.50
 */
@property(nonatomic, strong) NSNumber *beautySkinRetouchDegree;


/// 瘦脸 初始值0，建议值0.4
@property (nonatomic, strong) NSNumber *faceliftFaceTransDegree;

/// 大眼 初始值0，建议值0.25
@property(nonatomic, strong) NSNumber *faceliftEyeTransDegree;

/// 瘦鼻 初始值0，建议值0.25
@property (nonatomic, strong) NSNumber *faceliftShrinkNoseDegree;

/// 长鼻 初始值0，建议值0
//@property (nonatomic, strong) NSNumber *faceliftNoseLongerDegree;

@end

NS_ASSUME_NONNULL_END
