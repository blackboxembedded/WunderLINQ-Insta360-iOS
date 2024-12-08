//
//  INSCameraStabilizer.h
//  INSCameraSDK
//
//  Created by HkwKelvin on 2020/8/26.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <INSCoreMedia/INSCoreMedia.h>
#import "INSCameraMediaSession.h"

NS_ASSUME_NONNULL_BEGIN

@class INSCameraStabilizerOptions;
@class INSCameraStabilizer;

@protocol INSCameraStabilizerDataSource <NSObject>

@optional

- (INSCameraStabilizerOptions *)stabilizationOptionsForStablilizer:(INSCameraStabilizer *)stabilizer;

- (double)gyroTimestampAjustForStablilizer:(INSCameraStabilizer *)stabilizer;

@end

@protocol INSCameraStabilizerDelegate <NSObject>

@optional

- (void)stabilizer:(INSCameraStabilizer *)stabilizer didStartWithGyroPlayer:(INSGyroPlayer *)gyroPlayer;

@end

@interface INSCameraStabilizerOptions : NSObject

@property (nonatomic, nullable) NSString *offset;

@property (nonatomic) INSCamera *camera;

@property (nonatomic) CGFloat ratio;

@property (nonatomic) BOOL isSelfies;

- (instancetype)initWithOffset:(nullable NSString *)offset;

- (instancetype)initWithOffset:(nullable NSString *)offset camera:(INSCamera *)camera ratio:(CGFloat)ratio;

@end

@interface INSCameraStabilizer : NSObject <INSCameraMediaPluggable>

@property (nonatomic, weak, nullable) id<INSCameraStabilizerDataSource> dataSource;

@property (nonatomic, weak, nullable) id<INSCameraStabilizerDelegate> delegate;

@property (nonatomic) double gyroTimestampAdjust;

@property (nonatomic, readonly) CGFloat frameRotate;

@property (nonatomic, readonly) INSGyroPlayMode gyroPlayMode;

@property (nonatomic, readonly) INSGyroRealtimePlayer *gyroPlayer;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithOptions:(INSCameraStabilizerOptions *)options;

- (void)updateWithOptions:(INSCameraStabilizerOptions *)options;

- (GLKQuaternion)getOriginOrientation:(double)timestamp;

- (float)fetchRealtimeMainRotationAngle;

- (void)stop;

+ (GLKQuaternion)getOrientationWithPlayerImageOrientaion:(GLKQuaternion)orientation renderType:(INSRenderType)renderType;

@end

NS_ASSUME_NONNULL_END
