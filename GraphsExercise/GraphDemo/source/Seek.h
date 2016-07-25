#pragma once
#include "IBehaviour.h"

class Node;
class Seek : public IBehaviour
{
public:
	Seek();
	virtual ~Seek();
	
	virtual void update(Agent* tempAgent, float dTime);

protected:
	Agent* m_target;
	Node* m_targetNode;
	Node* m_nextNode;
	Node* m_currentNode;

	Graph* m_graph;
};

