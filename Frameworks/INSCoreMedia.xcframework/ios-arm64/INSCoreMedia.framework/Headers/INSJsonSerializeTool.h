//
//  INSJsonSerializeTool.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/9/27.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSJsonSerializeDisplay.h"

NS_ASSUME_NONNULL_BEGIN

@class INSDisplay;
@interface INSJsonSerializeTool : NSObject

/**
 display的serilize与deserialize
 */
+(NSDictionary*)serializeDisplay:(INSDisplay*)display;
+(INSDisplay*)deserializeDisplay:(NSDictionary*)dic;

+(NSArray*)serializeQuaternion:(GLKQuaternion)q;
+(GLKQuaternion)deserializeQuaternion:(NSArray*)array;


@end

NS_ASSUME_NONNULL_END
