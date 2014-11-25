#pragma once
#include <string>
#include <vector>

class Edge;
class GameObject;

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
	void SetGameObject(GameObject *obj);
	GameObject* GetGameObject();

	void CalculateH(Node *dest);

	bool operator<(const Node& n)const {
		return f_totalDistance < n.f_totalDistance;

		if (f_totalDistance != n.f_totalDistance)
			return f_totalDistance < n.f_totalDistance;

	}

private:
	GameObject *gameObject;

	std::vector<Edge*> edges;
};

