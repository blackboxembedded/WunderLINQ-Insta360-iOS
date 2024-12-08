//
//  INSCameraError.h
//  INSCameraSDK
//
//  Created by zeng bin on 4/5/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#ifndef INSCameraError_h
#define INSCameraError_h

#import <Foundation/Foundation.h>

extern NSString *const INSCameraSDKErrorDomain;

typedef NS_ENUM(NSUInteger, INSCameraErrorCode) {
    /// ok
    INSCameraErrorCodeOK = 200,
    
    /// accepted
    INSCameraErrorCodeAccept = 202,
    
    /// mainly means redirection
    INSCameraErrorCodeMovedTemporarily = 302,
    
    /// bad request, check your params
    INSCameraErrorCodeBadRequest = 400,
    
    /// the command has timed out
    INSCameraErrorCodeTimeout = 408,
    
    /// the requests are sent too often
    INSCameraErrorCodeTooManyRequests = 429,
    
    /// request is interrupted and no response has been gotten
    INSCameraErrorCodeNoResopnse = 444,
    
    INSCameraErrorCodeShakeHandeError = 445,
    
    INSCameraErrorCodePairError = 446,
    
    /// error on camera
    INSCameraErrorCodeInternalServerError = 500,
    
    /// the command is not implemented for this camera or firmware
    INSCameraErrorCodeNotImplemented = 501,
    
    /// there is no connection
    INSCameraErrorCodeNoConnection = 503,
    
    /// firmware error
    INSCameraErrorCodeFirmwareError = 504,
};

@interface NSError (INSCameraSDK)

+ (instancetype)errorWithINSCode:(NSInteger)code userInfo:(NSDictionary *)dict;

@end

#endif /* INSCameraError_h */
