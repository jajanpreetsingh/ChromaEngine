#include "Core/ChromaEngineApp.h"
#include <iostream>
#include "Logging/Log.h"
#include "Core/MSWindow.h"
#include <Event/EventDispatcher.h>
#include <functional>

namespace Chroma
{
	ChromaEngineApp::ChromaEngineApp()
	{
	}

	void ChromaEngineApp::Run()
	{
		std::cout << "Initiating Chroma Engine v7 !!!\n";

		WindowProps wp((unsigned int)1280, (unsigned int)720, "Title");

		win = std::unique_ptr<Window>(Window::Create(wp));

		win->SetEventCallback(std::bind(&ChromaEngineApp::OnEvent, this, std::placeholders::_1));

		while (true)
		{
			win->OnUpdate();
		}
	}

	void ChromaEngineApp::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&ChromaEngineApp::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&ChromaEngineApp::OnWindowResize, this, std::placeholders::_1));
	}

	bool ChromaEngineApp::OnWindowClose(WindowCloseEvent& e)
	{
		return true;
	}

	bool ChromaEngineApp::OnWindowResize(WindowResizeEvent& e)
	{
		return false;
	}

	ChromaEngineApp::~ChromaEngineApp()
	{
	}
}
