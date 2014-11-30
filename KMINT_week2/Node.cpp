#include "Node.h"
#include "Edge.h"
#include "BaseGameEntity.h"
#include <algorithm>

Node::Node() {

}

Node::Node(int x, int y, int id) {
	edges = std::vector<Edge*>();
	entities = std::vector<BaseGameEntity*>();
	this->x = x;
	this->y = y;
	this->id = id;
}


Node::~Node() {
}

Node* Node::AddEdge(Node *child, int w) {
	Edge *edge = new Edge(w, this, child);
	edges.push_back(edge);

	bool createEdge = true;
	if (!child->GetEdges().empty()) {
		for (auto e : child->GetEdges()) {
			if (e->parent == child && e->child == this)
				createEdge = false;
		}
	}
	// Create edge if child->GetEdges is empty OR edge does not already exist
	if (createEdge)
		child->AddEdge(this, w);

	return this;
}

std::vector<Edge*> Node::GetEdges() {
	return edges;
}

void Node::AddEntity(BaseGameEntity *entity) {
	this->entities.push_back(entity);
}

void Node::RemoveEntity(BaseGameEntity *entity) {
	this->entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

std::vector<BaseGameEntity*> Node::GetEntities() {
	return entities;
}

BaseGameEntity* Node::ContainsEntity(std::string name) {
	for (std::vector<BaseGameEntity*>::size_type i = 0; i != entities.size(); i++) {
		if (entities[i]->GetName() == name) 
			return entities[i];
	}
	return nullptr;
}