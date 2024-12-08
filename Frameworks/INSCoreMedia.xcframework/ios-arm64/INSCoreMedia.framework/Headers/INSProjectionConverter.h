//
//  INSProjectionConverter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/1/12.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSRender;
@class INSProjectionParam;
@class INSProjectionInfo;
@class INSPlayerImage;
@class INSMediaPos;

@interface INSProjectionConverter : NSObject

//@property (nonatomic, strong, nullable) INSProjectionParam *originProjectionParam;

@property (nonatomic) BOOL enable;      //是否可用，默认为YES
@property (nonatomic) BOOL retainEditDataBackProjection;

//- (BOOL) filterRender:(INSRender*)render timestamp:(int64_t)timestamp;
- (BOOL) filterRender:(INSRender*)render mediaPos:(INSMediaPos*)mediaPos;

@end

NS_ASSUME_NONNULL_END
