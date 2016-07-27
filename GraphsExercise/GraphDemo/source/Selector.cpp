#include "Selector.h"




Selector::Selector()
{
}


BehaviourResult Selector::execute(Agent)
{
	BehaviourResult *child = m_pendingChild; //also make these changes to the Sequencer class
	m_pendingChild = nullptr;

		if (child = nullptr)
		{
			child = childBehaviours.first;
		}

	while (child <= childBehaviours.last)
		{
			result = child.execute(agent);
		}
			if (result == Success)
			{
				return Success;
			}
			else if (result == Failure)
			{
				child = next child;
				return Failure;
			}
		else if (result == Pending)
			{
				pendingChild = child;
				return Pending;
			}
		
}

Selector::~Selector()
{
}
