#include "Sequence.h"
#include "Composite.h"



BehaviourResult Sequence::update(Agent * tempAgent, float dTime)
{
	for (int i = 0; i < m_childBehaviours.size(); i++)
	{
		if ((m_childBehaviours.at(i)->update(tempAgent, dTime)) == Failure)
		{
			return Failure;
		}
	}
	return Success;
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