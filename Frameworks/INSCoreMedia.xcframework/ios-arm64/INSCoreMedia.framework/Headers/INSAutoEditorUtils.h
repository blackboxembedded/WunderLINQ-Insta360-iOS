//
//  INSAutoEditorUtils.h
//  INSCoreMedia
//
//  Created by 那强 on 2019/4/19.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSAutoEditorUtils : NSObject
+ (void)updateAnalyzeJsonWithPath:(NSString *)path trimStartTimeMs:(double)trimStartTimeMs trimEndTimeMs:(double)trimEndTimeMs error:(NSError * _Nullable * _Nullable)error;


+ (BOOL)trimAnalyzeJsonWithStart:(double)trimStartMs end:(double)trimEndMs srcJsonPath:(NSString *)srcJsonPath outJsonPath:(NSString *)outJsonPath;

@end

NS_ASSUME_NONNULL_END
