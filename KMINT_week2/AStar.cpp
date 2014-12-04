#include "AStar.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

AStar::AStar(Node* source, Node* target) {
	this->source = source;
	this->target = target;

	openList.insert(source);
	cameFrom[source->id] = nullptr;
}

AStar::~AStar() {
}

std::stack<Node*> AStar::Find() {
	source->g_distanceToSource = 0;
	source->f_totalDistance = source->g_distanceToSource + CalculateH(source->x, source->y, target->x, target->y);

	while (!openList.empty()) {
		Node* current = (*openList.begin());

		if (current == target)
			return ReconstructPath(target);

		openList.erase(current);
		closedList.push_back(current);

		for (int i = 0; i < current->GetEdges().size(); i++) {
			Node* next = current->GetEdges()[i]->child;
			// If 'next' is in closed list, continue
			if (std::find(closedList.begin(), closedList.end(), next) != closedList.end())
				continue;

			double g_Cost = current->g_distanceToSource + current->GetEdges()[i]->weight;

			if (openList.find(next) == openList.end() || g_Cost < next->g_distanceToSource) {
				cameFrom[next->id] = current;
				next->g_distanceToSource = g_Cost;
				next->f_totalDistance = next->g_distanceToSource + CalculateH(next->x, next->y, target->x, target->y);
				// If not on open list, add
				openList.insert(next);
			}
		}
	}
}

std::stack<Node*> AStar::ReconstructPath(Node* current) {
	std::stack<Node*> totalPath = std::stack<Node*>();
	totalPath.push(current);

	int id = current->id;
	while (cameFrom[id] != nullptr) {
		Node* prev = cameFrom[id];
		totalPath.push(prev);
		id = prev->id;
	}

	return totalPath;
}

float AStar::CalculateH(int x1, int y1, int x2, int y2)
{
	float distance, tempx, tempy;
	tempx = (x1 - x2);
	tempx = tempx * tempx;
	tempy = (y1 - y2);
	tempy = tempy * tempy;
	distance = tempx + tempy;
	distance = sqrt(distance);
	return distance;
}

bool AStar::CompareNode::operator() (const Node* pNode1, const Node* pNode2) const
{
	if (pNode1 == pNode2)
		return false;
	if (pNode1 == nullptr)
		return true;
	if (pNode2 == nullptr)
		return false;

	return *pNode1 < *pNode2;
}