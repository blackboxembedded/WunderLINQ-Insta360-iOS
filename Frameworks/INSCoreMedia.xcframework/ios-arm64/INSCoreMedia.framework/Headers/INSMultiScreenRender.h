//
//  INSMultiScreenRender.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/4.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSNormalRender.h"

typedef NS_ENUM(NSInteger, INSMultiScreenLayoutType){
    INSMultiScreenLayoutTypeHorizontal,
    INSMultiScreenLayoutTypeVertical,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSMultiScreenRender : INSRender


/// view1的显示模式，默认为：INSContentModeScaleToFill
@property(nonatomic)INSContentMode view1ContentMode;
@property(nonatomic)INSContentMode view2ContentMode;

//显示图片的原图区域，默认值CGRectMake(0, 0, 1.0, 1.0)
@property(nonatomic)CGRect view1ContentRect;
@property(nonatomic)CGRect view2ContentRect;


/// 视图布局方式，默认值INSMultiScreenLayoutTypeVertical，上下两个视图
@property(nonatomic)INSMultiScreenLayoutType layoutType;

/// 视图布局分界线，默认值0.5，
@property(nonatomic)float layoutLine;

/**
 默认值为(0.0, 0.0, 0.0, 1.0)
 */
@property (nonatomic) GLKVector4 contentBackgroundColor;

@end

NS_ASSUME_NONNULL_END
