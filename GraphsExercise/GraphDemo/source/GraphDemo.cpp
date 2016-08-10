#include "GraphDemo.h"
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "Pathfinder.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include "Vector2.h"
#include <string>
#include <limits>
#include "Agent.h"
#include "KeyboardController.h"
#include "ArrowKeyController.h"
#include <chrono>
#include <iostream>
#include <math.h>
#include "FollowPath.h"
#include "Selector.h"
#include "Sequence.h"
#include "FindPath.h"
#include "Flee.h"
#include "BehaviourState.h"

Pathfinder* thepath;
Node* firstnode = nullptr;
std::list<Node*> path;
Node* secondnode;

GraphDemo::GraphDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	srand(time(NULL));
	sNode = nullptr;
	eNode = nullptr;
	//Sequence* wander = new Sequence();
	//wander->AddChild(new GetRandomPath());
	//wander->AddChild(new FollowPath());

	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);	

	m_graph = new Graph;
	//Node *a = m_graph->AddNode(Vector2(100, 100)); 
	
	float graphScale = 2.5f;
	
	Vector2 startOffset(50, 50);

	int sizeX = 10;
	int sizeY = 5;
	int padding = 100;

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			m_graph->AddNode(Vector2(i * padding + startOffset.m_x, j * padding + startOffset.m_y));
		}
	}

	for (Node* src : m_graph->m_list)
	{
		for (Node* dest : m_graph->m_list)
		{
			float distance = src->pos.distance(dest->pos);

			if (distance <= padding + (padding / 2) && src != dest)
			{
				m_graph->ConnectNodes(src, dest, distance);
				m_graph->ConnectNodes(dest, src, distance);
			}
		}
	}

	/*Node *b = m_graph->AddNode(Vector2(150 * graphScale, 100 * graphScale));
	Node *c = m_graph->AddNode(Vector2(200 * graphScale, 100 * graphScale));
	Node *d = m_graph->AddNode(Vector2(150 * graphScale, 150 * graphScale));
	Node *e = m_graph->AddNode(Vector2(100 * graphScale, 200 * graphScale));
	Node *f = m_graph->AddNode(Vector2(150 * graphScale, 200 * graphScale));
	Node *g = m_graph->AddNode(Vector2(200 * graphScale, 200 * graphScale));
	Node *h = m_graph->AddNode(Vector2(300 * graphScale, 150 * graphScale));
	Node *i = m_graph->AddNode(Vector2(250 * graphScale, 100 * graphScale));
	Node *j = m_graph->AddNode(Vector2(300 * graphScale, 100 * graphScale));
	Node *k = m_graph->AddNode(Vector2(350 * graphScale, 100 * graphScale));

	m_graph->ConnectNodes(a, d, a->pos.distance(d->pos));

	m_graph->ConnectNodes(d, c, d->pos.distance(c->pos)); 
	m_graph->ConnectNodes(d, b, d->pos.distance(b->pos)); 
	m_graph->ConnectNodes(d, h, d->pos.distance(h->pos)); 
	m_graph->ConnectNodes(d, e, d->pos.distance(e->pos)); 
	m_graph->ConnectNodes(d, f, d->pos.distance(f->pos)); 
	m_graph->ConnectNodes(d, g, d->pos.distance(g->pos)); 
	m_graph->ConnectNodes(h, i, h->pos.distance(i->pos)); 
	m_graph->ConnectNodes(h, j, h->pos.distance(j->pos)); 
	m_graph->ConnectNodes(h, k, h->pos.distance(k->pos));

	m_graph->ConnectNodes(h, g, h->pos.distance(g->pos));
	m_graph->ConnectNodes(g, d, g->pos.distance(d->pos));*/

	
//	agent->addBehaviourList(new KeyboardController());


	agent = new Agent(Vector3(650, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	agentList.push_back(agent);

	enemy = new Agent(Vector3(700, 250, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	agentList.push_back(enemy);

	{
	
		Selector* behaviourRoot = new Selector();
		Sequence* isChaseMode = new Sequence();
		BehaviourState* checkForChase = new BehaviourState(Run);
		Sequence* fleeRoot = new Sequence();
		Flee* findTargetFlee = new Flee(enemy, m_graph);
		FollowPath* FleeFollow = new FollowPath();
		agent->addBehaviourList(behaviourRoot);

		behaviourRoot->addChild(fleeRoot);

		isChaseMode->addChild(checkForChase);
		isChaseMode->addChild(fleeRoot);

		fleeRoot->addChild(findTargetFlee);
		fleeRoot->addChild(FleeFollow);
	}
	
	{
		//working *

		Selector* behaviourRoot = new Selector();
		Sequence* isChaseMode = new Sequence();
		BehaviourState* checkForChase = new BehaviourState(Chase);
		Sequence* seekRoot = new Sequence();
		FindPath* findTarget = new FindPath(agent, m_graph);
		FollowPath* followTarget = new FollowPath();
	
		enemy->addBehaviourList(behaviourRoot);

		behaviourRoot->addChild(isChaseMode);

		isChaseMode->addChild(checkForChase);
		isChaseMode->addChild(seekRoot);
		
		seekRoot->addChild(findTarget);
		seekRoot->addChild(followTarget);
			
		
	}
	
	



	crate = new Texture("./Images/box0_256.png");
	m_pinkNodeTexture = new Texture("./Images/pinkNode.png");
	m_nodeTexture = new Texture("./Images/nodeTexture.png");
	m_font = new Font("./Fonts/arial_20px.fnt");

	agent->m_sprite = m_nodeTexture;
	enemy->m_sprite = m_pinkNodeTexture;
}

GraphDemo::~GraphDemo()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_graph;
}


void GraphDemo::Update(float deltaTime)
{
	//if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_I))
	//{	
	//	if (sNode && eNode)
	//	{
	//		for (auto & node : m_graph->m_list)
	//		{
	//			node->parent = nullptr;
	//			node->gScore = std::numeric_limits<float>::max();
	//			node->hScore = 0;
	//			node->fScore = 0;
	//		}
	//		thepath->FindPathDijkstras(sNode, eNode, outPut);
	//	}
	//	std::cout << "Dijkstras" << std::endl;
	//}

	//enemy->update(outPut, deltaTime);
	
	//if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_O))
	//{
	//	if (sNode && eNode)
	//	{
	//		for (auto & node : m_graph->m_list)
	//		{
	//			node->parent = nullptr;
	//			node->gScore = std::numeric_limits<float>::max();
	//			node->hScore = 0;
	//			node->fScore = 0;
	//		}
	//		thepath->AStar(sNode, eNode, outPut);
	//		agent->path = outPut;
	//	}
	//		std::cout << "AStar" << std::endl;
	//}

	//if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_P))
	//{
	//	std::cout << "Reset" << std::endl;
	//	sNode = nullptr;
	//	eNode = nullptr;
	//	outPut.clear();
	//}
	
	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_3))
	{
		int x = rand() % 1200 + 0;
		int y = rand() % 700 + 0;
		agent->setPos(Vector3(x, y, 0));	
	}
	

	if (Input::GetSingleton()->WasMouseButtonPressed(0))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);

		Node* newNode = m_graph->AddNode(Vector2(mx, my));

		for (auto & node : m_graph->m_list)
		{
			float dist = node->pos.distance(newNode->pos);
			if (dist < 100)
			{
				m_graph->ConnectNodes(node, newNode, node->pos.distance(newNode->pos));
			}
		}
	}

	if (Input::GetSingleton()->WasMouseButtonPressed(1))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);
		if (!sNode)
		{
			sNode = m_graph->FindNode(Vector2(mx, my));
		}
		else if (!eNode)
		{
			eNode = m_graph->FindNode(Vector2(mx, my));
		}
		else if (sNode && eNode)
		{
			sNode = nullptr;
			eNode = nullptr;
		}
	}


	//update all Agents
	std::list<Agent*>::iterator i = agentList.begin();
	Agent* currentAgent = nullptr;
	while (i != agentList.end()) 
	{
		currentAgent = *i;
		currentAgent->update(deltaTime);
		std::advance(i, 1);
	}


	agent->count += deltaTime;
	float dist = sqrt(powf(agent->getPos().m_y - enemy->getPos().m_y, 2) + powf(agent->getPos().m_x - enemy->getPos().m_x, 2));
	//float dist = (enemy->getPos() - agent->getPos()).magnitude();

	//std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	if (dist <= 50)
	{
		//std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		Texture* temp;
		//int duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
		//int difference = agent->count - deltaTime;
		std::cout << "distance: " << dist << std::endl;
		if (agent->count < 3)
		{
			std::cout << "im working" << std::endl;
		}
		else
		{
			std::cout << "changed" << std::endl;
			temp = agent->m_sprite;
			agent->m_sprite = enemy->m_sprite;
			enemy->m_sprite = temp;
			agent->count = 0;
			

		}
	}
}
	

void GraphDemo::Draw()
{

	// clear the back buffer
	ClearScreen();
	
	m_spritebatch->Begin();

	m_spritebatch->DrawSprite(agent->m_sprite, agent->getPos().m_x, agent->getPos().m_y, 100, 100, 0, 0.5f, 0.5f);
	m_spritebatch->DrawSprite(enemy->m_sprite, enemy->getPos().m_x, enemy->getPos().m_y, 50, 50, 0, 0.5f, 0.5f);

	for (auto i : m_graph->m_list)
	{
		m_spritebatch->DrawSprite(m_nodeTexture, i->pos.m_x, i->pos.m_y);

		for (auto i2 : i->edgeList)
		{
			m_spritebatch->DrawLine(i->pos.m_x, i->pos.m_y, i2->m_destination->pos.m_x, i2->m_destination->pos.m_y);
		}
	}
	
	for (Node* node : outPut)
	{

	m_spritebatch->DrawSprite(crate, node->pos.m_x, node->pos.m_y, 30, 30);
	}

	if (sNode)
	{
		m_spritebatch->DrawSprite(crate, sNode->pos.m_x, sNode->pos.m_y, 30, 30);
	}
	if (eNode)
	{
		m_spritebatch->DrawSprite(crate, eNode->pos.m_x, eNode->pos.m_y, 30, 30);
	}
	// Draw graph here
	
	m_spritebatch->DrawString(m_font, "TEST", 10, 10);
	m_spritebatch->End();
}
