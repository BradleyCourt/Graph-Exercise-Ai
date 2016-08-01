#pragma once
#include "Agent.h"
#include "Composite.h"


class Sequence : public Composite
{
public:

	//void Update(Agent);

	BehaviourResult update(Agent* tempAgent, float dTime);

	Sequence();
	~Sequence();

};


