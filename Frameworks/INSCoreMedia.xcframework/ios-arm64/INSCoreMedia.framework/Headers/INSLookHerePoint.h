//
//  INSLookHerePoint.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/12/26.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "INSMediaPos.h"

NS_ASSUME_NONNULL_BEGIN


@class INSDisplay;
@class INSDisplayConfigManager;
@interface INSLookHerePoint : NSObject<NSCoding, NSCopying, NSMutableCopying>

@property (nonatomic) float xFov;
@property (nonatomic) float distance;
@property (nonatomic) float preRoll;
@property (nonatomic) GLKQuaternion anchorOrientation;
@property (nonatomic) GLKQuaternion orientation;
@property (nonatomic, strong, nullable)INSDisplay *display;
@property(nonatomic, strong)INSMediaPos *srcTimePos;

-(instancetype)initWithJsonDictionary:(NSDictionary*)dic;
-(NSDictionary*)serializeJsonDictionary;

- (INSLookHerePoint*) lookHerePointWithDisplay:(INSDisplay*)display displayConfigManager:(INSDisplayConfigManager*)manager;

@end

NS_ASSUME_NONNULL_END
