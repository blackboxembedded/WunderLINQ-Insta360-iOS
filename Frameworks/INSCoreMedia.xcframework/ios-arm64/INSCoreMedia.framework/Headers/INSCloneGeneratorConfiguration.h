//
//  INSCloneGeneratorConfiguration.h
//  INSCoreMedia
//
//  Created by HFY on 2020/4/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "INSRenderType.h"
NS_ASSUME_NONNULL_BEGIN

@class INSScreenRecorder;
@class INSGyroPBPlayer;
@class INSRender;
@class INSBgmClip;

typedef NS_ENUM(NSInteger, INSCloneTrailSliceStrategy) {
    // 等间隔
    INSCloneTrailSliceStrategyInterval = 0,
    // 目标框距离
    INSCloneTrailSliceStrategyGap = 1,
};

typedef NS_ENUM(NSInteger, INSCloneTrailExportMode) {
    // 留下影子
    INSCloneTrailExportModeLeft = 0,
    // 吃掉影子
    INSCloneTrailExportModeEat = 1,
};

@interface INSCloneGeneratorConfiguration : NSObject

// 分身帧以及导出width
@property (nonatomic) int width;

// 分身帧以及导出height
@property (nonatomic) int height;


// media size为文件总长度去掉文件尾的长度
@property (nonatomic) int64_t mediaFileSize;

// 存储分割mask，每个视频要创建的cache目录必须不同，由调用者管理何时删除cache目录，这里需要设置cache目录,需要是一个文件夹，如果不存在，将自动创建
@property (nonatomic) NSString *cacheDirPath;

// 导出比特率
@property (nonatomic) NSInteger exportBitrate;

// 导出帧率
@property (nonatomic) NSInteger exportFps;

// 导出bgm
@property (nullable, nonatomic) INSBgmClip *exportBgm;

// debug 标志, 默认关闭，统计文件存储在cacheDirPath下
@property (nonatomic) BOOL debugEnable;


- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithWidth:(int)width
                       height:(int)height
                mediaFileSize:(int64_t)mediaFileSize
                 cacheDirPath:(NSString *)cacheDirPath
                exportBitrate:(NSInteger)exportBitrate
                    exportFps:(NSInteger)exportFps
                    exportBgm:(INSBgmClip * _Nullable)exportBgm;

@end


@interface INSCloneTrailConfiguration : INSCloneGeneratorConfiguration

/// 需要使用父类提供的方法初始化属性
- (instancetype)init NS_UNAVAILABLE;

@end


@interface INSCloneShadowConfiguration : INSCloneGeneratorConfiguration

/// 需要使用父类提供的方法初始化属性
- (instancetype)init NS_UNAVAILABLE;

/// 默认40
@property (nonatomic) int blendWidth;

/// 画面停留的时长,计算方式为fps x 7s 由产品确定，这里默认取210帧
@property (nonatomic) int stayTimeFrames;

/// 默认0.03
@property (nonatomic) float thresh;

/// 是否开启偶数周期内的帧逆序, 默认为NO
@property (nonatomic) BOOL evenCycleInverseFrame;

@end


@class INSGyroPBPlayer;
@class INSRender;
@interface INSTrackerEnvironment : NSObject

/// offset
@property (nonatomic, readonly) NSString *offset;

/// 追踪使用的render的type
@property (nonatomic, readonly) INSRenderType renderType;

/// 防抖器
@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

/// 用来追踪render的 高:宽 比，
@property (nonatomic, readonly) CGFloat renderDemesionRatio;

/// 重要信息，追踪设置离屏渲染的尺寸
@property (nonatomic, readonly) int trackerWidth;

/// 智能追踪的数据，与stopmotion的模式目前不同，执行这里之前应该已经执行完tracker流程了
@property (nonatomic, readonly) INSScreenRecorder *trackerRecorder;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype) initWithOffset:(NSString *)offset
                     renderType:(INSRenderType)renderType
                     gyroPlayer:(nonnull INSGyroPBPlayer *)gyroPlayer
            renderDemesionRatio:(float)renderDemesionRatio
                   trackerWidth:(int)trackerWidth
                trackerRecorder:(INSScreenRecorder *)trackerRecorder;

/// 初始化方法
/// @param render 传入当前render，会生成属性列表中的数据
/// @param trackerWidth 追踪设置离屏渲染的尺寸
/// @param trackerRecorder 智能追踪的数据
- (instancetype) initWithRender:(INSRender *)render
                   trackerWidth:(int)trackerWidth
                trackerRecorder:(INSScreenRecorder *)trackerRecorder;

@end


NS_ASSUME_NONNULL_END
