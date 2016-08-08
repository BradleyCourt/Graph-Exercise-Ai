#pragma once
#include "IBehaviour.h"
#include <list>
class Node;
class Graph;
class FollowPath : public IBehaviour
{
public:
	FollowPath();
	virtual ~FollowPath();
	
	virtual BehaviourResult update(Agent * pAgent, float deltatime);
	

protected:
	

	int m_index = 0;
};

