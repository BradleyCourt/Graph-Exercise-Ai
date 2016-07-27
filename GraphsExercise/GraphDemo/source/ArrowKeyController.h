#pragma once
#include "Agent.h"
#include "Vector3.h"
#include "IBehaviour.h"
#include <iostream>
class ArrowKeyController :
	public IBehaviour
{
public:
	ArrowKeyController();
	~ArrowKeyController();
	virtual void update(Agent * enemy, float dTime);
};

