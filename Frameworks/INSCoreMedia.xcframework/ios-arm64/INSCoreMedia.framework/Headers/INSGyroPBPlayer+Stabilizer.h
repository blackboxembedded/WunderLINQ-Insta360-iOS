//
//  INSGyroPBPlayer+Stabilizer.h
//  INSCoreMedia
//
//  Created by HFY on 2020/8/12.
//  Copyright © 2020 insta360. All rights reserved.
//

#include <GyrostabLib/modules/common/Base.hpp>
#include <GyrostabLib/modules/common/GyroStabDataType.hpp>
#include <GyrostabLib/modules/common/GyroAttitudeFunctions.hpp>
#include <GyrostabLib/modules/filter/FootageFilterOffline.hpp>
#include <GyrostabLib/modules/gait/BulletAlys.hpp>

#import "INSExtraGyroData.h"
#import "INSGyroPBPlayer.h"
#import "INSGyroType.h"


NS_ASSUME_NONNULL_BEGIN

@interface INSGyroPBPlayer ()

- (std::shared_ptr<ins::FootageFilterBase_FIR>)footageFilter;

- (std::shared_ptr<ins::BulletViewportAlys>)bulletViewportAlys;

- (std::shared_ptr<ins::CameraPoseDetector>)cameraPoseDetector;

- (std::vector<ins::Stabilizer::GyroData>)allGyroDatas;

- (ins::Stabilizer::GYROTYPE)stabilizerGyroType;

- (void)updateFilter:(INSGyroPlayMode)gyroPlayMode forceRecreate:(BOOL)forceRecreate;

- (void)filterTryCommit;

@end

NS_ASSUME_NONNULL_END
