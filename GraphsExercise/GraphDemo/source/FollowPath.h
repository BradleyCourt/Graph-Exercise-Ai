#pragma once
#include "IBehaviour.h"
#include <list>

class Node;
class Graph;
class FollowPath : public IBehaviour
{
public:
	FollowPath();
	FollowPath(Agent* enemy, Graph* g);
	virtual ~FollowPath();
	
	virtual BehaviourResult update(Agent* Player, Agent * Enemy, float deltatime);
	

protected:
	Agent* m_target;
	Node* m_targetNode;
	Node* m_nextNode;
	Node* m_currentNode;

	Graph* m_graph;

	int m_index = 0;
};

