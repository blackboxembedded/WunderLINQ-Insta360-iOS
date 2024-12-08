//
//  INSExporterManager.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/6/23.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, INSExporterState){
    INSExporterStateError,
    INSExporterStateCancel,
    INSExporterStateEnd,
};


NS_ASSUME_NONNULL_BEGIN

@class INSExporterManager;
@protocol INSExporterDeletegate <NSObject>

- (void) expoterManager:(INSExporterManager*)manager progress:(float)progress;
- (void) expoterManager:(INSExporterManager*)manager state:(INSExporterState)state error:(nullable NSError*)error;

@end

@class INSExporter;
@interface INSExporterManager : NSObject

- (instancetype) initWithExporter:(INSExporter*)exporter;


/// 执行导出
/// 函数内存会创建一个定时器，如果在非主线程调用此函数，次函数会先阻塞同步等待主线程里面创建的定时器完成。
/// 所以在调用此函数时确保主线程非阻塞，否则主线程会死锁
- (BOOL) run;

/// 取消操作，异步执行，需要等待INSExporterStateCancel状态后，才能释放Manager
- (void) cancel;

/// 同步取消，阻塞线程，直到资源释放结束
- (void) cancelSyn;

- (void)interrupt;

@property (nonatomic, strong) INSExporter *exporter;
@property (nonatomic, weak, nullable) id<INSExporterDeletegate> delegate;
@property (nonatomic) float progressInterval;  //进度回调间隔 默认值：0.5   单位：秒

/**
 *  预测的视频大小 */
@property (assign, nonatomic, readonly) NSUInteger estimateSize;

@end

NS_ASSUME_NONNULL_END
