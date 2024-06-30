/*\
|*| § Made by Anders                                                    (¬_¬)
\*/
#include "utils/math.h"
#include "type.h"
#include <stdio.h>

vec2i gWinSize;

float NormalizeX(float x)
{
	return ((x*(float)gWinSize.x/2)+((float)gWinSize.x / 2));
}

float NormalizeY(float y)
{
	return ((y*(float)gWinSize.y/-2)+((float)gWinSize.y / 2));
}

// return true if vec2 is insize vec4
int PointInRectF(vec2 *p, vec4 *r)
{
	return  ( p && r && (p->x >= r->x) && (p->x < (r->x + r->z)) &&
		(p->y >= r->y) && (p->y < (r->y + r->w)) ) ? 1 : 0;
}

// Point in Rect Normalized
int PointInFRectN(vec2 mouse, vec4 rect)
{
	return PointInRectF(&mouse, &(vec4){
			NormalizeX(rect.x),
			NormalizeY(rect.y),
			rect.z,
			rect.w
			});
}

// Point in Rect Normalized Offset
int PointInFRectNOffset(vec2 mouse, vec4 rect, int offset)
{
	return PointInRectF(&mouse, &(vec4){
			NormalizeX(rect.x) - offset,
			NormalizeY(rect.y),
			rect.z,
			rect.w
			});
}
