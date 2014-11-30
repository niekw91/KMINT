#include "Cow.h"
#include "Node.h"
#include "WanderingState.h"


Cow::Cow(int id, std::string name, Node* start, Graph* graph) : BaseGameEntity(id, name, start, graph) {
	stateMachine = new StateMachine<Cow>(this);
	stateMachine->SetCurrentState(WanderingState::Instance());
	//stateMachine->SetGlobalState(MinerGlobalState::Instance());
}


Cow::~Cow() {
	delete stateMachine;
}

void Cow::Update() {
	stateMachine->Update();
}

void Cow::MoveTo(Node *dest) {
	if (dest) {
		GetPosition()->RemoveEntity(this);
		dest->AddEntity(this);
		SetPosition(dest);
	}
}

std::string Cow::GetCurrentState() {
	return stateMachine->CurrentState()->GetName();
}