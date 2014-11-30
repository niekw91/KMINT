#include "ChaseRabbitState.h"
#include "SDL.h"
#include "Cow.h"
#include "Node.h"
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
	Node* current = cow->GetPosition();
	
	Node* target = cow->GetGraph()->GetRabbitNode();
	// Calculate shortest path
	AStar *aStar = new AStar(cow->GetPosition(), target);
	
	std::stack<Node*> path = aStar->Find();
	printf("Shortest path: ");
	while (!path.empty()) {
		Node* step = path.top();
		path.pop();
		printf("[");
		printf(std::to_string(step->id).c_str());
		printf("] ");
	}
	printf("\n");

	cow->MoveTo(target);

	SDL_ShowSimpleMessageBox(0, "Rabbit found!", "The cow has found the rabbit", NULL);
	SDL_Quit();
}

void ChaseRabbitState::Exit(Cow* cow) {

}

std::string ChaseRabbitState::GetName() {
	return "Chase Rabbit";
}