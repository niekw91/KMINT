#pragma once
#include <vector>
#include <string>

class Node;

class Graph
{
public:
	Graph();
	virtual ~Graph();

	Node* CreateRoot(int x, int y, int id);
	Node* CreateNode(int x, int y, int id);
	Node* GetRandomNode(Node *current);

	Node* root;
	std::vector<Node*> allNodes;
};

