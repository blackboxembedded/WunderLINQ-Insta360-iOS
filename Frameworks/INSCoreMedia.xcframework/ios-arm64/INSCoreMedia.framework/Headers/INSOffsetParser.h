//
//  INSOffsetParser.h
//  INSCoreMedia
//
//  Created by pengwx on 2018/11/15.
//  Copyright © 2018年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface INSOffsetParameter : NSObject

@property (nonatomic) double cx;
@property (nonatomic) double cy;
@property (nonatomic) double fx;
@property (nonatomic) double fy;
@property (nonatomic) double k1;
@property (nonatomic) double k2;
@property (nonatomic) double k3;

@end

@interface INSOffsetParser : NSObject

- (instancetype) initWithOffset:(NSString*)offset width:(int)width height:(int)height;

@property (nonatomic, strong, nullable) NSArray<INSOffsetParameter*> *parameters;

@end

NS_ASSUME_NONNULL_END
