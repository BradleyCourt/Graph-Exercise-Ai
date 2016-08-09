#include "BehaviourState.h"
#include "Agent.h"


BehaviourState::BehaviourState()
{
}

BehaviourState::BehaviourState(state st)
{
	m_State = st;
}


BehaviourState::~BehaviourState()
{
}

BehaviourResult BehaviourState::update(Agent * pAgent, float deltatime)
{
	if (pAgent->m_state == m_State)
	{
		return Success;
	}
	return Failure;
}
