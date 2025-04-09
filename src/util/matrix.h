#pragma once
// #################################################################|#########
// #################################################################|# (¬_¬) #
// #################################################################|#########
#include "vector.h"

typedef vec2 mat2[2];
typedef vec3 mat3[3];
typedef vec4 mat4[4];

#define mIdentity2(i) {{i,0},{0,i}}
#define mIdentity3(i) {{i,0,0},{0,i,0},{0,0,i}}
#define mIdentity4(i) {{i,0,0,0},{0,i,0,0},{0,0,i,0},{0,0,0,i}}
#define mIdentity(i) mIdentity4(i)

/*
 * Multiply a and b.
 * Result will be stored in a.
 */
void mMultiply(mat4 a, mat4 b);

/*
 */
void mOrtho(mat4 matrix,
		float left, float right,
		float top,  float bot,
		float far,  float near
		);

/*
 */
void mPerspective(mat4 matrix, float fov, float aRatio, float near, float far);

/*
 */
void mRotate(mat4 matrix, vec3 vec);

/*
 */
void mRotateX(mat4 matrix, float x);

/*
 */
void mRotateY(mat4 matrix, float y);

/*
 */
void mRotateZ(mat4 matrix, float z);

/*
 */
void mScale(mat4 matrix, float s);

/*
 */
void mScalef(mat4 matrix, vec3 vec);

/*
 */
void mTranslate(mat4 matrix, vec3 vec);
