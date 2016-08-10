#pragma once

#include "IBehaviour.h"
#include "Pathfinder.h"
class Agent;
class Node;
class Graph;
class FindPath : public IBehaviour
{
public:
	FindPath();
	FindPath(Agent* target, Graph* graph);
	virtual ~FindPath();

	virtual BehaviourResult update(Agent * pAgent, float deltatime);
protected:
	Agent* m_target;
	Graph* m_graph;

	Pathfinder* m_pathFinder;	

	Node* findNearestNodeToAgent(Agent* a);
};

