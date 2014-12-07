#include "RabbitWanderingState.h"
#include "RabbitSleepingState.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
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
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	if (next->ContainsEntity("Pill")) {
		BaseGameEntity *pill = next->ContainsEntity("Pill");
		next->RemoveEntity(pill);

		Node *random = rabbit->GetGraph()->GetRandomNode(next);
		random->AddEntity(pill);
		pill->SetPosition(random);

		rabbit->GetFSM()->ChangeState(RabbitSleepingState::Instance());
	}

	rabbit->MoveTo(next);
}

void RabbitWanderingState::Exit(Rabbit* rabbit) {

}

std::string RabbitWanderingState::GetName() {
	return "Wandering";
}