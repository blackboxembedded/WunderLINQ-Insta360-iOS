//
//  INSStarrySky.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/29.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <UIKit/UIkit.h>


NS_ASSUME_NONNULL_BEGIN

@interface INSStarrySky : NSObject

//参数，默认值0.95
@property(nonatomic)float k;

-(UIImage*)starrySkyWithData:(NSData*)data;

-(CVPixelBufferRef)starrySkyPixelBufferWithData:(NSData*)data;

@end

NS_ASSUME_NONNULL_END
