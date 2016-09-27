#include "GameApplication.h"

GameApplication::GameApplication()
{
	CREATELOG("log.txt");
	m_WindowWidth = 640;
	m_WindowHeight = 480;
	m_WindowCreationFlags = 0;
	m_WindowTitle = "Game";
	m_pWindow = nullptr;
}

GameApplication::~GameApplication()
{
  CLOSELOG();
}

void GameApplication::parseConfig(int args,char * arg[])
{
  stringstream ss;
  //parse config file
  XMLOptionsParser xmlParser=XMLOptionsParser("settings.xml");
  xmlParser.parse(m_Options);
  ss<<m_Options;
  LOG(INFO,"Settings Parsed\n%s",ss.str().c_str());
  ss.str( std::string());
  ss.clear();
	//parse command line arguments into keyvalue pairs, this should
	//overide options in config files
  CommandLineParser commandLineParser=CommandLineParser(args,arg);
  commandLineParser.parse(m_Options);
  ss<<m_Options;
  LOG(INFO,"Command Line Parsed\n%s",ss.str().c_str());
  ss.str( std::string());
  ss.clear();
}


bool GameApplication::init(int args,char * arg[])
{
	parseConfig(args,arg);

	m_WindowWidth = m_Options.getOptionAsInt("WindowWidth");
	m_WindowHeight = m_Options.getOptionAsInt("WindowHeight");
	m_WindowTitle = m_Options.getOption("WindowTitle");


	//Create a window
	m_pWindow = SDL_CreateWindow(m_WindowTitle.c_str(), // window title
		0, //x position
		0, // y postion
		m_WindowWidth, // width, in pixels
		m_WindowHeight, //height, in pixels
		m_WindowCreationFlags //flags
	);

	return true;
}


void GameApplication::run()
{

}
