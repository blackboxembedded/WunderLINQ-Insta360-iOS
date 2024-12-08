//
//  INSJsonSerializeMultiview.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/9/28.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSJsonSerializeMultiview : NSObject

-(instancetype)initWithSerializeData:(NSData *)data;
-(instancetype)initWithJsonDictionary:(NSDictionary*)dic;
-(NSData* _Nullable)serializeJsonData;
-(NSDictionary* _Nullable)serializeJsonDictionary;
@property(nonatomic, copy, nullable)NSString *name;
@property(nonatomic, strong, nullable)NSArray *views;

@end

NS_ASSUME_NONNULL_END
