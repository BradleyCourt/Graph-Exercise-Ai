#include "Pathfinder.h"
#include "Edge.h"
#include <algorithm>



Pathfinder::Pathfinder(Graph* graph)
{
	m_graph = graph;
}


Pathfinder::~Pathfinder()
{
}

void Pathfinder::sortGscore(Node * n1, Node * n2)
{
}

void Pathfinder::FindPathDijkstras(Node * startNode, Node* potentialEndNodes, std::list<Node*>& outPut)
{
		std::list<Node*> Temp;
		std::list<Node*> openList;
		std::list<Node*> closeList;
		Node* endNode = nullptr;

		Node *currentNode = nullptr;

		openList.push_back(startNode);

		startNode->gScore = 0;

		while (!openList.empty())
		{
			openList.sort([](Node* a, Node* b)
			{
				return a->gScore < b->gScore;
			});

			currentNode = openList.front();


			if (currentNode == potentialEndNodes)
			{
				endNode = currentNode;
				break;

			}


			openList.remove(currentNode);
			closeList.push_back(currentNode);

			for (auto& edges : currentNode->edgeList)
			{
				if(std::find(closeList.begin(), closeList.end(), edges->m_destination) == closeList.end())
					openList.push_back(edges->m_destination);

				if (currentNode->gScore + edges->m_cost < edges->m_destination->gScore)
				{
					//edges->m_destination = nullptr;
					edges->m_destination->gScore = currentNode->gScore + edges->m_cost;
					edges->m_destination->parent = currentNode;
				}
			}

		}

		//currentNode = potentialEndNodes;
		while (currentNode != nullptr)
		{
			//currentNode->pos;
			Temp.push_front(currentNode);
			currentNode = currentNode->parent;
		}
		outPut = Temp;
}
				
			
void Pathfinder::AStar(Node * startNode, Node* endNode, std::list<Node*>& outPut)
{
	std::list<Node*> Temp;
	std::list<Node*> openList;
	std::list<Node*> closeList;

	for (auto & node : m_graph->m_list)
	{
		node->parent = nullptr;
		node->gScore = std::numeric_limits<float>::max();
		node->hScore = 0;
		node->fScore = 0;
	}

	Node *currentNode = nullptr;

	openList.push_back(startNode);

	startNode->gScore = 0;

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b)
		{
			return a->fScore < b->fScore;
		});

		currentNode = openList.front();


		if (currentNode == endNode)
		{
			break;
		}


		openList.remove(currentNode);
		closeList.push_back(currentNode);

		for (auto& edges : currentNode->edgeList)
		{
			if (edges->m_destination->gScore > currentNode->gScore)
			{
				//edges->m_destination = nullptr;
				edges->m_destination->gScore = currentNode->gScore + edges->m_cost;
				edges->m_destination->hScore = edges->m_destination->pos.distance(endNode->pos);
				edges->m_destination->fScore = edges->m_destination->gScore + edges->m_destination->hScore;
				edges->m_destination->parent = currentNode;
			}
			if (std::find(closeList.begin(), closeList.end(), edges->m_destination) == closeList.end())
				if (std::find(openList.begin(), openList.end(), edges->m_destination) == openList.end())
					openList.push_back(edges->m_destination);

			bool alreadyTraversed = false;
			for (std::list<Node*>::iterator it = closeList.begin(); it != closeList.end(); it++) {
				if (*it == edges->m_destination) {
					//Connected Node has already been traversed
					alreadyTraversed = true;
					break;

			}
		}
	}

		outPut.clear();
		currentNode = endNode;
		while (currentNode != nullptr)
		{
			outPut.push_front(currentNode);
			currentNode = currentNode->parent;
		}

	}
}
