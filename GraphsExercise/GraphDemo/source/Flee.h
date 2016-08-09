#pragma once
#include "Agent.h"
#include "IBehaviour.h"
#include "pathfinder.h"
class Flee : public IBehaviour
{
public:
	Flee();
	Flee(Agent* target, Graph* graph);
	virtual ~Flee();

	BehaviourResult update(Agent * pAgent, float deltatime);
protected:
	Agent* m_target;
	Graph* m_graph;

	Pathfinder* m_pathFinder = new Pathfinder();

	Node* findNearestNodeToAgent(Agent* a);
	Node* findFurthestNodeToAgent(Agent* a);
};

