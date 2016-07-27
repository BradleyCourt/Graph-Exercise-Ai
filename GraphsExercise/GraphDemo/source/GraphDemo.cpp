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

Pathfinder* thepath;
std::list<Node*>path;
Node* firstnode = nullptr;
Node* secondnode;

GraphDemo::GraphDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);	

	m_graph = new Graph;
	Node *a = m_graph->AddNode(Vector2(100, 100)); 

	
	
	float graphScale = 2.5f;
	Node *b = m_graph->AddNode(Vector2(150 * graphScale, 100 * graphScale));
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
	m_graph->ConnectNodes(g, d, g->pos.distance(d->pos));

	agent = new Agent();
	agent->addBehaviourList(new KeyboardController());
	agent->setPos(Vector3(100, 100, 0));
	enemy = new Agent();
	enemy->addBehaviourList(new ArrowKeyController());
	
	sNode = nullptr;
	eNode = nullptr;

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
	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_I))
	{	
		if (sNode && eNode)
		{
			for (auto & node : m_graph->m_list)
			{
				node->parent = nullptr;
				node->gScore = std::numeric_limits<float>::max();
				node->hScore = 0;
				node->fScore = 0;
			}
			thepath->FindPathDijkstras(sNode, eNode, outPut);
		}
		std::cout << "Dijkstras" << std::endl;
	}

	agent->update(deltaTime);
	enemy->update(deltaTime);
	

		if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_O))
		{
			if (sNode && eNode)
			{
				for (auto & node : m_graph->m_list)
				{
					node->parent = nullptr;
					node->gScore = std::numeric_limits<float>::max();
					node->hScore = 0;
					node->fScore = 0;
				}
				thepath->AStar(sNode, eNode, outPut);
			}
			std::cout << "AStar" << std::endl;
		}

		if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_P))
		{
			std::cout << "Reset" << std::endl;
			sNode = nullptr;
			eNode = nullptr;
			outPut.clear();


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


			// Handle mouse input here
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

	m_spritebatch->DrawSprite(agent->m_sprite, agent->getPos().m_x, agent->getPos().m_y, 50, 50, 0, 0.5f, 0.5f);
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
