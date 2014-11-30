#include "WanderingState.h"
#include "SearchWeaponState.h"
#include "Cow.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

WanderingState::WanderingState() {

}

WanderingState* WanderingState::Instance() {
	static WanderingState instance;
	
	return &instance;
}

void WanderingState::Enter(Cow* cow) {

}

void WanderingState::Execute(Cow* cow)
{
	Node* current = cow->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;	

	cow->MoveTo(next);

	if (Random::Next(1, 5) == 1)
		cow->GetFSM()->ChangeState(SearchWeaponState::Instance());
}

void WanderingState::Exit(Cow* cow) {

}

std::string WanderingState::GetName() {
	return "Wandering";
}