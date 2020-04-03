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

		WindowProps wp(1280,720,"Title");


		win = std::make_unique<MSWindow>(Window::Create(wp));
	}

	ChromaEngineApp::~ChromaEngineApp()
	{
	}
}
