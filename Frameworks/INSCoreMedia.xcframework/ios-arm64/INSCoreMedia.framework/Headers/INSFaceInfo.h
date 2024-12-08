//
//  INSFaceInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2019/7/6.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSFaceGender) {
    INSFaceGenderFemale = 0,
    INSFaceGenderMale = 1,
};

typedef NS_ENUM(NSInteger, INSFaceExpressionType) {
    INSFaceExpressionTypeAngry      = 0,   //!< Angry
    INSFaceExpressionTypeDisgust    = 1,   //!< Disgust
    INSFaceExpressionTypeFear       = 2,   //!< Fear
    INSFaceExpressionTypeHappy      = 3,   //!< Happy
    INSFaceExpressionTypeSad        = 4,   //!< Sad
    INSFaceExpressionTypeSurprise   = 5,   //!< Surprise
    INSFaceExpressionTypeNeutral    = 6,   //!< Neutral
    INSFaceExpressionTypeConfused   = 7,   //!< Confused
    INSFaceExpressionTypeUnknow     = 100,
};

@interface INSFaceInfo : NSObject

/** tracking ID */
@property (nonatomic, assign) NSInteger trackID;

/** 人脸的rect */
@property (nonatomic, assign) CGRect rect;

/** 该张人脸质量 */
@property (nonatomic, assign) CGFloat confidence;

/** 年龄 */
@property (nonatomic, assign) int age;
/** 性别 */
@property (nonatomic, assign) INSFaceGender gender;
/** 表情 */
@property (nonatomic, assign) INSFaceExpressionType expressionType;
/** 当前表情置信度 */
@property (nonatomic, assign) float expressionConfidence;
@end

NS_ASSUME_NONNULL_END
