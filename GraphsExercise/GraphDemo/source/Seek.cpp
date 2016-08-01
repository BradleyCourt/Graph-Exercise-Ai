#include "Seek.h"
#include "Node.h"
#include "Graph.h"
#include <list>
#include "Agent.h"
#include "Vector3.h"

int m_index = 0;
Seek::Seek()
{
}


Seek::~Seek()
{
}


BehaviourResult Seek::update(Agent * tempAgent, float dTime)
{
	//Find node closest to target

	//Find path to said node

	//Find next node in path list

	//Move towards that node

	//EXAMPLE:
	if (true) {
		//Condition you want to check
		result = Success;
	}
	return Result;
}

void Seek::update(std::list<Node*> path, Agent * agent, Agent * enemy, float deltatime)
{
	if (path.empty() && path.size() > 0)
	{
		if (m_index < path.size())
		{
			std::list<Node*>::iterator it = path.begin();
			std::advance(it, m_index);
			if (((enemy->m_pos - (*it)->pos).magnitude() < 5))
				m_index++;

			Vector3 direction = (Vector3((*it)->pos) - enemy->m_pos) * 1;
			direction.normalise();
			enemy->m_pos = enemy->m_pos + (direction * deltatime * 30);
			return;
		}
	}
	m_index = 0;
}
// current node?