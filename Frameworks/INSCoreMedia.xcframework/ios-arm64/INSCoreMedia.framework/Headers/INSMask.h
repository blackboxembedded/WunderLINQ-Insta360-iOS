//
//  INSMask.h
//  INSMediaApp
//
//  Created by pengwx on 16/11/14.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import "INS3DObject.h"

@class INSMaskRes;
@class INSMaskInfo;

typedef NS_ENUM(NSInteger, INSMaskType) {
    INSMaskTypeNormal,
    INSMaskTypeFace,
    INSMaskTypeFlatLogo,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSMask : INS3DObject

@property (nonatomic) INSMaskType maskType;             //类型
@property (nonatomic) float rotation;                   //方向旋转      单位： 角度
@property (nonatomic) float angleSize;                  //大小， 单位： 角度
@property (nonatomic) BOOL  isMirror;                   //是否镜像
@property (nonatomic, strong) INSMaskRes *maskRes;      //资源, 图片

- (instancetype) initWithMaskInfo:(INSMaskInfo*)info;

- (INSMaskInfo*) maskInfo;

- (BOOL) hitPoint:(GLKVector3)point;

- (GLKVector3) getCenterPoint;
- (GLKVector3) getLeft;
- (GLKVector3) getRight;
- (GLKVector3) getFront;
- (GLKVector3) getBack;

@end

NS_ASSUME_NONNULL_END
