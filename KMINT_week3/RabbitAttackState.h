#pragma once
#include "State.h"

class Rabbit;

class RabbitAttackState : public State<Rabbit>
{
private:
	RabbitAttackState();
	RabbitAttackState(const RabbitAttackState&);
	RabbitAttackState& operator=(const RabbitAttackState&);
public:
	static RabbitAttackState* Instance();

	virtual void Enter(Rabbit* rabbit);
	virtual void Execute(Rabbit* rabbit);
	virtual void Exit(Rabbit* rabbit);
	std::string GetName();
};

