#include "AStar.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include <queue>

AStar::AStar(Node* source, Node* target) {
	openList = std::set<Node*>();
	closedList = std::vector<Node*>();
	//this->graph = graph;

	this->source = source;
	this->target = target;

	if (!targetFound)
		Find();
	if (targetFound)
		Trace();
}

AStar::~AStar() {
}

void AStar::Find() {
	Node* current = source;

	for (int i = 0; i < current->GetEdges().size(); i++) {
		if (!targetFound) {
			Node* dest = current->GetEdges()[i]->child;
			Search(current, dest);
		}
	}
}

void AStar::Search(Node* current, Node *dest) {
	if (!dest)
		return;

	if (dest == target) {
		targetFound = true;
		return;
	}

	// Check if dest not in closed list
	if (std::find(closedList.begin(), closedList.end(), dest) == closedList.end()) {
		// Check if dest is in open list
		if (std::find(openList.begin(), openList.end(), dest) != openList.end()) {
			double cost = current->g_distanceToSource + CalculateH(current->x, current->y, dest->x, dest->y);

			if (cost < dest->g_distanceToSource) {
				dest->g_distanceToSource = cost;
			}
		}
		else { // Not in open list
			
		}
	}
}


float AStar::CalculateH(int x1, int y1, int x2, int y2)
{
	float distance, tempx, tempy, tempz;
	tempx = (x1 - x2);
	tempx = tempx * tempx; //compiler _might_ be able to make this faster
	tempy = (y1 - y2);
	tempy = tempy * tempy;
	distance = tempx + tempy;
	distance = sqrt(distance);
	return distance;
}
