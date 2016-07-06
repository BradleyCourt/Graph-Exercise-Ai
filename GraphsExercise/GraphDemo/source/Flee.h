#pragma once
#include "Agent.h"
#include "IBehaviour.h"
class Flee : public IBehaviour
{
public:
	Flee();
	virtual ~Flee();

	virtual void update(Agent* tempAgent, Agent enemy, float dTime);
};

