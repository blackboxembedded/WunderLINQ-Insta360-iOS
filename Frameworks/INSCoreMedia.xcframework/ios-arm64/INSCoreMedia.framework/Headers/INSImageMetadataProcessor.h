//
//  INSImageMetadataProcessor.h
//  INSCoreMedia
//
//  Created by pengwx on 2017/10/26.
//  Copyright © 2017年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>





typedef NS_ENUM(NSInteger, INSImageDataType){
    INSImageDataTypeJPEG,
    INSImageDataTypePNG,
};

@class INSImageXmp;
@class INSImageExif;

NS_ASSUME_NONNULL_BEGIN

@interface INSImageMetadataProcessor : NSObject

- (instancetype) initWithUIImage:(UIImage *)image ouputType:(INSImageDataType)type compression:(CGFloat)compression;
- (instancetype) initWithImageData:(NSData*)imageData width:(NSUInteger)width height:(NSUInteger)height;

@property (nonatomic, strong, nullable) INSImageXmp *xmp;
@property (nonatomic, strong, nullable) INSImageExif *exif;

- (NSData* _Nullable) getImageData;

@end

NS_ASSUME_NONNULL_END
