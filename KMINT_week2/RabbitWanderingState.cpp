#include "RabbitWanderingState.h"
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
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	rabbit->MoveTo(next);
}

void RabbitWanderingState::Exit(Rabbit* rabbit) {

}

std::string RabbitWanderingState::GetName() {
	return "Wandering";
}