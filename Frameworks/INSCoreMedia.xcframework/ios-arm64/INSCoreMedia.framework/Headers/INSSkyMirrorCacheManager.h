//
//  INSSkyMirrorCacheManager.h
//  INSCoreMedia
//
//  Created by HFY on 2021/3/1.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, INSSkyMirrorCacheMode){
    INSSkyMirrorCacheModeSave,
    INSSkyMirrorCacheModeLoad,
};

NS_ASSUME_NONNULL_BEGIN

@interface INSSkyMirrorCacheManager : NSObject

-(instancetype)initManagerWithMode:(INSSkyMirrorCacheMode)mode cachePath:(NSString*)path;

@property(nonatomic)INSSkyMirrorCacheMode cacheMode;
@property(nonatomic, strong)NSString *cachePath;

-(void)savePixelBuffer:(CVPixelBufferRef)pixelBuffer;
-(UIImage*)loadNextImage;

@end

NS_ASSUME_NONNULL_END
