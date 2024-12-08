//
//  INS3DLutFilter.h
//  INSCoreMedia
//
//  Created by kahn on 2018/7/30.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSFilter.h"
#import "INSFilterInfo.h"

@interface INS3DLutFilter : INSFilter

- (instancetype)initWithLutFilterParam:(INSLutStyleFilterConfig *)param;

- (instancetype)initWithRGBA3DTextureBuffer:(uint8_t *)buffer dimSize:(uint32_t)dimSize lutScale:(CGFloat)lutScale;

-(void)updateRGBA3DTextureBuffer:(void *)buffer width:(int)width height:(int)height depth:(int)depth;

@end
