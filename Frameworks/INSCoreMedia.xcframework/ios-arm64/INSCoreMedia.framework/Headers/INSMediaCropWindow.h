//
//  INSMediaCropWindow.h
//  INSCoreMedia
//
//  Created by kahn on 2018/9/4.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCropWindowType) {
    INSCropWindowTypeNoCrop = 0,
    INSCropWindowTypeCropped,
};

@interface INSMediaCropWindow : NSObject <NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic, readonly) uint32_t srcWidth;

@property (nonatomic, readonly) uint32_t srcHeight;

@property (nonatomic, readonly) uint32_t dstWidth;

@property (nonatomic, readonly) uint32_t dstHeight;

@property (nonatomic, readonly) int32_t xOffset;

@property (nonatomic, readonly) int32_t yOffset;

@property (nonatomic) INSCropWindowType cropType;

- (instancetype)initWithSrcWidth:(uint32_t)srcWidth srcHeight:(uint32_t)srcHeight dstWidth:(uint32_t)dstWidth dstHeight:(uint32_t)dstHeight;

- (instancetype)initWithSrcWidth:(uint32_t)srcWidth srcHeight:(uint32_t)srcHeight dstWidth:(uint32_t)dstWidth dstHeight:(uint32_t)dstHeight xOffset:(int32_t)xOffset yOffset:(int32_t)yOffset;

@end

NS_ASSUME_NONNULL_END
