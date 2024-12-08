//
//  INSGyroDataSource.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/5/16.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSExtraGyroData.h"

NS_ASSUME_NONNULL_BEGIN

//gyro数据接收协议
@protocol INSGyroReceiverProtocol <NSObject>

- (void)onGyroDataUpdate:(ins_gyro_info *)gyro;

@end

typedef NS_ENUM(NSUInteger, INSGyroDataSourceType) {
    INSGyroDataSourceTypeUnknown,
    INSGyroDataSourceTypeNano1iPhone,
    INSGyroDataSourceTypeNano12Gyro,
    INSGyroDataSourceTypeLiteGyro,
    INSGyroDataSourceTypeOne2Gyro,
    INSGyroDataSourceTypeEVOGyro,
    INSGyroDataSourceTypeWearableGyro,
    
    //ONER ONERS 577双鱼眼全景
    INSGyroDataSourceTypeOneRPano,
    
    //ONER ONERS 577广角 283广角
    INSGyroDataSourceTypeOneRWide,
    
    //ONER ONERS 577广角反插 283广角反插
    INSGyroDataSourceTypeOneRWideReverse,
    
    //ONER ONERS 577双鱼眼全景 反插
    INSGyroDataSourceTypeOneRPanoReverse,
    
    INSGyroDataSourceTypeOneX2,
    INSGyroDataSourceTypeOneX2Front,
    INSGyroDataSourceTypeOneX2Rear,
    INSGyroDataSourceTypeOneH,
    INSGyroDataSourceTypeGo2,
    
    //ONERS 283双鱼眼全景
    INSGyroDataSourceTypeOneRSFisheye,
    
    //ONERS 某镜头暂无信息
    INSGyroDataSourceTypeOneRSPantilt,
    
    //ONERS 283双鱼眼全景反插
    INSGyroDataSourceTypeOneRSFisheyeReverse,
    
    //ONERS 586广角
    INSGyroDataSourceTypeOneRSWide,
    
    //ONERS 586广角反插
    INSGyroDataSourceTypeOneRSWideReverse,
    
    //X3 586广角
    INSGyroDataSourceTypeX3,
    INSGyroDataSourceTypeX3Front,
    INSGyroDataSourceTypeX3Rear,
};

//gyro 数据源
@interface INSGyroDataSource : NSObject

@property (nonatomic, readonly) INSGyroDataSourceType sourceType;

- (void) openWithHandler:(void(^)(ins_gyro_info *info, NSError *error))handler;
- (void) close;
- (void) startGyroData:(id<INSGyroReceiverProtocol>)receiver;
- (void) stopGyroData:(id<INSGyroReceiverProtocol>)receiver;

@end

NS_ASSUME_NONNULL_END
