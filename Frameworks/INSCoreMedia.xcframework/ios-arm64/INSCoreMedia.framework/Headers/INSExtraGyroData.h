//
//  INSExtraGyroData.h
//  INSCoreMedia
//
//  Created by pengwx on 17/3/23.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSExtraMetadata.h"
#import "INSExtraTimeMapperData.h"

CF_EXTERN_C_BEGIN

struct ins_gyro_info {
    int64_t timestamp;      //millisecond
    double gravity_x;
    double gravity_y;
    double gravity_z;
    double rotation_x;
    double rotation_y;
    double rotation_z;
};

#pragma pack(1)
struct ins_gyro_info_raw {
    int64_t timestamp;      //microsecond
    uint16_t gravity_x;
    uint16_t gravity_y;
    uint16_t gravity_z;
    uint16_t rotation_x;
    uint16_t rotation_y;
    uint16_t rotation_z;
//    uint16_t accel[3];
//    uint16_t gyro[3];
};
#pragma pack()

typedef struct ins_gyro_info ins_gyro_info;

typedef struct ins_gyro_info_raw ins_gyro_info_raw;

/// 将ONE 的陀螺仪数据转为标准坐标系的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_to_one_coord(ins_gyro_info gyro_info);

/// 将标准坐标系的陀螺仪数据转为ONE 的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_from_one_coord(ins_gyro_info gyro_info);

/// 将ONE2 的陀螺仪数据转为标准坐标系的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_to_one2_coord(ins_gyro_info gyro_info);

/// 将标准坐标系的陀螺仪数据转为ONE2 的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_from_one2_coord(ins_gyro_info gyro_info);

/// 将EVO 的陀螺仪数据转为标准坐标系的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_to_evo_coord(ins_gyro_info gyro_info);

/// 将标准坐标系的陀螺仪数据转为EVO 的数据， 以Nano 插着手机的时候为标准坐标系
CF_EXPORT ins_gyro_info ins_gyro_convert_from_evo_coord(ins_gyro_info gyro_info);

CF_EXPORT ins_gyro_info ins_gyro_from_raw(ins_gyro_info_raw gyro_info_raw, double acc_range, double gyro_range, bool use_range);

CF_EXPORT ins_gyro_info_raw raw_from_gyro_info(ins_gyro_info gyro_info, double acc_range, double gyro_range, bool use_range);

CF_EXTERN_C_END

//陀螺仪数据类型，不同硬件不一样
typedef NS_ENUM(NSInteger, INSGyroDataType){
    INSGyroDataTypeNano         = 0,
    INSGyroDataTypeNano2        = 1,
    INSGyroDataTypeAir          = 2,
    INSGyroDataTypeAir2         = 3,
    INSGyroDataTypeOne2         = 4,
    INSGyroDataTypeEVO          = 5,
    INSGyroDataTypeWearable     = 6,
    
    //ONER ONERS 577双鱼眼全景
    INSGyroDataTypeOneRPano     = 7,
    
    //ONER ONERS 577广角 283广角
    INSGyroDataTypeOneRWide     = 8,
    
    //ONER ONERS 577广角反插 283广角反插
    INSGyroDataTypeOneRWideReverse  = 9,
    
    //ONER ONERS 577双鱼眼全景 反插
    INSGyroDataTypeOneRPanoReverse  = 10,
    INSGyroDataTypeOneX2 = 11,                      //ONEX2 fisheye
    INSGyroDataTypeOneX2Front = 12,                 //ONEX2 left
    INSGyroDataTypeOneX2Rear = 13,                  //ONEX2 right
    INSGyroDataTypeOneH = 14,
    INSGyroDataTypeGo2 = 15,
    
    //ONERS 283双鱼眼全景
    INSGyroDataTypeOneRSFisheye = 16,
    
    //ONERS 某镜头暂无信息
    INSGyroDataTypeOneRSPantilt = 17,
    
    //ONERS 283双鱼眼全景反插
    INSGyroDataTypeOneRSFisheyeReverse = 18,
    
    //ONERS 586广角
    INSGyroDataTypeOneRSWide = 19,
    
    //ONERS 586广角反插
    INSGyroDataTypeOneRSWideReverse = 20,
    
    //X3 586双鱼眼
    INSGyroDataTypeX3 = 21,
    INSGyroDataTypeX3Front = 22,
    INSGyroDataTypeX3Rear = 23,
};

typedef NS_ENUM (NSInteger, INSGyroDataBinaryFormat) {
    INSGyroDataBinaryFormatCommon = 0,  //ins_gyro_info
    INSGyroDataBinaryFormatRaw,         //ins_gyro_info_raw
};

NS_ASSUME_NONNULL_BEGIN

@interface INSExtraGyroFileInfo : NSObject

@property (nonatomic) NSURL *url;                           //gyro所在的文件路径

@property (nonatomic) NSUInteger location;                  // gyro数据在整个文件中的位置

@property (nonatomic) NSUInteger length;                    //二进制数据的长度

@property (nullable, nonatomic) NSData *firstGyroData;      //ins_gyro_info二进制数据

@property (nonatomic) INSSubMediaType mediaType;            //存储了文件类型

@end


@interface INSExtraGyroData : NSObject

/// gyro_info二进制数据
@property (nonatomic,nullable) NSData *gyroData;

/// 双路gyro_info二进制数据
@property (nonatomic,nullable) NSData *gyroDataExt;

/// exposure binary data
@property (nonatomic, nullable) NSData *exposureData;

/// exposure binary data, only timelapse video has this.
@property (nonatomic, nullable) NSData *framePtsData;

/// gyro 数据类型， 必须配置，根据镜头类型
@property (nonatomic) INSGyroDataType type;

/// gyro 二进制格式
@property (nonatomic) INSGyroDataBinaryFormat format;

/// 视频帧对应的时间戳, 必须配置，一般是第一帧视频的时间戳，单位 毫秒; 无论format值
@property (nonatomic) double timeOffset;

/// ins_gyro_info or ins_gyro_info_raw数据的数量
@property (nonatomic, readonly) int count;

/// 单个陀螺仪数据所占的字节数
@property (nonatomic, readonly) int singleGyroSize;

//如果多段trim生成的视频文件，则这里解析出新视频的解码时间戳与原始视频的解码时间戳的映射数据
@property (nullable, nonatomic) INSExtraTimeMapperData *timeMapperData;

//记录gyro文件的存储信息， 只有timelapse视频，且陀螺仪数据大于150M时，通过解析文件尾才会被赋值
@property (nonatomic, nullable) INSExtraGyroFileInfo *gyroFileInfo;

// 陀螺仪数据是否过大，需要流式传输， 默认为NO ，当gyroFileInfo != nil 时，该值一定为YES
@property (nonatomic) BOOL gyroDataOverflow;

/// Deprecated 是否应用gyro防抖, 默认是YES， 可忽略
@property (nonatomic) BOOL isApply;

/// 文件尾记录的取整帧率，如果是30的整数倍，在使用该值计算frameindex时， frameIndex = 1000 / (frameRate * (1000.0 / 1001.0))
@property (nonatomic) NSInteger roundedFrameRate;

/// 视频时长，默认文件尾解析之后，会读取固件在文件尾写入的值，不够精确但是够用，也可以外部设置精确值进来
@property (nonatomic) NSInteger totalDurationMs;

/// 文件尾记录的在曝光数据中查找时间戳的方式
@property (nonatomic) INSVideoPtsMapType ptsMapType;


@property (nonatomic, nullable) INSDynamicGyroAccRangeInfo *dynamicGyroAccRangeInfo;

/// 是否是双路陀螺仪数据
@property (nonatomic) BOOL hasSecondary;

// 最好是通过INSVideoInfoParser获取该值，如果你要自行创建该对象，调用该方法初始化，且需要显式配置timeOffset，type，count等属性
- (instancetype)initWithGyroData:(NSData * _Nullable)gyroData;
- (instancetype)initWithGyroData:(NSData * _Nullable)gyroData type:(INSGyroDataType)type format:(INSGyroDataBinaryFormat)format;

- (nullable INSExtraGyroData *)trimWithLeft:(int64_t)leftTimestamp right:(int64_t)rightTimestamp over:(int64_t)over;
- (nullable INSExtraGyroData *)trimToIndex:(int)index;

- (BOOL)firstGyroDataInfo:(ins_gyro_info *)info;

@end

NS_ASSUME_NONNULL_END
