#pragma once
#include "State.h"

class Rabbit;

class RabbitSearchWeaponState : public State<Rabbit>
{
private:
	RabbitSearchWeaponState();
	RabbitSearchWeaponState(const RabbitSearchWeaponState&);
	RabbitSearchWeaponState& operator=(const RabbitSearchWeaponState&);
public:
	static RabbitSearchWeaponState* Instance();

	virtual void Enter(Rabbit* rabbit);
	virtual void Execute(Rabbit* rabbit);
	virtual void Exit(Rabbit* rabbit);
	std::string GetName();
};

