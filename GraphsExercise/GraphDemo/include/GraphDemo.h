
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GraphDemo_H
#define GraphDemo_H

#include "Application.h"
#include <list>
class SpriteBatch;
class Graph;
class Texture;
class Node;
class Agent;


class GraphDemo : public Application
{
public:

	// assets loaded in constructor
	GraphDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~GraphDemo();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;
	Graph *m_graph;
	Texture *m_nodeTexture;
	Font* m_font;
	
	Texture* crate;
	std::list<Node*> outPut;

	Agent* agent;

	Node* sNode;
	Node* eNode;
private:
};

#endif