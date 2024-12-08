//
//  INSWidePanoOffscreenRender.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/21.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSOffscreenRender.h"
#import "INSWidePanoRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSWidePanoOffscreenRender : INSOffscreenRender

@property(nonatomic, strong, readonly)INSWidePanoRender *panoRender;

@end

NS_ASSUME_NONNULL_END
