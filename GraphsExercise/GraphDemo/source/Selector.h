#pragma once
#include "IBehaviour.h"
#include "Composite.h"
#include <list>

class Agent;

class Selector : public Composite
{
public:
//	BehaviourResult execute(Agent);


	Selector();
	virtual BehaviourResult update(Agent* agent, Agent* tempAgent, float dTime);
	~Selector();
};

