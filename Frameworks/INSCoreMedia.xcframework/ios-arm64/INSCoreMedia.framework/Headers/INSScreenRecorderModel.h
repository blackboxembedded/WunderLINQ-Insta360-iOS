//
//  INSScreenRecorderModel.h
//  INSCoreMedia
//
//  Created by HFY on 2020/4/7.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN


/// somen extra property for model property
@interface INSRecorderModelProperty : NSObject <NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) CGRect targetFlatROI;

@property (nonatomic) CGPoint targetFlatPoint;

@end

@interface INSScreenRecorderModel : NSObject <NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) double timestamp;

@property (nonatomic) double srcRepeatTimeMs;

@property (nonatomic) CGRect targetScreenROI;

@property (nonatomic) float xFov;

@property (nonatomic) float distance;

@property (nonatomic) GLKQuaternion orientation;

@property (nonatomic) INSRecorderModelProperty *property;


-(NSDictionary*)jsonDictionary;

+ (id _Nullable) modelWithJsonDictionary:(NSDictionary*)dic;

+(INSScreenRecorderModel*)slerpModelLeft:(INSScreenRecorderModel*)left right:(INSScreenRecorderModel*)right ratio:(double)ratio;

@end


NS_ASSUME_NONNULL_END
