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

	m_graph->ConnectNodes(a, d, 1);

	m_graph->ConnectNodes(d, b, 1); 
	m_graph->ConnectNodes(d, c, 1); 
	m_graph->ConnectNodes(d, h, 1); 
	m_graph->ConnectNodes(d, e, 1); 
	m_graph->ConnectNodes(d, f, 1); 
	m_graph->ConnectNodes(d, g, 1); 
	m_graph->ConnectNodes(h, i, 1); 
	m_graph->ConnectNodes(h, j, 1); 
	m_graph->ConnectNodes(h, k, 1);

	m_graph->ConnectNodes(h, g, 1);
	m_graph->ConnectNodes(g, d, 1);

	
	sNode = nullptr;
	eNode = nullptr;
	m_nodeTexture = new Texture("./Images/nodeTexture.png");
	crate = new Texture("./Images/box0_256.png");
	m_font = new Font("./Fonts/arial_20px.fnt");
}

GraphDemo::~GraphDemo()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_graph;
}


void GraphDemo::Update(float deltaTime)
{
	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_D))
	{	
		if(sNode && eNode)
			thepath->FindPathDijkstras(sNode, eNode, outPut);
		std::cout << "Dijkstras" << std::endl;
	}

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_A))
	{
		if (sNode && eNode)
			thepath->AStar(sNode, eNode, outPut);
		std::cout << "AStar" << std::endl;
	}

	if (Input::GetSingleton()->IsKeyDown(GLFW_KEY_H))
	{
		std::cout << "Reset" << std::endl;
		sNode = nullptr;
		eNode = nullptr;
		outPut.clear();
	
	//	thepath = nullptr;
		
		
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
		else if (sNode && eNode )
		{
			sNode = nullptr;
			eNode = nullptr;
		}
	}
}
	

void GraphDemo::Draw()
{

	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

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