#pragma once
#include "State.h"

class Rabbit;

class RabbitSleepingState : public State<Rabbit>
{
private:
	RabbitSleepingState();
	RabbitSleepingState(const RabbitSleepingState&);
	RabbitSleepingState& operator=(const RabbitSleepingState&);
public:
	static RabbitSleepingState* Instance();

	virtual void Enter(Rabbit* rabbit);
	virtual void Execute(Rabbit* rabbit);
	virtual void Exit(Rabbit* rabbit);
	std::string GetName();
};