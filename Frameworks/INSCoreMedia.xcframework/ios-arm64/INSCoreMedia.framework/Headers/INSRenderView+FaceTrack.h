//
//  INSRenderView+FaceTrack.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/5/31.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import "INSRenderView.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSRenderView (FaceTrack)

/**
 进行人脸贴图
 @param handle 回调块，maskInfo为INSMaskInfo类型的数组，初始的INSMaskInfo的name为nil，需要进行贴图设置，否则将不会创建出此INSMask对象
 */
- (void) faceMapping:(void (^)(NSMutableArray*_Nullable maskInfos))handle;


@end

NS_ASSUME_NONNULL_END
