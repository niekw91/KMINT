#include "BaseGameEntity.h"
#include "Graph.h"
#include "Node.h"
#include "SDL_image.h"

BaseGameEntity::BaseGameEntity(int id, std::string name, Node* start, Graph* graph) {
	this->id = id;
	this->name = name;
	this->position = start;
	this->graph = graph;

	std::string path = "Images\\" + name + ".png";
	LoadImage(path.c_str());
}

void BaseGameEntity::LoadImage(std::string path) {
	int pngFlags = IMG_INIT_PNG;
	if (!(IMG_Init(pngFlags) & pngFlags))
		printf("SDL_image Error: %s\n", IMG_GetError());
	else
	{
		// Load image at specified path
		SDL_Surface *surface = IMG_Load(path.c_str());
		if (surface != NULL) {
			image = surface;
		}
	}
}

std::string BaseGameEntity::GetName() {
	return name;
}

Node* BaseGameEntity::GetPosition() {
	return position;
}

void BaseGameEntity::SetPosition(Node* pos) {
	position = pos;
}

SDL_Surface* BaseGameEntity::GetImage() {
	return image;
}

Graph* BaseGameEntity::GetGraph() {
	return graph;
}