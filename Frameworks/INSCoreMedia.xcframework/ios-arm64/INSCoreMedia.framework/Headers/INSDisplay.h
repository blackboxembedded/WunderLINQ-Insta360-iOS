//
//  INSDisplay.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/22.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSDisplayStyle){
    INSDisplayStyleSuper,
    INSDisplayStyleLinear,
    INSDisplayStyleWide,
    INSDisplayStyleNarrow,
    INSDisplayStyleTinyPlanet,
    INSDisplayStyleCustom,
    INSDisplayStyleSuperPlus,
    INSDisplayStyleSuperPerspective,
    INSDisplayStyleWidePerspective,
    INSDisplayStyleLinearPlus,
    INSDisplayStyleLinearHorizontal,
    INSDisplayStyleLinearHorizontalWider,
    INSDisplayStyleFpv,
    INSDisplayStyleMaxView,
};

typedef NS_ENUM(NSInteger, INSDisplayAspect){
    INSDisplayAspect1x1,
    INSDisplayAspect16x9,
    INSDisplayAspect9x16,
    INSDisplayAspect4x3,
    INSDisplayAspect235x100,
    INSDisplayAspect3x2,
    INSDisplayAspect2x3,
    INSDisplayAspect3x4,
    INSDisplayAspectXpan,
    INSDisplayAspect100x235,
};


@interface INSDisplay : NSObject<NSCoding>

@property(nonatomic)INSDisplayStyle style;
@property(nonatomic)INSDisplayAspect aspect;

-(instancetype)initWithDisplayStyle:(INSDisplayStyle)style aspect:(INSDisplayAspect)aspect;

-(BOOL)isEqualDisplay:(INSDisplay*)display;

+(float)transformAspect:(INSDisplayAspect)aspect;

@end


NS_ASSUME_NONNULL_END
