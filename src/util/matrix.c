#include "matrix.h"
// #################################################################|#########
// #################################################################|# (¬_¬) #
// #################################################################|#########
#include <math.h>
#include "vector.h"

void mMultiply(mat4 a, mat4 b)
{
	mat4 c = mIdentity4(1.0f);
	int x, y;
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			c [x][y] = (a[x][0] * b[0][y]) +
				   (a[x][1] * b[1][y]) +
				   (a[x][2] * b[2][y]) +
				   (a[x][3] * b[3][y]);
		}
	}
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			a[x][y] = c[x][y];
		}
	}
}

void mOrtho(mat4 matrix,
		float left, float right,
		float top,  float bot,
		float far,  float near
		)
{
	mat4 i = {
		{2/(right-left), 0, 0, -((right+left)/(right-left))},
		{0, 2/(top-bot), 0, -((top+bot)/(top-bot))},
		{0, 0, -2/(far-near), -((far+near)/(far-near))},
		{0, 0, 0, 1}
	};
	mMultiply(matrix, i);
}

void mPerspective(mat4 matrix, float fov, float aRatio, float near, float far)
{
	float tangent = 1.0f / tan(fov * 0.5);
	mat4 i = mIdentity4(1.0f);
	i[0][0] = (tangent / aRatio);
	i[1][1] = tangent;
	i[2][2] = far / (near - far);
	i[2][3] = (-far * near) / (far - near) * 2;
	i[3][2] = -1.0f;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			matrix[x][y] = i[x][y];
		}
	}
}

void mRotate(mat4 matrix, vec3 vec)
{
	mRotateX(matrix, vec[X]);
	mRotateY(matrix, vec[Y]);
	mRotateZ(matrix, vec[Z]);
}

void mRotateX(mat4 matrix, float x)
{
	mat4 i = {
		{1,0,0,0},
		{0,cos(x),-sin(x),0},
		{0,sin(x), cos(x),0},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}

void mRotateY(mat4 matrix, float y)
{
	mat4 i = {
		{ cos(y),0,sin(y),0},
		{0,1,0,0},
		{-sin(y),0,cos(y),0},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}

void mRotateZ(mat4 matrix, float z)
{
	mat4 i = {
		{cos(z),-sin(z),0,0},
		{sin(z), cos(z),0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}

void mScale(mat4 matrix, float scale)
{
	mat4 i = {
		{scale,0,0,0},
		{0,scale,0,0},
		{0,0,scale,0},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}

void mScalef(mat4 matrix, vec3 vec)
{
	mat4 i = {
		{vec[X],0,0,0},
		{0,vec[Y],0,0},
		{0,0,vec[Z],0},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}

void mTranslate(mat4 matrix, vec3 vec)
{
	mat4 i = {
		{1,0,0,vec[X]},
		{0,1,0,vec[Y]},
		{0,0,1,vec[Z]},
		{0,0,0,1}
	};
	mMultiply(matrix, i);
}
