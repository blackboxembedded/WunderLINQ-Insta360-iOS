//
//  INSFilter+type.h
//  INSCoreMedia
//
//  Created by HFY on 2020/3/24.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSFilter.h"

NS_ASSUME_NONNULL_BEGIN
@class INSFillerBaseParam;
@interface INSFilter (type)

+ (INSFilter*_Nullable)filterWithParam:(id<INSFilterParamInterface> _Nullable)param;

@end

NS_ASSUME_NONNULL_END
