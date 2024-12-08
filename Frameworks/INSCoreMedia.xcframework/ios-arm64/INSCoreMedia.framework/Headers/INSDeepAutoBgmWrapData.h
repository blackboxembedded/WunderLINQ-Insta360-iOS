//
//  INSDeepAutoBgmWrapData.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/23.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSDeepAutoBgmWrapData : NSObject

@end

@interface INSDeepAutoBgmConfiguration : NSObject

/// 与render的尺寸相同， 设置为640
@property (nonatomic) int frameWidth;

/// 与render的尺寸相同， 设置为640
@property (nonatomic) int frameHeight;

// 是否开debug，默认为NO
@property (nonatomic) BOOL visualDebug;

// 调试的文件夹路径，可以把渲染的图存到这里，默认为""
@property (nonatomic) NSString *debugDirPath;

@end


@interface INSDeepAutoBgmOutputConfig : NSObject

/// 默认为2 现在已经失效
@property (nonatomic) int fetchTopK;

@end

@interface INSDeepAutoBgmLabel : NSObject<NSCoding, NSCopying, NSMutableCopying>

// label's confidence
@property(nonatomic) CGFloat confidence;
// label's name
@property(nonatomic) NSString *name;

// only for binary classification 暂时对上层无用
@property(nonatomic) BOOL binaryFlag;

@end

@interface INSDeepAutoBgmResult : NSObject<NSCoding, NSCopying, NSMutableCopying>

/// 识别信息数组，一定不为nil，但是count可能为0
@property(nonatomic) NSArray<INSDeepAutoBgmLabel *> *labels;

@end

NS_ASSUME_NONNULL_END
