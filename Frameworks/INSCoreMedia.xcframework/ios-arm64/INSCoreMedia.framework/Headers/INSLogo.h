//
//  INSLogo.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/8/8.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSLogoPosition) {
    INSLogoPositionCameraDown,             //下方
    INSLogoPositionCameraSide,             //竖插电池
    INSLogoPositionDivingShell,            //潜水壳
};

@interface INSLogo : NSObject

- (instancetype) initWithOneXDivingShellLogo;
- (instancetype) initWithImage:(UIImage*)image size:(float)size;
- (instancetype) initWithImage:(UIImage *)image size:(float)size position:(INSLogoPosition)position;

@property (nonatomic, strong, readonly, nullable) UIImage *image;
@property (nonatomic, readonly) float size;
@property (nonatomic, readonly) INSLogoPosition position;

@end

NS_ASSUME_NONNULL_END
