//
//  INSSuperRecordWriter.h
//  INSCoreMedia
//
//  Created by HFY on 2021/7/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSAudioSample.h"
#import "INSPlayerImage.h"
#import "INSDemuxerCacheProxy.h"

NS_ASSUME_NONNULL_BEGIN


@interface INSSuperRecordWriterInfo : NSObject

-(instancetype)initWithOutputUrl:(NSURL*)url width:(int)width height:(int)height bitrate:(int)bitrate fps:(double)fps;

@property(nonatomic, strong)NSURL *url;
@property(nonatomic)int width;
@property(nonatomic)int height;
@property(nonatomic)int bitrate;
@property(nonatomic)double fps;
@property(nonatomic)INSVideoColorSpace colorSpace;
@property(nonatomic)INSVideoColorRange colorRange;
@property(nonatomic, copy, nullable)NSString *metadataMake;
@property(nonatomic, copy, nullable)NSString *metadataModel;
@property(nonatomic, copy, nullable)NSString *metadataComment;

@end


@interface INSSuperRecordWriter : NSObject

-(instancetype)initWithWriterInfo:(INSSuperRecordWriterInfo*)info errorCallback:(void(^)(NSError* error))errorCallback;

@property(nonatomic)BOOL enableDebug;
@property(nonatomic, readonly)double currentDurationMs;

-(void)writerVideoImage:(INSPlayerImage*)playerImage;
-(void)writerAudioSample:(INSAudioSample*)audioSample;
-(void)start;
-(void)stop;


@end

NS_ASSUME_NONNULL_END
