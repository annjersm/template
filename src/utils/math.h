/*\
|*| § Made by Anders                                                    (¬_¬)
\*/
#pragma once

#include "utils/utils.h"

float NormalizeX(float x);
float NormalizeY(float y);

int PointInFRectN(vec2 mouse, vec4 rect);
int PointInFRectNOffset(vec2 mouse, vec4 rect, int offset);
