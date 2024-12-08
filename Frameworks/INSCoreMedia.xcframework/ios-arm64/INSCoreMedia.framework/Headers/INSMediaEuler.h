//
//  INSMediaEuler.h
//  INSMediaApp
//
//  Created by pengwx on 16/11/16.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMediaEuler : NSObject

- (instancetype) initWithPitch:(double)pitch yaw:(double)yaw roll:(double)roll;

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

@property (nonatomic) double pitch;
@property (nonatomic) double yaw;
@property (nonatomic) double roll;

NS_ASSUME_NONNULL_END

@end
