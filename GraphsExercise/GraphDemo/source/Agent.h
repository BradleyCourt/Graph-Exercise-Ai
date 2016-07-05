#pragma once
#include "Vector3.h"
#include <vector>
#include "SpriteBatch.h"
#include "Matrix3.h"
class IBehaviour;
class Agent
{
protected:

	Vector3 m_pos;
	Vector3 m_vel, m_accel;
	Vector3 m_force;

	std::vector<IBehaviour*> m_BehaviourList;
public:
	Agent();
	Agent(Vector3 pos, Vector3 vel, Vector3 accel, Vector3 force);
	virtual ~Agent();

	void addBehaviourList(IBehaviour* behaviour);
	void setPos(Vector3 pos);
	Vector3 getPos();
	void setVel(Vector3 vel);
	void setAccel(Vector3 accel);
	void addForce(Vector3 force);
	Texture* m_sprite;
	Matrix3 transform;
	void update(float dTime);

};
