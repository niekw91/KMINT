#pragma once
#include "SDL.h"
#include "Node.h"
#include <string>

class GameObject
{
public:
	GameObject(std::string name, Node *start);
	virtual ~GameObject();

	void MoveTo(Node *dest);
	void LoadImage(std::string path);

	SDL_Surface *image;
	std::string name;
	Node *current;
};

