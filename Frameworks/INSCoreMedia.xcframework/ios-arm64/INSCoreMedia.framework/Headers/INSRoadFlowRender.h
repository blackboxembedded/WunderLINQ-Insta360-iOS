//
//  INSRoadFlowRender.h
//  INSCoreMedia
//
//  Created by Mac on 2021/6/24.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSRender.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSRoadFlowRenderConfiguration : NSObject
/// 背景视频帧率，用于估算视频帧的序号
@property (nonatomic) double fps;
/// 马路延时特效在成片时间轴上的开始时间
@property (nonatomic) double startTime;
/// 缓存路径，存放特定前景的预处理结果（缩略图和分割mask），【无论预处理还是预览导出都必须配置】，不同的前景视频不能共享
/// 预处理向其写数据，渲染（预览和导出）从中读数据
/// 由调用者维护这个文件夹的创建、销毁；如果文件夹不存在会报错
@property (nonatomic) NSString *cacheImageDir;

@end

@interface INSRoadFlowRender : INSRender
// 传入初始化参数，成功返回nil，失败返回具体NSError
- (nullable NSError *) loadConfiguration:(INSRoadFlowRenderConfiguration *)config;

@end

NS_ASSUME_NONNULL_END
