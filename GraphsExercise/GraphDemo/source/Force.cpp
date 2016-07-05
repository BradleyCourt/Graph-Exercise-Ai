#include "Force.h"



Force::Force()
{
}


Force::~Force()
{
}

void Force::update(Agent * tempAgent, float dTime)
{
	tempAgent->addForce(Vector3(10, 0, 1));
}
