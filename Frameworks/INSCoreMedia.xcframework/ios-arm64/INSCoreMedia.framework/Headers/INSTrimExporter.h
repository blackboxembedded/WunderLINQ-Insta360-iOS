//
//  INSTrimExporter.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/7/10.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import "INSExporter.h"

NS_ASSUME_NONNULL_BEGIN


@interface INSTrimRange :NSObject

@property(nonatomic, readonly)double startTimeMs;
@property(nonatomic, readonly)double endTimeMs;
-(instancetype)initWithStartTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs;

@end


@class INSEmSegment;
@class INSTimeMap;
@interface INSTrimExporter : INSExporter

- (instancetype) initWithInputURLs:(NSArray<NSURL*>*)inputURLs outputURLs:(NSArray<NSURL*>*)outputURLs startTimeMs:(double)startTimeMs endTimeMs:(double)endTimeMs;
- (instancetype) initWithInputURLs:(NSArray<NSURL*>*)inputURLs outputURLs:(NSArray<NSURL*>*)outputURLs trimRanges:(NSArray<INSTrimRange*>*)ranges;
- (instancetype) initWithInputEmSegments:(NSArray<INSEmSegment*>*)emSegments outputURLs:(NSArray<NSURL*>*)outputURLs trimRanges:(NSArray<INSTrimRange*>*)ranges;

@property(nonatomic, strong) NSArray<NSURL*>* inputURLs;
@property(nonatomic, strong) NSArray<NSURL*>* outputURLs;


/// trim时是否保留packet的原始pts，默认值NO
@property (nonatomic) BOOL retainPacketPts;

/// 强制4k视频兼容iPhone相册，默认NO
@property (nonatomic) BOOL force4KVideoCompatibleIPhoneAlbum;

///视频旋转信息，值类型 double ，当metaDataRotate设置为nil时，表示不使用自定义的metaDataRotate
@property (nonatomic, strong, nullable) NSNumber *metaDataRotate;


-(INSTimeMap*_Nullable)getTimeMap;


@end


NS_ASSUME_NONNULL_END
