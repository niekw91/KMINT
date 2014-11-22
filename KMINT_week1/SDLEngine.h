#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

#include <string>

class Graph;
class Node;
class GameObject;

class SDLEngine
{
public:
	SDLEngine(int width, int height);
	virtual ~SDLEngine();

	void Render();

	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawEllipseFromGraph(Graph* graph);
	void RenderImage(GameObject *obj);
	void RenderText(std::string text, int x, int y);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

