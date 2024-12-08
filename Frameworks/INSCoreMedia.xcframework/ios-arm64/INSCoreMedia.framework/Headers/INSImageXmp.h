//
//  INSImageXmp.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/10/26.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSMediaGyro;

@interface INSImageXmp : NSObject

- (instancetype) initDefaultWithWidth:(NSInteger)width height:(NSInteger)height cameraType:(NSString*_Nullable)cameraType ;

@property (nonatomic, copy, nullable) NSString *projectionType;
@property (nonatomic, strong, nullable) NSNumber *croppedAreaImageWidthPixels;        //int
@property (nonatomic, strong, nullable) NSNumber *croppedAreaImageHeightPixels;       //int
@property (nonatomic, strong, nullable) NSNumber *fullPanoWidthPixels;                //int
@property (nonatomic, strong, nullable) NSNumber *fullPanoHeightPixels;               //int
@property (nonatomic, strong, nullable) NSNumber *croppedAreaLeftPixels;              //int
@property (nonatomic, strong, nullable) NSNumber *croppedAreaTopPixels;               //int
@property (nonatomic, strong, nullable) NSNumber *initialViewVerticalFOVDegrees;      //int
@property (nonatomic, strong, nullable) NSNumber* initialHorizontalFOVDegrees;        //int
@property (nonatomic, strong, nullable) NSNumber *poseHeadingDegrees;                 //float
@property (nonatomic, strong, nullable) NSNumber *posePitchDegrees;                   //float
@property (nonatomic, strong, nullable) NSNumber *poseRollDegrees;                    //float
@property (nonatomic, copy, nullable) NSString *usePanoramaViewer;
@property (nonatomic, copy, nullable) NSString* captureSoftware;
@property (nonatomic, copy, nullable) NSString* stitchingSoftware;
@property (nonatomic, copy, nullable) NSString* sourceImageCreateTime;
@property (nonatomic, copy, nullable) NSString* logoLocation;
@property (nonatomic, strong, nullable) INSMediaGyro *gyroData;
@end

NS_ASSUME_NONNULL_END
