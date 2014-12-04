#include "Rabbit.h"
#include "Node.h"
#include "RabbitWanderingState.h"
#include "GameItem.h"
#include "Graph.h"

Rabbit::Rabbit(int id, std::string name, Node* start, Graph* graph) : BaseGameEntity(id, name, start, graph) {
	stateMachine = new StateMachine<Rabbit>(this);
	stateMachine->SetCurrentState(RabbitWanderingState::Instance());
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

std::string Rabbit::GetCurrentState() {
	return stateMachine->CurrentState()->GetName();
}

void Rabbit::Pickup(GameItem *item) {
	this->item = item;
}

bool Rabbit::HasPill() {
	if (item && item->GetName() == "Pill")
		return true;
	return false;
}

bool Rabbit::HasWeapon() {
	if (item && item->GetName() == "Weapon")
		return true;
	return false;
}

void Rabbit::ThrowAway() {
	if (HasPill() || HasWeapon()) {
		Node* random = GetGraph()->GetRandomNode(nullptr);
		random->AddEntity(item);
		item->SetPosition(random);
		item = nullptr;
	}
}