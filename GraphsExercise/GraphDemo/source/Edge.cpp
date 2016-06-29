#include "Edge.h"
#include "Node.h"


Edge::Edge()
{
	m_destination = nullptr;
	m_cost = 0;
}

Edge::Edge(Node* connect, float cost)
{
	m_destination = connect;
	m_cost = cost;
}

Edge::~Edge()
{
}

