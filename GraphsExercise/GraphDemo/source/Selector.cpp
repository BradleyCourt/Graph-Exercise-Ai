#include "Selector.h"
#include "Agent.h"



Selector::Selector()
{
}

// refactor so that path and other agent related variables are stored in the agent
BehaviourResult Selector::update(Agent *pAgent, float dTime)
{
	
	m_currentChild = m_pendingChild; //also make these changes to the Sequencer class

	

	m_pendingChild = nullptr;

		if (m_currentChild = nullptr)
		{
			m_currentChild = m_childBehaviours.front();
		}

		for (unsigned int i = 0; i < m_childBehaviours.size(); i++) {
			if (m_currentChild->update(pAgent, dTime) == Success)
			{
				return Success;
			}
			else if (m_currentChild->update(pAgent, dTime) == Failure)
			{
				//Do nothing, allow loop to iterate one
			}
			else if (m_currentChild->update(pAgent, dTime) == Pending)
			{
				m_pendingChild = m_currentChild;
				return Pending;
			}
		}

		/*while (m_currentChild <= m_childBehaviours.end())
		{
			//result 
			Result = m_currentChild->update(pAgent, dTime);
			if (Result == Success)
			{
				return Success;
			}
			else if (Result == Failure)
			{
				m_currentChild = next child;
			}
			else if (Result == Pending)
			{
				m_pendingChild = m_currentChild;
				return Pending;
			}
		}*/
	return Result;
}

Selector::~Selector()
{
}
