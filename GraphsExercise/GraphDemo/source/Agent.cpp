#include "Agent.h"
#include "IBehaviour.h"
#include "Vector3.h"
#include "Node.h"

#include <list>

void Agent::addBehaviourList(IBehaviour* behaviour)
{
	/*for (unsigned int i = m_BehaviourList.size(); i >= 0; i--)
	{
		delete m_BehaviourList.at(i);
		m_BehaviourList.pop_back();
	}*/
	m_BehaviourList.push_back(behaviour);
}


Agent::Agent()
{
}
Agent::Agent(Vector3 pos, Vector3 vel, Vector3 accel, Vector3 force)
{
	m_pos = pos;
	m_vel = vel;
	m_accel = accel;
	m_force = force;
	//count = 0;
}


Agent::~Agent()
{
}



void Agent::setPos(Vector3 pos)
{
	m_pos = pos;
}

Vector3 Agent::getPos()
{
	return m_pos;
}

void Agent::setVel(Vector3)
{
	m_vel = m_force - m_vel;
}

void Agent::setAccel(Vector3 accel)
{
	m_accel = accel;
}

void Agent::addForce(Vector3 force)
{
	m_force = m_force + force;
}

void Agent::update(Agent* enemy, std::list<Node*> path, float dTime)
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); i++)
	{
		m_BehaviourList.at(i)->update(enemy, this, dTime);
		
	}

	m_vel = m_force - m_vel;

	m_pos = m_pos + m_vel;
}


