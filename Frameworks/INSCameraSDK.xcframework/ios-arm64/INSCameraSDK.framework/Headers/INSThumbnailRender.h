//
//  INSThumbnailRender.h
//  INSCameraSDK
//
//  Created by zeng bin on 5/15/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSThumbnailRender : NSObject

- (instancetype)initWithWidth:(int)width height:(int)height;

/**
 *  解码h264数据
 *  @param data h264图像数据
 *  @return 解码成功返回YUV420图像数据, 此返回值需要手动释放内存，解码失败返回NULL
 */
- (CVPixelBufferRef)copyPixelBufferWithDecodeH264Data:(NSData *)data;

/**
 *  渲染h264数据
 *  @param data     h264图像数据
 *  @param offset   h264图像数据渲染时使用的offset值
 *  @return         最终得到的图片
 */
- (nullable UIImage *)renderWithH264Data:(NSData *)data
                    offset:(NSString *)offset;

@end

NS_ASSUME_NONNULL_END
