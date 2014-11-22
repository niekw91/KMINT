#pragma once
#include <vector>
#include <string>

class Node;

class Graph
{
public:
	Graph();
	virtual ~Graph();

	Node* CreateRoot(int x, int y, std::string id);
	Node* CreateNode(int x, int y, std::string id);

	Node* root;
	std::vector<Node*> allNodes;
};

