#pragma once
#include <vector>
#include <set>

class Node;
class Graph;
class Edge;

class AStar
{
public:
	AStar(Node* source, Node* target);
	virtual ~AStar();

	void Search(Node *src, Node *dest);
	void Search();

private:
	Graph *graph;

	Node* source;
	Node* target;

	bool targetFound;

	void Find();
	void Trace();

	float CalculateH(int x1, int y1, int x2, int y2);
	////indexed into by node. Contains the "real" cumulative cost to that node
	//std::vector<double> gCosts;
	////indexed into by node. Contains the cost from adding m_GCosts[n] to
	////the heuristic cost from n to the target node. This is the vector the
	////iPQ indexes into.
	//std::vector<double> fCosts;

	//std::vector<const Edge*> shortestPathTree;
	//std::vector<const Edge*> searchFrontier;

	//int iSource;
	//int iTarget;

	std::set<Node*> openList;
	std::vector<Node*> closedList;
};

