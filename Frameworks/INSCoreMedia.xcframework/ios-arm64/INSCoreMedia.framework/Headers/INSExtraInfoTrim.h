//
//  INSMetadataTrim.h
//  INSCoreMedia
//
//  Created by HFY on 2018/12/6.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class INSExtraInfoTrim;
@class INSExtraInfo;

/*!
 *  载入进度
 */
extern NSString *const kINSExtraInfoTrimProgress;

/*!
 *  下载之后暂存在沙盒文件中位置
 */
extern NSString *const kINSExtraInfoTrimLocation;

/*!
 *  错误信息
 */
extern NSString *const kINSExtraInfoTrimError;



typedef NS_ENUM(NSUInteger, INSExtraInfoTrimState) {
    //未进行操作 userInfo = nil
    INSExtraInfoTrimStateNotStart = 0,
    
    //开始下载 userInfo = nil
    INSExtraInfoTrimStateStartDownload,
    
    //正在下载 userInfo = @{kINSExtraInfoTrimProgress : NSNumber<float>}
    INSExtraInfoTrimStateDownloading,
    
    //下载结束 userInfo = @{kINSExtraInfoTrimLocation : NSURL}
    INSExtraInfoTrimStateEndDownload,
    
    //远程下载的文件尾数据拷贝到文件后缀 userInfo = nil
    INSExtraInfoTrimStateStartCopy,
    
    //正在拷贝 userInfo = @{kINSExtraInfoTrimProgress : NSNumber<float>}
    INSExtraInfoTrimStateCopying,
    
    //拷贝结束 userInfo = @{kINSExtraInfoTrimLocation : NSURL}
    INSExtraInfoTrimStateEndCopy,
    
    //成功结束 userInfo = nil
    INSExtraInfoTrimStateComplete,
    
    //取消 userInfo = nil
    INSExtraInfoTrimStateCancel,
    
    //发生错误 userInfo = @{kINSExtraInfoTrimError : NSError}
    INSExtraInfoTrimStateFailed,
};

@protocol INSExtraInfoTrimDelegate <NSObject>


/**
 按照INSExtraInfoTrimState 的顺序更新状态, 部分信息携带userInfo

 @param extraInfoTrim self
 @param state 当前更新到何种状态
 @param userInfo 对应状态下，携带的信息，部分为nil
 
 INSExtraInfoTrimStateNotStart
 
 
 */
- (void)extraInfoTrim:(INSExtraInfoTrim *)extraInfoTrim
          didUpdateToState:(INSExtraInfoTrimState)state
                  userInfo:(nullable NSDictionary *)userInfo;

@end

@interface INSExtraInfoTrim : NSObject

@property (nonatomic, readonly) NSURL *trimUrl;

@property (nonatomic, readonly) NSURL *fileUrl;

@property (nonatomic, weak, nullable, readonly) id<INSExtraInfoTrimDelegate> delegate;

@property (nonatomic, nullable, readonly) dispatch_queue_t delegateQueue;

/**
 当前状态，与上一次代理方法所回调的状态一致
 */
@property (nonatomic, readonly) INSExtraInfoTrimState state;


/**
 文件远程下载在沙盒中的路径，INSExtraInfoTrimStateEndDownload之后才有值
 */
@property (nonatomic, readonly) NSURL *cacheLocation;


/**
 初始化

 @param trimUrl 远程文件地址
 @param fileUrl 已经trim的媒体资源的路径
 @return instance
 */
- (instancetype)initWithTrimUrl:(NSURL *)trimUrl fileUrl:(NSURL *)fileUrl;


/// set the delegate and delegate calling queue. Not thread-safe, it means you should NOT reset the delegate or delegate queue when calling run
/// @param delegate delegate
/// @param delegateQueue delegate queue,  MUST BE SERIAL QUEUE,   the delegate will run on the thread this queue dispatched, main queue if delegateQueue is nil
- (void)setDelegate:(id<INSExtraInfoTrimDelegate> _Nullable)delegate
      delegateQueue:(dispatch_queue_t _Nullable)delegateQueue;

/**
  当fileURL下没有已经下载的媒体资源时，可以选择把文件尾存成一个独立的data，此时把该变量置为YES， 默认为NO， 多数情况下，该值应为NO
 */
@property (nonatomic) BOOL tryCreateBenchMark;

/**
 初始化后，开始流式 下载-更新 文件尾的流程. 异步进行，通过实现代理方法拿到回调
 */
- (void)run;

/**
 取消正在进行的流程，清空缓存
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
