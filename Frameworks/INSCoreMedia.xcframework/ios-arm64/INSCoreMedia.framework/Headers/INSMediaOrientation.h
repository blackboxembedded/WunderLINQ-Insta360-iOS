//
//  INSMediaOrientation.h
//  INSMediaApp
//
//  Created by pengwx on 16/8/10.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaOrientation : NSObject

- (instancetype) initWithX:(double)x y:(double)y z:(double)z w:(double)w;

/**
 *  使用json格式的NSDictionary初始化对象
 *  @param dic NSDictionary
 *  @return 成功返回对象，失败返回nil
 */
- (instancetype __nullable) initWithJsonDictionary:(NSDictionary*)dic;

/**
 *  获取对象的json格式的NSDictionary
 *  @return NSDictionary
 */
- (NSDictionary*)jsonDictionary;

@property (nonatomic) double x;
@property (nonatomic) double y;
@property (nonatomic) double z;
@property (nonatomic) double w;

@end

NS_ASSUME_NONNULL_END
