//
//  INSFaceFilterMeishe.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/15.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSFaceBeautyFilter.h"


/// 1.由外部创建NvsEffect对象、判断是否安装了相应的package、执行安装与更新；外部管理NvsEffectSdkContext
/// 2.CoreMedia 只负责NvsEffectRenderCore接口的封装
/// 3.由app管理，effect集合的增删改，配置完成后，通过update设置过来即可

NS_ASSUME_NONNULL_BEGIN

@class NvsEffectRenderCore;
@class NvsEffectSdkContext;
@class NvsEffect;
@interface INSNvFilter : NSObject


@property (nonatomic, readonly) int width;

@property (nonatomic, readonly) int height;

@property (nonatomic, readonly) NvsEffectSdkContext *effectContext;

@property (nonatomic, readonly) NSArray<NvsEffect *> *effects;

@property (nonatomic, readonly) CGSize contentSize;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithNvEffectContext:(NvsEffectSdkContext *)effectContext effectQueue:(dispatch_queue_t)effectQueue;

- (instancetype)initWithNvEffectContext:(NvsEffectSdkContext *)effectContext effectQueue:(dispatch_queue_t)effectQueue glContext:(EAGLContext *)renderContext width:(int)width height:(int)height;

- (void)setContentSize:(CGSize)contentSize;

- (void)resetFirstEffectTimeMs:(int64_t)firstEffectTimeMs;

- (BOOL)appendVideoEffect:(NvsEffect*)effect;

- (BOOL)removeRenderEffect:(NSString*)effectId;

- (void)enableDebug:(BOOL)enableDebug;

@end

NS_ASSUME_NONNULL_END
