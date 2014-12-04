#include "RabbitSearchPillState.h"
#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"
#include "GameItem.h"

RabbitSearchPillState::RabbitSearchPillState() {

}

RabbitSearchPillState* RabbitSearchPillState::Instance() {
	static RabbitSearchPillState instance;

	return &instance;
}

void RabbitSearchPillState::Enter(Rabbit* rabbit) {

}

void RabbitSearchPillState::Execute(Rabbit* rabbit)
{
	Node* current = rabbit->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	if (next->ContainsEntity("Pill")) {
		BaseGameEntity *pill = next->ContainsEntity("Pill");
		next->RemoveEntity(pill);
		pill->SetPosition(nullptr);

		rabbit->Pickup(static_cast<GameItem*>(pill));

		printf("Rabbit: picked up pill\n");

		rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
	}
	rabbit->MoveTo(next);
}

void RabbitSearchPillState::Exit(Rabbit* rabbit) {

}

std::string RabbitSearchPillState::GetName() {
	return "Search Pill";
}