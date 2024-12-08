//
//  INSRender.h
//  INSVideoPlayApp
//
//  Created by pwx on 20/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSRenderType.h"
#import "INSCoreMedia/INSStitchingInfo.h"

@class INSLogo;
@class INSCamera;
@class INS3DObject;
@class INSRenderManager;
@class INSFilter;
@class INSRenderTarget;
@class INSProjectionParam;
@class INSProjectionInfo;
@class INSMediaGyro;
@class INSMediaEuler;
@class INSGyroPlayer;
@class CIFilter;
@class INSPlayerImage;
@class INSTailClipInfo;
@class INSSingleHDRInfo;
@class INSCoordinateScale;
@class INSFlashInfo;
@class INSFilterInfo;
@class INSFaceBeautyFilter;
@class INSPovInfo;
@class INSStitchingInfo;
@class INSNvFilter;
@class INSUnderwaterInfo;
@class INSColorPlusInfo;
@class INSSingleDenoiseInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol INSScreenRecordProtocol <NSObject>

/**
 图像数据
 @param pixelBuffer BGRA格式图像数据
 @param timestamp 时间戳
 */
- (void) onScreenRecordPixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(int64_t)timestamp;

@end

@interface INSRender : NSObject


- (instancetype) initWithRenderWidth:(int)width renderHeight:(int)height context:(EAGLContext*)context target:(INSRenderTarget*)target;

@property (nonatomic, readonly) INSRenderType type;
@property (nonatomic, readonly) int width;                  //渲染图形宽
@property (nonatomic, readonly) int height;                 //渲染图形高

@property (nonatomic) BOOL isDuplicate;                     //是否为双屏               默认：NO
@property (nonatomic) BOOL isDuplicateWidth;                //是否宽度方向双屏          默认：NO

@property (nonatomic) BOOL removePurple;                    //消除紫边

@property (nonatomic, strong, nullable) INSLogo *logo;

@property (nonatomic, copy, nullable) NSArray <CIFilter *>*ciFilters;
@property (nonatomic, strong, nullable) INSFilter *sharpenFilter;

/**
 *  滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *filter;
@property (nonatomic, strong, nullable) NSArray<INSFilterInfo*> *filterInfo;
@property (nonatomic, strong, nullable, readonly) NSArray<INSFilter*> *filters;

/**
 *  美颜滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *beautifyFilter;

/**
 *  调色表滤镜
 */
@property (nonatomic, strong, nullable) INSFilter *lutFilter;

@property (nonatomic, copy, nullable) NSString *offset;               //镜头offset值
@property (nonatomic, strong, nullable) INSCamera *camera;            //相机
@property (nonatomic, strong, nullable) INS3DObject *object3D;        //3D模型
@property (nonatomic, strong) EAGLContext *glContext;       //gl上下文

@property (nonatomic, strong, readonly) INSRenderTarget *drawableRenderTarget;     //drawable渲染target
@property (nonatomic, strong) INSProjectionParam *projectionParam;
@property (nonatomic, strong) INSProjectionInfo *projectionInfo;
@property (nonatomic, strong, nullable) INSMediaEuler *eulerAdjust;   //euler校正
@property (nonatomic, strong, nullable) INSMediaGyro *gyroAdjust;     //gyro校正
@property (nonatomic, strong, nullable) INSMediaEuler *gestureEuler;  //手势转动的欧拉角
@property (nonatomic) GLKVector3 rotationEuler;
@property (nonatomic) GLKQuaternion gyroStabilityOrientation;       //gyro防抖
@property (nonatomic) GLKQuaternion orientation;                    //方向
@property (nonatomic) GLfloat preRoll;                              //roll方向
@property (nonatomic) GLKVector3 euler;                             //euler角:Pitch Yaw Roll
@property (nonatomic) int64_t currentTimestamp;

/**
 防水壳亮度优化开关，默认为NO
 */
@property (nonatomic) BOOL waterproofLuminance;
/**
 *  获取渲染场景锁, 跟函数sceneUnlock成对使用
 */
- (void) sceneLock;

/**
 *  释放渲染场景锁, 跟函数sceneLock成对使用
 */
- (void) sceneUnlock;

- (void) startScreenRecord:(id <INSScreenRecordProtocol>)delegate width:(int)width height:(int)height fps:(int)fps pixelFormat:(OSType)pixelFromat;
- (void) startScreenRecord:(id <INSScreenRecordProtocol>)delegate fps:(float)fps pixelFormat:(OSType)pixelFromat;
- (void) stopScreenRecord;

/**
 *  当前渲染结果的画面快照
 *  @param block 用作返回快照图片，block是在GCD的全局队列中调用返回的
 */
- (void) snapshot:(void(^)(UIImage *__nullable image))block;

/// 同步截屏操作，必须主线程调用
- (UIImage*__nullable)snapshotSync;

/**
 *  当前渲染结果的画面快照
 *  @param width 画面width大小，高度height根据比例自动计算得出
 *  @param block 用作返回快照图片，block是在GCD的全局队列中调用返回的
 */
- (void) snapshotWithImageWidth:(int)width result:(void (^)(UIImage * __nullable))block;
- (void) snapshotWithImageWidth:(int)width height:(int)height result:(void (^)(UIImage * __nullable))block;

//设置渲染场景
- (void) setScenes:(NSArray*)scenes;

//更新渲染场景
- (void) updateScene;

//设置渲染宽、高，   width、height必须与drawable的属性对应的图层大小相匹配，否则可能出现设置失败
- (void) setRenderWidth:(int)width renderHeight:(int)height renderTarget:(INSRenderTarget*)target;

//渲染视频帧（YUV图像数据）
- (void) renderPlayerImage:(INSPlayerImage*)playerImage;
- (void) renderPlayerImage:(INSPlayerImage *)playerImage forceRender:(BOOL)force;
- (void) renderPixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(double)timestamp;
- (void) renderPixelBuffer:(CVPixelBufferRef)pixelBuffer right:(CVPixelBufferRef)pixelBufferRight timestamp:(double)timestamp;

//渲染图片
- (void) renderImage:(UIImage *)image;
- (void) renderTexture2D:(NSUInteger)texture texUnit:(NSUInteger)texUnit;

//执行渲染操作
- (void) onRender;

- (void) offscreenRender;

- (void) removeAllFrameListener;

- (void) destroyRender;
-(void)resetBackgroundColor:(GLKVector4)color;

@property(nonatomic, strong, nullable) INSGyroPlayer *gyroPlayer;
@property(nonatomic) BOOL enableRollingShutter;
@property(nonatomic) float sweepTime;
@property(nonatomic) BOOL verticalSweep;    //默认YES
@property (nonatomic) INSObjectGeometryLevel objectGeometryLevel;
@property (nonatomic) BOOL useOpenGLESTextureCache;            //default:YES
@property (nonatomic) BOOL forceUseVideoDynamicStitching;      //default:NO
@property(nonatomic, strong, nullable)INSStitchingInfo *stitchingInfo;
@property (nonatomic) INSStitchType stitchType;                // 拼接类型

/**
 默认值为分屏方向上的1/2
 */
@property (nonatomic) int vrPupilDistance;
@property (nonatomic) BOOL enableVrPupilDistance;
@property (nonatomic, strong, nullable)INSTailClipInfo *tailClipInfo;

@property (nonatomic) BOOL colorFusion;


@property (nonatomic, strong, nullable)INSColorPlusInfo *colorPlusInfo;

/// 闪电侠特效
@property (nonatomic, strong, nullable)INSFlashInfo *flashInfo;

/// 开启漫画滤镜
@property (nonatomic) BOOL enableCartoon;

/// 开启水下色彩增强
@property (nonatomic, strong, nullable)INSUnderwaterInfo *underwaterInfo;

/// 开启预览单帧降噪
@property (nonatomic, strong, nullable)INSSingleDenoiseInfo *singleDenoiseInfo;

/// povt投影效果， nil为关闭
@property(nonatomic, strong, nullable)INSPovInfo *povInfo;

/// 机身消除优化
@property(nonatomic)BOOL enableCameraBodyOptimization;

/// 坐标缩放，可以分别对x，y进行缩放，为nil时表示不进行缩放
@property (nonatomic, strong, nullable)INSCoordinateScale *coordinateScale;

/// 全景声方位角，x-pitch   y-heading   z-bank;
@property(nonatomic, readonly)GLKVector3 spatialAudioRotation;

@property (nonatomic, nullable) INSFaceBeautyFilter *faceBeautyFilter;

@property (nonatomic, nullable) INSNvFilter *nvFilter;

@end


NS_ASSUME_NONNULL_END
