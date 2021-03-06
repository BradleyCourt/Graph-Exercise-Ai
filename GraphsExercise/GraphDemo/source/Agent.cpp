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
	m_BehaviourList = behaviour;
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
	m_targetNode = nullptr;
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

void Agent::update(float dTime)
{
	if (m_BehaviourList != nullptr) 
	{
		m_BehaviourList->update(this, dTime);
	}

	m_vel = m_force - m_vel;

	m_pos = m_pos + m_vel;
}


