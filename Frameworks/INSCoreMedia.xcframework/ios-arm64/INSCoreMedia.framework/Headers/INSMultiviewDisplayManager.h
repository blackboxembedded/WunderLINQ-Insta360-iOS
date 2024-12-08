//
//  INSMultiviewDisplayManager.h
//  INSCoreMedia
//
//  Created by HFY on 2020/7/2.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSMultiviewDisplay.h"
#import "INSDisplayConfigManager.h"



NS_ASSUME_NONNULL_BEGIN

@interface INSMultiviewDisplayConfig : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithMultiviewDisplay:(INSMultiviewDisplay*)display multiviewTemplate:(NSData*)jsonData;

@property(nonatomic, strong)INSMultiviewDisplay *display;
@property(nonatomic, strong)NSData *jsonData;

@end



@class INSMultiviewScheme;
@interface INSMultiviewDisplayManager : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithDisplayConfigs:(NSArray<INSMultiviewDisplayConfig*>*)configs;
-(INSMultiviewDisplayConfig* _Nullable)displayConfigWithDisplay:(INSMultiviewDisplay*)display;

-(NSArray<INSMultiviewScheme*>*)schemesWithDefaultDisplayValue:(INSDisplayValue*)displayValue aspect:(INSDisplayAspect)aspect  schemes:(NSArray<INSMultiviewScheme*>*)schemes;

@end


NS_ASSUME_NONNULL_END

