//
//  INSStitchingInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2021/1/12.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, INSColdShoeMode){
    INSColdShoeModeNone = 0,
    INSColdShoeModeOpen = 1 ,
    INSColdShoeModeLeft = 2,
    INSColdShoeModeRight = 3,
};

// 拼接类型
typedef NS_ENUM(NSInteger, INSStitchType){
    INSStitchTypeNone,
    INSStitchTypeDynamic,
    INSStitchTypeDisflow,
};



NS_ASSUME_NONNULL_BEGIN

@interface INSStitchingInfo : NSObject


/// 冷靴模式，默认值INSColdShoeModeNone
@property(nonatomic)INSColdShoeMode coldShoeMode;

/// 竖拍电视，默认值NO
@property(nonatomic)BOOL standUpBattery;

/// X3子弹时间 默认值NO
@property(nonatomic)BOOL bulletTimeVideo;

/// X3自拍模式 默认值NO
@property(nonatomic)BOOL selfVideo4k;

-(BOOL)isEqualInfo:(INSStitchingInfo*)info;

@end

NS_ASSUME_NONNULL_END
