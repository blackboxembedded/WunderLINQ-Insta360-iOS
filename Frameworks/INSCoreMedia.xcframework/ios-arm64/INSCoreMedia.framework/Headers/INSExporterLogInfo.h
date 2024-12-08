//
//  INSExporterLogInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2021/4/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSExporterLogState : NSObject

-(instancetype)initWithJsonDictionary:(NSDictionary *)dic;
-(NSDictionary*)serializeJsonDictionary;

@property(nonatomic)double time;
@property(nonatomic)double xFov;
@property(nonatomic)double distance;
@property(nonatomic)GLKQuaternion orientation;
@property(nonatomic)GLKQuaternion gyroOrientation;

@end


@interface INSExporterLogFileInfo : NSObject

-(instancetype)initWithJsonDictionary:(NSDictionary *)dic;
-(NSDictionary*)serializeJsonDictionary;

@property(nonatomic, copy)NSString* offset;
@property(nonatomic)double imageWidth;
@property(nonatomic)double imageHeight;

@end



@interface INSExporterLogInfo : NSObject

@property(nonatomic)CVPixelBufferRef pixelBuffer;
@property(nonatomic)CVPixelBufferRef rightPixelBuffer;

@property(nonatomic, strong)INSExporterLogState *stateInfo;

@end


@interface INSExporterLogStateInfo : NSObject

-(instancetype)initWithFileNames:(NSArray<NSString*>*)fileNames state:(INSExporterLogState*)state;
-(instancetype)initWithJsonDictionary:(NSDictionary *)dic;
-(NSDictionary*)serializeJsonDictionary;

@property(nonatomic, strong)NSArray<NSString*> *fileNames;
@property(nonatomic, strong)INSExporterLogState *state;

@end


NS_ASSUME_NONNULL_END
