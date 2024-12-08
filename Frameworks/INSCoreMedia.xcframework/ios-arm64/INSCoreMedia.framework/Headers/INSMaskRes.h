//
//  INSMaskRes.h
//  INSMediaApp
//
//  Created by pengwx on 16/12/6.
//  Copyright © 2016年 Insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSMaskRes : NSObject

- (instancetype) initWithName:(NSString*)name obtainImage:(UIImage*(^)(NSString* name))block;

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) UIImage*(^block)(NSString *name);

@end

NS_ASSUME_NONNULL_END
