#include "RabbitSleepingState.h"
#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include "Node.h"
#include "Edge.h"
#include "Random.h"

RabbitSleepingState::RabbitSleepingState() {

}

RabbitSleepingState* RabbitSleepingState::Instance() {
	static RabbitSleepingState instance;

	return &instance;
}

void RabbitSleepingState::Enter(Rabbit* rabbit) {

}

void RabbitSleepingState::Execute(Rabbit* rabbit)
{
	if (Random::Next(0, 10) == 1)
		rabbit->GetFSM()->ChangeState(RabbitWanderingState::Instance());
}

void RabbitSleepingState::Exit(Rabbit* rabbit) {

}

std::string RabbitSleepingState::GetName() {
	return "Sleeping";
}