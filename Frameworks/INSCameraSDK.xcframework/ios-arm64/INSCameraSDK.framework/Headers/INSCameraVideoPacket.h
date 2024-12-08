//
//  INSCameraVideoPacket.h
//  INSCameraSDK
//
//  Created by zeng bin on 1/23/18.
//  Copyright © 2018 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface INSCameraVideoPacket : NSObject

@property (nonatomic) NSData *data;

@property (nonatomic) BOOL isKeyFrame;

@property (nonatomic) NSTimeInterval timestamp;

- (instancetype)initWithH264Data:(NSData *)data isKeyFrame:(BOOL)isKeyFrame
                       timestamp:(NSTimeInterval)timestamp;

@end


NS_ASSUME_NONNULL_END
