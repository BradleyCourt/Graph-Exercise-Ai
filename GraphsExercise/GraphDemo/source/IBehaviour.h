#pragma once
#include <vector>
#include <list>
class Agent;
class Node;


enum BehaviourResult
{
	Success,
	Failure,
	Pending
};

class IBehaviour
{

public:

	void addChild(IBehaviour* b);

	IBehaviour();
	~IBehaviour();
	
	BehaviourResult Result;

	virtual BehaviourResult update(Agent* enemy, Agent* tempAgent, float dTime) = 0;

protected:
	std::vector<IBehaviour*> m_childBehaviours;
};

