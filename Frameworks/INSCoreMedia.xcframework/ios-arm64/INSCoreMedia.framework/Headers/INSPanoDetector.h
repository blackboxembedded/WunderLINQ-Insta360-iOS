//
//  INSPanoDetector.h
//  INSCoreMedia
//
//  Created by HFY on 2022/1/24.
//  Copyright © 2022 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>



NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, INSPanoDetectorErrorCode) {
    INSPanoDetectorErrorCodeDetectorInit = -10,
    INSPanoDetectorErrorCodeMultiDetectorInit = -11,
    INSPanoDetectorErrorCodeEmptyMat = -12,
    INSPanoDetectorErrorCodeDetectionEmpty = -13,
    INSPanoDetectorErrorCodeRenderNull = -14,
    INSPanoDetectorErrorCodeInputFrameEmpty = -15,
    INSPanoDetectorErrorCodeDectorNull = -16,
    INSPanoDetectorErrorCodeTargetEmpty = -17,
};

typedef NS_ENUM(NSInteger, INSPanoDetectType) {
    INSPanoDetectTypeMNNDetectionContext = 0,
    INSPanoDetectTypeMNNYolov3Detect = 1,
};


@interface INSPanoDetectorConfig : NSObject

-(instancetype)initWithImageWidth:(int)width height:(int)height;

@property(nonatomic, copy)NSString *modelPath;
@property(nonatomic)int imageWidth;
@property(nonatomic)int imageHeight;

/// 默认值 0.75
@property(nonatomic)float detectThresh;

/// 默认值INSPanoDetectTypeMNNDetectionContext
@property(nonatomic)INSPanoDetectType detectType;


@end


@interface INSPanoDetectorRange : NSObject

-(instancetype)initWithSphericalOrientation:(GLKQuaternion)orientation;

@property(nonatomic)GLKQuaternion orientation;

/// 检测方向，默认值180度
@property(nonatomic)float targetAngle;

/// 在检测方向上的检测范围，默认值30度
@property(nonatomic)float rangeAngle;

/// 调试开关，默认值NO
@property(nonatomic)BOOL debug;

/// 调试输出目录，默认值nil
@property(nonatomic, copy, nullable)NSString *debugDir;

@end


@interface INSPanoDetectorResult : NSObject
@property(nonatomic)GLKQuaternion orientation;
@end



@interface INSPanoDetector : NSObject

-(instancetype)initWithConfig:(INSPanoDetectorConfig*)config;

-(NSArray<INSPanoDetectorResult*>*)detect:(CVPixelBufferRef)pixelBuffer range:(INSPanoDetectorRange*)range error:(NSError * _Nullable * _Nullable)errorPtr;


@property(nonatomic, strong)INSPanoDetectorConfig *config;

@end

NS_ASSUME_NONNULL_END
