#pragma once

#include <Contract/Runnable.h>
#include <Core/APIMacros.h>
#include <Core/MSWindow.h>
#include <Event/Event.h>
#include <Event/ApplicationEvent/WindowResizeEvent.h>
#include <Event/ApplicationEvent/WindowCloseEvent.h>

namespace Chroma
{
	class CHROMA_API ChromaEngineApp : public Runnable
	{
	public:
		ChromaEngineApp();

		void Run() override;

		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

		bool OnWindowResize(WindowResizeEvent& e);

		~ChromaEngineApp();

		std::unique_ptr<Window> win;
	};
}