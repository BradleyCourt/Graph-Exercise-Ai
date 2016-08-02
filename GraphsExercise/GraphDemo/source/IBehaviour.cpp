#include "IBehaviour.h"
#include"Agent.h"



void IBehaviour::addChild(IBehaviour * b)
{
	m_childBehaviours.push_back(b);
}

IBehaviour::IBehaviour()
{
}


IBehaviour::~IBehaviour()
{
}

//BehaviourResult IBehaviour::returnResult()
//{
//	return result;
//}

