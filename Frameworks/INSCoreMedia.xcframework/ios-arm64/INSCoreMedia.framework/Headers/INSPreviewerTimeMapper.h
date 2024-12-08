//
//  INSPreviewerTimeMapper.h
//  INSCoreMedia
//
//  Created by HFY on 2021/9/16.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSFileClip.h"
NS_ASSUME_NONNULL_BEGIN

@class INSClip;
@class INSFileClipPos;
@interface INSPreviewerTimeMapper : NSObject


/// open函数
/// @param videoClip 播放列表
-(NSError*_Nullable)open:(NSArray<INSClip*>*)videoClip;


/// 关闭函数，关闭后不能再调用任何功能函数
-(void)close;


/// 将media映射到视频帧时间上
/// @param mediaTime 进度条时间media
/// @param fileClipPos 视频帧的原始时间
- (BOOL) mapMediaTimeMs:(double)mediaTime toSrcTime:(INSFileClipPos* _Nullable *_Nonnull)fileClipPos;


/// 将视频帧时间映射到media时间上
/// @param fileClipPos 视频帧的原始时间
/// @param mediaTime 进度条时间media
- (BOOL) mapSrcTime:(INSFileClipPos*)fileClipPos toMediaTimeMs:(double*)mediaTime;


/// 获取转场clip末尾的转场开始时间
/// @param index clip的序号，从0开始
- (double) getClipEndTimeMsExcludeEndCutscenes:(int)index;


/// 获取时长
-(double)getDurationMs;

@end

NS_ASSUME_NONNULL_END
