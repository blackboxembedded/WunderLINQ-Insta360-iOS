//
//  INSTimeMap+data.h
//  INSCoreMedia
//
//  Created by HFY on 2021/8/25.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSTimeMap.h"
#import "INSLookHerePoint.h"
#import "INSScreenRecorder.h"
#import "INSTimeScale.h"
#import "INSTimeRange.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSTimeMap ()

-(NSArray<INSLookHerePoint*>* _Nullable) mapLookHerePoints:(NSArray<INSLookHerePoint*>*)lookHerePoints;
-(NSArray<INSScreenRecorder*>* _Nullable) mapScreenRecorders:(NSArray<INSScreenRecorder*>*)recorders;
-(NSArray<INSTimeScale*>* _Nullable) mapTimeScales:(NSArray<INSTimeScale*>*)timeScales;
-(INSTimeRange* _Nullable)mapTimeRange:(INSTimeRange*)range;

@end

NS_ASSUME_NONNULL_END
