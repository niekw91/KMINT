#pragma once
#include "State.h"

class Cow;

class CowWanderingState : public State<Cow>
{
private:
	CowWanderingState();
	CowWanderingState(const CowWanderingState&);
	CowWanderingState& operator=(const CowWanderingState&);
public:
	static CowWanderingState* Instance();

	virtual void Enter(Cow* cow);
	virtual void Execute(Cow* cow);
	virtual void Exit(Cow* cow);
	std::string GetName();
};

