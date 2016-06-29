#include "Graph.h"
#include "Node.h"
#include "Edge.h"


Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::list(Node * node)
{
	
}


Node *Graph::AddNode(Vector2 data)
{
	Node* newNode = new Node(data);
	m_list.push_back(newNode);
	return newNode;
}


void Graph::RemoveNode(Node * pNode)
{
	
}

void Graph::ConnectNodes(Node * nodeA, Node * nodeB, float data)
{

	nodeA->edgeList.push_back(new Edge(nodeB, data));
	nodeB->edgeList.push_back(new Edge(nodeA, data));
}

Node * Graph::FindNode(Vector2 pos)
{
	for (auto & node : m_list)
	{
		float dist = node->pos.distance(pos);
		if (dist < 50)
		{
			return node;
		}
	}
	return nullptr;
}


