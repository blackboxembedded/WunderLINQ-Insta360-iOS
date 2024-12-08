//
//  INSROIDetector.h
//  INSCoreMedia
//
//  Created by HFY on 2019/4/23.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// "person"
extern NSString *const INSROIDetectorTargetPerson;
// "car"
extern NSString *const INSROIDetectorTargetCar;
// "dog"
extern NSString *const INSROIDetectorTargetDog;
// "face"
extern NSString *const INSROIDetectorTargetFace;
// "ball"
extern NSString *const INSROIDetectorTargetBall;
// "head"
extern NSString *const INSROIDetectorTargetHead;
// 支持多选
typedef  NS_ENUM(NSUInteger, INSROIDetectorCapability) {
    INSROIDetectorCapabilityNone = 0,

    INSROIDetectorCapabilityMNAPCD = 1,// MNA人车狗(old and default)

    INSROIDetectorCapabilityFace = 2,  // 人脸-普通图像中检测
        
    INSROIDetectorCapabilityHead = 3,  // MM人头
    
    INSROIDetectorCapabilityBall = 4,  // MM球
    
    INSROIDetectorCapabilityMMPCD = 5, // MM人车狗(new)
};

@interface INSDetectorCapabilityOption : NSObject
/// INSROIDetectorCapability的NSNumber形式
@property (nonatomic, copy) NSNumber *detectorCapability;
/// 阈值，过滤置信度低于该值的检测结果
@property (nonatomic, assign) float score_thr;
/// 是否使用全景检测器检测，NO:不使用，YES：使用，使用全景检测器耗时约为平面检测器的4倍。当前全景检测器只在缩略图人脸检测使用
@property (nonatomic, assign) BOOL detectPanoViewFlag;

/// 初始化
/// @param option INSROIDetectorCapability的NSNumber形式
/// @param score_thr 置信度阈值
/// @param detectPanoViewFlag 是否使用全景检测器检测
- (instancetype)initWithOption:(INSROIDetectorCapability)option score_thr:(float)score_thr forDetectPanoViewFlag:(BOOL)detectPanoViewFlag;
@end

@interface INSROIRecognition : NSObject
@property (nonatomic ,readonly) NSString *name;
@property (nonatomic ,readonly) CGFloat confidence;
@property (nonatomic ,readonly) CGRect box;
@end

@interface INSROIDetector : NSObject

- (instancetype)init NS_UNAVAILABLE;

/// 初始化函数，内部支持 INSROIDetectorCapabilityMNAPCD 与 INSROIDetectorCapabilityBall
/// 返回nil表示物体检测器初始化失败，请检查模型是否放在了正确的路径下
- (nullable instancetype)initROIDetector DEPRECATED_MSG_ATTRIBUTE("Please use -initROIDetectorWithOptions:");

/// 初始化函数，识别选项通过非空数组传入
/// NOTE: INSROIDetectorCapabilityMNAPCD 与 INSROIDetectorCapabilityMMPCD同时传入为非法！
/// 返回nil表示物体检测器初始化失败，请检查模型是否放在了正确的路径下
- (nullable instancetype)initROIDetectorWithOptions:(NSArray<NSNumber*>*)options DEPRECATED_MSG_ATTRIBUTE("Please use -initROIDetectorWithDetectorOptions:");


/// 初始化函数，识别选项通过非空数组传入
/// @param detectoroptions 可以配置相关检测器的检测阈值大小
- (nullable instancetype)initROIDetectorWithDetectorOptions:(NSArray<INSDetectorCapabilityOption *>*)detectoroptions;

/// 识别一张图片，如果数组中没有元素，表示没有识别到物体
/// @param image 输入图片
/// @param renderScale 一个比例，因为识别结果是相对于图片本身尺寸的，如果这个位置不满足你的需求，可以通过配置renderScale来调整INSROIRecognition Box. 如果图片本身尺寸(750, 750)，且该值配置为2，那么得到的box尺寸为(375, 375) 。0为非法值，会被处理为默认值1。
- (NSArray<INSROIRecognition *> *)detectWithUIImage:(UIImage *)image renderScale:(CGFloat)renderScale;

- (NSArray<INSROIRecognition *> *)detectWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer renderScale:(CGFloat)renderScale;

/// input `fileName` param for debug save image
- (NSArray<INSROIRecognition *> *)detectWithUIImage:(UIImage *)image renderScale:(CGFloat)renderScale debugFileName:(NSString * _Nullable)debugFileName;

@property (nonatomic) BOOL debugMode;

// 如果配置为nil或者不存在这个文件夹，则输出到Ducuments/ROIDetector目录下
@property (nonatomic, nullable) NSString *debugDir;

@end

NS_ASSUME_NONNULL_END
