#pragma once
#include <string>
#include "SDL.h"

class Graph;
class Node;

class BaseGameEntity
{
private:
	int id;
	std::string name;
	Node* position;
	SDL_Surface* image;
	Graph* graph;
public:
	BaseGameEntity(int id, std::string name, Node* start, Graph* graph);
	virtual ~BaseGameEntity(){}

	virtual void Update() = 0;

	int GetId()const { return id; }
	void SetId(int val);
	void MoveTo(Node *dest);
	void LoadImage(std::string path);

	Graph* GetGraph();
	std::string GetName();
	SDL_Surface* GetImage();
	Node* GetPosition();
	void SetPosition(Node* pos);
};

