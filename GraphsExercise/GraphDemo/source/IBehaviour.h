#pragma once
class Agent;
class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void update(Agent* tempAgent, float dTime) = 0;
};

