#pragma once
#include "IBehaviour.h"
#include "Agent.h"

class BehaviourState : public IBehaviour
{
protected:
	state m_State;
public:
	BehaviourState();
	BehaviourState(state st);
	virtual ~BehaviourState();

	BehaviourResult update(Agent * pAgent, float deltatime);
};
