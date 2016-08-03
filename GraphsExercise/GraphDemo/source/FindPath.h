#pragma once

#include "IBehaviour.h"

class FindPath : public IBehaviour
{
public:
	FindPath();
	virtual ~FindPath();

	virtual BehaviourResult update(Agent * pAgent, float deltatime);
};

