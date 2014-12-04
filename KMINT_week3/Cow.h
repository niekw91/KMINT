#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"

#include <string>

class Node;
class Graph;

class Cow : public BaseGameEntity
{
private:
	StateMachine<Cow>* stateMachine;
	int stunCount;
public:
	Cow(int id, std::string name, Node* start, Graph* graph);
	virtual ~Cow();

	void Update();
	void MoveTo(Node *dest);
	void Stun();
	bool IsStunned();
	std::string GetCurrentState();
	StateMachine<Cow>* GetFSM()const 
	{ 
		return stateMachine; 
	}
};


