#pragma once
#include "Vector3.h"
#include <vector>
class IBehaviour;
class Agent
{
protected:

	Vector3 m_pos;
	Vector3 m_vel, m_accel;
	Vector3 m_force;

	std::vector<IBehaviour*> m_BehaviourList = { nullptr };

	void addBehaviourList();
public:
	Agent();
	Agent(Vector3 pos, Vector3 vel, Vector3 accel, Vector3 force);
	virtual ~Agent();

	void setPos(Vector3 pos);
	void setVel(Vector3 vel);
	void setAccel(Vector3 accel);
	void setForce(Vector3 force);

	void update(float dTime);

};
