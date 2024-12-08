//
//  INSBgm.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/7.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface INSBgm : NSObject

- (instancetype) initWithURL:(NSURL*)url weight:(float)weight startTimestamp:(int64_t)startTimestamp;
//- (instancetype) initWithURL:(NSURL *)url weight:(float)weight startTimestamp:(int64_t)startTimestamp endTimestamp:(int64_t)endTimestamp;

@property (nonatomic, strong) NSURL *url;
@property (nonatomic) float weight;
@property (nonatomic) int64_t startTimstamp;
//@property (nonatomic) int64_t endTimestamp;         //为0时表示为bgm文件的结尾

@end
