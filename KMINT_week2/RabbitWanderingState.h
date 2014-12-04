#pragma once
#include "State.h"

class Rabbit;

class RabbitWanderingState : public State<Rabbit>
{
private:
	RabbitWanderingState();
	RabbitWanderingState(const RabbitWanderingState&);
	RabbitWanderingState& operator=(const RabbitWanderingState&);
public:
	static RabbitWanderingState* Instance();

	virtual void Enter(Rabbit* rabbit);
	virtual void Execute(Rabbit* rabbit);
	virtual void Exit(Rabbit* rabbit);
	std::string GetName();
};


