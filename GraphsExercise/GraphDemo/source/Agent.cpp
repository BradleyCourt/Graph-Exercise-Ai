#include "Agent.h"
#include "IBehaviour.h"
#include "KeyboardController.h"


void Agent::addBehaviourList()
{
	for (unsigned int i = m_BehaviourList.size(); i >= 0; i--)
	{
		delete m_BehaviourList.at(i);
		m_BehaviourList.pop_back();
	}
	m_BehaviourList.push_back(new KeyboardController());
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
}


Agent::~Agent()
{
}

void Agent::setPos(Vector3 pos)
{
	m_pos = pos;
}

void Agent::setVel(Vector3 vel)
{
	m_vel = vel;
}

void Agent::setAccel(Vector3 accel)
{
	m_accel = accel;
}

void Agent::setForce(Vector3 force)
{
	m_force = force;
}

void Agent::update(float dTime)
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); i++)
	{
		(m_BehaviourList.at(i))->update(this, dTime);
	}
}