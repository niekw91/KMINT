#pragma 
#include "SDL.h"

class SDL_DrawEllipse
{
public:
	static void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
	static void draw_circle(SDL_Surface *surface, int n_cx, int n_cy, int radius, Uint32 pixel);
	static void fill_circle(SDL_Surface *surface, int cx, int cy, int radius, Uint32 pixel);
};

