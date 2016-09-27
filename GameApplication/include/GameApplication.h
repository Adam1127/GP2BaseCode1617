#ifndef _GAMEAPPLICATION_H
#define _GAMEAPPLICATION_H

#include "Common.h"

//Game Application class, this basically wraps up the initialisation of a game
//this will be the base class of any game we are making. You should override this
//and some of the methods to create your own game
class GameApplication:public NonCopyable
{
public:

	void createWindow(cons string& windowTitle,
		const unsigned int width, const unsigned int height,
		const unsigned int windowflags = 0);

	//Constructor
	GameApplication();
	//Virtual Deconstructor
	virtual ~GameApplication();

	//This is where all major subsystems are created
	virtual bool init(int args,char * arg[]);

	//Basically runs our game
	void run();
protected:

	SDL_Window * m_pWindow;

	ProgramOptions m_Options;

	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;
	unsigned int m_WindowCreationFlags;
	string m_WindowTitle;

	void parseConfig(int args,char * arg[]);

		//init everything - SDL, if it is nonzero we have a problem
		if (SDL_Init(SDL_INIT_EVERYTHING) !+ 0)
		{

			LOG(ERROR, "SDL can't be initialised %s", SDL_GetError());

			return false;

		}

}
#endif
