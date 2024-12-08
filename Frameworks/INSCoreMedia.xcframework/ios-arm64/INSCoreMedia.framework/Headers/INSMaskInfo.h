//
//  INSMaskInfo.h
//  INSMediaApp
//
//  Created by pengwx on 16/11/14.
//  Copyright © 2016年 Insta360. All rights reserved.
//


#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMaskRes;

@interface INSMaskInfo : NSObject

- (instancetype) initWithAngleSize:(float)size orientation:(GLKQuaternion)orientation rotation:(float)rotation resource:(INSMaskRes*)res;

@property (nonatomic) float angleSize;      //大小

@property (nonatomic) float rotation;       //旋转值

@property (nonatomic) GLKQuaternion orientation;

@property (nonatomic) BOOL isMirror;

@property (nonatomic, strong) INSMaskRes *res;


@end

NS_ASSUME_NONNULL_END
