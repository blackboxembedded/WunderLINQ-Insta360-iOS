//
//  INSEyePoint.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/7/17.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEyePoint : NSObject

- (instancetype) initWithXFov:(float)xFov distance:(float)distance ratio:(float)ratio;

@property (nonatomic) float xFov;
@property (nonatomic) float distance;
@property (nonatomic) float ratio;              //[0-1]

@end



@interface INSEyePointManager : NSObject

- (instancetype) initWithEyePoints:(NSArray<INSEyePoint*>*)eyePoints;

@property (nonatomic)BOOL enableSmoothPoint;
@property (nonatomic, readonly) float xFovMin;
@property (nonatomic, readonly) float xFovMax;
@property (nonatomic, readonly) float distanceMin;
@property (nonatomic, readonly) float distanceMax;
@property (nonatomic, readonly) NSArray<INSEyePoint*> *eyePoints;


/**
 根据yFov值获取视点
 @param yFov yFov值
 @return 返回对应yFov的点，不存在时返回nil
 */
- (INSEyePoint*) getEyePointWithXFov:(float)xFov;


/**
 根据比率获取视点
 @param ratio 比率，范围【0， 1】
 @return 返回对应视点，不存在时返回nil
 */
- (INSEyePoint*) getEyePointWithRatio:(float)ratio;

- (void)setSmoothPointXFov:(float)xFov distance:(float)distance;

- (float) getDistanceNoCheck:(float)xFov;

@end

NS_ASSUME_NONNULL_END
