#include "ChaseRabbitState.h"
#include "SDL.h"
#include "BaseGameEntity.h"
#include "Cow.h"
#include "Node.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Edge.h"
#include "AStar.h"
#include "Random.h"

ChaseRabbitState::ChaseRabbitState() {

}

ChaseRabbitState* ChaseRabbitState::Instance() {
	static ChaseRabbitState instance;

	return &instance;
}

void ChaseRabbitState::Enter(Cow* cow) {

}

void ChaseRabbitState::Execute(Cow* cow)
{
	if (!cow->IsStunned()) {
		Node* current = cow->GetPosition();

		Node* next = current->GetEdges()[Random::Next(0, current->GetEdges().size() - 1)]->child;

		cow->MoveTo(next);

		if (next->ContainsEntity("Rabbit")) {
			BaseGameEntity* entity = next->ContainsEntity("Rabbit");
			Rabbit *rabbit = static_cast<Rabbit*>(entity);
			if (rabbit->HasPill()) {
				cow->Stun();
				rabbit->ThrowAway();
				printf("Cow: eating sleeping pill\n");
			}
		}
	}
	else
	{
		printf("Cow: unable to move\n");
	}

	//Node* target = cow->GetGraph()->GetRabbitNode();
	//// Calculate shortest path
	//AStar *aStar = new AStar(cow->GetPosition(), target);
	//


	//cow->MoveTo(target);

}

void ChaseRabbitState::Exit(Cow* cow) {

}

std::string ChaseRabbitState::GetName() {
	return "Chase Rabbit";
}