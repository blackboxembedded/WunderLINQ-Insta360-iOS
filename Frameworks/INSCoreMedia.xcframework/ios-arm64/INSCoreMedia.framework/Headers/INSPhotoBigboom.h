//
//  INSPhotoBigboom.h
//  INSCoreMedia
//
//  Created by HFY on 2020/9/3.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INSPhotoBigboomTarget) {
    // 小行星
    INSPhotoBigboomTargetAsteroid = 0,
    // 以人为目标的广角 渲染为16:9
    INSPhotoBigboomTargetHumanWide,
    // 以人为目标的反向广角 渲染为9:16
    INSPhotoBigboomTargetHumanReverseWide,
    // 以人为目标的超广角 渲染为insta pano
    INSPhotoBigboomTargetHumanUltra,
    // 以显著性为目标的超广角 渲染为insta pano
    INSPhotoBigboomTargetSaliencyUltra,
    // 没有特殊目标的超广角 渲染为insta pano
    INSPhotoBigboomTargetNormalUltra,
};

typedef NS_ENUM(NSInteger, INSPhotoBigboomFeature) {
    // 无特性
    INSPhotoBigboomPositionNoSpecial = 0,
    // 小合照
    INSPhotoBigboomPositionSmallGroup,
    // 大合照
    INSPhotoBigboomPositionBigGroup,
    // 自拍
    INSPhotoBigboomPositionSelfie,
};

@interface INSPhotoBigboomResult : NSObject<NSCopying, NSMutableCopying, NSCoding>

@property (nonatomic) INSPhotoBigboomTarget target;

@property (nonatomic) INSPhotoBigboomFeature feature;

@property (nonatomic) GLKQuaternion orientation;

@property (nonatomic) GLKVector3 euler; //(Pitch, Yaw, Roll)

@property (nonatomic) float xFov; //推荐使用的xFov值，0为无效值

@end

@interface INSPhotoBigboom : NSObject

// 置为true，移除人脸，且选取识别框面积最大的作为输出。(人 > 显著性)
// 若返回结果为2个，则第一个为人，第二个为显著性
// 若返回为1个，可能是人也可能是显著性,target属性可查看类型
@property (nonatomic)BOOL removeFace;

/// DEPRECATED! 默认初始化方法，关闭了debug模式
- (instancetype)init;

/// debug初始化方法， 暂时不要调用， 待底层算法开发debug接口
/// @param debugMode 是否打开调试模式，打开后会把中间数据保存在相应文件夹下
/// @param debugDirPath 调试文件夹
- (instancetype)initWithDebugMode:(BOOL)debugMode debugDirPath:(NSString * _Nullable)debugDirPath;

// 表示当前算法是否可用，NO为不可用，即使调用[processorImagePath:error:]方法也会返回错误
@property (nonatomic, readonly) BOOL valid;


/// 处理图片，传入指定格式的url，"http://192.168.1.109:8000/**.insp" or "file:///var/mobile/Ducuments/***.insp"
/// @param inputURL image url
/// @param error error
- (nullable NSArray<INSPhotoBigboomResult *> *)processorImageURL:(NSURL *)inputURL error:(NSError * _Nullable * _Nullable)error;


/// 取消操作，异步线程调用
- (void) cancel;

@end

NS_ASSUME_NONNULL_END
