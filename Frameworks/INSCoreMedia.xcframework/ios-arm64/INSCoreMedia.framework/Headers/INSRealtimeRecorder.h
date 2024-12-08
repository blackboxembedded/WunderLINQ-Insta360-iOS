//
//  INSRealtimeRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/5/18.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN

@class INSProjectionInfo;

typedef  INSProjectionInfo * _Nullable (^UpdateDataBlk)(double timestamp);

@interface INSRealtimeRecorder : INSScreenRecorder

- (instancetype)initWithinitWithDisplay:(INSDisplay*)display updateDataBlk:(UpdateDataBlk)updateDataBlk;


@end

NS_ASSUME_NONNULL_END
