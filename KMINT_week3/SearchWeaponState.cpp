#include "SearchWeaponState.h"
#include "ChaseRabbitState.h"
#include "Cow.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

SearchWeaponState::SearchWeaponState() {

}

SearchWeaponState* SearchWeaponState::Instance() {
	static SearchWeaponState instance;

	return &instance;
}

void SearchWeaponState::Enter(Cow* cow) {

}

void SearchWeaponState::Execute(Cow* cow)
{
	Node* current = cow->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	if (next->ContainsEntity("Gun")) {
		BaseGameEntity *gun = next->ContainsEntity("Gun");
		next->RemoveEntity(gun);
		gun->SetPosition(nullptr);

		cow->GetFSM()->ChangeState(ChaseRabbitState::Instance());
	}
	cow->MoveTo(next);
}

void SearchWeaponState::Exit(Cow* cow) {

}

std::string SearchWeaponState::GetName() {
	return "Search Weapon";
}
