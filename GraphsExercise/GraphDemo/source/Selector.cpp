#include "Selector.h"



Selector::Selector()
{
}


BehaviourResult Selector::update(Agent * tempAgent, float dTime)
{
	
	m_currentChild = m_pendingChild; //also make these changes to the Sequencer class

	

	m_pendingChild = nullptr;

		//if (m_currentChild = nullptr)
		//{
		//	m_currentChild = m_childBehaviours.begin;
		//}

		//while (m_currentChild <= m_childBehaviours.end)
		//{
		//	//result 
		//	Result = m_currentChild->update(pAgent);
		//}
		//	if (return == Success)
		//	{
		//		return Success;
		//	}
		//	else if (result == Failure)
		//	{
		//		child = next child;
		//		return Failure;
		//	}
		//else if (result == Pending)
		//	{
		//		m_pendingChild = child;
		//		return Pending;
		//	}
	return Result;
}

Selector::~Selector()
{
}
