//
//  INSLLog.h
//  INSCoreMedia
//
//  Created by pengwx on 2019/3/20.
//  Copyright © 2019 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger, INSLLogLevelType) {
    INSLLogLevelTypeVerbose,
    INSLLogLevelTypeInfo,
    INSLLogLevelTypeWarning,
    INSLLogLevelTypeError,
};


@interface INSLLog : NSObject

+ (void) configurateLogLevel:(INSLLogLevelType)type;

+ (void) configurateLogFile:(NSString*)path;

//+ (INSLLog*) defaultLLog;

@end

NS_ASSUME_NONNULL_END
