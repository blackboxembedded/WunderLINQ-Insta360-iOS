//
//  INSMultiViewCell.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/11/24.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCamera;
@interface INSMultiViewCell : NSObject<NSCoding, NSCopying, NSMutableCopying>

- (instancetype) initRectangleWithRect:(CGRect)rect;

@property (nonatomic, copy, nullable) NSString* name;
@property (nonatomic) CGRect rect;
@property (nonatomic) CGRect viewport;
@property (nonatomic) GLKQuaternion orientation;
@property (nonatomic) BOOL fovAndDistanceValid;
@property (nonatomic) float xFov;
@property (nonatomic) float distance;

/**
 投影camera
 初始为nil，表示默认
 */
@property (nonatomic, strong, nullable) INSCamera *camera;

- (BOOL) hitTest:(CGPoint)point;

@end


NS_ASSUME_NONNULL_END
