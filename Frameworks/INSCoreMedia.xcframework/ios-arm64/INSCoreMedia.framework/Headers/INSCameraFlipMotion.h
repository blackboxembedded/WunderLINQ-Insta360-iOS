//
//  INSCameraFlipMotion.h
//  INSCoreMedia
//
//  Created by HFY on 2019/12/10.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraFlipMotionType) {
    INSCameraFlipMotionTypeJump = 0,
    INSCameraFlipMotionTypeRotation = 1,
};

@class INSExtraTimeMapperData;
@interface INSCameraFlipMotionParam:NSObject

/// 分析查找何种类型的动作
@property (nonatomic) INSCameraFlipMotionType fetchType;

/// 对于多段trim后的文件，需要从文件尾传入这个变量
@property (nonatomic, nullable) INSExtraTimeMapperData *timeMapperData;

@end

@interface  INSCameraFlipMotionInfo : NSObject

/// 算法识别的动作类型，应该与fetchType相同
@property (nonatomic) INSCameraFlipMotionType motionType;

/// 动作的起始时间 in ms
@property (nonatomic) double motionStart;

/// 动作的结束时间
@property (nonatomic) double motionEnd;

- (instancetype)initWithMotionType:(INSCameraFlipMotionType)motionType motionStart:(double)motionStart motionEnd:(double)motionEnd;

@end


//使用INSGyroPBPlayer生成对象
@interface INSCameraFlipMotion : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (nullable INSCameraFlipMotionInfo *)motionStatusWithFetchType:(INSCameraFlipMotionType)fetchType DEPRECATED_MSG_ATTRIBUTE("Please use -motionStatusSetWithParam: instead");

- (nullable NSArray <INSCameraFlipMotionInfo *> *)motionStatusSetWithFetchType:(INSCameraFlipMotionType)fetchType DEPRECATED_MSG_ATTRIBUTE("Please use -motionStatusSetWithParam: instead");

- (nullable NSArray <INSCameraFlipMotionInfo *> *)motionStatusSetWithParam:(INSCameraFlipMotionParam *)param;

@end

NS_ASSUME_NONNULL_END
