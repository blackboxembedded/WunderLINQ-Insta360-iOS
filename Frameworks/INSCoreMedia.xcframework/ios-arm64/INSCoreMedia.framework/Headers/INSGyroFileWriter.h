//
//  INSGyroFileWriter.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/23.
//  Copyright © 2017年 insta360. All rights reserved.
//


#import <Foundation/Foundation.h>

@class INSGyroDataSource;

NS_ASSUME_NONNULL_BEGIN

@interface INSGyroFileWriter : NSObject

- (instancetype)initWithSaveURL:(NSURL*)url;

- (instancetype)initWithSaveURL:(NSURL*)url dataSource:(INSGyroDataSource *)dataSource;

- (void) startGyroData;
- (void) stopGyroData;

- (void) startWrite:(int64_t)timestamp;
- (void) stopWrite;

@end

NS_ASSUME_NONNULL_END
