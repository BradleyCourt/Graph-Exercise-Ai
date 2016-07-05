#pragma once
#include "IBehaviour.h"
#include "Agent.h"
class Force : public IBehaviour
{
public:
	Force();
	virtual ~Force();

	virtual void update(Agent* tempAgent, float dTime);

};

