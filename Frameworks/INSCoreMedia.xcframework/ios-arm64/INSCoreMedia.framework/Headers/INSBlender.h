//
//  INSBlender.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/8/22.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSLensOffset.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSBlender : NSObject


- (BOOL) getBlendAngle:(float*)blendAngle lenType:(INSLensType)lensType;

/**
 融合角度，默认值为0，表示使用内部的默认值进行融合，大于零时起作用
 */
@property (nonatomic) float blendAngle;


@end

NS_ASSUME_NONNULL_END
