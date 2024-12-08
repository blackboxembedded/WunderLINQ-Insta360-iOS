//
//  INSExporterLogJson.h
//  INSCoreMedia
//
//  Created by HFY on 2021/4/6.
//  Copyright © 2021 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INSExporterLogInfo.h"

NS_ASSUME_NONNULL_BEGIN


@interface INSExporterLogJson : NSObject

-(instancetype)initWithFileInfo:(INSExporterLogFileInfo*)fileInfo stateInfo:(NSArray<INSExporterLogStateInfo*>*)stateInfo;
-(instancetype)initWithSerializeData:(NSData *)data;

-(NSData*)serializeJsonData;

@property(nonatomic, strong)NSArray<INSExporterLogStateInfo*> *stateInfo;
@property(nonatomic, strong)INSExporterLogFileInfo *fileInfo;

@end

NS_ASSUME_NONNULL_END
