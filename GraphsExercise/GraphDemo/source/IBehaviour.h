#pragma once
class Agent;
class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	enum BehaviourResult
	{
		Success,
		Failure,
		Pending
	};

	virtual void update(Agent* tempAgent, float dTime) = 0;
};

