//
//  INSTransitionParser.h
//  INSCoreMedia
//
//  Created by 那强 on 2020/2/16.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSTransitionRecorder;
@class INSProjectionParam;
@class INSTimeScale;

@interface INSTransitionParser : NSObject


/// 初始化方法，整个转场分为 动画转场 + 效果转场，动画转场由INSTransitionRecorder模式实现；效果转场由Lottie模式实现；通过该类，解析全景转场模板，可以获取Lottie与INSTransitionRecorder的信息，在Project中配置相关参数
/// @param jsonPath 全景转场json path
- (instancetype)initWithJsonPath:(NSString *)jsonPath;


/// 必须调用，可以获取转场配置所需要的信息， 返回 NO 表示解析失败，请检查Json格式以及内容是否合法
- (BOOL)open;

/// 当前jsonPath
@property (nonatomic, readonly) NSString *jsonPath;

/// 效果转场时长，占总时长的比例，调用者根据转场总时长，计算效果转场的时间
@property (nonatomic, readonly) CGFloat endCutDurationRatio;

/// 效果转场json ID， 用来找到lottie json，目前就只用fade_in_fade_out
@property (nonatomic, readonly) NSString* endCutJsonID;

/// 生成前一段视频的动画转场，类似模板动画的原理，转入的参数也与模板动画意义相同
/// @param transDurationMs 整段转场的时长，指的是前后两段转场的总长度
/// @param clipStartTimestampMs 前一段clip的开始时间，为clip.startTimestamp
/// @param clipEndTimestampMs 前一段clip的结束时间，为clip.endTimestamp
/// @param beginParam 动画开始时刻的旋转状态，可由renderView.render获得
- (nullable INSTransitionRecorder *) layer1TransitionRecorderTransDurationMs:(int64_t)transDurationMs
                                                        clipStartTimestampMs:(int64_t)clipStartTimestampMs
                                                          clipEndTimestampMs:(int64_t)clipEndTimestampMs
                                                                  timescales:(NSArray<INSTimeScale *> * _Nullable)timescales
                                                                  beginParam:(INSProjectionParam *)beginParam;

/// 生成后面一段视频的动画转场，类似模板动画的原理，转入的参数也与模板动画意义相同
/// @param transDurationMs 整段转场的时长
/// @param clipStartTimestampMs 后一段clip的开始时间，为clip.startTimestamp
/// @param clipEndTimestampMs 后一段clip的结束时间，为clip.endTimestamp
/// @param beginParam 动画开始时刻的旋转状态，可由renderView.render获得
- (nullable INSTransitionRecorder *) layer2TransitionRecorderTransDurationMs:(int64_t)transDurationMs
                                                        clipStartTimestampMs:(int64_t)clipStartTimestampMs
                                                          clipEndTimestampMs:(int64_t)clipEndTimestampMs
                                                                  timescales:(NSArray<INSTimeScale *> * _Nullable)timescales
                                                                  beginParam:(INSProjectionParam *)beginParam;

@end

NS_ASSUME_NONNULL_END
