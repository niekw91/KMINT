#include "GameObject.h"
#include "SDL_image.h"

GameObject::GameObject(std::string name, Node* start) {
	this->name = name;
	this->current = start;

	std::string path = "Images\\" + name + ".png";
	LoadImage(path.c_str());
}

void GameObject::LoadImage(std::string path) {
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


GameObject::~GameObject()
{
}

void GameObject::MoveTo(Node *dest) {
	if (dest->GetGameObject()) {
		GameObject *obj = dest->GetGameObject();
		dest->SetGameObject(nullptr);
	}
	if (current->GetGameObject() == this) {
		current->SetGameObject(nullptr);
		dest->SetGameObject(this);
		current = dest;
	}
}
