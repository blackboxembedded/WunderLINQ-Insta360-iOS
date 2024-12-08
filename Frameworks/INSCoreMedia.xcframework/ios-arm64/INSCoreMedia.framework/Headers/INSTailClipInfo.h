//
//  INSTailClipInfo.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/6/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSTailClipInfo : NSObject

- (instancetype) initWithStartTimeMs:(double)startTimeMs durationMs:(double)durationMs jsonURL:(NSURL*)jsonURL;

@property(nonatomic)double startTimeMs;
@property(nonatomic)double durationMs;
@property(nonatomic, strong)NSURL* jsonURL;


@end

NS_ASSUME_NONNULL_END
