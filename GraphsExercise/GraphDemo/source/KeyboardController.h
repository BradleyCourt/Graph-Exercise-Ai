#pragma once
#include "Agent.h"
#include "Vector3.h"
#include <iostream>
class KeyboardController 

{
public:
	KeyboardController();
	virtual ~KeyboardController();

	virtual void update(Agent* tempAgent, float dTime);

};

