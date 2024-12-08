//
//  INSCameraAudioPacket.h
//  INSCameraSDK
//
//  Created by zeng bin on 12/22/17.
//  Copyright © 2017 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, INSCameraAudioPacketType) {
    INSCameraAudioPacketTypeADTS,
    INSCameraAudioPacketTypeAAC,
    INSCameraAudioPacketTypePCM,
};

@interface INSCameraAudioPacket : NSObject

/// the pts, in seconds
@property (nonatomic) NSTimeInterval timestamp;

/// the content
@property (nonatomic, readonly) NSData *data;

@property (nonatomic, readonly) INSCameraAudioPacketType type;

/// adts would not has asbd
@property (nonatomic, readonly) BOOL hasASBD;

@property (nonatomic, readonly) AudioStreamBasicDescription asbd;

@property (nonatomic, nullable, readonly) NSData *magicCookie;

@property (nonatomic, readonly, nullable) NSData *audioSpecificConfigData;

+ (instancetype)aacPacketWithData:(NSData *)data
                        timestamp:(NSTimeInterval)timestamp
                          asbdPtr:(AudioStreamBasicDescription *)asbdPtr
                      magicCookie:(NSData *)magicCookie;

+ (instancetype)adtsPacketWithData:(NSData *)data
                         timestamp:(NSTimeInterval)timestamp;

- (instancetype)initWithData:(NSData *)data type:(INSCameraAudioPacketType)type
                   timestamp:(NSTimeInterval)timestamp
                     asbdPtr:(nullable AudioStreamBasicDescription *)asbdPtr
                 magicCookie:(nullable NSData *)magicCookie;

@end

NS_ASSUME_NONNULL_END
