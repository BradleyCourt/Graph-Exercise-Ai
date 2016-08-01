#pragma once
#include "Agent.h"
#include "Vector3.h"
#include <iostream>
class ArrowKeyController

{
public:
	ArrowKeyController();
	~ArrowKeyController();
	virtual void update(Agent * enemy, float dTime);
};

