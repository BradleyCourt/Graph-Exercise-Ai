#include "FollowPath.h"
#include "Node.h"
#include "Graph.h"
#include <list>
#include <vector>
#include "Agent.h"
#include "Vector3.h"


FollowPath::FollowPath()
{
}
FollowPath::FollowPath(Agent* enemy, Graph* g)
{
	m_graph = g;

}

FollowPath::~FollowPath()
{
}


BehaviourResult FollowPath::update(Agent * pAgent, float deltatime)
{
	for ()

	//Find node closest to player
	
	//find node closest to agent

	//find path between those two nodes







	//go to next node in the path
	std::list<Node*> path = m_graph->m_list;
	if (!path.empty())
	{
		
		if (m_index < path.size())
		{
			std::list<Node*>::iterator it = path.begin();
			std::advance(it, m_index);
			if (((pAgent->m_pos - (*it)->pos).magnitude() < 5))
			{				
				m_index++;
				std::advance(it, 1);
				if (m_index == path.size())
				{
					BehaviourResult::Success;
				}
			}

			Vector3 direction = (Vector3((*it)->pos) - pAgent->m_pos) * 1;
			direction.normalise();
			pAgent->m_pos = pAgent->m_pos + (direction * deltatime * 30);
			return BehaviourResult::Pending;
		}
	}
	m_index = 0;
	return BehaviourResult::Failure;
}


// current node?