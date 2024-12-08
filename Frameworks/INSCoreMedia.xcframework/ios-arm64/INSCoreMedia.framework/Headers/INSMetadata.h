//
//  INSMetadata.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/10/25.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kMetadataMakeKey;
extern NSString* const kMetadataModelKey;
extern NSString* const kMetadataSourceVideoCreateTime;

@interface INSMetadata : NSObject

@property (nonatomic, copy, nullable) NSString *make;           //拍摄来源（相机）
@property (nonatomic, copy, nullable) NSString *model;          //文件类型（子弹时间，freecapture，等）
@property (nonatomic, copy, nullable) NSString *sourceVideoCreateTime;

- (void) addValue:(NSString*)value forKey:(NSString*)key;
- (NSDictionary*) dictionary;

@end

NS_ASSUME_NONNULL_END
