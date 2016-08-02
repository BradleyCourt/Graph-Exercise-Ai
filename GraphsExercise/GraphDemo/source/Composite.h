#pragma once
#include <list>
#include <vector>
#include "IBehaviour.h"

class Composite : public IBehaviour
{
public:

	Composite();
	~Composite();

	virtual BehaviourResult update(Agent* tempAgent, float dTime) = 0;

	
	
	//list childBehaviours;
	//IBehaviour pendingChild : null
	//func execute(agent) = 0
protected:
	IBehaviour* m_pendingChild;
	IBehaviour* m_currentChild;
};

