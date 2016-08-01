#pragma once
#include "IBehaviour.h"
#include <list>

class Node;
class Graph;
class Seek : public IBehaviour
{
public:
	Seek();
	virtual ~Seek();
	
	virtual BehaviourResult update(Agent* tempAgent, float dTime);
	void Seek::update(std::list<Node*>path, Agent *agent, Agent *enemy, float deltatime);

protected:
	Agent* m_target;
	Node* m_targetNode;
	Node* m_nextNode;
	Node* m_currentNode;

	Graph* m_graph;
};

