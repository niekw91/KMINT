#pragma once
#include <string>
#include <vector>

class Edge;
class BaseGameEntity;

class Node
{
public:
	Node();
	Node(int x, int y, int id);
	virtual ~Node();

	int id;

	int x, y;
	double f_totalDistance;
	double g_distanceToSource;

	Node* AddEdge(Node *child, int w);
	std::vector<Edge*> GetEdges();
	void AddEntity(BaseGameEntity *entity);
	std::vector<BaseGameEntity*> GetEntities();
	void RemoveEntity(BaseGameEntity *entity);
	BaseGameEntity* ContainsEntity(std::string name);

	bool operator<(const Node& n)const {
		return f_totalDistance < n.f_totalDistance;

		if (f_totalDistance != n.f_totalDistance)
			return f_totalDistance < n.f_totalDistance;

	}

private:
	std::vector<BaseGameEntity*> entities;

	std::vector<Edge*> edges;
};

