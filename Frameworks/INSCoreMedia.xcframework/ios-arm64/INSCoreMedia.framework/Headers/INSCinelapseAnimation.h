//
//  INSCinelapseAnimation.h
//  INSCoreMedia
//
//  Created by HFY on 2022/1/21.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSAnimationRecorder.h"
#import "INSAppletWrapData.h"
#import "INSCinelapseWarpData.h"

NS_ASSUME_NONNULL_BEGIN
@class INSCinelapseDatasource;
@class INSCinelapseConfiguration;
@class INSCinelapseResult;
@interface INSCinelapseAnimation : NSObject<INSPlugableAnimation, NSCoding>

@property (nonatomic, readonly) INSCinelapseConfiguration *configuration;

@property (nonatomic, readonly) NSArray<INSCinelapseDatasource *> *dataSources;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithConfiguration:(INSCinelapseConfiguration *)configuration dataSources:(NSArray<INSCinelapseDatasource *> *)dataSources;

/// prepare after init and before get result
- (nullable NSError *)prepare;

/// get cinelapse result.
/// Return nil when preparing is not ok or nothing is recommended in algorithm
- (nullable INSCinelapseResult *)getCinelpase;

@end

NS_ASSUME_NONNULL_END
