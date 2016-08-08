#pragma once
#include "Vector3.h"
#include <vector>
#include "SpriteBatch.h"
#include "Matrix3.h"
#include "Node.h"
#include <list>
class IBehaviour;
class Agent
{
protected:

	

	IBehaviour* m_BehaviourList = { nullptr };
public:
	std::list<Node*>path;
	Vector3 m_pos;
	Vector3 m_vel, m_accel;
	Vector3 m_force;
	Node* m_targetNode = nullptr; // Where we are going (destination)
	Node* m_nextNode = nullptr; // Where we are going (next)
	std::list<Node*> output;

	Agent();
	Agent(Vector3 pos, Vector3 vel, Vector3 accel, Vector3 force);
	virtual ~Agent();
	float count = 0;
	void addBehaviourList(IBehaviour* behaviour);
	void setPos(Vector3 pos);
	Vector3 getPos();
	void setVel(Vector3 vel);
	void setAccel(Vector3 accel);
	void addForce(Vector3 force);
	void update(float dTime);
	Texture* m_sprite;
	Matrix3 transform;

};
