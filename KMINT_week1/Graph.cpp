#include "Graph.h"
#include "Node.h"


Graph::Graph() {
	allNodes = std::vector<Node*>();
}


Graph::~Graph()
{
}

Node* Graph::CreateNode(int x, int y, std::string id) {
	Node *n = new Node(x, y, id);
	allNodes.push_back(n);
	return n;
}

Node* Graph::CreateRoot(int x, int y, std::string id) {
	root = CreateNode(x, y, id);
	return root;
}