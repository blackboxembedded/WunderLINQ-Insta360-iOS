//
//  INSJsonSerializeAnimation.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/9/30.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSLookHerePoint;
@class INSScreenRecorder;
@interface INSJsonSerializeAnimation : NSObject

-(instancetype)initWithJsonData:(NSData*)data;
-(instancetype)initWithJsonDictionary:(NSDictionary*)dic;
-(instancetype)initWithFreecaputre:(NSArray<INSScreenRecorder*>* _Nullable)recorders lookHerePoints:(NSArray<INSLookHerePoint*>* _Nullable)lookHerePoints;
-(NSData*_Nullable)serializeJsonData;
-(NSDictionary*_Nullable)serializeJsonDictionary;

@property(nonatomic, strong, nullable)NSArray<INSScreenRecorder*> *recorders;
@property(nonatomic, strong, nullable)NSArray<INSLookHerePoint*> *lookHerePoints;

@end

NS_ASSUME_NONNULL_END
