#pragma once
#include "Graph.h"
#include <list>
#include "Node.h"
class Pathfinder
{
public:
	Pathfinder();
	virtual ~Pathfinder();
	

	void Pathfinder::sortGscore(Node* n1, Node* n2);

	void FindPathDijkstras(Node * startNode, Node* potentialEndNodes, std::list<Node*>& outPut);

	void AStar(Node * startNode, Node * potentialEndNodes, std::list<Node*>& outPut);




};



