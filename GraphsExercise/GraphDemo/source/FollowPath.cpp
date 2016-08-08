#include "FollowPath.h"
#include "Node.h"
#include "Graph.h"
#include <list>
#include <vector>
#include "Agent.h"
#include "Vector3.h"
#include "GraphDemo.h"

FollowPath::FollowPath()
{
}

FollowPath::~FollowPath()
{
}


BehaviourResult FollowPath::update(Agent * pAgent, float deltatime)
{
	if (pAgent->m_nextNode)
	{
		Vector3 direction = ((pAgent->m_nextNode->pos) - (pAgent->m_pos));
		direction.normalise();
		pAgent->m_pos = pAgent->m_pos + (direction);

		if (pAgent->getPos().distance(pAgent->m_nextNode->pos) < 10)
		{
			if (pAgent->output.size() > 0)
			{
				pAgent->m_nextNode = pAgent->output.front();
				pAgent->output.pop_front();
			}
			else
			{
				pAgent->m_targetNode = nullptr;
			}
			
			return Success;
		}
	}

	//pAgent->m_pos = pAgent->m_pos + (direction * deltatime * 30);

	return Failure;
}