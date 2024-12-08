//
//  INSBitmapData.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/11/24.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface INSBitmapData : NSObject

@property (nonatomic) int width;
@property (nonatomic) int height;
@property (nonatomic) int colorType;
@property (nonatomic, strong) NSData *colorData;

@end


NS_ASSUME_NONNULL_END
