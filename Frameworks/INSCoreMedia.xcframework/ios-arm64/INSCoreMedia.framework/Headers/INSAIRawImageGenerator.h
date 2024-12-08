//
//  INSAIRawImageGenerator.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSAIRawImageGeneratorError) {
    // 参数错误
    INSAIRawImageGeneratorErrorParameters = -1,
    // 算法运行出错误
    INSAIRawImageGeneratorErrorAlgorithm = -2,
    // opencv 抛出异常
    INSAIRawImageGeneratorErrorOpenCV = -3,
};

@interface INSAIRawImageGenerator : NSObject

/// 每次输入一张dng图片路径， 如果失败，会返回nil，且抛出error
/// @param dngPath dng图片路径
/// @param denoiseLutPath lut abosule path: 283.ilut,577.ilut, x2.ilut...
/// @param error error
- (nullable NSData *)processWithDNGPath:(NSString *)dngPath denoiseLutPath:(NSString *)denoiseLutPath error:(NSError * _Nullable * _Nullable)error;

-(void)cancel;

@end

NS_ASSUME_NONNULL_END
