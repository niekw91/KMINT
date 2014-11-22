// SDL Portable installation
#include "SDL.h"
#include "SDLEngine.h"
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "GameObject.h"

Graph* InitGraph();
void Update();
void Draw(Graph *g, SDLEngine *e, GameObject *cow, GameObject *rabbit);
Node* HandleMouseEvent(SDL_MouseButtonEvent e, Graph *g);

int main(int argc, char* argv[])
{
	bool quit = false;

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
	Node *root = g->CreateRoot(110, 200, "A");
	Node *child = g->CreateNode(210, 120, "B");
	root->AddEdge(child, 50);
	Node *node = g->CreateNode(150, 300, "C");
	root->AddEdge(node, 30);
	node->AddEdge(child, 70);
	child = g->CreateNode(320, 250, "D");
	node->AddEdge(child, 120);
	Node *child2 = g->CreateNode(260, 310, "E");
	node->AddEdge(child2, 40);
	child2->AddEdge(child, 60);
	return g;
}

void Draw(Graph *g, SDLEngine *e, GameObject *cow, GameObject *rabbit) {
	e->DrawEllipseFromGraph(g);

	for (auto n : g->allNodes) {
		std::vector<Edge*> edges = n->GetEdges();
		for (auto ed : edges) {
			Node *child = ed->child;
			e->DrawLine(n->x, n->y, child->x, child->y);

			int x = n->x > child->x ? n->x - (n->x - child->x) : child->x - (child->x - n->x);
			int y = n->y > child->y ? n->y - (n->y - child->y) : child->y - (child->y - n->y);

			e->RenderText(std::to_string(ed->weight), x, y);
		}

		e->RenderText(n->id, n->x, n->y);
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

