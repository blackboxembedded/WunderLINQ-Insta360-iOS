//
//  INSMotionData.h
//  INSMediaApp
//
//  Created by pengwx on 5/16/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>




/**
 *  gps data
 */
typedef struct
{
    double latitude;
    double longitude;
    double altitude;
} gps_media_data;


//陀螺仪数据
typedef struct
{
    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
} gyro_media_data;


