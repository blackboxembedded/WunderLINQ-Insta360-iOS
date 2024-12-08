//
//  INSDisplayConfigManager.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/11/22.
//  Copyright © 2019 insta360. All rights reserved.
//

#import "INSDisplay.h"

NS_ASSUME_NONNULL_BEGIN


@interface INSDisplayValue : NSObject

@property(nonatomic, readonly)float xFov;
@property(nonatomic, readonly)float distance;

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithXFov:(float)xFov distance:(float)distance;

@end


@interface INSDisplayConfig : NSObject

@property(nonatomic, strong)INSDisplay *display;
@property(nonatomic, strong)INSDisplayValue *defaultValue;
@property(nonatomic, strong)INSDisplayValue *minValue;
@property(nonatomic, strong)INSDisplayValue *maxValue;

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithDisplay:(INSDisplay*)display defaultValue:(INSDisplayValue*)value minValue:(INSDisplayValue*)min maxValue:(INSDisplayValue*)max;
-(INSDisplayValue*)displayValueFromRatio:(float)ratio;
-(float)ratioFromDisplayValue:(INSDisplayValue*)value;

@end


@interface INSDisplayConfigManager : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithDisplayConfigs:(NSArray<INSDisplayConfig*>*)configs;
-(INSDisplayConfig* _Nullable)displayConfigWithDisplay:(INSDisplay*)display;
-(INSDisplayValue* _Nullable)displayDefaultValueWithDisplay:(INSDisplay*)display;
-(INSDisplayValue* _Nullable)displayValueWithDisplay:(INSDisplay*)display fromDisplay:(INSDisplay*)fromDisplay fromeDisplayValue:(INSDisplayValue*)displayValue;

@end

NS_ASSUME_NONNULL_END
