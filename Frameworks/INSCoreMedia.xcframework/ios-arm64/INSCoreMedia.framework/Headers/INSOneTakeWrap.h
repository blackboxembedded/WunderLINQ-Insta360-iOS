//
//  INSOneTakeWrap.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/24.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSGyroPBPlayer;
@class INSOneTakeWrapConfiguration;
@class INSOneTakeVideoInfo;
@class INSOneTakeResult;
@class INSOneTakeAnimation;

typedef NS_ENUM(NSInteger, INSOneTakeWrapErrorCode){
    
    // 必须停止，算法返回错误
    INSOneTakeWrapErrorCodeRunFailed = -10,
};

typedef NS_ENUM(NSInteger, INSOneTakeWrapWarningCode){
    
    // 可以继续执行
    INSOneTakeWrapWarningCodeMoveFailed = -1,
    
    // 可以继续执行，静止时间过长
    INSOneTakeWrapWarningCodeMoveExceed = -2,
    
    // 可以继续执行, 受光线影响无法生成
    INSOneTakeWrapWarningCodeFeatureForMove = -3,
    
    // 可以继续执行，当前特征点不匹配
    INSOneTakeWrapWarningCodeFeatureForRun = -4,

};

@interface INSOneTakeWrap : NSObject

@property (nonatomic, readonly)INSOneTakeWrapConfiguration *config;

@property (nonatomic, readonly)INSOneTakeVideoInfo *oneTakeVideoInfo;


/// 构造方法
/// @param config config
/// @param oneTakeVideoInfo  see INSOneTakeVideoInfo
- (instancetype)initWithOneTakeConfig:(INSOneTakeWrapConfiguration *)config oneTakeVideoInfo:(INSOneTakeVideoInfo *)oneTakeVideoInfo;


/// 异步方法，会马上返回，结果需要在回调中获取，但是由于算法耗时较长，可能需要调用者阻塞线程
/// @param progress 进度回调 [0.0, 1.0]
/// @param warning 进度回调 [warningCode, warningValue] warningValue 目前是NSNumber对象，表示warning出现的onetake区段, 即oneTakeVideoInfo中，INSOneTakeClipInfo数组的索引
/// @param completion 完成时的回调，如果失败，则返回error，否则返回INSOneTakeResult
- (void)runOneTakeWithProgress:(void (^)(double value))progress warning:(void (^)(INSOneTakeWrapWarningCode warningCode, id warninValue))warning completion:(void (^)(NSError * _Nullable error, NSArray <INSOneTakeResult *> * _Nullable results))completion;

/// 销毁资源，如果在run结束前如果需要退出页面，则必须调用
- (void)destory;

/// 生成一个animation对象，可以用来配置INSOneTakeRecorder
/// @param gyroPlayer gyroPlayer，内部会修改其gyroPlayMode， 如果这个对象还有其他用途，需要切回到正确的gyroPlayMode
/// @param xFov 播放的xFov
/// @param distance 播放的distance
/// @param srcDuration 原始视频的时长，单位为ms
/// @param timestep 插点间隔，建议值为300ms
/// @param oneTakeResults onetake算法返回的result, 必须配置其beforeAnimationDurationMs afterAnimationDurationMs cutSceneTime

@end

NS_ASSUME_NONNULL_END
