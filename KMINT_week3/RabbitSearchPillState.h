#pragma once
#include "State.h"

class Rabbit;

class RabbitSearchPillState : public State<Rabbit>
{
private:
	RabbitSearchPillState();
	RabbitSearchPillState(const RabbitSearchPillState&);
	RabbitSearchPillState& operator=(const RabbitSearchPillState&);
public:
	static RabbitSearchPillState* Instance();

	virtual void Enter(Rabbit* rabbit);
	virtual void Execute(Rabbit* rabbit);
	virtual void Exit(Rabbit* rabbit);
	std::string GetName();
};

