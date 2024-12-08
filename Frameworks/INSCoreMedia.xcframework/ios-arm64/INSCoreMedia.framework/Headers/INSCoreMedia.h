//
//  INSCoreMedia.h
//  INSCoreMedia
//
//  Created by pengwx on 16/12/21.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for INSCoreMedia.
FOUNDATION_EXPORT double INSCoreMediaVersionNumber;

//! Project version string for INSCoreMedia.
FOUNDATION_EXPORT const unsigned char INSCoreMediaVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <INSCoreMedia/PublicHeader.h>


//fundation
#import <INSCoreMedia/INSCoreMediaSDK.h>
#import <INSCoreMedia/INSPlayerProtocol.h>
#import <INSCoreMedia/INSPlayerImage.h>
#import <INSCoreMedia/INSAudioSample.h>
#import <INSCoreMedia/INSRecordProtocol.h>
#import <INSCoreMedia/INSSuperRecordWriter.h>

#import <INSCoreMedia/UIImage+INSMediaSDK.h>
#import <INSCoreMedia/NSData+AES256.h>

#import <INSCoreMedia/INSMediaGyro.h>
#import <INSCoreMedia/INSMediaGyro+Feature.h>
#import <INSCoreMedia/INSMediaGps.h>
#import <INSCoreMedia/INSMediaOrientation.h>
#import <INSCoreMedia/INSMediaEuler.h>
#import <INSCoreMedia/INSMotionData.h>
#import <INSCoreMedia/INSMediaCropWindow.h>
#import <INSCoreMedia/INSMediaAAA.h>
#import <INSCoreMedia/INSTimeMap.h>
#import <INSCoreMedia/INSTimeMap+data.h>

//multi view
#import <INSCoreMedia/INSMultiViewInfo.h>
#import <INSCoreMedia/INSMultiViewCell.h>
#import <INSCoreMedia/INSMultiViewCircleCell.h>
#import <INSCoreMedia/INSMultiviewConfiguration.h>
#import <INSCoreMedia/INSMultiviewScheme.h>
#import <INSCoreMedia/INSMultiviewDisplay.h>
#import <INSCoreMedia/INSMultiviewDisplayManager.h>

//util
#import <INSCoreMedia/INSMetadata.h>
#import <INSCoreMedia/INSLogo.h>
#import <INSCoreMedia/INSWatermark.h>
#import <INSCoreMedia/INSImageExif.h>
#import <INSCoreMedia/INSImageXmp.h>
#import <INSCoreMedia/INSTrim.h>
#import <INSCoreMedia/INSPlayRateRange.h>
#import <INSCoreMedia/INSImageMetadataProcessor.h>
#import <INSCoreMedia/INSSingleHDRInfo.h>
#import <INSCoreMedia/INSCoordinateScale.h>
#import <INSCoreMedia/INSTimeRange.h>
#import <INSCoreMedia/INSMediaPos.h>
#import <INSCoreMedia/insFloat.h>
#import <INSCoreMedia/INSStitchingInfo.h>
#import <INSCoreMedia/INSSkyMirrorCacheManager.h>
#import <INSCoreMedia/INSExporterLog.h>
#import <INSCoreMedia/INSExporterLogInfo.h>
#import <INSCoreMedia/INSExporterLogJson.h>
#import <INSCoreMedia/INSVideoTagger.h>
#import <INSCoreMedia/INSStandMotionHeadTracker.h>
#import <INSCoreMedia/INSFpsSelectFilter.h>
#import <INSCoreMedia/INSFileDownloader.h>
#import <INSCoreMedia/INSFramePtsPlayer.h>
#import <INSCoreMedia/LowPerformantDeviceHandler.h>

//render
#import <INSCoreMedia/INSLens.h>
#import <INSCoreMedia/INSLens+Feature.h>
#import <INSCoreMedia/INSLensOffset.h>
#import <INSCoreMedia/INSLensOffset+Feature.h>
#import <INSCoreMedia/INSOffsetCalculator.h>
#import <INSCoreMedia/INSOffsetParser.h>
#import <INSCoreMedia/INSTailClear.h>

#import <INSCoreMedia/INS3DObject.h>
#import <INSCoreMedia/INSCamera.h>
#import <INSCoreMedia/INSRenderManager.h>
#import <INSCoreMedia/INSDisplayLink.h>

#import <INSCoreMedia/INSRenderProtocol.h>
#import <INSCoreMedia/INSRenderType.h>
#import <INSCoreMedia/INSRender.h>
#import <INSCoreMedia/INSDuplicateRender.h>
#import <INSCoreMedia/INSDoubleAsteroidRender.h>
#import <INSCoreMedia/INSFaceOffRender.h>

#import <INSCoreMedia/INSFlatPanoRender.h>
#import <INSCoreMedia/INSPreviewRender.h>
#import <INSCoreMedia/INSSphericalPanoRender.h>
#import <INSCoreMedia/INSSphericalParallaxRender.h>
#import <INSCoreMedia/INSSphericalRender.h>
#import <INSCoreMedia/INSParallaxPanoRender.h>
#import <INSCoreMedia/INSNormalRender.h>
#import <INSCoreMedia/INSMultiviewRender.h>
#import <INSCoreMedia/INSMultiviewPanoRender.h>
#import <INSCoreMedia/INSMultiviewFlatRender.h>
#import <INSCoreMedia/INS120FPSThumbnailRender.h>
#import <INSCoreMedia/INSRender+GestureRecognizer.h>
#import <INSCoreMedia/INSFlatGyroAdjustRender.h>
#import <INSCoreMedia/INSTransformRender.h>
#import <INSCoreMedia/INSVR180FlatPanoRender.h>
#import <INSCoreMedia/INSVR180SphericalPanoRender.h>
#import <INSCoreMedia/INSGiantAsteroidRender.h>
#import <INSCoreMedia/INSMultiScreenRender.h>
#import <INSCoreMedia/INSSkyMirrorRender.h>
#import <INSCoreMedia/INSSuperRecordRender.h>
#import <INSCoreMedia/INSSkySegRender.h>
#import <INSCoreMedia/INSRoboticArmRender.h>
#import <INSCoreMedia/INSFlatPanoPreviewRender.h>

//offscreen render
#import <INSCoreMedia/INSOffscreenRender.h>
#import <INSCoreMedia/INSMultiviewPanoOffscreenRender.h>
#import <INSCoreMedia/INSMultiviewFlatOffscreenRender.h>
#import <INSCoreMedia/INSFlatPanoOffscreenRender.h>
#import <INSCoreMedia/INSFlatGyroAdjustOffscreenRender.h>
#import <INSCoreMedia/INSSphericalFlatOffscreenRender.h>
#import <INSCoreMedia/INSSphericalPanoOffscreenRender.h>
#import <INSCoreMedia/INSNormalOffscreenRender.h>
#import <INSCoreMedia/INSTransformOffscreenRender.h>
#import <INSCoreMedia/INSVR180FlatPanoOffscreenRender.h>
#import <INSCoreMedia/INSVR180SphericalPanoOffscreenRender.h>
#import <INSCoreMedia/INSWidePanoOffscreenRender.h>
#import <INSCoreMedia/INSDoubleAsteroidOffscreenRender.h>
#import <INSCoreMedia/INSFaceOffOffscreenRender.h>
#import <INSCoreMedia/INSGiantAsteroidOffscreenRender.h>
#import <INSCoreMedia/INSMultiScreenOffscreenRender.h>
#import <INSCoreMedia/INSSkyMirrorOffscreenRender.h>
#import <INSCoreMedia/INSRoboticArmOffScreenRender.h>
#import <INSCoreMedia/INSSkySegOffScreenRender.h>
#import <INSCoreMedia/INSRoadFlowOffscreenRender.h>

//filter
#import <INSCoreMedia/INSFilterType.h>
#import <INSCoreMedia/INSFilter.h>
#import <INSCoreMedia/INSFilter+type.h>
//#import <INSCoreMedia/INSSharpenFilter.h>
#import <INSCoreMedia/INS3DLutFilter.h>
#import <INSCoreMedia/INSFilterHelper.h>
#import <INSCoreMedia/INSFilterInfo.h>

#import <INSCoreMedia/INSProjectionStrategy.h>
#import <INSCoreMedia/INSProjectionInfo.h>
#import <INSCoreMedia/INSProjectionParam.h>
#import <INSCoreMedia/INSEyePoint.h>
#import <INSCoreMedia/INSVisionField.h>
#import <INSCoreMedia/INSRenderView.h>
#import <INSCoreMedia/INSRenderView+Mask.h>
#import <INSCoreMedia/INSRenderView+FaceTrack.h>
#import <INSCoreMedia/INSRenderView+BulletTime.h>
#import <INSCoreMedia/INSRender+Mask.h>
#import <INSCoreMedia/INSMask.h>
#import <INSCoreMedia/INSFlatMask.h>
#import <INSCoreMedia/INSMaskInfo.h>
#import <INSCoreMedia/INSMaskRes.h>
#import <INSCoreMedia/INSFaceSDK.h>
#import <INSCoreMedia/INSInfo.h>

//record
#import <INSCoreMedia/INSDeepTrackerInfo.h>
#import <INSCoreMedia/INSScreenRecorder.h>
#import <INSCoreMedia/INSScreenRecorderBuilder.h>
#import <INSCoreMedia/INSScreenTracker.h>
#import <INSCoreMedia/INSScreenTrackerRecorderDelegate.h>
#import <INSCoreMedia/INSBgm.h>
#import <INSCoreMedia/INSTemplateRecorder.h>
#import <INSCoreMedia/INSDirectionRecorder.h>
#import <INSCoreMedia/INSBigboomRecorder.h>
#import <INSCoreMedia/INSLeadRoleRecorder.h>
#import <INSCoreMedia/INSSaliencyRecorder.h>
#import <INSCoreMedia/INSTransitionRecorder.h>
#import <INSCoreMedia/INSRealtimeRecorder.h>
#import <INSCoreMedia/INSTrackerRecorder.h>
#import <INSCoreMedia/INSDoubleAsteroidRecorder.h>
#import <INSCoreMedia/INSTimeshift2Recorder.h>
#import <INSCoreMedia/INSScreenRecorderModel.h>
#import <INSCoreMedia/INSHeroFollowTracker.h>
#import <INSCoreMedia/INSDualHeroFollowTracker.h>
#import <INSCoreMedia/INSHeroFollowRecorder.h>
#import <INSCoreMedia/INSOneTakeRecorder.h>
#import <INSCoreMedia/INSPassByRecorder.h>
#import <INSCoreMedia/INSAnimationRecorder.h>

//detect & processor & AI tracker
#import <INSCoreMedia/INSDeepLearningMeasure.h>
#import <INSCoreMedia/INSTrackerSequence.h>
#import <INSCoreMedia/INSTrackerSeqDistributor.h>
#import <INSCoreMedia/INSROIDetector.h>
#import <INSCoreMedia/INSDirectionProcessor.h>
#import <INSCoreMedia/INSMultiTargetTracker.h>
#import <INSCoreMedia/INSLeadRoleTracker.h>
#import <INSCoreMedia/INSDirectionTracker.h>
#import <INSCoreMedia/INSOrientationPlayer.h>
#import <INSCoreMedia/INSSaliencyTracker.h>
#import <INSCoreMedia/INSSkeletonTracker.h>
#import <INSCoreMedia/INSClassifierTracker.h>
#import <INSCoreMedia/INSSkeletonRecommender.h>
#import <INSCoreMedia/INSSkeletonMultipleRecommender.h>
#import <INSCoreMedia/INSSkeletonFrameExporter.h>
#import <INSCoreMedia/INSSkeletonConfiguration.h>
#import <INSCoreMedia/INSStillRegionTracker.h>
#import <INSCoreMedia/INSPanoDetector.h>

//previewer2
#import <INSCoreMedia/INSClip.h>
#import <INSCoreMedia/INSEmptyClip.h>
#import <INSCoreMedia/INSFileClip.h>
#import <INSCoreMedia/INSBgmClip.h>
#import <INSCoreMedia/INSImageClip.h>
#import <INSCoreMedia/INSDataSources.h>
#import <INSCoreMedia/INSPreviewer2.h>
#import <INSCoreMedia/INSTimeScale.h>
#import <INSCoreMedia/INSFileClipPos.h>
#import <INSCoreMedia/INSPreviewer2Pos.h>
#import <INSCoreMedia/INSEmSegment.h>
#import <INSCoreMedia/INSClipConfig.h>
#import <INSCoreMedia/INSIntervalFramePlayer.h>
#import <INSCoreMedia/INSBgmSource.h>
#import <INSCoreMedia/INSPreviewerTimeMapper.h>

//animation
#import <INSCoreMedia/INSAnimation.h>
#import <INSCoreMedia/INSAnimationState.h>
#import <INSCoreMedia/INSAsteroidAnimation.h>
#import <INSCoreMedia/INSDailyDisplayAnimation.h>
#import <INSCoreMedia/INSAutoFindAnimation.h>

//gyro
#import <INSCoreMedia/INSGyroType.h>
#import <INSCoreMedia/INSGyroDataSource.h>
#import <INSCoreMedia/INSiPhoneGyroDataSource.h>
#import <INSCoreMedia/INSLiteGyroDataSource.h>
#import <INSCoreMedia/INSGyroRecorder.h>
#import <INSCoreMedia/INSGyroPBPlayer.h>
#import <INSCoreMedia/INSGyroPlayer.h>
#import <INSCoreMedia/INSGyroRealtimePlayer.h>
#import <INSCoreMedia/INSGyroFileWriter.h>
#import <INSCoreMedia/INSGyroFilePlayer.h>
#import <INSCoreMedia/INSExposureRecorder.h>
#import <INSCoreMedia/INSGyroPlayerWrapData.h>
#import <INSCoreMedia/INSExtraGyroDataGroup.h>

// gyro extension
#import <INSCoreMedia/INSGyroPBPlayer+Detector.h>
#import <INSCoreMedia/INSGyroPBPlayer+Image.h>
#import <INSCoreMedia/INSGyroPBPlayer+Tools.h>
#import <INSCoreMedia/INSBulletTimeMotion.h>
#import <INSCoreMedia/INSBulletTimePeriod.h>
#import <INSCoreMedia/INSCameraFlipMotion.h>
#import <INSCoreMedia/INSGaitStateMotion.h>


//#import <INSCoreMedia/version.h>
#import <INSCoreMedia/INSExtraInfo.h>
#import <INSCoreMedia/INSExtraInfo+Serializer.h>
#import <INSCoreMedia/INSExtraMetadata.h>
#import <INSCoreMedia/INSExtraMetadata+Serializer.h>
#import <INSCoreMedia/INSExtraGyroData.h>
#import <INSCoreMedia/INSExtraGyroData+Serializer.h>
#import <INSCoreMedia/INSMediaGyro+ExtraInfo.h>
#import <INSCoreMedia/INSMediaGps+ExtraInfo.h>
#import <INSCoreMedia/INSExtraGPSData.h>
#import <INSCoreMedia/INSExtraInfo+GyroDataOverflow.h>
#import <INSCoreMedia/INSExtraInfoTrim.h>
#import <INSCoreMedia/INSTailClipInfo.h>
#import <INSCoreMedia/INSExtraAAAData.h>
#import <INSCoreMedia/INSExtraHighlightData.h>
#import <INSCoreMedia/INSMediaHighlight.h>
#import <INSCoreMedia/INSHighlightPlayer.h>
#import <INSCoreMedia/INSMediaHighlight+Orientation.h>
#import <INSCoreMedia/INSExtraInfoEmuTool.h>
#import <INSCoreMedia/INSExtraTimeMapperData.h>
#import <INSCoreMedia/INSMediaSpeed.h>
#import <INSCoreMedia/INSExtraSpeedData.h>

//muxer
#import <INSCoreMedia/INSMuxer.h>
#import <INSCoreMedia/INSH264Muxer.h>
#import <INSCoreMedia/INSPixelMuxer.h>
#import <INSCoreMedia/INSLiveMuxer.h>
#import <INSCoreMedia/INSPixelBufferMuxer.h>

//media
#import <INSCoreMedia/INSPlayer.h>
#import <INSCoreMedia/INSAVPlayer.h>
#import <INSCoreMedia/INSARPlayer.h>
#import <INSCoreMedia/INSTranscodeExporter.h>

//exporter
#import <INSCoreMedia/INSRational.h>
#import <INSCoreMedia/INSExporterInfo.h>
#import <INSCoreMedia/INSExporterManager.h>
#import <INSCoreMedia/INSExporter.h>
#import <INSCoreMedia/INSTrimExporter.h>
#import <INSCoreMedia/INSRenderExporter.h>
#import <INSCoreMedia/INSFixFrameExporter.h>
#import <INSCoreMedia/INSProjectExporter.h>
#import <INSCoreMedia/INSVideoTranscoder.h>
#import <INSCoreMedia/INSSequenceExporter.h>
#import <INSCoreMedia/INSSequentialExporter.h>
#import <INSCoreMedia/INSAudioSplitExporter.h>

//auto editor
#import <INSCoreMedia/INSSceneFrameAnalyzer.h>
#import <INSCoreMedia/INSAutoEditRecommender.h>
#import <INSCoreMedia/INSAutoEditorConfigurations.h>
#import <INSCoreMedia/INSAutoEditorUtils.h>
#import <INSCoreMedia/INSAudioExtractor.h>

#import <INSCoreMedia/INSDeepAutoEditorLongAnalyzer.h>
#import <INSCoreMedia/INSDeepAutoEditorLongWrapData.h>
#import <INSCoreMedia/INSDeepAutoEditorAnalyzer.h>
#import <INSCoreMedia/INSDeepAutoEditorWrapData.h>
#import <INSCoreMedia/INSDeepAutoBgmAnalyzer.h>
#import <INSCoreMedia/INSDeepAutoBgmWrapData.h>

//face detect, egg, beauty
#import <INSCoreMedia/INSEGGAlgorithmInfo.h>
#import <INSCoreMedia/INSFaceppAlgorithmInfo.h>
#import <INSCoreMedia/INSFaceAlgorithmVerify.h>
#import <INSCoreMedia/INSFaceBeautyFilter.h>
#import <INSCoreMedia/INSFaceBeautyParam.h>
#import <INSCoreMedia/INSNvFilter.h>
//#import <INSCoreMedia/NvsVideoEffect+Custom.h>

#import <INSCoreMedia/INSFaceInfo.h>
#import <INSCoreMedia/INSFaceDetectEngineConfig.h>

//parser
#import <INSCoreMedia/INSImageInfoParser.h>
#import <INSCoreMedia/INSVideoInfoParser.h>
#import <INSCoreMedia/INSAudioInfoParser.h>
#import <INSCoreMedia/INSExtraInfoParser.h>
#import <INSCoreMedia/INSVideoFrameExtracter.h>
#import <INSCoreMedia/INSHTTPSystemProxyBlackList.h>
#import <INSCoreMedia/INSTransitionParser.h>
#import <INSCoreMedia/INSTrackSequenceParser.h>
#import <INSCoreMedia/INSDemuxerInfoParser.h>
#import <INSCoreMedia/INSVideoInfoParser+Compatible.h>
//tools
#import <INSCoreMedia/INSMediaTool.h>
#import <INSCoreMedia/INSSingleLensCalculator.h>
#import <INSCoreMedia/INSLiteDetector.h>
#import <INSCoreMedia/INSLLog.h>
#import <INSCoreMedia/INSIDRFrameDecoder.h>
#import <INSCoreMedia/INSViewOrientation.h>
#import <INSCoreMedia/INSVideoTimePicker.h>
#import <INSCoreMedia/INSVideoEndCutTime.h>
#import <INSCoreMedia/INSOpencvException.h>
#import <INSCoreMedia/INSHttpCacheProxy.h>
#import <INSCoreMedia/INSDemuxerCacheProxy.h>

//image
#import <INSCoreMedia/INSHDRGenerator.h>
#import <INSCoreMedia/INSBlender.h>
#import <INSCoreMedia/INSSeamlessBlender.h>
#import <INSCoreMedia/INSTemplateBlender.h>
#import <INSCoreMedia/INSColorAdjustment.h>
//#import <INSCoreMedia/INSHandDetector.h>
//#import <INSCoreMedia/INSBrillianceEnhancer.h>
#import <INSCoreMedia/INS3DPlanetGenerator.h>
#import <INSCoreMedia/INSSuperNight.h>
#import <INSCoreMedia/INSHDRPlusGenerator.h>
#import <INSCoreMedia/INSAIRawImageGenerator.h>
#import <INSCoreMedia/INSJPGDenoise.h>
#import <INSCoreMedia/INSJpegToH264Encoder.h>

//look here
#import <INSCoreMedia/INSLookHerePoint.h>
#import <INSCoreMedia/INSRenderView+LookHere.h>

//projection converter
#import <INSCoreMedia/INSProjectionConverter.h>
#import <INSCoreMedia/INSMultipleConverter.h>
#import <INSCoreMedia/INSMultipleInfo.h>

//floatage
#import <INSCoreMedia/INSFloatageCell.h>
#import <INSCoreMedia/INSFloatageCellManager.h>
#import <INSCoreMedia/INSFloatagePosition.h>
#import <INSCoreMedia/INSFloatageView.h>
#import <INSCoreMedia/INSFloatageDrawProtocol.h>
#import <INSCoreMedia/INSBitmapData.h>
#import <INSCoreMedia/INSFloatageExportDraw.h>

//applet
#import <INSCoreMedia/INSAppletWrapData.h>
#import <INSCoreMedia/INSFaceFeatureDetector.h>
#import <INSCoreMedia/INSStarrySky.h>
#import <INSCoreMedia/INSCloneTrailGenerator.h>
#import <INSCoreMedia/INSCloneShadowGenerator.h>
#import <INSCoreMedia/INSCloneGeneratorConfiguration.h>
#import <INSCoreMedia/INSFlashInfo.h>
#import <INSCoreMedia/INSTimewarp.h>
#import <INSCoreMedia/INSGiantShakeInfo.h>
#import <INSCoreMedia/INSGiantAsteroidAnalyzer.h>
#import <INSCoreMedia/INSTimeflip.h>
#import <INSCoreMedia/INSPhotoBigboom.h>
#import <INSCoreMedia/INSMulticam.h>
#import <INSCoreMedia/INSOneTakeWrap.h>
#import <INSCoreMedia/INSOneTakeData.h>
#import <INSCoreMedia/INSOneTakeAnimation.h>
#import <INSCoreMedia/INSOneTakeUtils.h>
#import <INSCoreMedia/INSRemovePerson2.h>
#import <INSCoreMedia/INSMultiFrameDelayGenerator.h>
#import <INSCoreMedia/INSMultiFrameDelayWrapData.h>
#import <INSCoreMedia/INSShadowDancingGenerator.h>
#import <INSCoreMedia/INSShadowDancingWrapData.h>
#import <INSCoreMedia/INSPassByWarpData.h>
#import <INSCoreMedia/INSPassByAnalyzer.h>
#import <INSCoreMedia/INSPassBySequence.h>
#import <INSCoreMedia/INSPassBySequenceParser.h>
#import <INSCoreMedia/INSRoboticArmGenerator.h>
#import <INSCoreMedia/INSCollageDanceGenerator.h>
#import <INSCoreMedia/INSCollageDanceWrapData.h>
#import <INSCoreMedia/INSCycleCloneGenerator.h>
#import <INSCoreMedia/INSCycleCloneWrapData.h>
#import <INSCoreMedia/INSFlyOutEarthGenerator.h>
#import <INSCoreMedia/INSFlyOutEarthAnimation.h>
#import <INSCoreMedia/INSStrangeAnimation.h>
#import <INSCoreMedia/INSStrangeGenerator.h>
#import <INSCoreMedia/INSCinelapseWarpData.h>
#import <INSCoreMedia/INSCinelapseAnimation.h>
#import <INSCoreMedia/INSRoadFlowBackgorundGenerator.h>
#import <INSCoreMedia/INSRoadFlowPersonSegmentor.h>
#import <INSCoreMedia/INSRoadFlowRender.h>
#import <INSCoreMedia/INSMoveSceneGenerator.h>
#import <INSCoreMedia/INSMoveSceneAnimation.h>
#import <INSCoreMedia/INSThumbnailDetect.h>


//display
#import <INSCoreMedia/INSDisplay.h>
#import <INSCoreMedia/INSDisplayConfigManager.h>

//json serialize
#import <INSCoreMedia/INSJsonSerializeTool.h>
#import <INSCoreMedia/INSJsonSerializeMultiview.h>
#import <INSCoreMedia/INSJsonSerializeDisplay.h>
#import <INSCoreMedia/INSJsonSerializeAnimation.h>
