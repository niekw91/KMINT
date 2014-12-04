#include "RabbitSearchWeaponState.h"
#include "RabbitAttackState.h"
#include "GameItem.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

RabbitSearchWeaponState::RabbitSearchWeaponState() {

}

RabbitSearchWeaponState* RabbitSearchWeaponState::Instance() {
	static RabbitSearchWeaponState instance;

	return &instance;
}

void RabbitSearchWeaponState::Enter(Rabbit* rabbit) {

}

void RabbitSearchWeaponState::Execute(Rabbit* rabbit)
{
	Node* current = rabbit->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	if (next->ContainsEntity("Gun")) {
		BaseGameEntity *gun = next->ContainsEntity("Gun");
		next->RemoveEntity(gun);
		gun->SetPosition(nullptr);

		rabbit->Pickup(static_cast<GameItem*>(gun));

		printf("Rabbit: picked up gun\n");

		rabbit->GetFSM()->ChangeState(RabbitAttackState::Instance());
	}
	rabbit->MoveTo(next);
}

void RabbitSearchWeaponState::Exit(Rabbit* rabbit) {

}

std::string RabbitSearchWeaponState::GetName() {
	return "Search Weapon";
}