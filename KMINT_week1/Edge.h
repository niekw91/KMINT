#pragma once

class Node;

class Edge
{
public:
	Edge(int weight, Node *parent, Node *child);
	virtual ~Edge();

	int weight;
	Node *parent;
	Node *child;
};

