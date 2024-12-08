//
//  INSTimeMap+ins.h
//  INSCoreMedia
//
//  Created by HFY on 2021/8/12.
//  Copyright © 2021 insta360. All rights reserved.
//

#import "INSTimeMap.h"
#include <vector>

NS_ASSUME_NONNULL_BEGIN

@interface INSTimeMap ()

-(instancetype)initWithTimeMap:(std::vector<ins_timemap>&)timemap rangMap:(std::vector<ins_rangemap>&)rangemap;

-(void)getTimemapVec:(std::vector<ins_timemap>&)timemap;

-(void)getRangmapVec:(std::vector<ins_rangemap> &)rangeMap;

@end

NS_ASSUME_NONNULL_END
