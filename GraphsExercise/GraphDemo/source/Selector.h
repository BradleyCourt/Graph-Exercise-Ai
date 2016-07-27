#pragma once
#include "IBehaviour.h"
#include "Agent.h"
#include "Composite.h"
class Selector : Composite
{
public:
	BehaviourResult Selector::execute(Agent);
		
	Selector();
	~Selector();
};

