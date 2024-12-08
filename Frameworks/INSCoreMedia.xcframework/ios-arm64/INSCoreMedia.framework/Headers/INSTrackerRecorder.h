//
//  INSTrackerRecorder.h
//  INSCoreMedia
//
//  Created by HFY on 2020/5/21.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSScreenRecorder.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSTrackerRecorder : INSScreenRecorder


- (instancetype) initWithDataSourceRecorder:(INSScreenRecorder *)dataSourceRecorder;


@end

NS_ASSUME_NONNULL_END
