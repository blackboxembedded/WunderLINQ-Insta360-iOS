//
//  INSTranscodeExporter.h
//  INSCoreMedia
//
//  Created by Mac on 2021/3/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^Callback)(int encodeFrameCount, int totalFrameCount, bool finished);
@interface INSTranscodeExporter : NSObject
- (void) transcodeWithInput:(NSString *)inputStr Output:(NSString *)outputStr Width:(int)width Height:(int)height enableCodeHwaccel:(BOOL)enableCodeHwaccel enableDecodeHwaccel:(BOOL)enableDecodeHwaccel Callback:(Callback)callback;
@end

NS_ASSUME_NONNULL_END

