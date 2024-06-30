/*\
|*| § Made by Anders                                                    (¬_¬)
\*/
#pragma once

#include <SDL3/SDL_rect.h>

float NormalizeX(float x);
float NormalizeY(float y);

int PointInFRectN(SDL_FPoint mouse, SDL_FRect rect);
int PointInFRectNOffset(SDL_FPoint mouse, SDL_FRect rect, int offset);
