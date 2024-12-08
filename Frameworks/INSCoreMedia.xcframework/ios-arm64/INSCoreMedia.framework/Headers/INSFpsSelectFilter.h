//
//  INSFpsSelectFilter.h
//  INSCoreMedia
//
//  Created by HFY on 2021/8/31.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSPlayerImage;
@interface INSFpsSelectFilter : NSObject

-(instancetype)initSrcFps:(double)srcFps dstFps:(double)dstFps;

-(BOOL) isValidImage:(INSPlayerImage*)image;

@property(nonatomic)BOOL debugLog;

@end

NS_ASSUME_NONNULL_END
