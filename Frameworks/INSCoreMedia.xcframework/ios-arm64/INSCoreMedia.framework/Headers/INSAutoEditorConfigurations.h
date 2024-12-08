//
//  INSSceneFrameConfiguration.h
//  INSCoreMedia
//
//  Created by HFY on 2019/4/5.
//  Copyright © 2019年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "INSExtraMetadata.h"
#import "INSGyroPBPlayer.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Analyzer
@class INSPlayerImage;

@interface INSSceneFrame : NSObject

@property (nonatomic, nullable) INSPlayerImage *playerImage;

@property (nonatomic) double timestampMs;// pts * time_base

@property (nonatomic) int frameIndex;

-(instancetype)initWithPlayerImage:(INSPlayerImage  * _Nullable)playerImage timestampMs:(double)timestampMs frameIndex:(int)frameIndex;

@end

// video json所选的视角信息
typedef NS_ENUM(NSUInteger, INSAutoEditCaptureViewType) {
    // 无
    INSAutoEditCaptureViewTypeNone = 0,
    // 行进方向
    INSAutoEditCaptureViewTypeHeading,
    // 主角视角
    INSAutoEditCaptureViewTypeLeadRole,
    // 用户自定义free capture视角
    INSAutoEditCaptureViewTypeFreeCapture,
    // 大爆炸视角
    INSAutoEditCaptureViewTypeBigboom,
    // 外部镜头方向
    INSAutoEditCaptureViewTypeOuterLens,
    // 自拍镜头方向
    INSAutoEditCaptureViewTypeSelfieLens,
    // 显著性目标检测
    INSAutoEditCaptureViewTypeSaliency,
    
    INSAutoEditCaptureViewTypeDefault = INSAutoEditCaptureViewTypeNone,
};

@interface INSVideoInfoUniqueKey : NSObject

@property (nonatomic) NSString *videoKey;

@property (nonatomic) INSAutoEditCaptureViewType captureType;

@property (nonatomic) int targetId;

- (instancetype)initWithVideoKey:(NSString *)videoKey; // use default capture type

- (instancetype)initWithVideoKey:(NSString *)videoKey captureType:(INSAutoEditCaptureViewType)captureType targetId:(int)targetId;

@end

@interface INSVideoInfoConfiguration : NSObject
// key
@property (nonatomic) NSString *videoKey;
// name
@property (nonatomic) NSString *videoName;
// 文件类型
@property (nonatomic) INSSubMediaType mediaType;
// 防抖数据
@property (nonatomic, nullable) INSGyroPBPlayer *gyroPlayer;
// 文件在Ducuments下的绝对路径:var/sandbox/Ducuments/relativePath, json中只把relativePath解析出来存入，推荐模块再重新拼好全路径
@property (nonatomic) NSString *videoPath;
// 创建时间，UTC时间戳
@property (nonatomic) NSTimeInterval createTimestamp;
// 原始视频宽度
@property (nonatomic) NSInteger width;
// 原始视频高度
@property (nonatomic) NSInteger height;
// 渲染图宽度. 原视频解码出来的帧需要经过渲染，这里记录渲染后的图片尺寸
@property (nonatomic) NSInteger detectWidth;
// 渲染图高度
@property (nonatomic) NSInteger detectHeight;
// 播放信息
@property (nonatomic) double frameRate;
// 视频的原始时长，不受trim时间影响
@property (nonatomic) double durationMs;
// trim信息
@property (nonatomic) double trimStartTimeMs;

@property (nonatomic) double trimEndTimeMs;

@end


@interface INSSceneAnalyzerConfiguration : NSObject

// Desprecated.设置是否只用CPU计算，默认为false
@property(nonatomic) BOOL useCpuOnly;

// 设置是否需要计算运动状态 （走路，跑步，静止等）
@property(nonatomic) BOOL motionJudge;

// 设置是否需要计算人脸属性（性别，年龄，表情等）
@property(nonatomic) BOOL faceDetect;

// 设置分析结果模型文件(json)的存储路径
@property(nonatomic) NSString *outputJsonPath;

@property(nonatomic) INSAutoEditCaptureViewType captureType;

@property(nonatomic) int targetId;

// 目前analyze支持附加一组输出，该变量表示另一组分析结果文件的路径
@property(nonatomic, nullable) NSString *outputJsonPathAdd;

@property(nonatomic) INSAutoEditCaptureViewType captureTypeAdd;

@property(nonatomic) int targetIdAdd;

@end


#pragma mark - Recommender
typedef NS_ENUM(NSInteger, INSAutoEditRecommenderError) {
    // no error
    INSAutoEditRecommenderErrorOK = 0,
    // 未知错误
    INSAutoEditRecommenderErrorUnknown = -1,
    // 文件错误(或者对象为null)
    INSAutoEditRecommenderErrorFileOpenFail = -2,
    // 素材分析结果错误
    INSAutoEditRecommenderErrorJsonParseFail = -3,
    // 模板规则格式错误
    INSAutoEditRecommenderErrorTemplateParseFail = -4,
    // 输入素材不足
    INSAutoEditRecommenderErrorInsuffFootages = -5,
    // 没有初始化（没有输入素材）
    INSAutoEditRecommenderErrorUninitialized = -6,
    // 没有镜头信息
    INSAutoEditRecommenderErrorNoShots = -7,
    // 参数错误
    INSAutoEditRecommenderErrorInvalidParam = -8,
    // 时间长度不够
    INSAutoEditRecommenderErrorInsuffDuration = -9,
    // exceed batch
    INSAutoEditRecommenderErrorExceedBatchCount = -10,
    // 接口未实现
    INSAutoEditRecommenderErrorNotImplement = -100,
};

// Desperated! 预留配置项，推荐初始配置信息
@interface INSEditRecommenderConfiguration : NSObject

@end


// Desperated! 预留配置项
typedef NS_ENUM(NSInteger, INSAutoEditTemplateType) {
    // 未知类型,默认为INSAutoEditTemplateTypeLensScene
    INSAutoEditTemplateTypeUnknow = -1,
    // 场景模板
    INSAutoEditTemplateTypeLensScene = 1,
    // 卡点模板
    INSAutoEditTemplateTypeProjectScene = 2,
    // 聚类模板
    INSAutoEditTemplateTypeClusterScene = 3,
};


typedef NS_ENUM(NSInteger, INSAutoEditTemplateSortedType) {
    // 默认，分数排序
    INSAutoEditTemplateSortedTypeDefaultSort = 0,
    // 按拍摄时间
    INSAutoEditTemplateSortedTypeShootingTime = 1,
    // 质量最好的放到镜头时间最长的
    INSAutoEditTemplateSortedTypeLensDurationSort = 2,
    // 相对时间戳排序
    INSAutoEditTemplateSortedTypeRelativelyTimestamp = 3,
};


@interface INSAutoEditThreshConfig : NSObject

@property (nonatomic) float detectorThresh;

@property (nonatomic) float classifierThresh;

@property (nonatomic) float imagelabThresh;

@property (nonatomic) float qualityCefos;

@property (nonatomic) float scaraceCefos;

@property (nonatomic) float matchCefos;

@property (nonatomic) float minSegIntervalInSameVideo;      //in second

@property (nonatomic) int maxEpochCount;

@property (nonatomic) float povThresh;

+ (INSAutoEditThreshConfig *)defaultConfig;

- (instancetype) initWithDetectorThresh:(float)detectorThresh
                       classifierThresh:(float)classifierThresh
                         imagelabThresh:(float)imagelabThresh
                           qualityCefos:(float)qualityCefos
                           scaraceCefos:(float)scaraceCefos
                             matchCefos:(float)matchCefos
                              povThresh:(float)povThresh;

@end


@interface INSAutoEditLensLockState : NSObject

@property (nonatomic) BOOL lockState;

@property (nonatomic) float lockStartTimeMs;

@property (nonatomic) float lockDurationMs;

@property (nonatomic, nullable) INSVideoInfoUniqueKey *lockVideoKey;

- (instancetype)initWithLockState:(BOOL)lockState
                  lockStartTimeMs:(int64_t)lockStartTimeMs
                   lockDurationMs:(int64_t)lockDurationMs
                     lockVideoKey:(INSVideoInfoUniqueKey * _Nullable)lockVideoKey;
@end


@interface INSAutoEditLogic : NSObject

@property (nonatomic, readonly) int64_t startTimeMs;

@property (nonatomic, readonly) int64_t endTimeMs;

@property (nonatomic, readonly, copy, nullable) NSArray<NSString *> *lensRules;

@property (nonatomic, readonly, copy, nullable) NSArray<NSNumber *> *prefProjectRules;

@property (nonatomic, readonly, copy, nullable) INSAutoEditLensLockState *lensLockState;

@property (nonatomic, readonly, copy, nullable) NSString *necessaryCondition;

- (instancetype)initWithStarTimeMs:(int64_t)startTimeMs
                         endTimeMs:(int64_t)endTimeMs
                         lensRules:(NSArray<NSString *> * _Nullable)lensRules
                  prefProjectRules:(NSArray<NSNumber *> * _Nullable)prefProjectRules
                     lensLockState:(INSAutoEditLensLockState * _Nullable)lensLockState
                necessaryCondition:(NSString * _Nullable)necessaryCondition;

/**
 * DEPRECATED! Do Not Support For Current Version
 */
- (instancetype)initWithStarTimeMs:(int64_t)startTimeMs
                         endTimeMs:(int64_t)endTimeMs
                templateJsonString:(NSString * _Nullable)templateJsonString;

@end


@interface INSAutoEditComposeRule :NSObject

@property (nonatomic) NSString *srcRules;

@property (nonatomic) NSString *dstComposeRule;

@property (nonatomic) float duration;

- (instancetype)initWithSrcRules:(NSString *)srcRules dstComposeRule:(NSString *)dstComposeRule duration:(float)duration;

@end


@interface INSAutoEditTemplate : NSObject

@property (nonatomic, readonly, copy) NSArray <INSAutoEditLogic *> *editLogics;

@property (nonatomic, readonly, copy, nullable) NSArray <NSString *> *projectRules;

@property (nonatomic, nullable) INSAutoEditThreshConfig *threshConfig;

@property (nonatomic, nullable) NSArray<INSAutoEditComposeRule *> *composeRules;

@property (nonatomic) INSAutoEditTemplateType templateType;//默认为lenScene

@property (nonatomic) INSAutoEditTemplateSortedType sortedType;//默认为score

@property (nonatomic) BOOL isVideoResue;        //default value:  NO

- (instancetype)initWithEditLogics:(NSArray<INSAutoEditLogic *> *)editLogics projectRules:(NSArray<NSString*>  * _Nullable)projectRules;

@end


@interface INSAutoEditSegment : NSObject

// (videoKey)
@property (nonatomic) INSVideoInfoUniqueKey *videoUniqueKey;

// 匹配的规则(rule)
@property (nonatomic) NSString *templateLogic;

// 所属镜头号(shotIndex)
@property (nonatomic) int clipIndex;

// 指明从视频中的哪帧时间戳开始播放(startTime)
@property (nonatomic) float startTimeMs;

// 视频时长(duration)
@property (nonatomic) float durationMs;

// 该片段的平均得分(avgcore)
@property (nonatomic) float averageScore;

// 剪切视频起始，关键帧的索引
//@property (nonatomic) int startIndice;

//@property (nonatomic) int endIndice;
// 匹配的剪辑规则
//@property (nonatomic) int matchRuleID;

// 是否是有效的分割
//@property (nonatomic) BOOL isValid;

// 视频块结束的时间戳 = 视频创建时间 + startTimeMs + durationMs
//@property (nonatomic) NSTimeInterval segmentTimestamp;
@end

NS_ASSUME_NONNULL_END
