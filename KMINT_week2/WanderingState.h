#pragma once
#include "State.h"

class Cow;

class WanderingState : public State<Cow>
{
private:
	WanderingState();
	WanderingState(const WanderingState&);
	WanderingState& operator=(const WanderingState&);
public:
	static WanderingState* Instance();

	virtual void Enter(Cow* cow);
	virtual void Execute(Cow* cow);
	virtual void Exit(Cow* cow);
	std::string GetName();
};

