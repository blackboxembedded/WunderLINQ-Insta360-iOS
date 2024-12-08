//
//  INSPassBySequenceParser.h
//  INSCoreMedia
//
//  Created by HFY on 2020/12/24.
//  Copyright © 2020 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class INSPassBySequence;
@interface INSPassBySequenceParser : NSObject

@property (nonatomic, readonly) NSString *passByJsonString;

@property (nonatomic, copy, readonly) NSArray <INSPassBySequence *> *passBySequences;

- (instancetype)initWithPassByJsonPath:(NSString *)passByJsonString;

- (BOOL)open;

@end

NS_ASSUME_NONNULL_END
