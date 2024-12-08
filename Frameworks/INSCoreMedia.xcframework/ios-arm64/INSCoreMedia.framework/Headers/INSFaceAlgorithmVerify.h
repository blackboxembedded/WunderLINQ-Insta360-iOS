//
//  INSFaceAlgorithmVerify.h
//  INSCoreMedia
//
//  Created by 那强 on 2019/10/6.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSFaceppAlgorithmInfo;
@class INSEGGAlgorithmInfo;
@interface INSFaceAlgorithmVerify : NSObject

// 如果返回nil，则说明model data 错误，需要检查
+ (nullable INSFaceppAlgorithmInfo *)getFaceppAlgorithmInfoWithModel:(NSData *)faceppModelData;

+ (nullable INSEGGAlgorithmInfo *)getEggAlgorithmInfoWithModel:(NSData *)eggModelData;

+ (BOOL)validateEggModel:(NSData *)eggModelData;

+ (BOOL)validateFaceppModel:(NSData *)faceppModelData;

@end

NS_ASSUME_NONNULL_END
