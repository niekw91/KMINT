#include "RabbitWanderingState.h"
#include "RabbitSearchPillState.h"
#include "RabbitSearchWeaponState.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

RabbitWanderingState::RabbitWanderingState() {

}

RabbitWanderingState* RabbitWanderingState::Instance() {
	static RabbitWanderingState instance;

	return &instance;
}

void RabbitWanderingState::Enter(Rabbit* rabbit) {

}

void RabbitWanderingState::Execute(Rabbit* rabbit)
{
	Node* current = rabbit->GetPosition();

	if (!rabbit->HasPill()) {
		for (auto e : current->GetEdges()) {
			if (e->child->ContainsEntity("Cow")) {
				int choice = Random::Next(1, 3);
				if (choice == 1) {
					printf("Rabbit: searching for pill!\n");
					rabbit->GetFSM()->ChangeState(RabbitSearchPillState::Instance());
				}
				if (choice == 2) {
					printf("Rabbit: searching for weapon!\n");
					rabbit->GetFSM()->ChangeState(RabbitSearchWeaponState::Instance());
				}
				if (choice == 3) {
					printf("Rabbit: running!\n");
				}
			}
		}
	}

	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	rabbit->MoveTo(next);
}

void RabbitWanderingState::Exit(Rabbit* rabbit) {

}

std::string RabbitWanderingState::GetName() {
	return "Wandering";
}