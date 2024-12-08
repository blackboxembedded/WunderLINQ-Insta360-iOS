//
//  INS3DObject.h
//  INSVideoPlayApp
//
//  Created by pwx on 27/1/16.
//  Copyright © 2016年 insta360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class INSCamera;
@class INSGeometry;
@class INSMaterial;

@interface INS3DObject : NSObject
{
    GLKMatrix4 _tModelView;
    GLKMatrix4 _modelViewMat;
    INSGeometry *_geometry;
}

@property (nonatomic) GLKQuaternion adjustCoordinate;      //校正坐标系

@property (nonatomic) GLKVector3 position;
@property (nonatomic) GLKVector3 scale;

@property (nonatomic) GLKVector3 eulerAngle;                        //欧拉角
@property (nonatomic) GLKQuaternion orientation;                    //方向

@property (nonatomic) GLfloat preRoll;                    //方向, 单位:度

@property (nonatomic) GLKVector3 rotationEulerAngle;                //旋转欧拉角
@property (nonatomic) GLKQuaternion rotationOrientation;            //旋转方向
@property(nonatomic) GLKQuaternion preRollQuaternion;

@property (nonatomic) GLenum frontFace;                             //
@property (nonatomic, strong, nullable) INSMaterial *material;                //材料
@property (nonatomic, strong, nullable) INSGeometry *geometry;                //几何体

@property (nonatomic, strong, readonly) NSMutableArray *objects;                 //3D模型
@property (nonatomic, readonly) GLKQuaternion quaternion;

@property (nonatomic) GLKQuaternion gyroStabilityOrientation;
@property (nonatomic) GLKQuaternion directionalOrientation;
@property (nonatomic)GLKQuaternion applyQuaternion;

@property (nonatomic, readonly) GLKMatrix4 modelMat4;                             //包括adjustCoordinate
@property (nonatomic, readonly) GLKMatrix4 subModelMat4;                         //不包括adjustCoordinate

@property (nonatomic, copy, nullable) void (^gyroPlayModelAutoFovBlock)(double autoFov);

-(GLKVector3)spatialAudioRotation;

//清理
- (void) clean;

- (void) addChildToFront:(INS3DObject *)child;

//添加3D物体
- (void) addChild:(INS3DObject*)child;

//移除3D物体
- (void) removeChild:(INS3DObject*)child;

- (void) removeAllChild;

- (void) removeChilds:(NSArray*)childs;

//渲染
- (void) renderWithCamera:(INSCamera*)camera projectMat:(GLKMatrix4*)pProjectMat ViewMat:(GLKMatrix4*)pViewMat parentMat:(GLKMatrix4*)pParentMat;

@end

NS_ASSUME_NONNULL_END
