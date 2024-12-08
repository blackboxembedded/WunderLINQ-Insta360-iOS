//
//  INSShadowCloneProcotol.h
//  INSCoreMedia
//
//  Created by HFY on 2020/8/18.
//  Copyright © 2020 insta360. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCloneTrailGenerator;
@protocol INSCloneTrailGeneratorDelegate <NSObject>


/// 导出过程中的帧信息，可用来显示进度
/// @param cloneTrailGenerator cloneTrailGenerator
/// @param currentCount 当前已经导出的帧个数，从1开始， 最多到expectedCount
/// @param expectedCount process输入的总个数
- (void)cloneTrailGenerator:(INSCloneTrailGenerator *)cloneTrailGenerator currentExport:(NSInteger)currentCount expectedExport:(NSInteger)expectedCount;

/// 用于捕获导出的过程如果出现错误
/// @param cloneTrailGenerator cloneTrailGenerator
/// @param error error
- (void)cloneTrailGenerator:(INSCloneTrailGenerator*)cloneTrailGenerator failedWithError:(NSError * _Nullable )error;


/// 表示导出成功
- (void)cloneTrailGeneratorDidSuccess;

@optional
- (void)cloneTrailGeneratorDidCancel;

@end

@class INSCloneShadowGenerator;
@protocol INSCloneShadowGeneratorDelegate <NSObject>


/// 导出过程中的帧信息，可用来显示进度
/// @param cloneShadowGenerator cloneShadowGenerator
/// @param currentCount 当前已经导出的帧个数，从1开始， 最多到expectedCount
/// @param expectedCount process输入的总个数
- (void)cloneShadowGenerator:(INSCloneShadowGenerator *)cloneShadowGenerator currentExport:(NSInteger)currentCount expectedExport:(NSInteger)expectedCount;

/// 用于捕获导出的过程如果出现错误
/// @param cloneShadowGenerator cloneShadowGenerator
/// @param error error
- (void)cloneShadowGenerator:(INSCloneShadowGenerator *)cloneShadowGenerator failedWithError:(NSError * _Nullable )error;


/// 表示导出成功
- (void)cloneShadowGeneratorDidSuccess;

@optional
- (void)cloneShadowGeneratorDidCancel;

@end


/// 如果error不为nil，则一定发生了错误；stop为YES表示流程已经结束，可能发生在1.流程被cancel；2.出错结束 3.正常结束.  cancel不会抛错，但是进度会重新回到0
typedef void(^CloneGeneratorProgressBlk)(NSError * _Nullable error, float ratio, BOOL stop);

NS_ASSUME_NONNULL_END
