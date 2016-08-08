#include "Selector.h"
#include "Agent.h"



Selector::Selector()
{
}

// refactor so that path and other agent related variables are stored in the agent
BehaviourResult Selector::update(Agent *pAgent, float dTime)
{
	for (int i = 0; i < m_childBehaviours.size(); i++)
	{
		if ((m_childBehaviours.at(i)->update(pAgent, dTime)) == Success)
		{
			return Success;
		}
	}
	return Failure;
}

Selector::~Selector()
{
}
