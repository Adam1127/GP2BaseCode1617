#include "MyGame.h"

struct Vertex
{
	float x, y, z;

};


MyGame::MyGame()
{

}

void initScene()
{
	Vertex verts[]=
	{
		{-0.5f, -0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f}
	};
}

void destroyScene()
{

}

void render()
{

}

void update()
{

}

MyGame::~MyGame()
{

}
