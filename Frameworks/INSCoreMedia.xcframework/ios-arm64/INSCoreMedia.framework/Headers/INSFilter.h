//
//  INSFilter.h
//  INSMediaApp
//
//  Created by pengwx on 3/18/16.
//  Copyright © 2016 Insta360. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INSFilterType.h"
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>

@protocol INSFilterParamInterface;

#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define SHADER_STRING(text) @ STRINGIZE2(text)


#define FilterTextureUnit   GL_TEXTURE2                 //滤镜使用的textureunit 起点
#define TextureSample(X)    (X-GL_TEXTURE0)             //取样器计算
#define FilterTextureMaxUnit  GL_TEXTURE7               //最大纹理单元


extern NSString *const kARVImageVertexShaderString;
extern NSString *const kARVImagePassthroughFragmentShaderString;


struct ARVVector4 {
    GLfloat one;
    GLfloat two;
    GLfloat three;
    GLfloat four;
};
typedef struct ARVVector4 ARVVector4;

struct ARVVector3 {
    GLfloat one;
    GLfloat two;
    GLfloat three;
};
typedef struct ARVVector3 ARVVector3;

struct ARVMatrix4x4 {
    ARVVector4 one;
    ARVVector4 two;
    ARVVector4 three;
    ARVVector4 four;
};
typedef struct ARVMatrix4x4 ARVMatrix4x4;

struct ARVMatrix3x3 {
    ARVVector3 one;
    ARVVector3 two;
    ARVVector3 three;
};
typedef struct ARVMatrix3x3 ARVMatrix3x3;


@class INSRenderTarget;
@class INSMaterial;
@class INSScene;
@class INSTexture;

NS_ASSUME_NONNULL_BEGIN

@interface INSFilter : NSObject{
    GLuint _program;
    GLint filterPositionAttribute;
    GLint filterTextureCoordinateAttribute;
    GLint filterInputTextureUniform;
//
//    GLint _position;
//    GLint _inputTextureCoordinate;
    CGSize _size;
    
}

//@property (nonatomic) GLint textureSample;

- (instancetype) initWithVertexShaderString:(NSString*)vertexString fragmentShaderString:(NSString*)fragmentString;
- (instancetype) initWithVersion300VertexShaderString:(NSString*)vertexString fragmentShaderString:(NSString*)fragmentString;

- (instancetype) initWithFragmentShaderString:(NSString*)fragmentString;

- (void) resetVertexShaderString:(NSString*)vertexString fragmentShaderString:(NSString*)fragmentString;
- (void) resetVersion300VertexShaderString:(NSString*)vertexString fragmentShaderString:(NSString*)fragmentString;

- (void)setupFilterForSize:(CGSize)filterFrameSize;
- (void)setUniformsForProgramAtIndex:(NSUInteger)programIndex;

- (INSScene*_Nullable) createRenderSceneWithInputTexture:(NSArray*)texture output:(INSRenderTarget*)renderTarget;

@property (nonatomic, strong, readonly) INSMaterial *material;

///当前type
@property (nonatomic) INSFilterType type;

/// 每种type对应了不同param的实现类
@property (nonatomic, nullable, readonly) id<INSFilterParamInterface> param;

- (BOOL)applyFilterParam:(id<INSFilterParamInterface>)param;

@end

NS_ASSUME_NONNULL_END
