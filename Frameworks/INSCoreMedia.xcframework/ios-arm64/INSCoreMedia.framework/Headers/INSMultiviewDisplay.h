//
//  INSMultiviewDisplay.h
//  INSCoreMedia
//
//  Created by HFY on 2020/7/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSDisplay.h"


typedef NS_ENUM(NSInteger, INSMultiViewDisplayStyle){
    INSMultiViewDisplayStyleFloatingRectangle,
    INSMultiViewDisplayStyleTwoRectangle,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSMultiviewDisplay : NSObject<NSCoding, NSCopying, NSMutableCopying>

@property(nonatomic)INSDisplayAspect aspect;
@property(nonatomic)INSMultiViewDisplayStyle style;

-(instancetype)initWithDisplayStyle:(INSMultiViewDisplayStyle)style aspect:(INSDisplayAspect)aspect;

-(BOOL)isEqualDisplay:(INSDisplay*)display;

@end

NS_ASSUME_NONNULL_END



