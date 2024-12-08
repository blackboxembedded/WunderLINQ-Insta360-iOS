//
//  INSRemovePerson2.h
//  INSCoreMedia
//
//  Created by HFY on 2020/11/4.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface INSRemovePersonConfig : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initWithImageWith:(int)width imageHeight:(int)height cacheDir:(NSString*)cacheDir;

/// cache directory
@property(nonatomic, copy)NSString *cacheDir;

/// input image width
@property(nonatomic)int imageWidth;

/// input image height
@property(nonatomic)int imageHeight;

/// The number of optimal images generated
/// default: 15
@property(nonatomic)int num;

/// debug
/// default:NO
@property(nonatomic)BOOL enableDebug;

@end


@interface INSRemovePerson2 : NSObject

-(NSError*_Nullable)configRemovePerson:(INSRemovePersonConfig*)config;

/// 输入图像，当返回code为-1041时，表示遮挡物过多的提示，这时可以继续输入图像
/// @param pixelBuffer 输入的图像
/// @param timestamp 输入图像的时间（标识）
-(NSError*_Nullable)inputPixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(int64_t)timestamp;

-(NSArray<NSNumber*>* _Nullable)getBestImageTimestamps;

-(void)beginInputBestImage;

/// 输入图像，当返回code为-1041时，表示遮挡物过多的提示，这时可以继续输入图像
/// @param pixelBuffer 输入的图像
/// @param timestamp 输入图像的时间（标识）
-(NSError*_Nullable)inputBestPixelBuffer:(CVPixelBufferRef)pixelBuffer timestamp:(int64_t)timestamp;

-(void)endInputBestImage;

-(NSError*_Nullable)processBestImages:(NSArray<NSNumber*>*)BestImageTimestamps outputFilePath:(NSString*)path;

-(BOOL)hasCachedFramesAndMaskes:(NSArray<NSNumber*>*)selectTimes;

-(void)destroy;

/// 取消操作，需要在另一个线程中调用
-(void)cancel;

@end

NS_ASSUME_NONNULL_END
