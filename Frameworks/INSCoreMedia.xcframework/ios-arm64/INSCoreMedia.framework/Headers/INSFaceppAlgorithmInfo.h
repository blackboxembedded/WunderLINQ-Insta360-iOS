//
//  INSFaceppAlgorithmInfo.h
//  INSCoreMedia
//
//  Created by 那强 on 2019/10/6.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const INS_FACE_ABILITY_KEY_POSE3D;
extern NSString* const INS_FACE_ABILITY_KEY_EYE_STATUS;
extern NSString* const INS_FACE_ABILITY_KEY_MOUTH_SATUS;
extern NSString* const INS_FACE_ABILITY_KEY_MINORITY;
extern NSString* const INS_FACE_ABILITY_KEY_BLURNESS;
extern NSString* const INS_FACE_ABILITY_KEY_AGE_GENDER;
extern NSString* const INS_FACE_ABILITY_KEY_EXTRACT_FEATURE;
extern NSString* const INS_FACE_ABILITY_KEY_TRACK_FAST;
extern NSString* const INS_FACE_ABILITY_KEY_TRACK_ROBUST;
extern NSString* const INS_FACE_ABILITY_KEY_DETECT;
extern NSString* const INS_FACE_ABILITY_KEY_DETECT_RECT;
extern NSString* const INS_FACE_ABILITY_KEY_IDCARD_QUALITY;
extern NSString* const INS_FACE_ABILITY_KEY_TRACK;
extern NSString* const INS_FACE_ABILITY_KEY_TRACK_RECT;

@interface INSFaceppAlgorithmInfo : NSObject

/**
 SDK 版本号
 */
@property (nonatomic, copy, readonly) NSString *version;

/**
 SDK 过期时间
 */
@property (nonatomic, strong, readonly) NSDate *expireDate;


/**
 是否需要联网授权
 */
@property (nonatomic, assign, readonly) BOOL needNetLicense;


/**
 SDK 功能列表
 */
@property (nonatomic, strong, readonly) NSArray *SDKAbility;


/**
 SDK 限制的bundleId
 */
@property (nonatomic, strong, readonly) NSString *bundleId;

@end

NS_ASSUME_NONNULL_END
