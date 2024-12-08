//
//  INSDeepLearningMeasure.h
//  INSCoreMedia
//
//  Created by Mac on 2021/4/19.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDeepLearningMeasure : NSObject


/// 用来测试深度学习模型的加载
- (void)startTestCreator;

- (void)testModelPaths;
@end

NS_ASSUME_NONNULL_END
