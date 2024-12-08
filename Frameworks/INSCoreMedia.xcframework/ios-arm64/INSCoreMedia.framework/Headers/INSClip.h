//
//  INSClip.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/20.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, INSClipType){
    INSClipTypeEmpty,
    INSClipTypeFile,
    INSClipTypeImage,
    INSClipTypeBgm,
    INSClipTypeEm,
};


@interface INSClip : NSObject<NSCoding, NSCopying, NSMutableCopying>{
    INSClipType _type;
}

@property (nonatomic, readonly) INSClipType type;


/**
 导出帧数，大于0时，clip时长将由帧数控制，默认为0
 仅导出时生效
 */
@property (nonatomic) int exportFrameCount;


/**
 去除文件尾的文件长度，单位：字节
 */
@property (nonatomic) int64_t mediaFileSize;

@end

NS_ASSUME_NONNULL_END
