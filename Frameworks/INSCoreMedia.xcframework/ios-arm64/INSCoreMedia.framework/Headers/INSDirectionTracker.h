//
//  INSDirectionTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/9/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDirectionTrackerConfigration : NSObject

@property (nonatomic) NSString *outputJsonPath;

@property (nonatomic) int frameWidth;

@property (nonatomic) int frameHeight;

@property (nonatomic) double duration;

//默认为NO，设置为YES算法更精确
@property (nonatomic) BOOL setMask;

//是否要求算法内部作walk步态检测
@property (nonatomic) BOOL doWalkingDetect;

@property (nonatomic) BOOL visualDebug;

@end

@class INSGyroPBPlayer;
@interface INSDirectionTracker : NSObject

@property (nonatomic, readonly) INSDirectionTrackerConfigration *config;

@property (nonatomic, readonly) INSGyroPBPlayer *gyroPlayer;

@property (nonatomic, readonly) NSString *offset;

/**
 生成对象，offset和gyroPlayer为必须，内部会做检查，如果参数不合法，会返回nil
 
 @param offset 镜头offset信息
 @param gyroPlayer 当前素材使用的防抖器
 @return self
 */
- (nullable instancetype)initWithConfig:(INSDirectionTrackerConfigration *)config offset:(NSString *)offset gyroPlayer:(INSGyroPBPlayer *)gyroPlayer;


/// 可选！为了更高的精度，在进行真正的行进方向分析之前，算法需要确认用哪个鱼眼作为分析的数据，整个视频文件只需平均送入20帧副码流即可。如果调用了feedBackgroundTestFrame，必须在指定帧全部输入结束后，调用一次finishBackgroundTest后，再进行普通的行进方向分析
/// @param pixelBuffer 可能为单鱼眼（go、5.7k左眼）可能为双鱼眼（全景4k）
/// @param rightPixelBuffer 5.7k右眼，其他为空
- (void)feedBackgroundTestFrame:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer;


/// 可选！当feedBackgroundTestFrame做完后，调用该方法，表示结束BackgroundTest
- (void)finishBackgroundTest;

/**
 分析一帧结果，这里传入的pixelBuffer是双鱼眼，则为YUV格式， 如果是渲染后的格式，则为BGRA格式, 目前算法仅支持双鱼眼

 @param pixelBuffer 可能为单鱼眼（go、5.7k左眼）可能为双鱼眼（全景4k）
 @param rightPixelBuffer 5.7k右眼，可能为空
 @param timestampMs 视频解码时间戳
 @return 是否成功
 */
- (BOOL)analyzePixelBuffer:(CVPixelBufferRef)pixelBuffer rightPixelBuffer:(CVPixelBufferRef _Nullable)rightPixelBuffer ptsMs:(double)timestampMs;



/**
 获取任意时间下direction的旋转量，如果还没有analyze到当前时间戳，则返回GLKQuaternionIdentity

 @param timestamp timestamp in ms
 @return 行进方向旋转量
 */
- (GLKQuaternion)fetchQuaternion:(double)timestamp;

/**
 analyse whether the motion type is walking, call before calling Method `finish:`, if needed
 @return whether refine the direction successfully
 */
- (BOOL)refineDirection;

/**
 所有帧分析结束之后，可以获得多目标识别结果：每个目标出现的时间以及位置的序列，每个序列代表一个物体的track路径
 
 @return 追踪到的目标序列个数，0表示没有追踪到序列或者写json时发生错误，在自动方向模块，成功时返回值最大为1
 */
- (int)finish;
@end

NS_ASSUME_NONNULL_END
