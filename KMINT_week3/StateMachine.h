#pragma once
#include <cassert>
#include <string>

#include "State.h"

template <class entity_type>
class StateMachine
{
private:
	entity_type* owner;
	State<entity_type>* currentState;
	State<entity_type>* previousState;
	// The global state contains state logic that is called 
	// every time the FSM is updated
	State<entity_type>* globalState;
public:
	StateMachine(entity_type* owner) : owner(owner),
		currentState(NULL),
		previousState(NULL),
		globalState(NULL)
	{}

	// Initialization methods
	void SetCurrentState(State<entity_type>* s) { currentState = s; }
	void SetGlobalState(State<entity_type>* s) { globalState = s; }
	void SetPreviousState(State<entity_type>* s) { previousState = s; }

	void Update()const
	{
		// If a global state exists, call its execute method
		if (globalState) globalState->Execute(owner);
		// If a current state exists, call its execute methode
		if (currentState) currentState->Execute(owner);
	}

	// Change to a new state
	void ChangeState(State<entity_type>* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");

		previousState = currentState;

		// Exit the current state
		currentState->Exit(owner);
		// Change to new state
		currentState = pNewState;
		// Enter new state
		currentState->Enter(owner);
	}

	// Change state back to the previous state
	void RevertToPreviousState()
	{
		ChangeState(previousState);
	}

	State<entity_type>* CurrentState() const{ return currentState; }
	State<entity_type>* GlobalState() const{ return globalState; }
	State<entity_type>* PreviousState() const{ return previousState; }

	bool isInState(const State<entity_type>& st)const;
};

