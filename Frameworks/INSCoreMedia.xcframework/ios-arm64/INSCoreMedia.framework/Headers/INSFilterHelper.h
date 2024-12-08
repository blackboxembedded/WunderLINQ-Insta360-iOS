//
//  INSFilterHelper.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/18.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSFilterType.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFilterHelper : NSObject

/**
 *  获取滤镜的字符表示方式, 当type为INSFilterTypeNull或者无效时返回nil
 *  @param type 滤镜类型
 *  @return 滤镜字符表示
 */
+ (NSString*_Nullable) stringWithType:(INSFilterType)type;

/**
 *  获取滤镜的枚举表示方式,   当string为nil或无效时返回INSFilterTypeNull
 *  @param string 滤镜类型字符表示
 *  @return 滤镜枚举表示
 */
+ (INSFilterType) typeWithString:(NSString*)string;

/**
 *  获取滤镜所占比重，lut表方式生效， string应为xxx_0.9，则返回0.9
 */
+ (CGFloat)filterScaleWithString:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
