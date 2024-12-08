//
//  INSIDRFrameDecoder.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/21.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSIDRFrameDecoder : NSObject


/// 返回图片，需要手动释放内存
/// @param data IDR数据
/// @param error 返回值为空时的错误信息
-(CVPixelBufferRef _Nullable)decodeIDRData:(NSData*)data error:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
