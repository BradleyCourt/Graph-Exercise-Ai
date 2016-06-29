#include "Pathfinder.h"
#include "Edge.h"



Pathfinder::Pathfinder()
{
}


Pathfinder::~Pathfinder()
{
}

void Pathfinder::sortGscore(Node * n1, Node * n2)
{
}

void Pathfinder::FindPathDijkstras(Node * startNode, Node* potentialEndNodes, std::list<Node*>& outPut)
{
	std::list<Node*> openList;
	std::list<Node*> closeList;
	Node* endNode = nullptr;

	Node *currentNode = nullptr;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b)
		{
			return a->gScore < b->gScore;
		});

		Node* currentNode = openList.front();

		
		if (currentNode == potentialEndNodes)
		{
			endNode = currentNode;
			break;
		}
		

		openList.remove(currentNode);
		closeList.push_back(currentNode);

		for (auto& edges : currentNode->edgeList)
		{
			bool added = false;
			for (auto & cList : closeList)
			{
				if (cList == edges->m_destination)
				{
				added = true;
				}
			}
			for (auto & oList : openList)
			{
				if (oList == edges->m_destination)
					added = true;

			}
			if (!added)
			{
				openList.push_back(edges->m_destination);
				edges->m_destination->gScore = currentNode->gScore + edges->m_cost;
				edges->m_destination->parent = currentNode;
			}

		}
	}

	currentNode = potentialEndNodes;
	while (currentNode != nullptr)
	{
		//currentNode->pos;
		outPut.push_front(currentNode);
		currentNode = currentNode->parent;
	}
	
}
				
			
// TEST ASTAR
void Pathfinder::AStar(Node * startNode, Node* endNode, std::list<Node*>& aStarPath)
{
	std::list<Node*> openList;
	std::list<Node*> closeList;
//	Node* endNode = nullptr;

	Node *currentNode = nullptr;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b)
		{
			return a->gScore < b->gScore;
		});

		Node* currentNode = openList.front();


		if (currentNode == endNode)
		{

			break;
		}


		openList.remove(currentNode);
		closeList.push_back(currentNode);

		for (auto& edges : currentNode->edgeList)
		{
			bool added = false;
			for (auto & cList : closeList)
			{
				if (cList == edges->m_destination)
				{
					added = true;
				}
			}
			for (auto & oList : openList)
			{
				if (oList == edges->m_destination)
					added = true;

			}
			if (!added)
			{
				openList.push_back(edges->m_destination);
				edges->m_destination->gScore = currentNode->gScore + edges->m_cost;
				currentNode->gScore = currentNode->gScore + edges->m_cost;
				currentNode->hScore = currentNode->pos.distance(endNode->pos);
				currentNode->fScore = currentNode->gScore + currentNode->hScore;
				edges->m_destination->parent = currentNode;
			}

		}
	}

	currentNode = endNode;
	while (currentNode != nullptr)
	{
		//currentNode->pos;
		aStarPath.push_front(currentNode);
		currentNode = currentNode->parent;
	}

}
