#include "Graph.h"
#include "Node.h"
#include "Random.h"

Graph::Graph() {
	allNodes = std::vector<Node*>();
}


Graph::~Graph()
{
}

Node* Graph::GetRandomNode(Node *current) {
	std::vector<Node*>::iterator it = std::find(allNodes.begin(), allNodes.end(), current);
	size_t index = std::distance(allNodes.begin(), it);

	int random = 0;
	do {
		random = Random::Next(0, allNodes.size() - 1);
	} while (random == index);

	return allNodes[random];
}

Node* Graph::CreateNode(int x, int y, int id) {
	Node *n = new Node(x, y, id);
	allNodes.push_back(n);
	return n;
}

Node* Graph::CreateRoot(int x, int y, int id) {
	root = CreateNode(x, y, id);
	return root;
}