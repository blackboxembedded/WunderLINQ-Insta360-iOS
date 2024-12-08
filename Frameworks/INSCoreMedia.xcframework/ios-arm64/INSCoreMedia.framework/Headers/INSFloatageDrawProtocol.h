//
//  INSFlotageDrawProtocol.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/11/23.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSBitmapData.h"
#import "INSFloatagePosition.h"

NS_ASSUME_NONNULL_BEGIN

@protocol INSFloatageDrawProtocol <NSObject>

- (INSBitmapData* _Nullable) floatageDrawWithPosition:(INSFloatagePosition*)position;

@optional

- (void) willDrawTurnBack;

@end

@protocol INSFloatageExportDelegate <NSObject>

@optional

- (void) exportWillDrawTurnBack;

- (void) exportContext:(CGContextRef)context didSetupWithSize:(CGSize)size;

- (void) exportContextWillRelease:(CGContextRef)context;

- (void) exportContextDidRelease;

- (void) exportContext:(CGContextRef)context willRenderDataAt:(INSFloatagePosition *)position;

- (void) exportContext:(CGContextRef)context didRenderDataAt:(INSFloatagePosition *)position;

@end

NS_ASSUME_NONNULL_END
