#include "SDLEngine.h"
#include "SDL_DrawEllipse.h"
#include "Graph.h"
#include "Node.h"
#include "BaseGameEntity.h"
#include <random>

SDLEngine::SDLEngine(int width, int height) {
	// Initialize SDL.
	SDL_Init(SDL_INIT_VIDEO);
	// Create the window where we will draw.
	window = SDL_CreateWindow("SDL_RenderClear",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		0);
	// We must call SDL_CreateRenderer in order for draw calls to affect this
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(renderer);

	// Initialize SDL_ttf library
	if (!TTF_WasInit())
		TTF_Init();
	// Create new font
	font = TTF_OpenFont("arial.ttf", 11);
}

void SDLEngine::DrawLine(int x1, int y1, int x2, int y2) {
	//Draw blue horizontal line
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void SDLEngine::DrawEllipseFromGraph(Graph* graph) {
	//int c = ((rand() % 0xff) << 16) +
	//	((rand() % 0xff) << 8) +
	//	(rand() % 0xff);
	int radius = 10;

	SDL_Surface *screen = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0);
	if (screen) {
		SDL_LockSurface(screen);

		for (auto n : graph->allNodes) {
			//SDL_DrawEllipse::fill_circle(screen, n->x, n->y, radius, 0xff000000 + c);
			SDL_DrawEllipse::fill_circle(screen, n->x, n->y, radius, 0xff000000);
			SDL_DrawEllipse::draw_circle(screen, n->x, n->y, radius, 0xffffffff);
		}

		SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, screen);

		SDL_RenderCopy(renderer, tex, NULL, NULL);

		SDL_DestroyTexture(tex);
		SDL_FreeSurface(screen);
	}
}

void SDLEngine::RenderText(std::string text, int x, int y) {
	SDL_Color bgColor = { 0, 0, 0, 0 };
	SDL_Color fgColor = { 255, 255, 255 };
	SDL_Surface *surface = TTF_RenderText(font, text.c_str(), fgColor, bgColor);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_ADD);

	SDL_Rect rect;
	rect.h = surface->h;
	rect.w = surface->w;
	rect.x = x - 25;
	rect.y = y - 25;

	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void SDLEngine::RenderImage(BaseGameEntity *obj) {
	if (obj->GetPosition()) {
		SDL_Rect rect;
		rect.h = obj->GetImage()->h / 4;
		rect.w = obj->GetImage()->w / 4;
		rect.x = obj->GetPosition()->x - rect.w / 2;
		rect.y = obj->GetPosition()->y - rect.h / 2;

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, obj->GetImage());
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_DestroyTexture(texture);
	}
}

void SDLEngine::Render() {
	SDL_RenderPresent(renderer);
}


SDLEngine::~SDLEngine() {
	SDL_Quit();
}

