//
//  INSTemplateRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2019/5/9.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN

@class INSProjectionParam;
@interface INSTemplateRecorder : INSScreenRecorder

- (nullable instancetype)initWithTemplateData:(NSData *)templateData startTime:(double)startTimeMs endTimeMs:(double)endTime beginState:(INSProjectionParam *)beginParam;


- (nullable instancetype)initWithTemplateData:(NSData *)templateData startTime:(double)startTimeMs endTimeMs:(double)endTimeMs aspect:(float)aspect;

@end

NS_ASSUME_NONNULL_END
