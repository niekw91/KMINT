#pragma once
#include "BaseGameEntity.h"

class Graph;

class GameItem : public BaseGameEntity
{
private:

public:
	GameItem(int id, std::string name, Node* start, Graph* graph);
	virtual ~GameItem();

	void Update();
};

