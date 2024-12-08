//
//  INSSingleHDRInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/1/12.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger, INSUnderwaterVersion){
    INSUnderwaterVersionV1,
    INSUnderwaterVersionV2,
};

@interface INSUnderwaterInfo : NSObject

-(instancetype)init NS_UNAVAILABLE;
-(instancetype)initVersion:(INSUnderwaterVersion)version lutFilePath:(NSString* _Nullable)lutPath;

@property(nonatomic, readonly)INSUnderwaterVersion version;
@property(nonatomic, strong, readonly, nullable)NSString *lutPath;

-(BOOL)isEualInfo:(INSUnderwaterInfo*)underwaterInfo;

@end

typedef NS_ENUM(NSInteger, INSDeepLearningSysType);

@interface INSColorPlusInfo :NSObject

@property(nonatomic) NSString *modelPath;

@property(nonatomic) INSDeepLearningSysType sysType;

//default value 33
@property(nonatomic)int sampleSize;

//default value 0.1
@property(nonatomic)float movingAverageRatio;

//default NO
@property(nonatomic, readonly)BOOL enableLocalContrast;

// default NO 
@property(nonatomic, readonly)BOOL enableColorPlus;

// default NO
@property(nonatomic, readonly)BOOL enableExtra;

// new colorplus
@property(nonatomic, readonly)BOOL enableNewLTM;

-(BOOL)isEualInfo:(INSColorPlusInfo*)info;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initWithColorplus:(BOOL)colorplus localContrast:(BOOL)localContrast;

-(instancetype)initWithColorplus:(BOOL)colorplus localContrast:(BOOL)localContrast enableExtra:(BOOL)enableExtra;

/**
  * @param colorplus
  * @param localContrast ：控制LTM开关
  * @param enableExtra：全景导出时置为true，减小色差线
  * @param enableNewLTM：控制LTM的新旧版本，false为旧版，true为新版
  */
-(instancetype)initWithColorplus:(BOOL)colorplus localContrast:(BOOL)localContrast enableExtra:(BOOL)enableExtra enableNewLTM:(BOOL)enableNewLTM;

@end


@class INSMediaAAA;
@interface INSSingleDenoiseInfo : NSObject

/// default is 10
@property (nonatomic) int downSampleScale;

/// radius 导向滤波时影响的局部区域的范围，越大影响范围越大，一般设置为10的倍数，默认使用10
@property (nonatomic) int radius;

/// 用来区分局部区域是细节还是噪声，越大越最终结果模糊，一般设置为0.0001，可以设置为0.1-0.00001之间
@property (nonatomic) double eps;

/// 3A 数据，在文件尾拿到，可以解析出iso值，iso值大于isoThreshold，会开启降噪
@property (nonatomic, nullable) NSArray<INSMediaAAA *> *mediaAAA;

/// use INSExtraInfo.framePtsData
@property (nonatomic, nullable) NSData* framePtsData;

/// 当前帧的iso值大于或等于isoThreshold，才会应用降噪，默认为100; 如果设置为0，意味着一定开启
@property (nonatomic) int isoThreshold;

@end

NS_ASSUME_NONNULL_END
