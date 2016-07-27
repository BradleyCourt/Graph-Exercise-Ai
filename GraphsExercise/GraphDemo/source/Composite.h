#pragma once
#include <list>
class Composite
{
public:
	
	

	//list childBehaviours;
	//IBehaviour pendingChild : null
	//func execute(agent) = 0
	//Composite();
	//~Composite();
protected:
	std::vector<IBehaviour*> m_childBehaviours;
	IBehaviour* m_pendingChild;
};

