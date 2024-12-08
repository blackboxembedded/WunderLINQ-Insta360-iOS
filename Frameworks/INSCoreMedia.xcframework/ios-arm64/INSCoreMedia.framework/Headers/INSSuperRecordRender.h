//
//  INSSuperRecordRender.h
//  INSCoreMedia
//
//  Created by HFY on 2021/7/15.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSRender.h"
#import "INSRecordProtocol.h"

NS_ASSUME_NONNULL_BEGIN



@interface INSSuperRecordRender : INSRender

/// 录制分辨率
@property(nonatomic)CGSize recordSize;

/// 2:1经纬图全景绘制区域，其中origin.x, size.width为实际大小与整个视图View的width的比例，origin.y, size.height为实际大小与整个视图View的height的比例，范围为0~1.0
@property(nonatomic)CGRect flatPanoFrame;

/// 录屏主画面的绘制区域，其中origin.x, size.width为实际大小与整个视图View的width的比例，origin.y, size.height为实际大小与整个视图View的height的比例，范围为0~1.0
@property(nonatomic)CGRect sphericalPanoFrame;

/// 阴影背景区域，其中origin.x, size.width为实际大小与整个视图View的width的比例，origin.y, size.height为实际大小与整个视图View的height的比例，范围为0~1.0
@property(nonatomic)CGRect shadowFrame;

/// 是否显示全景小窗
@property(nonatomic)BOOL enableFlatPano;

/// 阴影背景图片
@property(nonatomic, strong, nullable)UIImage *shadowBackgroundImage;

/// recordDelegate
@property (nonatomic, weak) id<INSRecordProtocol> recordDelegate;

/// 开始录制，录制播放器推出的每一帧画面内容，当播放器暂停时，录制也会自动暂停，没有画面推出
-(void)startRecord;

/// 开始录制，以帧率fps来录制当前屏幕显示的内容
-(void)startSnapshotRecordWithFps:(double)fps;

/// 停止录制
-(void)stopRecord;


@end

NS_ASSUME_NONNULL_END
