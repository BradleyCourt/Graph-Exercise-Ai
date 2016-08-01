#pragma once
#include "Graph.h"
#include <vector>


class Edge;

class Node
{
public:

	Vector2 pos;
	float gScore;
	Node *parent;
	float hScore;
	float fScore;


	std::vector<Edge*> edgeList;

	//Vector2 m_data;

	//std::vector< Edge > connections;

	Node();
	
	Node(Vector2 a_pos);
	
	Node(Vector2 a_pos, float a_gScore, Node *a_parent);

	~Node();
};