#pragma once
#include "State.h"

class Cow;

class SearchWeaponState : public State<Cow>
{
private:
	SearchWeaponState();
	SearchWeaponState(const SearchWeaponState&);
	SearchWeaponState& operator=(const SearchWeaponState&);
public:
	static SearchWeaponState* Instance();

	virtual void Enter(Cow* cow);
	virtual void Execute(Cow* cow);
	virtual void Exit(Cow* cow);
	std::string GetName();
};
