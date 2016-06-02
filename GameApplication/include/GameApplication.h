#ifndef _GAMEAPPLICATION_H
#define _GAMEAPPLICATION_H

#include "Common.h"

//Game Application class, this basically wraps up the initialisation of a game
//this will be the base class of any game we are making. You should override this
//and some of the methods to create your own game
class GameApplication
{
public:
	//Constructor
	GameApplication();
	//Virtual Deconstructor
	virtual ~GameApplication();

	//This is where all major subsystems are created
	virtual bool init();

	//This is where a scene is initialised, this assumes we only have one scene
	//we should probably create some sort of SceneManager class to manage more than one
	//scene
	virtual void initScene();

	//This updates the current frame of the game, this will call each subsystem in
	//turn and everything in the game should be up to date
	virtual void update();

	//render the current frame of the game
	virtual void render();

	//called when we have to render a GUI, we are using IMGUI for ease of use
	//we should really create our own retained GUI system
	virtual void onRenderGUI();

	//called when we want to destroy the game, this will delete all major
	//subsystem in reverse order
	virtual void destroy();

	//Called to render one game object
	//void render(GameObject::GameObjectSharedPtr gObj);

	//Basically runs our game
	void run();

	void createWindow(const string& windowTitle,const unsigned int width, const unsigned int height, const unsigned int windowFlags=0);
private:
	//this is the C++0x11 way  of disabling the copy constuctor and copy assignment
	//these are generated for you by the compiler, if you don't want copying
	//then do the following!
	GameApplication(const GameApplication&) = delete;
	GameApplication & operator=(const GameApplication&) = delete;
protected:
	//SDL Windows
	SDL_Window * m_pWindow;
	//SDL Drawing Context
	//SDL_GLContext m_glcontext;
	bool m_bIsRunning;
	//This is the vector of game objects, we should probably move
	//this into some sort of scene class
	//vector<GameObject::GameObjectSharedPtr> m_GameObjects;
	//Camera Game object, again lets move it into a scene
	//GameObject::GameObjectSharedPtr m_MainCamera;
	//Game Time
	//Timer m_GameTimer;

	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;
	unsigned int m_WindowCreationFlags;
};
#endif
