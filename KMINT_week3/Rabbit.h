#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"

class Node;
class Graph;
class GameItem;

class Rabbit : public BaseGameEntity
{
private:
	StateMachine<Rabbit>* stateMachine;
	GameItem* item;
public:
	Rabbit(int id, std::string name, Node* start, Graph* graph);
	virtual ~Rabbit();

	void Update();
	void MoveTo(Node *dest); 
	void Pickup(GameItem *item);
	bool HasPill();
	bool HasWeapon();
	void ThrowAway();
	std::string GetCurrentState();
	StateMachine<Rabbit>* GetFSM()const
	{
		return stateMachine;
	}
};

