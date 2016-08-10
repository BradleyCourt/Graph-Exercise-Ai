#include "FindPath.h"
#include"Agent.h"
#include "Node.h"
#include "Graph.h"
#include "Vector3.h"
#include <list>

FindPath::FindPath()
{
}

FindPath::FindPath(Agent * target, Graph * graph)
{
	m_target = target;
	m_graph = graph;

	m_pathFinder = new Pathfinder(m_graph);
}


FindPath::~FindPath()
{
}

BehaviourResult FindPath::update(Agent * pAgent, float deltatime)
{
	//pAgent->m_currentNode = findNearestNodeToAgent(pAgent);
	//figure out the closest node to the agent
	Node* currentNode = findNearestNodeToAgent(pAgent);

	
	if (pAgent->m_targetNode == nullptr || (pAgent->output.empty() && currentNode != pAgent->m_targetNode)) // || output.empty())
	{
		
		//and the closest node to the player
		pAgent->m_targetNode = findNearestNodeToAgent(m_target);
		//find a path between these two nodes
		if (!pAgent->output.empty())
			pAgent->output.clear();

		for (auto & node : m_graph->m_list)
		{
			node->parent = nullptr;
			node->gScore = std::numeric_limits<float>::max();
			node->hScore = 0;
			node->fScore = 0;
		}
		m_pathFinder->AStar(currentNode, pAgent->m_targetNode, pAgent->output);

		if (pAgent->output.size() > 0)
		{
			if (pAgent->output.size() == 2 && pAgent->output.front() == pAgent->m_lastNodeVisit)
			{
				pAgent->m_nextNode = pAgent->output.back();
				pAgent->output.pop_front();
			}
			else
			{
				pAgent->m_nextNode = pAgent->output.front();
				pAgent->output.pop_front();
			}
		}
		
		////set path on agent
		//if (output.size() == 1) 
		//{
		//	//Agent is at the closest node
		//	pAgent->m_targetNode = output.front();
		//}
		//else if (output.size() == 2) 
		//{
		//	//go to last node in list
		//	pAgent->m_targetNode = output.back();
		//}
		//else 
		//{
		//	if (pAgent->m_lastVisitedNode == output.front())
		//	{
		//		std::list<Node*>::iterator i = output.begin();
		//		std::advance(i, 1);

		//		pAgent->m_targetNode = *i;
		//	}
		//	else
		//	{
		//		pAgent->m_targetNode = output.front();
		//	}
		//}
		return Success;
	}
	else 
	{

		return Success;
	}
	
	
}

Node* FindPath::findNearestNodeToAgent(Agent * a)
{
	//loop through all nodes, find nearest to Agent a
	float currentClosestDistance = std::numeric_limits<float>::max();

	Node* tempNode = nullptr;
	Node* resultNode = nullptr;
	std::list<Node*>::iterator i = m_graph->m_list.begin();
	while (i != m_graph->m_list.end()) 
	{
		//if the distance from the node the loop is looking at
		//is less than the current shortest distance,
		//make that node the closest one
		tempNode = *i;
		if (tempNode->pos.distance(Vector2(a->getPos())) < currentClosestDistance) 
		{
			resultNode = tempNode;
			currentClosestDistance = tempNode->pos.distance(Vector2(a->getPos()));
		}

		//advance iterator
		std::advance(i, 1);
	}

	return resultNode;
}
