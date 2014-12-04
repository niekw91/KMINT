#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"

class Node;
class Graph;

class Rabbit : public BaseGameEntity
{
private:
	StateMachine<Rabbit>* stateMachine;
public:
	Rabbit(int id, std::string name, Node* start, Graph* graph);
	virtual ~Rabbit();

	void Update();
	void MoveTo(Node *dest); 
	std::string GetCurrentState();
	StateMachine<Rabbit>* GetFSM()const
	{
		return stateMachine;
	}
};

