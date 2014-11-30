#pragma once
#include "State.h"

class Cow;

class ChaseRabbitState : public State<Cow>
{
private:
	ChaseRabbitState();
	ChaseRabbitState(const ChaseRabbitState&);
	ChaseRabbitState& operator=(const ChaseRabbitState&);
public:
	static ChaseRabbitState* Instance();

	virtual void Enter(Cow* cow);
	virtual void Execute(Cow* cow);
	virtual void Exit(Cow* cow);
	std::string GetName();
};
