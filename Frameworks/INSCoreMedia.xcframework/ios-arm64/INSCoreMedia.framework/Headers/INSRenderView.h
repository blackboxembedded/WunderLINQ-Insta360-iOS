//
//  INSRenderView.h
//  INSVideoPlayApp
//
//  Created by pwx on 20/2/16.
//  Copyright © 2016年 insta360. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "INSRenderType.h"
#import "INSPlayerProtocol.h"
#import "INSRenderProtocol.h"

@class INSRender;
@class INSRenderManager;
@class INSDisplayLink;
@class INSProjectionStrategy;
@class INSAnimation;
@class INSAnimationState;
@class INSScreenTracker;
@class INSProjectionInfo;
@class INSEyePointManager;
@class INSVisionField;
@class INSProjectionConverter;
@class INSFpsSelectFilter;

NS_ASSUME_NONNULL_BEGIN


@interface INSRenderView : UIView<INSPlayDisplay>

/**
 *  初始化函数
 *  @param frame      视图的fram
 *  @param renderType 使用render的类型
 *  @return INSRenderView对象的实例
 */
- (instancetype) initWithFrame:(CGRect)frame renderType:(INSRenderType)renderType;


/**
 动态改变render的类型，会重新创建render, 并将上个render的属性转移给新的render
 @param type 新render的类型
 @param reRender 是否用上一次的image或pixelBuffer重新渲染
 */
- (INSRender*) changeRenderType:(INSRenderType)type reRender:(BOOL)reRender;

/**
 动态改变render的类型，会重新创建render，不做属性配置
 @param type 新render的类型
 @return 新render
 */
- (INSRender*) changeRenderType:(INSRenderType)type converter:(INSProjectionConverter*_Nullable)converter;


- (void) setRender:(INSRender*)render converter:(INSProjectionConverter*_Nullable)converter;
/**
 执行动画
 @param animation 需要展示的动画效果， 为nil时表示取消加入的动画
 @param complete 动画完成后的回调block，可以为nil
 @return 返回添加动画的状态
 */

- (INSAnimationState* _Nullable) performAnimation:(INSAnimation*)animation complete:(void(^_Nullable)())complete;

/**
 *  播放视频流
 *  @param player 流播放器
 *  @param offset 拼接offset值
 */
- (void) playVideoWithOffset:(NSString*__nullable)offset;


/**
 *  播放图片
 *  @param image  图片
 *  @param offset 拼接offset值
 */
- (void) playImage:(UIImage*)image offset:(NSString*__nullable)offset;
- (void) playTexture2D:(NSUInteger)texture texUnit:(NSUInteger)texUnit offset:(NSString*__nullable)offset;

/**
 *  播放图片
 *  此函数会强制绘制图片一次，但会调用stopDisplayLink，即不会以屏幕刷新率来同步绘制显示内容，如需与屏幕刷新率同步，需显式调用startDisplayLink；
 *  @param image  图片
 *  @param offset 拼接offset值
 */
- (void) playImageWithStopDisplayLink:(UIImage *)image offset:(NSString *__nullable)offset;

/**
 *  开始屏幕刷新
 */
- (void) startDisplayLink;

/**
 *  停止屏幕刷新
 */
- (void) stopDisplayLink;

/**
 *设置投影模式与投影参数
 *@param projectionMode 投影模式
 *@param block 投影参数设置block， 可以为nil，表示采用默认参数, 可以通过修改param值来自定义投影模式的各个参数值
 */
- (void) setProjectionMode:(INSViewProjectionMode)projectionMode projectionParam:(void(^_Nullable)(STProjectionParam * const param))block;

- (void) destroyRender;


/**
 重新刷新当前画面
 */
- (void) resetCurrentPlayImage;

-(INSPlayerImage*)getCurrentPlayImage;

//清楚当前持有的画面图片，当切换片段时调用
-(void)clearCurrentPlayImage;

-(void)resetBackgroundColor:(GLKVector4)color;

-(void)addRenderDelegate:(id<INSRenderProtocol>)renderDelegate;
-(void)removeRenderDelegate:(id<INSRenderProtocol>)renderDelegate;
-(void)removeAllRenderDelegate;

/**
 当前视图的yFov值
 */
@property (nonatomic) float yFov;
@property (nonatomic) float xFov;

/**
 当前视图camera的distance值
 */
@property (nonatomic) float distance;

/**
 投影参数信息
 */
@property (nonatomic, nullable) INSProjectionInfo *projectionInfo;

/**
 设置是否需要进行yFov值的转换, 当旋屏的时候，在改变视图的Frame属性后，需要设置此值，以保证视图投影的大小不发生变化，
 */
@property (nonatomic) BOOL yFovTransformWithAspect;


/**
 *  画面展示模式，一般为INSViewPresentModeSingle，但对于部分render可能为其他值
 */
@property (nonatomic) INSViewPresentMode presentMode;

/**
 *  画面交互模式，默认INSInteractiveModeFinger
 */
@property (nonatomic) INSViewInteractiveMode interactiveMode;

/**
 *  画面投影观看模式，默认为INSViewProjectionModeFisheye
 *  使用INSViewProjectionModeCustom值设置此属性，属性值将不会改变
 */
@property (nonatomic) INSViewProjectionMode projectionMode;

/**
 *  陀螺仪模式下手势滑动方式，X，Y坐标体系为View的坐标体系
 *  属性interactiveMode=INSViewInteractiveModeFingerAndGyro时，此属性值起作用
 */
@property (nonatomic) INSGyroSlipType gyroSlipType;

@property (nonatomic) BOOL enablePlayerImageFilter;

/**
 观看视角范围控制
 */
@property (nonatomic, strong, nullable) INSVisionField *visionField;
@property (nonatomic, readonly) UIPanGestureRecognizer *panGesture;
@property (nonatomic, readonly) UIPinchGestureRecognizer *pinchGesture;

@property (nonatomic) BOOL enablePinchGesture;
@property (nonatomic) BOOL enablePanGesture;
@property (nonatomic) float minSlidingY;            //Y方向手势最小滑动的角度，单位：°
@property (nonatomic) float maxSlidingY;            //Y方向手势最大滑动的角度，单位：°

@property (nonatomic) bool disableUpdateStaticGyroStabilityOrientation;            //禁用在线更新防抖矩阵，使用静态防抖矩阵时应置为true

@property (nonatomic, weak, readonly, nullable) id <INSPlayControl> player;            //流播放器
@property (nonatomic, strong, readonly) INSRender *render;                      //画面渲染器
@property (nonatomic, strong, readonly) INSRenderManager *renderManager;        //渲染管理器，手势，陀螺仪处理
@property (nonatomic, strong, readonly) CAEAGLLayer *glLayer;                   //画面显示layer
@property (nonatomic, strong, readonly) INSDisplayLink *displayLink;             //显示
@property (nonatomic, readonly) float refreshRate;                              //画面刷新率
@property (nonatomic, readonly) float playImageFps;                             //播放图像帧率
@property (nonatomic, weak, nullable) id<INSRenderViewGestureProtocol> gestureDelegate;

@property (nonatomic, strong, nullable) INSScreenTracker *tracker;

@property (nonatomic, strong, nullable) INSEyePointManager *eyePointManager;
@property (nonatomic, strong, nullable) INSProjectionConverter *projectionConverter;
@property (nonatomic) float frameBufferScale;
@property(nonatomic)BOOL enableRenderEveryPlayerImage;
///追踪时支持缩放fov，默认值NO
@property(nonatomic)BOOL enableTrackingScaleFov;

/// 滑动手势移动速度的倍数，默认值1.0
@property(nonatomic)float panGestureMoveScale;

@property(nonatomic, strong, nullable)INSFpsSelectFilter *fpsSelectFilter;


/// 强制播放帧率，默认NO, 设置YES时属性forcePlayingFps生效
@property(nonatomic)BOOL enableForcePlayingFps;

/// 强制播放帧率
@property(nonatomic)double forcePlayingFps;
@property(nonatomic)BOOL enableShareNv12Cache;

@end



@interface INSRenderView(ProjectionPlayer)
- (void) playVideoWithOffset:(NSString*__nullable)offset projectionConverter:(INSProjectionConverter*)converter;
@end


NS_ASSUME_NONNULL_END
