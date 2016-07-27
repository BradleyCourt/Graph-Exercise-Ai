#pragma once
#include "Agent.h"
#include "Vector3.h"
#include "IBehaviour.h"
#include <iostream>
class KeyboardController :
	public IBehaviour
{
public:
	KeyboardController();
	virtual ~KeyboardController();

	virtual void update(Agent* tempAgent, float dTime);

};

