#include "Node.h"
#include "Edge.h"

Node::Node() {

}

Node::Node(int x, int y, int id) {
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

void Node::SetGameObject(GameObject *obj) {
	gameObject = obj;
}

GameObject* Node::GetGameObject() {
	return gameObject;
}