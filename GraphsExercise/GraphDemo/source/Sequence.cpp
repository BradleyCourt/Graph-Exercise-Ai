#include "Sequence.h"
#include "Composite.h"



BehaviourResult Sequence::update(Agent* agent, Agent * tempAgent, float dTime)
{
	for (int i = 1; i <= 1; i++)
	{
		if ((m_childBehaviours[i]->Result) == Failure)
		{
			// Flee
		}

		if ((m_childBehaviours[i]->Result) == Success)
		{
			// Seek
		}

		if ((m_childBehaviours[i]->Result) != Success && ((m_childBehaviours[i]->Result) != Failure) == Pending)
		{
			//Pending
		}

	}
	return Result;
}

Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}													

void Update(Agent)
{

}