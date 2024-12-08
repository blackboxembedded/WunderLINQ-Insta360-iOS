//
//  INSBulletTimeDetector.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/17.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSBulletTimeFeature) {
    // 正常
    INSBulletTimeFeatureNormal = 0,
    // 转的太快
    INSBulletTimeFeatureOverSpeed = -1,
    // 圈数太少
    INSBulletTimeFeatureLessCircle = -2,
};

@class INSExtraTimeMapperData;
@interface INSBulletTimePeriodParam : NSObject

/// 最小有效时间，默认为6.0
@property (nonatomic) double minValidTimePeroid;

/// 合并时间阈值，默认为0.05
@property (nonatomic) double timeMergeThreshold;

/// 设置最大有效转速，默认为1.0
@property (nonatomic) double maxCirclePerSecond;

/// 超过最大转速的所占的比例，默认为0.4，即如果转速有40%的时间大于maxCirclePerSecond，会被判定为旋转超速
@property (nonatomic) double minPercentInvalid;

/// 对于多段trim后的文件，需要从文件尾传入这个变量
@property (nonatomic, nullable) INSExtraTimeMapperData *timeMapperData;

@end

@interface INSBulletTimePeriodInfo : NSObject

@property (nonatomic) int64_t bulletStart; // in ms

@property (nonatomic) int64_t bulletEnd; // in ms

@property (nonatomic) INSBulletTimeFeature feature;

@end

@interface INSBulletTimePeriod : NSObject


/// 该类的实例由INSGyroPBPlayer生成
- (instancetype)init NS_UNAVAILABLE;


/// 获取bullet time 的时间区段，如果返回nil，则表示不做trim
- (nullable INSBulletTimePeriodInfo *)getTypicalBulletTimePeriodInfo:(INSBulletTimePeriodParam *)param;


@end

NS_ASSUME_NONNULL_END
