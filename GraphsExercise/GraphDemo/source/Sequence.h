#pragma once
#include "Agent.h"
#include "Composite.h"


class Sequence : public Composite
{
public:

	//void Update(Agent);

	virtual BehaviourResult update(Agent* agent, Agent* tempAgent, float dTime);

	Sequence();
	~Sequence();

};


