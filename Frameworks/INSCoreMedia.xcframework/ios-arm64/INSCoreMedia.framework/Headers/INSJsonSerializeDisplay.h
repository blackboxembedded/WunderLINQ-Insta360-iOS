//
//  INSJsonSerializeDisplay.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/9/27.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSRenderType.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSJsonSerializeDisplay : NSObject

-(instancetype)initWithJsonDictionary:(NSDictionary*)dic;
//-(instancetype)initWithRenderAspectRation:(INSRenderAspectRatio)aspectRatio;
-(NSDictionary*)serializeJsonDictionary;

//@property(nonatomic, readonly)INSRenderAspectRatio aspectRatio;
@property(nonatomic, copy)NSString* type;
@property(nonatomic, assign)double width;
@property(nonatomic, assign)double height;

@end

NS_ASSUME_NONNULL_END
