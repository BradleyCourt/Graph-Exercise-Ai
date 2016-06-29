#pragma once
class Node;

class Edge
{
public:
	Edge();
	~Edge();
	Edge(Node* connect, float cost);

	float m_cost;
	Node *m_destination;
	//Node *origin;
	// Add the approprate data.
};

