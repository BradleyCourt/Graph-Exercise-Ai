#pragma once
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

	virtual BehaviourResult update(std::list<Node*>&path, Agent* tempAgent, Agent* agent, float dTime) = 0;

protected:
	BehaviourResult result = Pending;
};

