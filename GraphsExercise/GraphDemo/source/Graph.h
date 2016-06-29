#pragma once

#include <vector>
#include "Vector2.h"
#include <iostream>


class Edge;
class Node;
class Graph
{
public:

	std::vector<Node*>m_list;
	// List of Nodes
	// (which container type are you going to use)
	

public:

	Graph();
	virtual ~Graph();

	void list(Node * node);

	Node* AddNode(Vector2 data);

	//Node* FindNode(Vector2 data); // find node with value

	void RemoveNode(Node *pNode); // remove the given node
	void ConnectNodes(Node *nodeA, Node *nodeB, float data);
		/* edge data (cost or something) */

	Node * FindNode(Vector2 pos);



		// Handle mouse input here
	
protected:

};
