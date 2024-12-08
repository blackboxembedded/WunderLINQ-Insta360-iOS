//
//  INSDoubleAsteroidRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/5/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"
#import "INSDisplay.h"

NS_ASSUME_NONNULL_BEGIN
@class INSProjectionParam;
typedef NS_ENUM(NSInteger, INSDoubleAsteroidType) {
    INSDoubleAsteroidTypeOutside = 0,
    INSDoubleAsteroidTypeInside = 1,
};

@class INSCamera;
@class INS3DObject;
@class INSDisplayValue;
@interface INSDoubleAsteroidRecorder : INSScreenRecorder

- (instancetype)init NS_UNAVAILABLE;

- (instancetype) initWithDataSourceRecorder:(INSScreenRecorder *)dataSourceRecorder
                               asteroidType:(INSDoubleAsteroidType)asteroidType
                               displayAspect:(INSDisplayAspect)displayAspect
                                radiusRatio:(float)radiusRatio
                                 blendSpace:(float)blendSpace
                                   playXFov:(float)playXFov
                               playDistance:(float)playDistance;



/// 当成功的时候返回合适的displayValue，失败返回nil
/// @param dataSourceRecorder 追踪数据
/// @param asteroidType 小行星类型
/// @param trackAspect 追踪时画面的宽/高
/// @param asteroidAspect 小行星显示画面的宽/高
/// @param radiusRatio 半径大小与显示画面短边的比例
/// @param blendSpace 内圈小行星与外圈小行星融合的空间大小
/// @param trimStartTimeMs 生效的数据起始时间，单位ms
/// @param trimEndTimeMs 生效的数据j结束时间，单位ms
+(INSDisplayValue* _Nullable)displayValueWithDataSourceRecorder:(INSScreenRecorder *)dataSourceRecorder
                                                   asteroidType:(INSDoubleAsteroidType)asteroidType
                                                    trackAspect:(float)trackAspect
                                                 asteroidAspect:(float)asteroidAspect
                                                    radiusRatio:(float)radiusRatio
                                                     blendSpace:(float)blendSpace
                                                trimStartTimeMs:(double)trimStartTimeMs
                                                  trimEndTimeMs:(double)trimEndTimeMs;


/// 切换比例的时候，获取对应INSDisplayAspect的radiusRatio值, 为nil时使用init方法传入的radiusRatio值
/// key使用[NSNumber numberOfInt:   (int)INSDisplayAspect  ]
/// value使用[NSNumber numberOfFloat:   radiusRatio  ]
@property(nonatomic, strong)NSDictionary *aspectMapRadiusRadio;

/// 生效的数据起始时间，单位ms
@property(nonatomic)double trimStartTimeMs;

/// 生效的数据j结束时间，单位ms
@property(nonatomic)double trimEndTimeMs;


+ (BOOL) transformScreenPoint:(CGPoint)point toQuaternion:(GLKQuaternion *)quaternion camera:(INSCamera*)camera1 object:(INS3DObject*)object;
+ (BOOL) transfromQuaternion:(GLKQuaternion)quaternion toScreenPoint:(CGPoint *)point camera:(INSCamera*)camera1 object:(INS3DObject*)object;

@end

NS_ASSUME_NONNULL_END
