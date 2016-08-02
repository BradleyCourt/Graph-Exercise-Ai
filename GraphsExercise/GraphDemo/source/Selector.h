#pragma once
#include "IBehaviour.h"
#include "Composite.h"
#include <list>

class Agent;

class Selector : Composite
{
public:
//	BehaviourResult execute(Agent);


	Selector();
	virtual BehaviourResult update(std::list<Node*> path, Agent * pAgent, float dTime);
	~Selector();
};

