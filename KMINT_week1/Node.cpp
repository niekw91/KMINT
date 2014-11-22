#include "Node.h"
#include "Edge.h"

Node::Node() {

}

Node::Node(int x, int y, std::string id) {
	edges = std::vector<Edge*>();
	this->x = x;
	this->y = y;
	this->id = id;
}


Node::~Node() {
}

Node* Node::AddEdge(Node *child, int w) {
	Edge *edge = new Edge(w, this, child);
	edges.push_back(edge);

	for (auto e : child->GetEdges()) {
		if (e->parent != child && e->child == this)
			child->AddEdge(this, w);
	}

	return this;
}

std::vector<Edge*> Node::GetEdges() {
	return edges;
}

void Node::SetGameObject(GameObject *obj) {
	gameObject = obj;
}

GameObject* Node::GetGameObject() {
	return gameObject;
}