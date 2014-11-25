// SDL Portable installation
#include "SDL.h"
#include "SDLEngine.h"
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "GameObject.h"
#include "AStar.h"

#include <stack>

Graph* InitGraph();
void Draw(Graph *g, SDLEngine *e, GameObject *cow, GameObject *rabbit);
void CalcShortestPath(AStar *aStar);
Node* HandleMouseEvent(SDL_MouseButtonEvent e, Graph *g);

int main(int argc, char* argv[])
{
	Graph* graph = InitGraph();

	SDLEngine *engine = new SDLEngine(800, 600);

	GameObject *cow = new GameObject("Cow", graph->root);
	GameObject *rabbit = new GameObject("Rabbit", graph->allNodes[3]);

	graph->root->SetGameObject(cow);
	graph->allNodes[3]->SetGameObject(rabbit);
	
	Draw(graph, engine, cow, rabbit);

	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				return 0;
			if (event.button.type == SDL_MOUSEBUTTONDOWN) {
				Node *dest = HandleMouseEvent(event.button, graph);
				if (dest) {
					// Calculate shortest path
					AStar *aStar = new AStar(cow->current, dest);
					CalcShortestPath(aStar);

					// If destination contains rabbit, jump to another node
					if (dest->GetGameObject() != nullptr) {
						if (dest->GetGameObject()->name == "Rabbit") {
							Node* random = nullptr;
							do {
								random = graph->GetRandomNode(rabbit->current);
							} while (random == cow->current);
							rabbit->MoveTo(random);
						}
					}
					cow->MoveTo(dest);
					Draw(graph, engine, cow, rabbit);
				}
			}
		}
		engine->Render();
	}

	return 0;
}

Graph* InitGraph() {
	Graph *g = new Graph();
	Node *root = g->CreateRoot(110, 200, 1);
	Node *child = g->CreateNode(210, 120, 2);
	root->AddEdge(child, 50000);
	Node *node = g->CreateNode(150, 300, 3);
	root->AddEdge(node, 30000);
	node->AddEdge(child, 70000);
	child = g->CreateNode(320, 250, 4);
	node->AddEdge(child, 120000);
	Node *child2 = g->CreateNode(260, 310, 5);
	node->AddEdge(child2, 40000);
	child2->AddEdge(child, 60000);
	return g;
}

void CalcShortestPath(AStar *aStar) {
	std::stack<Node*> path = aStar->Find();
	printf("Shortest path: ");
	while (!path.empty()) {
		Node* step = path.top();
		path.pop();
		printf("[");
		printf(std::to_string(step->id).c_str());
		printf("] ");
	}
	printf("\n");
}

void Draw(Graph *g, SDLEngine *e, GameObject *cow, GameObject *rabbit) {
	e->DrawEllipseFromGraph(g);

	for (auto n : g->allNodes) {
		std::vector<Edge*> edges = n->GetEdges();
		for (auto ed : edges) {
			Node *child = ed->child;
			e->DrawLine(n->x, n->y, child->x, child->y);

			int x = (n->x + child->x) / 2;
			int y = (n->y + child->y) / 2;

			e->RenderText(std::to_string(ed->weight), x, y);
		}

		e->RenderText(std::to_string(n->id), n->x, n->y);
	}

	e->RenderImage(cow);
	e->RenderImage(rabbit);
}

Node* HandleMouseEvent(SDL_MouseButtonEvent e, Graph *g) {
	int minX = e.x - 10;
	int maxX = e.x + 10;
	int minY = e.y - 10;
	int maxY = e.y + 10;

	for (auto n : g->allNodes) {
		if (n->x > minX && n->x < maxX && n->y > minY && n->y < maxY)
			return n;
	}
	return nullptr;
}

