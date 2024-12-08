//
//  INSAudioSplitExporter.h
//  INSCoreMedia
//
//  Created by HFY on 2020/10/20.
//  Copyright © 2020 insta360. All rights reserved.
//

#import "INSExporter.h"

NS_ASSUME_NONNULL_BEGIN

@interface INSAudioSplitExporter : INSExporter

-(instancetype)initWithInputUrl:(NSURL*)inputUrl outputDirectory:(NSURL*)outputDir;


-(NSArray<NSURL*>*_Nullable)getOutputUrls;

@end

NS_ASSUME_NONNULL_END

//AudioSplitExporter(const std::string &inputUrl, const std::string &outputDir);
