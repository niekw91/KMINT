#include "CowWanderingState.h"
#include "SearchWeaponState.h"
#include "Cow.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

CowWanderingState::CowWanderingState() {

}

CowWanderingState* CowWanderingState::Instance() {
	static CowWanderingState instance;

	return &instance;
}

void CowWanderingState::Enter(Cow* cow) {

}

void CowWanderingState::Execute(Cow* cow)
{
	Node* current = cow->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	cow->MoveTo(next);

	if (Random::Next(1, 5) == 1)
		cow->GetFSM()->ChangeState(SearchWeaponState::Instance());
}

void CowWanderingState::Exit(Cow* cow) {

}

std::string CowWanderingState::GetName() {
	return "Wandering";
}