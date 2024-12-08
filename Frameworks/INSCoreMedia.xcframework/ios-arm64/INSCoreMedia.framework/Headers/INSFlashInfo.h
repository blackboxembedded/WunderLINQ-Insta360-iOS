//
//  INSFlashInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/4/3.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSTimeRange;
@class INSScreenRecorder;
@interface INSFlashInfo : NSObject

@property(nonatomic, strong, nullable)NSURL *backgroundImage;
@property(nonatomic, strong, nullable)NSArray<NSURL*> *bodyImages;
@property(nonatomic, strong, nullable)NSArray<NSURL*> *backImages;
@property(nonatomic, strong, nullable)NSArray<INSTimeRange*> *bodyImageTimeRanges;
@property(nonatomic, strong, nullable)NSArray<INSTimeRange*> *backImageTimeRanges;
@property(nonatomic, strong, nullable)NSArray<INSTimeRange*> *backgroundImageTimeRanges;
@property(nonatomic, strong, nullable)NSArray<INSScreenRecorder*> *recorders;

@end

NS_ASSUME_NONNULL_END
