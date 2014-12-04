#ifndef STATE_H
#define STATE_H

#include <string>

template <class entity_type>
class State
{
public:
	virtual void Enter(entity_type*) = 0;
	virtual void Execute(entity_type*) = 0;
	virtual void Exit(entity_type*) = 0;
	virtual std::string GetName() = 0;
	virtual ~State(){}
};

#endif