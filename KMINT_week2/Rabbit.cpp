#include "Rabbit.h"
#include "Node.h"

Rabbit::Rabbit(int id, std::string name, Node* start, Graph* graph) : BaseGameEntity(id, name, start, graph) {
	stateMachine = new StateMachine<Rabbit>(this);
	//stateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
	//stateMachine->SetGlobalState(MinerGlobalState::Instance());
}


Rabbit::~Rabbit() {
	delete stateMachine;
}

void Rabbit::Update() {
	stateMachine->Update();
}

void Rabbit::MoveTo(Node *dest) {
	if (dest) {
		GetPosition()->RemoveEntity(this);
		dest->AddEntity(this);
		SetPosition(dest);
	}
}

