//
//  INSImageExif.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/10/26.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMediaGps;

@interface INSImageExif : NSObject

- (instancetype) initDefaultWithWidth:(NSInteger)width height:(NSInteger)height cameraType:(NSString*_Nullable)cameraType;

@property (nonatomic, copy, nullable) NSString *make;
@property (nonatomic, copy, nullable) NSString *model;
@property (nonatomic, strong, nullable) NSNumber *orientation;                //int
@property (nonatomic, strong, nullable) NSNumber *xResolution;                //int
@property (nonatomic, strong, nullable) NSNumber *yResolution;                //int
@property (nonatomic, strong, nullable) NSNumber *resolutionUnit;             //int
@property (nonatomic, copy, nullable) NSString *software;
@property (nonatomic, strong, nullable) NSNumber *pixelXDimension;            //int
@property (nonatomic, strong, nullable) NSNumber *pixelYDimension;            //int
@property (nonatomic, copy, nullable) NSString *copyright;
@property (nonatomic, strong, nullable) INSMediaGps *gps;
@property (nonatomic, copy, nullable) NSString *createTime;

@end

NS_ASSUME_NONNULL_END

