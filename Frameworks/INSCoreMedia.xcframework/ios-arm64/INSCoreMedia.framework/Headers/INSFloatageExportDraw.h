//
//  INSFloatageExportDraw.h
//  INSCoreMedia
//
//  Created by kahn on 2018/12/4.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSFloatageCellManager.h"
#import "INSFloatageDrawProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSFloatageExportDraw : NSObject<INSFloatageDrawProtocol>

@property (nonatomic, strong, readonly) INSFloatageCellManager *cellManager;

@property (nonatomic, weak) id<INSFloatageExportDelegate> delegate;

- (instancetype) initWithExportWidth:(int)width height:(int)height layerFrame:(CGRect)frame scale:(CGFloat)scale;

@end

NS_ASSUME_NONNULL_END
