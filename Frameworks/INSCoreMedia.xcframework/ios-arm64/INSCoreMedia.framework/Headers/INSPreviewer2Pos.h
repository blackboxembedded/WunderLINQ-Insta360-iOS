//
//  INSPreviewerPos.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/3.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSFileClipPos;

@interface INSPreviewer2Pos : NSObject<NSCoding>

- (instancetype) initWithCurrentPosMs:(double)timestamp videoPos:(INSFileClipPos* _Nullable)videoPos bgmPos:(INSFileClipPos* _Nullable)bgmPos;


/**
 当前进度时间点
 */
@property (nonatomic, readonly) double currentPosMs;


/**
 当前视频画面时间点
 */
@property (nonatomic, readonly, nullable) INSFileClipPos *videoPos;


/**
 bgm时间点
 */
@property (nonatomic, readonly, nullable) INSFileClipPos *bgmPos;

@end

NS_ASSUME_NONNULL_END
