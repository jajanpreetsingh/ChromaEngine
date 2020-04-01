#include "Core/ChromaEngineApp.h"
#include <iostream>
#include "Logging/Log.h"

ChromaEngineApp::ChromaEngineApp()
{
}

void ChromaEngineApp::Run()
{
	Log l;
	//l.LogInfo("***************Info******************");
	//l.LogWarning("***************Warning******************");
	//l.LogError("***************Error******************");
	std::cout << "Initiating Chroma Engine !!!\n";
}

ChromaEngineApp::~ChromaEngineApp()
{
}
