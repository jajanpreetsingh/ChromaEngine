#include "Core/ChromaEngineApp.h"
#include <iostream>
#include "Logging/Log.h"
#include "Core/MSWindow.h"

namespace Chroma
{
	ChromaEngineApp::ChromaEngineApp()
	{
	}

	void ChromaEngineApp::Run()
	{
		std::cout << "Initiating Chroma Engine v7 !!!\n";

		WindowProps wp((unsigned int)1280, (unsigned int)720,"Title");

		win = Window::Create(wp);

		while (true)
		{
			win->OnUpdate();
		}
	}

	ChromaEngineApp::~ChromaEngineApp()
	{
	}
}
