//
//  INSHighlightParser.h
//  INSCoreMedia
//
//  Created by HFY on 2019/10/24.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSExtraHighlightData;
@interface INSHighlightPlayer : NSObject

- (instancetype)initWithHightlightData:(INSExtraHighlightData *)highlightData;

@end

NS_ASSUME_NONNULL_END
