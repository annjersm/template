/*\
|*| § Made by Anders                                                    (¬_¬)
\*/
#include "utils/math.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "type.h"
#include <stdio.h>

extern SDL_Renderer *gRender;
extern vec2i gWinSize;

float NormalizeX(float x)
{
	return ((x*(float)gWinSize.x/2)+((float)gWinSize.x / 2));
}

float NormalizeY(float y)
{
	return ((y*(float)gWinSize.y/-2)+((float)gWinSize.y / 2));
}

int PointInFRectN(SDL_FPoint mouse, SDL_FRect rect)
{
	return SDL_PointInRectFloat(&mouse, &(SDL_FRect){
			NormalizeX(rect.x),
			NormalizeY(rect.y),
			rect.w,
			rect.h
			});
}

int PointInFRectNOffset(SDL_FPoint mouse, SDL_FRect rect, int offset)
{
	return SDL_PointInRectFloat(&mouse, &(SDL_FRect){
			NormalizeX(rect.x) - offset,
			NormalizeY(rect.y),
			rect.w,
			rect.h
			});
}
