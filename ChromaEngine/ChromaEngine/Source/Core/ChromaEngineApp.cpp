#include "Core/ChromaEngineApp.h"
#include <iostream>
#include "Logging/Log.h"
#include "Core/MSWindow.h"
#include <Event/EventDispatcher.h>
#include <functional>
#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

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

		win->SetEventCallback(HZ_BIND_EVENT_FN(ChromaEngineApp::OnEvent));

		while (true)
		{
			win->OnUpdate();
		}
	}

	void ChromaEngineApp::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		//dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(ChromaEngineApp::OnWindowClose));
		//dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(ChromaEngineApp::OnWindowResize));
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
