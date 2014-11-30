#include "Edge.h"
#include "Node.h"

Edge::Edge(int weight, Node *parent, Node *child) {
	this->weight = weight;
	this->parent = parent;
	this->child = child;
}


Edge::~Edge()
{
}
