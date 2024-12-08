//
//  INSCameraMediaBasic.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/10/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>

#ifndef INSCameraMediaBasic_H
#define INSCameraMediaBasic_H

CF_EXTERN_C_BEGIN

struct INSVideoResolution {
    NSInteger width;
    NSInteger height;
    NSInteger fps;
};

typedef struct INSVideoResolution INSVideoResolution;

CF_EXPORT const INSVideoResolution INSVideoResolutionZero;

/// @available NANO
CF_EXPORT const INSVideoResolution INSVideoResolution2160x1080x30;

/// @available ONE, Nano S, ONE X, EVO, ONE R (4K)
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x30;

/// @available ONE, Nano, Nano S, OneX, EVO, ONE R (1280P)
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1280x30;

/// @available ONE, Nano, Nano S, OneX, EVO, ONE R (960P)
CF_EXPORT const INSVideoResolution INSVideoResolution1920x960x30;

/// @available ONE
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1280x60;

/// @available ONE
CF_EXPORT const INSVideoResolution INSVideoResolution2048x512x120;

/// @available ONE
CF_EXPORT const INSVideoResolution INSVideoResolution3328x832x60;

/// @available Nano S
CF_EXPORT const INSVideoResolution INSVideoResolution3072x1536x30;

/// @available Nano S
CF_EXPORT const INSVideoResolution INSVideoResolution2240x1120x30;

/// @available Nano S
CF_EXPORT const INSVideoResolution INSVideoResolution2240x1120x24;

/// @available Nano S, One X, EVO, ONE R (720P)
CF_EXPORT const INSVideoResolution INSVideoResolution1440x720x30;

/// @available ONE X, EVO, ONE R (5.7K)
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x30;

/// @available ONE X, EVO, ONE R (5.7K)
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x25;

/// @available ONE X, EVO, ONE R (5.7K)
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x24;

/// @available ONE X, EVO, ONE R (4K)
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x60;

/// @available ONE X, EVO, ONE R (4K)
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x50;

/// @available ONE X, EVO, ONE R (3K)
CF_EXPORT const INSVideoResolution INSVideoResolution3008x1504x100;

/// @available X3 (3K)
CF_EXPORT const INSVideoResolution INSVideoResolution2944x736x180;

/// @available X4 (3K)
CF_EXPORT const INSVideoResolution INSVideoResolution3040x760x240;

/// @available ONE X, EVO, ONE R Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution960x480x30;

/// @available ONE X, EVO, ONE R (3K)
CF_EXPORT const INSVideoResolution INSVideoResolution3040x1520x30;

/// @available ONE X, EVO, ONE R (1080P)
CF_EXPORT const INSVideoResolution INSVideoResolution2176x1088x30;

/// @available ONE X, EVO, ONE R Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution720x360x30;

/// @available ONE X, EVO, ONE R Secondary Stream(using)
CF_EXPORT const INSVideoResolution INSVideoResolution480x240x30;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution640x320x30;

/// @available GO3 Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution640x640x30;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution640x320x15;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution640x320x8;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution1024x512x30;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution1024x512x15;

/// @available ONE X Secondary Stream(reserved)
CF_EXPORT const INSVideoResolution INSVideoResolution1024x512x8;

/// @available GO
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2720x25;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x60;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x100;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x200;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x240;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x120;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution5472x3078x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x48;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x50;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x60;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution854x640x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution720x406x30;

/// @available ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution424x240x15;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution5312x2988x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x60;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x60;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1280x720x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1280x960x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1152x768x30;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution5312x2988x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution5312x2988x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution4000x3000x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x24;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x25;

/// @arailable ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x24;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x60;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x60;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x1920x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x60;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x1920x60;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x60;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x25;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x25;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x25;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution720x1280x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution960x1280x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1152x1152x30;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution640x360x30;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution640x480x30;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution360x640x30;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution480x640x30;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution368x368x30;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x15;

/// @arailable ONE X2 Secondary Stream
CF_EXPORT const INSVideoResolution INSVideoResolution1440x720x15;

/// @arailable GO2
CF_EXPORT const INSVideoResolution INSVideoResolution854x854x30;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x50;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x50;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x50;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x50;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x24;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x24;

/// @arailable ONE X2, GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x24;

/// @arailable ONE X2
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x120;

/// @arailable ONE GO2
CF_EXPORT const INSVideoResolution INSVideoResolution1280x1280x30;

/// @arailable ONE ONE R
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x50;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution1280x1280x25;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3040x3040x24;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3040x3040x25;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3040x3040x30;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x24;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x25;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3920x1920x30;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3040x1520x50;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x50;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5312x3552x24;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5312x3552x25;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5312x3552x30;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5472x2328x24;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5472x2328x25;

/// @arailable ONE R, ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution5472x2328x30;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution1760x990x30;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution1600x900x30;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1634x30;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1634x25;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1634x24;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution6720x2856x25;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution6720x2856x24;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution6016x2560x25;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution6016x2560x24;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3200x3200x25;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3200x3200x24;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3200x3200x30;

/// @arailable ONE RS

CF_EXPORT const INSVideoResolution INSVideoResolution3072x3072x25;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3072x3072x24;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution3072x3072x30;

/// @arailable ONE RS
CF_EXPORT const INSVideoResolution INSVideoResolution2944x2880x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2944x2944x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2944x2944x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2944x2944x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3840x960x120;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2160x3840x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2160x3840x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2160x3840x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2160x3840x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2160x3840x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x100;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1080x100;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1080x1920x100;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3456x1944x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3456x1944x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3456x1944x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3456x1944x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3456x1944x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1944x3456x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1944x3456x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1944x3456x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3840x3840x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3840x3840x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3840x3840x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2400x3584x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2400x3584x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2400x3584x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2016x3584x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2016x3584x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2016x3584x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2016x3584x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2016x3584x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3584x2016x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3584x2016x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3584x2016x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3584x2016x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution3584x2016x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2880x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2880x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2880x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2880x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2880x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x1440x24;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x1440x25;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x1440x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x1440x50;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x1440x60;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1472x1472x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution2880x720x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1152x648x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution648x1152x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution1152x864x30;

/// @available X3
CF_EXPORT const INSVideoResolution INSVideoResolution864x1152x30;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x4320x30;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x4320x24;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x4320x25;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x3268x25;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x3268x30;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x3272x24;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution4032x3024x24;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution4032x3024x25;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution4032x3024x30;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution4032x3024x50;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution4032x3024x60;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x24;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x25;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x30;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x50;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x60;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x100;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2688x1520x120;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x120;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x60;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2040x50;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution2720x1530x120;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x50;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution7680x3268x24;

/// @available PSC56
CF_EXPORT const INSVideoResolution INSVideoResolution3840x2160x100;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x1;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x2;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x5;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution2560x1440x15;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x1;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x2;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x5;

/// @available GO3
CF_EXPORT const INSVideoResolution INSVideoResolution1440x2560x15;
 
/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x3456x30;

/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x3456x25;

/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x3456x24;

/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x2614x30;

/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x2614x25;

/// @available IAC1
CF_EXPORT const INSVideoResolution INSVideoResolution6144x2614x24;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution5120x5120x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution5632x5632x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution3840x1920x100;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x50;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2880x2880x60;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1440x240;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x120;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x60;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x50;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x25;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1920x1920x24;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1530x2720x120;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x24;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x25;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x48;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x50;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2040x2720x60;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution3000x4000x24;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution3000x4000x25;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution3000x4000x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution5760x1440x120;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2720x60;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2720x50;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2720x30;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution2720x2720x24;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1440x1920x50;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1440x1920x25;

/// @available X4
CF_EXPORT const INSVideoResolution INSVideoResolution1440x1920x24;
/**
 *  it is recommended to call this function to generate INSVideoResolution
 *
 *  @param width  display dimension width
 *  @param height display dimension height, half of width
 *  @param fps    frames per second, 15, 30
 *
 *  @return video resolution
 */
CF_INLINE INSVideoResolution INSMakeVideoResolution(NSInteger width, NSInteger height, NSInteger fps) {
    INSVideoResolution resolution;
    resolution.width = width;
    resolution.height = height;
    resolution.fps = fps;
    return resolution;
}

CF_INLINE BOOL INSVideoResolutionEqualToResolution(INSVideoResolution resolution1, INSVideoResolution resolution2) {
    if (resolution1.width == resolution2.width &&
        resolution1.height == resolution2.height &&
        resolution1.fps == resolution2.fps) {
        return YES;
    }
    return NO;
}

CF_EXPORT void INSVideoResolutionGetImageDimension(INSVideoResolution resolution, NSInteger *width, NSInteger *height);

typedef NS_ENUM(NSUInteger, INSPreviewStreamType) {
    INSPreviewStreamTypeMain,
    INSPreviewStreamTypeSecondary,
};

typedef NS_ENUM(NSUInteger, INSPreviewStreamRotation) {
    INSPreviewStreamRotationNone = 0,
    INSPreviewStreamRotationHorizon180,
};

typedef NS_ENUM(NSUInteger, INSPreviewStreamFlag) {
    INSPreviewStreamFlagDefault,
    INSPreviewStreamFlagLive,
};

CF_EXPORT NSInteger INSPreviewStreamTypeToValue(INSPreviewStreamType previewStream);
CF_EXPORT INSPreviewStreamType INSPreviewStreamTypeWithValue(NSInteger previewStream);

struct INSPhotoSize {
    NSInteger width;
    NSInteger height;
};

typedef struct INSPhotoSize INSPhotoSize;

/// @available ONE
CF_EXPORT const INSPhotoSize INSPhotoSize6912x3456;

/// @available Nano S
CF_EXPORT const INSPhotoSize INSPhotoSize6272x3136;

/// @available ONE X
CF_EXPORT const INSPhotoSize INSPhotoSize6080x3040;

/// @available Go
CF_EXPORT const INSPhotoSize INSPhotoSize3040x3040;

/// @available ONE R
CF_EXPORT const INSPhotoSize INSPhotoSize4000x3000;

/// @available ONE R
CF_EXPORT const INSPhotoSize INSPhotoSize4000x2250;

/// @available ONE R
CF_EXPORT const INSPhotoSize INSPhotoSize5212x3542;

/// @available ONE R
CF_EXPORT const INSPhotoSize INSPhotoSize5312x2988;

/// @available ONE RS
CF_EXPORT const INSPhotoSize INSPhotoSize8000x6000;

/// @available ONE RS
CF_EXPORT const INSPhotoSize INSPhotoSize8000x4500;

/// @available ONE RS
CF_EXPORT const INSPhotoSize INSPhotoSize2976x2976;

/// @available ONE RS
CF_EXPORT const INSPhotoSize INSPhotoSize5984x5984;

/// @available X3
CF_EXPORT const INSPhotoSize INSPhotoSize11968x5984;

/// @available X3
CF_EXPORT const INSPhotoSize INSPhotoSize5952x2976;


CF_INLINE INSPhotoSize INSMakePhotoSize(NSInteger width, NSInteger height) {
    INSPhotoSize photoSize = {.width = width, .height = height};
    return photoSize;
}

typedef NS_ENUM(NSUInteger, INSMediaDataType) {
    INSMediaDataTypeVideo,
    INSMediaDataTypeAudio,
    INSMediaDataTypeGyro,
};

typedef NS_ENUM(NSUInteger, INSAudioSampleRate) {
    INSAudioSampleRate48000Hz,
    
    /// @available ONE, Nano S, NANO(firmware version > v1.43_0190)
    INSAudioSampleRate44100Hz,
};

CF_EXPORT NSInteger INSAudioSampleRateToValue(INSAudioSampleRate sampleRate);
CF_EXPORT INSAudioSampleRate INSAudioSampleRateWithValue(NSInteger sampleRate);

typedef NS_ENUM(NSUInteger, INSAudioFormat) {
    INSAudioFormatAACRaw,
    INSAudioFormatAACAdts,
};

typedef NS_ENUM(NSUInteger, INSVideoEncode) {
    INSVideoEncodeH264 = 0,
    INSVideoEncodeH265,
};

struct INSOriginOffset {
    int32_t radius1;
    int32_t cx1;
    int32_t cy1;
    int32_t radius2;
    int32_t cx2;
    int32_t cy2;
    uint16_t width;
    uint16_t height;
};

typedef struct INSOriginOffset INSOriginOffset;

struct INSNanoLensOffset {
    int32_t r_offset;
    int32_t x_offset;
    int32_t y_offset;
    int32_t yaw_angle;
    int32_t pitch_angle;
    int32_t roll_angle;
    int32_t Reserved0;
    int32_t Reserved1;
};

typedef struct INSNanoLensOffset INSNanoLensOffset;

#define INS_SENSOR_NUMBER_MAX				(2)

struct INSMediaOffset {
    uint16_t media_width;
    uint16_t media_height;
    uint32_t lens_index;
    uint8_t  sensor_number;
    uint8_t  Reserved0;
    uint16_t Reserved1;
    uint32_t Reserved2;
    INSNanoLensOffset sensor[INS_SENSOR_NUMBER_MAX];
};

typedef struct INSMediaOffset INSMediaOffset;

CF_EXPORT NSString *insMediaOffsetStringFromINSMediaOffset(INSMediaOffset mediaOffset);

CF_EXPORT INSMediaOffset insGetMediaOffsetFromOffset(NSString *offset);

CF_EXPORT INSOriginOffset insGetOriginOffsetFromOffset(NSString *offset);

typedef NS_ENUM(NSUInteger, INSFileMndType) {
    /// 所有文件尾数据，包括总大小、版本、UUID等， 通过[INSExtraInfo initWithExtraInfoData] 来解析
    INSFileMndTypeAll = 0,
    
    /// 文件尾的metadata 数据，返回的数据为序列化过的 ExtraMetada
    INSFileMndTypeMetadata = 1,
    
    /// 图片/视频的缩略图, CameraVersion > Nano 2
    INSFileMndTypeThumbnail = 2,
    
    /// 陀螺仪数据 {{ts|ax|ay|az|gx|gy|gz},{ts|ax|ay|az|gx|gy|gz} ...}
    INSFileMndTypeGyro = 3,
    
    /// 曝光数据
    INSFileMndTypeExposure = 4,
    
    /// 文件尾的metadata 数据 5.7k另一个数据
    INSFileMndTypeExtThumbnail = 5,
    
    /// timelapse每帧的时间戳数据 {{timestamp} ... }
    INSFileMndTypeFramePts = 6,
    
    /// gps数据{{timestamp_s, timestamp_ms, valid, latitude, n_s, longitude, e_w, ground_speed, ground_crouse, altitude } ... }
    INSFileMndTypeGps = 7,
    ///高光数据
    INSFileMndTypeHighlight = 10,
    /// 机内分析数据
    INSFileMndTypeEditor = 18,
};

typedef NS_ENUM(NSUInteger, INSCameraVideoOutputType) {
    INSCameraVideoOutputTypeFishEyeH264,
    INSCameraVideoOutputTypeFishEyePixelBuffer,
    INSCameraVideoOutputTypePlayerImage,
    INSCameraVideoOutputTypeFlatPixelBuffer,
};

typedef NS_ENUM(NSUInteger, INSStorageCardLocation) {
    INSStorageCardLocationCamera = 0,
    INSStorageCardLocationReader = 1,
};

CF_EXTERN_C_END

#endif /* INSCameraMediaBasic_H */
