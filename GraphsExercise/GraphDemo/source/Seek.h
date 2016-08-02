#pragma once
#include "IBehaviour.h"
#include <list>

class Node;
class Graph;
class Seek : public IBehaviour
{
public:
	Seek();
	Seek(Agent* enemy, Graph* g);
	virtual ~Seek();
	
	virtual BehaviourResult update(std::list<Node*> path, Agent * pAgent, float deltatime);
	

protected:
	Agent* m_target;
	Node* m_targetNode;
	Node* m_nextNode;
	Node* m_currentNode;

	Graph* m_graph;

	int m_index = 0;
};

