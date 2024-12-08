//
//  INSRecordProtocol.h
//  INSCoreMedia
//
//  Created by HFY on 2021/7/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSPlayerImage.h"
#import "INSAudioSample.h"

@protocol INSRecordProtocol <NSObject>

- (void) recordVideoImage:(INSPlayerImage*)image;
//- (void) recordAudioSample:(INSAudioSample*)sample;

@end
