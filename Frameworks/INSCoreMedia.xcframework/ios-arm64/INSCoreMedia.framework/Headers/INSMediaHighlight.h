//
//  INSMediaHighlight.h
//  INSCoreMedia
//
//  Created by HFY on 2019/10/24.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, INSHighlightDataType) {
    /// highlight点数据
    INSHighlightDataTypeSpot = 0x01,
    /// highlight段数据
    INSHighlightDataTypeSeg = 0x02,
    /// 屏幕“指哪儿打哪儿” 数据
    INSHighlightDataTypeMark = 0x03,
    /// 无线“指哪儿打哪儿” 数据
    INSHighlightDataTypeWireless = 0x04,
    /// multi cam 外屏数据
    INSHighlightDataTypeMultiCamRear = 0x10,
    /// multi cam 内屏数据
    INSHighlightDataTypeMultiCamFront = 0x11,
    /// multi cam 内外分屏数据
    INSHighlightDataTypeMultiCamBoth = 0x12,
};

@interface INSMediaHighlight : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic, readonly) INSHighlightDataType type;

/// 数据点开始时间戳，单位ms
@property (nonatomic) double startTimestamp;

/// 数据点结束时间戳，INSHighlightDataTypeSpot与INSHighlightDataTypeMark两种类型， endTimestamp==startTimestamp， 单位ms
@property (nonatomic) double endTimestamp;
 
- (instancetype)initWithType:(INSHighlightDataType)type startTimestamp:(double)startTimestamp endTimestamp:(double)endTimestamp;

@end

NS_ASSUME_NONNULL_END
