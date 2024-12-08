//
//  INSPreviewItem.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/7/12.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSPreviewItem : NSObject

- (instancetype) initWithURL:(NSURL*)url;
- (instancetype) initWithURL:(NSURL*)url startTimestamp:(int64_t)startTimestamp endTimestamp:(int64_t)endTimestamp;

@property (nonatomic, strong) NSURL *url;
@property (nonatomic, readonly) BOOL cliped;
@property (nonatomic) int64_t startTimestamp;
@property (nonatomic) int64_t endTimestamp;

@end
