//
//  INSFaceOffOffscreenRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/6/19.
//  Copyright © 2020 insta360. All rights reserved.
//


#import "INSOffscreenRender.h"

NS_ASSUME_NONNULL_BEGIN

@class INSFaceOffInfo;
@interface INSFaceOffOffscreenRender : INSOffscreenRender

@property(nonatomic, strong)INSFaceOffInfo *faceOffInfo;

@end

NS_ASSUME_NONNULL_END


