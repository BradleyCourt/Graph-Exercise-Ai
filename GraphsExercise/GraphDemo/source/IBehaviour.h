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

	

	IBehaviour();
	~IBehaviour();
	
	BehaviourResult Result;

	virtual BehaviourResult update(std::list<Node*> path, Agent* pAgent, float dTime) = 0;

protected:
	BehaviourResult result = Pending;
};

