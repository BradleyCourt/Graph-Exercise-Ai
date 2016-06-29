#include "Node.h"
#include "Edge.h"


Node::Node()
{	
	pos = Vector2(0, 0);
	gScore = 0;
	parent = nullptr;
	hScore = 0;
	fScore = 0;
}

Node::Node(Vector2 a_pos)
{
	pos = a_pos;
	gScore = 0;
	parent = nullptr;
}

Node::Node(Vector2 a_pos, float a_gScore, Node * a_parent)
{
	pos = a_pos;
	gScore = 0;
	parent = a_parent;
}


Node::~Node()
{
}
