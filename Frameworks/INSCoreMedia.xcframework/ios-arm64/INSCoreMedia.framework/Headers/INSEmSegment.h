//
//  INSEmSegment.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSEmSegment : NSObject<NSCoding, NSCopying, NSMutableCopying>

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithUrl:(NSArray<NSURL*>*)urls totalSrcDurationMs:(double)totalSrcDurationMs isValid:(BOOL)isValid;

@property(nonatomic, strong)NSArray<NSURL*> *urls;
@property(nonatomic)double totalSrcDurationMs;
@property(nonatomic)BOOL isValid;

@end


typedef struct{
    int index;
    double srcTimeMS;
} ins_em_seg;

@interface INSEmPlayList : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithEmSegments:(NSArray<INSEmSegment*>*)emSegments;

@property(nonatomic, strong)NSArray<INSEmSegment*>* emSegments;

-(BOOL)mapClipSrcTime:(double)clipSrcTimeMs toSegmentSrcTime:(ins_em_seg*)segSrcTimeMs;
-(BOOL)mapSegmentSrcTime:(ins_em_seg)segSrcTimeMs toClipSrcTime:(double*)clipSrcTimeMs;

@end

NS_ASSUME_NONNULL_END
