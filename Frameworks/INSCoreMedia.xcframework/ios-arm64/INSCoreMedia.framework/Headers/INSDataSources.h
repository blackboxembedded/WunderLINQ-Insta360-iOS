//
//  INSDataSources.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/21.
//  Copyright © 2018年 insta360. All rights reserved.
//


#import "INSFileClip.h"
#import "INSEmptyClip.h"
#import "INSBgmClip.h"
#import "INSBgmSource.h"


NS_ASSUME_NONNULL_BEGIN


@interface INSDataSources : NSObject


- (instancetype) initWithVideoClips:(NSArray<INSClip*>*)videoClips bgmClip:(INSBgmClip*_Nullable)bgmClip;
- (instancetype) initWithVideoClips:(NSArray<INSClip*>*)videoClips bgm:(NSArray<INSBgmConfig*>*_Nullable)bgms weight:(double)weight;

@property(nonatomic, strong) NSArray<INSClip*>* videoClips;
@property(nonatomic, strong, nullable) INSBgmSource *bgm;
@property(nonatomic, strong, nullable)NSArray<INSBgmClip*> *audioEffectClips;

@end


NS_ASSUME_NONNULL_END
