//
//  INSMultiviewConfiguration.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/9/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSRenderType.h"
#import "INSJsonSerializeMultiview.h"

NS_ASSUME_NONNULL_BEGIN

@class INSDisplayValue;
@interface INSMultiviewConfiguration : NSObject<NSCoding, NSCopying, NSMutableCopying>


/**
 使用multiview模板初始化configuration
 
 @param aspectRatio 渲染视图的比例，如9x16，1x1等
 @param jsonData multiview的模板json数据
 @param reverse 是否将multiview的方向反转，目前视频为NO，图片为YES
 @return 设置好的configuration
 */
- (instancetype)initWithDefaultDisplayValue:(INSDisplayValue* _Nullable)displayValue multiviewTemplate:(NSData*)jsonData reverseOrientation:(BOOL)reverse;


/**
 使用multiview模板和multiview序列化对象共同初始化configuration

 @param jsonMultiview multiview序列化的json对象
 @param jsonData jsonData multiview的模板json数据
 @return 设置好的configuration
 */
- (instancetype)initWithJsonSerialize:(INSJsonSerializeMultiview*)jsonMultiview multiviewTemplate:(NSData*)jsonData;


/**
 multiview序列化的json对象
 */
@property(nonatomic, strong, readonly)INSJsonSerializeMultiview *jsonMultiview;

@end

NS_ASSUME_NONNULL_END
