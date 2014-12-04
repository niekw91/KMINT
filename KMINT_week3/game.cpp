// SDL Portable installation
#include "SDL.h"
#include "Timer.h"
#include "SDLEngine.h"
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "BaseGameEntity.h"
#include "AStar.h"
#include "Cow.h"
#include "GameItem.h"
#include "Rabbit.h"

#include <sstream>
#include <stack>

Graph* InitGraph();
void Draw(Graph *g, SDLEngine *e, Cow *cow, Rabbit *rabbit, std::vector<GameItem*> gameItems);
void CalcShortestPath(AStar *aStar);
Node* HandleMouseEvent(SDL_MouseButtonEvent e, Graph *g);

const int SCREEN_FPS = 1;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char* argv[])
{
	/*
	 * FPS Timer variables
	 *************************************************************************/
	// The frames per second timer
	Timer fpsTimer;

	// The frames per second cap timer
	Timer capTimer;

	// In memory text stream
	std::stringstream timeText;

	// Start counting frames per second
	int countedFrames = 0;
	fpsTimer.start();


	/*
	 * Graph initialization
	 *************************************************************************/
	Graph* graph = InitGraph();

	SDLEngine *engine = new SDLEngine(800, 600);

	Cow *cow = new Cow(1, "Cow", graph->GetRandomNode(nullptr), graph);
	Rabbit *rabbit = new Rabbit(2, "Rabbit", graph->GetRandomNode(nullptr), graph);
	GameItem *gun = new GameItem(3, "Gun", graph->GetRandomNode(rabbit->GetPosition()), graph);
	GameItem *pill = new GameItem(4, "Pill", graph->GetRandomNode(gun->GetPosition()), graph);

	cow->GetPosition()->AddEntity(cow);
	rabbit->GetPosition()->AddEntity(rabbit);
	gun->GetPosition()->AddEntity(gun);
	pill->GetPosition()->AddEntity(pill);

	std::vector<GameItem*> gameItems;
	gameItems.push_back(gun);
	gameItems.push_back(pill);
	
	Draw(graph, engine, cow, rabbit, gameItems);


	/*
	* Game Loop
	*************************************************************************/
	while (true)
	{
		//Start cap timer
		capTimer.start();

		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.get_ticks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		cow->Update();
		rabbit->Update();
		Draw(graph, engine, cow, rabbit, gameItems);
		engine->Render();

		++countedFrames;
		//If frame finished early
		int frameTicks = capTimer.get_ticks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				return 0;
		}

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
	Node* child3 = g->CreateNode(410, 410, 5);
	child->AddEdge(child3, 80000);
	Node * child4 = g->CreateNode(180, 410, 6);
	child3->AddEdge(child4, 50000);
	Node *child2 = g->CreateNode(260, 310, 7);
	child2->AddEdge(child4, 30000);
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

void Draw(Graph *g, SDLEngine *e, Cow *cow, Rabbit *rabbit, std::vector<GameItem*> gameItems) {
	e->DrawEllipseFromGraph(g);

	for (auto n : g->allNodes) {
		std::vector<Edge*> edges = n->GetEdges();
		for (auto ed : edges) {
			Node *child = ed->child;
			e->DrawLine(n->x, n->y, child->x, child->y);

			int x = (n->x + child->x) / 2;
			int y = (n->y + child->y) / 2;

			e->RenderText(std::to_string(ed->weight), x, y + 15);
		}

		e->RenderText(std::to_string(n->id), n->x, n->y);
	}

	e->RenderImage(cow);
	e->RenderText(cow->GetCurrentState(), cow->GetPosition()->x, cow->GetPosition()->y + 60);
	e->RenderImage(rabbit);
	e->RenderText(rabbit->GetCurrentState(), rabbit->GetPosition()->x, rabbit->GetPosition()->y + 60);
	for (auto g : gameItems)
		e->RenderImage(g);
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

