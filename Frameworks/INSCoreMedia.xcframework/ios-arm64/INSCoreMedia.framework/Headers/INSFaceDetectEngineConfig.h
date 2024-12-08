//
//  INSFaceDetectEngineConfig.h
//  INSCoreMedia
//
//  Created by Mac on 2021/6/11.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, INSFaceDetectEngineType) {
    INSFaceDetectEngineTypeResearcher = 0,
    INSFaceDetectEngineTypeFacepp,
};

typedef NS_OPTIONS(NSUInteger, INSFaceDetectEngineAbility) {
    INSFaceDetectEngineAbilityFaceDetectOnly    = 1u << 0,
    INSFaceDetectEngineAbilityAge           = 1u << 1,
    INSFaceDetectEngineAbilityGender        = 1u << 2,
    INSFaceDetectEngineAbilityExpression    = 1u << 3,
    INSFaceDetectEngineAbilityLandmarks     = 1u << 4,
    INSFaceDetectEngineAbilityHeadpose      = 1u << 5,
    
    INSFaceDetectEngineAbilityAll = INSFaceDetectEngineAbilityFaceDetectOnly |
                                    INSFaceDetectEngineAbilityAge |
                                    INSFaceDetectEngineAbilityGender |
                                    INSFaceDetectEngineAbilityExpression |
                                    INSFaceDetectEngineAbilityLandmarks |
                                    INSFaceDetectEngineAbilityHeadpose,
    
    INSFaceDetectEngineAbilityDefault = INSFaceDetectEngineAbilityFaceDetectOnly,
};

@interface INSFaceDetectEngineConfig: NSObject

@property (nonatomic) INSFaceDetectEngineType engineType;

/// 支持的能力，能力开的越少，速度越快， 默认只有人脸识别的能力，即给出人脸位置与置信度，其他属性均不可靠
@property (nonatomic) INSFaceDetectEngineAbility engineAbility;

/// 最小人脸尺寸，小于这个尺寸的人脸将不会被检测到，默认为15像素
@property (nonatomic) int faceMinSize;

/// 每幅图最多识别的人脸个数， 即最多识别到countLimit个人脸，默认为30
@property (nonatomic) int countLimit;

/// 分数阈值，小于这个分数的检测结果将被移除，默认为0.4
@property (nonatomic) float scoreThresh;

@property (nonatomic) BOOL debug;

@property (nonatomic, nullable) NSString *debugDir;

@end

NS_ASSUME_NONNULL_END
