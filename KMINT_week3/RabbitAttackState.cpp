#include "RabbitAttackState.h"
#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Cow.h"
#include "Graph.h"
#include "Random.h"
#include "GameItem.h"

RabbitAttackState::RabbitAttackState() {

}

RabbitAttackState* RabbitAttackState::Instance() {
	static RabbitAttackState instance;

	return &instance;
}

void RabbitAttackState::Enter(Rabbit* rabbit) {

}

void RabbitAttackState::Execute(Rabbit* rabbit)
{
	Node* current = rabbit->GetPosition();
	Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

	for (auto e : current->GetEdges()) {
		if (e->child->ContainsEntity("Cow")) {
			BaseGameEntity *entity = e->child->ContainsEntity("Cow");
			rabbit->ThrowAway();
			Node* random = rabbit->GetGraph()->GetRandomNode(entity->GetPosition());
			entity->GetPosition()->RemoveEntity(entity);
			random->AddEntity(entity);

			printf("Cow: i got shot\n");

			rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
		}
	}
	rabbit->MoveTo(next);
}

void RabbitAttackState::Exit(Rabbit* rabbit) {

}

std::string RabbitAttackState::GetName() {
	return "Search Pill";
}