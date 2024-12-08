//
//  INSVideoTagger.h
//  INSCoreMedia
//
//  Created by Mac on 2021/8/9.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class INSGyroPBPlayer;

typedef NS_ENUM(NSInteger, INSVideoTaggerType) {
    INSVideoTaggerDoubleFishEye, // 双鱼眼视频
    INSVideoTaggerWideAngle, // 广角视频
    INSVideoTaggerNormal, // 普通视频
    INSVideoTaggerEquirection, // 展开后的2:1全景
};

@interface INSVideoTaggerConfiguration : NSObject
@property (nonatomic) INSVideoTaggerType videoType;
@property (nonatomic) int width; // 希望传给算法的图片宽度和高度，双鱼眼视频2:1，广角和普通视频1:1、16:9、9:16等均可
@property (nonatomic) int height;
@property (nonatomic, copy) NSString *offset;
@property (nonatomic, strong) INSGyroPBPlayer *gyroPlayer;
@property (nonatomic) double xFov;
@property (nonatomic) double distance;
@property (nonatomic, copy) NSString *cacheDir; // 输出json和debug图片的目录，以'/'结尾
@property (nonatomic) bool debug_mode;
@end

@interface INSVideoTaggerPair : NSObject
@property (nullable, nonatomic, copy) NSString *name;
@property (nonatomic) float confidence;
@end

@interface INSVideoTaggerSection : NSObject
@property (nullable, nonatomic, copy) NSString *name;
@property (nullable, nonatomic, strong) NSArray <INSVideoTaggerPair *> *pairs;
@end

@interface INSVideoTaggerResult : NSObject
@property (nonatomic) bool is_underwater;
@property (nonatomic) bool is_motorcycle;
@property (nullable, nonatomic, strong) NSArray <INSVideoTaggerSection *> *sections;
@end

@interface INSVideoTagger : NSObject

- (instancetype) init NS_UNAVAILABLE;
- (instancetype) initWithConfiguration:(INSVideoTaggerConfiguration*)config;
- (bool) processImage:(INSPlayerImage*)image; // 传入一幅图像
- (nullable INSVideoTaggerResult *) getResult; // 图像传完之后即可获取分析结果，同时在config.cacheDir生成result.json（fcp设计如此）
@end



NS_ASSUME_NONNULL_END
