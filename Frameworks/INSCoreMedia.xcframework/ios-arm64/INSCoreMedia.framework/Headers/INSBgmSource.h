//
//  INSBgmSource.h
//  INSCoreMedia
//
//  Created by HFY on 2021/4/27.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface INSBgmConfig : NSObject

-(instancetype)initWithWithURL:(NSURL*)url startSrcTimeMs:(double)startSrcTimeMs endSrcTimeMs:(double)endSrcTimeMs totalSrcDurationMs:(double)totalSrcDurationMs;

@property(nonatomic)NSURL *url;
@property(nonatomic)double positionInMediaTimeMs;
@property(nonatomic)double startSrcTimeMs;
@property(nonatomic)double endSrcTimeMs;
@property(nonatomic)double totalSrcDurationMs;

//音量,  默认值：1.0
@property(nonatomic)double volume;
//淡入效果时长  默认值：1000
@property(nonatomic)double afadeInDurationMs;
//淡出效果时长  默认值：1000
@property(nonatomic)double afadeOutDurationMs;

@end


@class INSBgmClip;
@interface INSBgmSource : NSObject

-(instancetype)initWithBgmClip:(INSBgmClip*)bgmClip;
-(instancetype)initWithBgm:(NSArray<INSBgmConfig*>*)bgms weight:(double)weight;

@property(nonatomic)double weight;
@property(nonatomic, strong, nullable)NSArray<INSBgmConfig*> *bgms;
@property(nonatomic, strong, nullable)INSBgmClip *bgmClip;

@end

NS_ASSUME_NONNULL_END
