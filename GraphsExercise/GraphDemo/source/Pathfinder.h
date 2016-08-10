#pragma once
#include <list>
#include "Node.h"
#include "Graph.h"
class Pathfinder
{
public:
	Pathfinder(Graph* graph);
	virtual ~Pathfinder();
	

	void Pathfinder::sortGscore(Node* n1, Node* n2);

	void FindPathDijkstras(Node * startNode, Node* potentialEndNodes, std::list<Node*>& outPut);

	void AStar(Node * startNode, Node * endNode, std::list<Node*>& outPut);


private:
	Graph* m_graph;
};



