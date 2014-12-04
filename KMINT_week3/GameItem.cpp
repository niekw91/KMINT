#include "GameItem.h"
#include "Graph.h"

GameItem::GameItem(int id, std::string name, Node* start, Graph* graph) : BaseGameEntity(id, name, start, graph) {
}


GameItem::~GameItem() {
}

void GameItem::Update() {

}
