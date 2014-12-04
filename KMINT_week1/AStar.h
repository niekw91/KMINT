#pragma once
#include <vector>
#include <set>
#include <map>
#include <stack>

class Node;
class Graph;
class Edge;

class AStar
{
public:
	AStar(Node* source, Node* target);
	virtual ~AStar();

	std::stack<Node*> Find();

private:
	Graph *graph;

	Node* source;
	Node* target;

	float CalculateH(int x1, int y1, int x2, int y2);
	std::stack<Node*> ReconstructPath(Node* current);

	class CompareNode
	{
	public:
		bool operator () ( const Node*, const Node* ) const;
	};

	std::set<Node*,CompareNode> openList;
	std::vector<Node*> closedList;
	std::map<int, Node*> cameFrom;
};

