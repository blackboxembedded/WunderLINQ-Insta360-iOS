//
//  INSSubmodeOptions.h
//  INSCameraSDK
//
//  Created by kahn on 2018/10/12.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint16_t, INSSubmodeOptionsType) {
    INSSubmodeOptionsTypeSubmodeOptionUnknown = 0,
    
    /// 定时拍摄时间, readwrite. @available ONE X
    INSSubmodeOptionsTypeSelfTimer = 1,
};

@interface INSSubmodeOptions : NSObject

@property (nonatomic) uint32_t selfTimer;

@end

NS_ASSUME_NONNULL_END
