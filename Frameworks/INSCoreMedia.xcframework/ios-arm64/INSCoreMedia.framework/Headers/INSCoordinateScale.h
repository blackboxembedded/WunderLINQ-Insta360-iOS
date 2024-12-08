//
//  INSCoordinateScale.h
//  INSCoreMedia
//
//  Created by pengwx on 2020/2/3.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface INSCoordinateScale : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithScaleX:(float)x y:(float)y;

@property(nonatomic, readonly)float x;
@property(nonatomic, readonly)float y;

@end

NS_ASSUME_NONNULL_END
