//
//  INSFaceTracker.h
//  INSCoreMedia
//
//  Created by HFY on 2019/6/14.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import <GLKit/GLKit.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSFaceBeautyDetectMode) {
    INSFaceBeautyDetectModeVideo = 0,
    INSFaceBeautyDetectModeImage = 1,
};

@class INSFaceBeautyParam;
@interface INSFaceBeautyFilter : NSObject

@property (nonatomic, readonly) EAGLContext *renderContext;

@property (nonatomic, readonly) int width;

@property (nonatomic, readonly) int height;

@property (nonatomic) INSFaceBeautyParam *param;

@property (nonatomic) INSFaceBeautyDetectMode detectMode;

/// 构造方法
/// @param syncDispatchQueue 执行美颜渲染流程的队列，对于不同的render上下文，需要不同的队列; 如预览和导出时，在renderview 调用changeRenderType时，无需额外创建对象
/// @param param 美颜参数，默认为VideoMode，效率更高，但是识别可能不准
/// @param detectMode
- (nullable instancetype)initWithSyncDispatchQueue:(dispatch_queue_t)syncDispatchQueue param:(INSFaceBeautyParam *)param detectMode:(INSFaceBeautyDetectMode)detectMode;

- (nullable instancetype)initWithSyncDispatchQueue:(dispatch_queue_t)syncDispatchQueue param:(INSFaceBeautyParam *)param;

// 开启美颜开关，默认打开，通过更新INSFaceBeautyParam调整美颜参数；设置为NO，则所有美颜参数置零
@property (nonatomic, assign) BOOL enableFaceBeauty;

//disable
//@property (nonatomic, assign) BOOL enableFaceDetect;
//@property (nonatomic, assign) BOOL enableEffect;
//@property (nonatomic, assign) BOOL enableBodyBeauty;
//@property (nonatomic, assign) BOOL enablePartFaceDetect;
//@property (nonatomic, assign) BOOL enableSegment;
//@property (nonatomic, assign) BOOL enableGesture;
//@property (nonatomic, assign) BOOL enableBodyDetect;
//@property (nonatomic, assign) BOOL enableCatDogDetect;
//@property (nonatomic, assign) BOOL enableImport;
//@property (nonatomic, assign) BOOL enableFilter;
//@property (nonatomic, assign) BOOL enableFaceShape;

-(void)releaseFilter;

@end

NS_ASSUME_NONNULL_END
