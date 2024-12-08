//
//  INSDeepTrackerInfo.h
//  INSCoreMedia
//
//  Created by HFY on 2020/8/6.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSDeepTrackerSDKVersion) {
    //INSDeepTrackerSDKVersionV1 = 0,
    INSDeepTrackerSDKVersionV2 = 1,
    INSDeepTrackerSDKVersionDefault = INSDeepTrackerSDKVersionV2,
};

typedef NS_ENUM(NSUInteger, INSDeepTrackerSolution) {
    // 可用来追万物，速度要快当前播放页正在使用的模式, 可追 person dog car（可以被替换下来了）.
    INSDeepTrackerSolutionSTAPLE_LT_BASIC = 1,
    
    // 可用来追万物，跟踪效果较好，物体类别不是Person或类别未知的情况建议用改模式
    INSDeepTrackerSolutionSIAMRPN_LT_BASIC = 2,
    
    // 追人的第一选择
    INSDeepTrackerSolutionSTAPLE_LT_PERSON = 3,
    
    // 追人的第二选择
    INSDeepTrackerSolutionDETECT_LT_PERSON = 4,
    
    // 更接近纯cv的追踪方式
    INSDeepTrackerSolutionSTAPLE_ST_BASIC = 5,
    
    // 单纯的siamrpn网络跟踪，核心与2相似
    INSDeepTrackerSolutionSIAMRPN_ST_BASIC = 6,
    
    // 球类追踪算法
    INSDeepTrackerSolutionSIAMRPN_BALL_BASIC = 7,
    
    // 在追踪过程中，自动切换人体或者人头，进行追踪算法
    INSDeepTrackerSolutionSIAMRPN_PERSON_OR_HEAD_BASIC = 8,
    
    // 播放页追踪人
    INSDeepTrackerSolutionUAV_STAPLE_LT_PERSON = 9,
};


@interface INSDeepTrackerInfo : NSObject

@property (nonatomic) INSDeepTrackerSDKVersion version;

@property (nonatomic) INSDeepTrackerSolution solution;

@property (nonatomic) NSString *debugDirPath;

- (instancetype)initWithSDKVersion:(INSDeepTrackerSDKVersion)version
                          solution:(INSDeepTrackerSolution)solution;

@end

/*   功能       |       推荐                                     |         备注
 
    SmartTrack | STAPLE_LT_BASIC(人) + SIAMRPN_LT_BASIC(其他)   |
    TimeShift  | STAPLE_ST_BASIC / SIAMRPN_ST_BASIC            |  在用版本等价于STAPLE_ST_BASIC，建议切换到 SIAMRPN_ST_BASIC 以保证跟踪效果
    dollyzoom  | STAPLE_LT_BASIC(人) + SIAMRPN_ST_BASIC(其他)   |
    ShadowClone| DETECT_LT_PERSON(在用)  |
    theFlash   | STAPLE_LT_PERSON(在用)  |
    runPlanet  | DETECT_LT_PERSON(在用)  |                         建议切换到推荐方案
    stopMotion | DETECT_LT_PERSON(在用)  |                         建议切换到推荐方案
    翻转半圈     | STAPLE_LT_BASIC(在用) / STAPLE_LT_PERSON(推荐)  |  建议切换到推荐方案
 
    机械臂      | SIAMRPN_HEAD_BASIC
 
 STAPLE_LT_PERSON效果平滑性不好
 */

NS_ASSUME_NONNULL_END
