#include "FollowPath.h"
#include "Node.h"
#include "Graph.h"
#include <list>
#include <vector>
#include "Agent.h"
#include "Vector3.h"
#include "GraphDemo.h"
#include "FindPath.h"

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
		if (pAgent->getPos().distance(pAgent->m_nextNode->pos) < 6 || pAgent->m_nextNode->pos.distance(pAgent->m_pos) < 6)
		{
			pAgent->m_lastNodeVisit = pAgent->m_nextNode;

			if (pAgent->output.size() > 0)
			{
				//if (pAgent->output.size() == 0)
				//{
				//	//at node, do nothing
				//	pAgent->output.clear();
				//}
				if (pAgent->output.size() == 1)
				{
					pAgent->m_nextNode = pAgent->output.back();
					pAgent->output.clear();
				//	pAgent->m_targetNode = nullptr;
				}
				else
				{
					pAgent->m_nextNode = pAgent->output.front();
					pAgent->output.pop_front();
					//pAgent->output.clear(); // added this
					//pAgent->m_targetNode = nullptr;
				}
			}
			else
			{
				pAgent->m_targetNode = nullptr;
			}
			
			return Success;
		}
		Vector3 direction = ((pAgent->m_nextNode->pos) - (pAgent->m_pos));
		direction.normalise();
		pAgent->m_pos = pAgent->m_pos + (direction);

		//pAgent->output.pop_front();
	}
	else 

	//pAgent->m_pos = pAgent->m_pos + (direction * deltatime * 30);

	return Failure;
}