#pragma once
#include "IBehaviour.h"
#include "Agent.h"
#include "Composite.h"

class Selector : Composite
{
public:
//	BehaviourResult execute(Agent);

	BehaviourResult Selector::update(Agent * tempAgent, float dTime);

	Selector();
	~Selector();
};

