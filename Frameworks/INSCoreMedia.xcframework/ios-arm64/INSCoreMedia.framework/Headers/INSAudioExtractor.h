//
//  audioExtractor.h
//  INSCoreMedia
//
//  Created by dml on 2022/5/17.
//  Copyright © 2022 insta360. All rights reserved.
//


#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, INSAudioExtractorErrorCode){
    INSAudioSuccess = 0,
    INSAudioEerrorInputEempty = - 5001,
    INSAudioEerrorLoadMedia = -5002,
    INSAudioEerrorReadMedia = - 5003,
    INSAudioEerrorWriteMedia = - 5004,
    INSAudioEerrorWriteFinish = -5005,
    INSAudioEerrorNoAudioTrack = -5006,
    INSAudioEerrorOutputEmpty = -5007,
};


@interface INSAudioExtractor : NSObject

+ (INSAudioExtractorErrorCode)parserVideo:(NSString*)inputUrl toAudio:(NSString*)outputUrl;

@end
