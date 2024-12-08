//
//  INSTimeMap.h
//  INSCoreMedia
//
//  Created by HFY on 2021/8/12.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct{
    //合成后文件的解码时间戳(连续的)， 单位: ms
    double srcTimeMs;
    
    //原视频中的解码时间戳，单位: ms
    double originSrcTimeMs;
} ins_timemap;

typedef struct{
    double startTimeMs;
    double endTimeMs;
} ins_range;

typedef struct{
    ins_range srcRange;
    ins_range originSrcRange;
} ins_rangemap;


@interface INSTimeMap : NSObject

@property(nonatomic, readonly) int timeMapCount;

@property(nonatomic, readonly) int rangeMapCount;

-(ins_timemap)getTimeMapValue:(int)index;

-(ins_rangemap)getRangeMapValue:(int)index;

@end

NS_ASSUME_NONNULL_END
